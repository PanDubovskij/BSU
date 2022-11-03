import javax.swing.*;
import javax.swing.filechooser.FileSystemView;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.StandardOpenOption;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class AppForm extends JFrame {

    private JTextArea inputTextArea;
    private JTextArea outputTextArea;
    private JTextArea rules;

    private boolean isFileSaved = false;
    private String prevRules = "";
    private Map<String, String> dictionary = new HashMap<>();

    public AppForm() {
        super("Translator");
        setSize(700, 700);
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
//                super.windowClosing(e);
                if (!isFileSaved && outputTextArea.getText().length() != 0) {
                    int confirm = JOptionPane.showOptionDialog(null, "Do you want to save the file before closing?", "Exit Confirmation", JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null, null, null);
                    if (confirm == 0) {
                        if (showSaveFileDialog() != JFileChooser.APPROVE_OPTION) {
                            return;
                        }
                        System.exit(0);
                    }
                    if (confirm == 1) {
                        System.exit(0);
                    }
                } else {
                    System.exit(0);
                }
            }
        });
        setJMenuBar(menuBar());
        getContentPane().add(panel());


//        pack();
        setVisible(true);
    }

    private JMenuBar menuBar() {
        JMenuBar jMenuBar = new JMenuBar();
        JMenu file = new JMenu("File");
        JFileChooser jFileChooser = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
        jFileChooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
        JMenuItem openFile = new JMenuItem("Open");
        openFile.addActionListener(new openFileListener());
        file.add(openFile);


        JMenuItem saveAsFile = new JMenuItem("Save As...");
        saveAsFile.addActionListener(new saveFileListener());
        file.add(saveAsFile);

        jMenuBar.add(file);
        return jMenuBar;
    }

    private JPanel panel() {
        JPanel jPanel = new JPanel();
        jPanel.setLayout(new BorderLayout());

        inputTextArea = new JTextArea(5, 20);
        inputTextArea.setLineWrap(true);
        outputTextArea = new JTextArea(5, 20);
        outputTextArea.setLineWrap(true);
        outputTextArea.setEditable(false);

        JPanel centerPanel = new JPanel();
        JButton fileChooserButton = new JButton("Choose translation rules file:");
        fileChooserButton.addActionListener(new openRulesFileListener());
        JButton translateButton = new JButton("Translate!");
        translateButton.addActionListener(e -> {
            StringBuilder temp = new StringBuilder();
            Scanner scanner;
            String rulesText = rules.getText();
            if (!prevRules.equals(rulesText)) {
                prevRules=rulesText;
                dictionary.clear();
                scanner = new Scanner(rulesText);
                while (scanner.hasNextLine()) {
                    dictionary.put(scanner.next(), scanner.next());
                }
            }

            scanner = new Scanner(inputTextArea.getText());
            scanner.useDelimiter("");
            while (scanner.hasNext()) {
                String c = scanner.next();
                if (Character.isUpperCase((c.charAt(0)))) {
                    c = c.toLowerCase();
                    String c1 = dictionary.getOrDefault(c, c);
                    temp.append(c1.replace(c1.charAt(0), String.valueOf(c1.charAt(0)).toUpperCase().charAt(0)));
                } else {
                    temp.append(dictionary.getOrDefault(c, c));
                }
            }
//            prevInput = temp.toString();
            outputTextArea.setText(temp.toString());
            scanner.close();
            isFileSaved(false);
        });
        rules = new JTextArea(33, 10);

        centerPanel.add(fileChooserButton);
        centerPanel.add(translateButton);
        centerPanel.add(rules);
        jPanel.add(centerPanel, BorderLayout.CENTER);
        jPanel.add(inputTextArea, BorderLayout.LINE_START);
        jPanel.add(outputTextArea, BorderLayout.LINE_END);
        return jPanel;
    }


    private class saveFileListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            showSaveFileDialog();
        }
    }

    private int showSaveFileDialog() {
        JFileChooser fileChooser = new JFileChooser();
        int option = fileChooser.showSaveDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            try {
                if (selectedFile.createNewFile()) {
                    writeToFile(selectedFile, outputTextArea.getText());
                } else {
                    int input = JOptionPane.showConfirmDialog(null, "File already exists. Do you want to rewrite it?", "Attention!", JOptionPane.YES_NO_CANCEL_OPTION);
                    if (input == 0) {
                        writeToFile(selectedFile, outputTextArea.getText());
                    }
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
        return option;
    }

    private void writeToFile(File selectedFile, String text) throws IOException {
        Files.writeString(selectedFile.toPath(), text, StandardCharsets.UTF_8, StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING);
        isFileSaved(true);
    }

    private class openRulesFileListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            showOpenRulesFileDialog();
        }
    }

    private void showOpenRulesFileDialog() {
        JFileChooser fileChooser = new JFileChooser();
        int option = fileChooser.showOpenDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            try {
                rules.setText("");
                showText(Files.readString(selectedFile.toPath(), StandardCharsets.UTF_8), rules);
                dictionary.clear();
                Scanner scanner = new Scanner(rules.getText());
                while (scanner.hasNextLine()) {
                    dictionary.put(scanner.next(), scanner.next());
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    private class openFileListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            if (!isFileSaved && outputTextArea.getText().length() != 0) {
                int input = JOptionPane.showConfirmDialog(null, "File is not saved. Do you want to save it?", "Attention!", JOptionPane.YES_NO_OPTION);
                if (input == 0) {
                    showSaveFileDialog();
                }
            }
            showOpenFileDialog();
        }
    }

    private void showOpenFileDialog() {
        JFileChooser fileChooser = new JFileChooser();
        int option = fileChooser.showOpenDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            try {
                inputTextArea.setText("");
                showText(Files.readString(selectedFile.toPath(), StandardCharsets.UTF_8), inputTextArea);
                isFileSaved(true);
            } catch (IOException ex) {
                ex.printStackTrace();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    private void showText(String readString, JTextArea jTextArea) throws InterruptedException {
        jTextArea.setText(readString);
    }

    private void isFileSaved(boolean isSaved) {
        isFileSaved = isSaved;
    }
}
