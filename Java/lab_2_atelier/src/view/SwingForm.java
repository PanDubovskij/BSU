package view;

import managers.ViewManager;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;


public class SwingForm extends JFrame {
    private JMenuItem saveAsFile;
    private JMenuItem analyzeFile;
    private JMenuItem addToAtelier;
    private JTextArea inputTextArea;
    private JTextArea outputTextArea;
    private AnalyzeDialog analyzeDialog;
    private AddToAtelierDialog addToAtelierDialog;

    private ViewManager viewManager = ViewManager.getInstance();
    private boolean isFileSaved = true;
    private boolean isFileOpened = false;

    public SwingForm() {
        super("Atelier Application");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
//                super.windowClosing(e);
                if (!isFileSaved) {
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
        setJMenuBar(createMenuBar());
        getContentPane().add(createPanel());
        pack();
        analyzeDialog = new AnalyzeDialog(this);
        addToAtelierDialog = new AddToAtelierDialog(this);
        setVisible(true);
    }

    JMenuBar createMenuBar() {
        var jMenuBar = new JMenuBar();
        var file = new JMenu("File");
//        var jFileChooser = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
//        jFileChooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);

        var openFile = new JMenuItem("Open");
        openFile.addActionListener(new OpenFileListener());
        file.add(openFile);

        saveAsFile = new JMenuItem("Save As...");
        saveAsFile.addActionListener(new SaveFileListener());
        saveAsFile.setEnabled(isFileOpened);
        file.add(saveAsFile);

        analyzeFile = new JMenuItem("Analyze");
        analyzeFile.addActionListener(new AnalyzeActionListener());
        analyzeFile.setEnabled(isFileOpened);
        file.add(analyzeFile);

        addToAtelier = new JMenuItem("Add Order");
        addToAtelier.addActionListener(new AddToAtelierActionListener());
        addToAtelier.setEnabled(isFileOpened);
        file.add(addToAtelier);

        jMenuBar.add(file);
        return jMenuBar;
    }

    JPanel createPanel() {
        var jPanel = new JPanel();
        jPanel.setPreferredSize(new Dimension(750, 600));
        jPanel.setLayout(new BorderLayout());
        inputTextArea = new JTextArea(1, 30);
        // inputTextArea.setLineWrap(true);
        inputTextArea.setEditable(false);
        outputTextArea = new JTextArea(1, 30);
        //outputTextArea.setLineWrap(true);
        outputTextArea.setEditable(false);
        var inputScrollPane = new JScrollPane(inputTextArea);
        var outputScrollPane = new JScrollPane(outputTextArea);
        var centerPanel = new JPanel();
        jPanel.add(centerPanel, BorderLayout.CENTER);
        jPanel.add(inputScrollPane, BorderLayout.LINE_START);
        jPanel.add(outputScrollPane, BorderLayout.LINE_END);
        return jPanel;
    }

    private int showSaveFileDialog() {
        var fileChooser = new JFileChooser();
        int option = fileChooser.showSaveDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            try {
                if (selectedFile.createNewFile()) {
                    viewManager.saveAtelierString(selectedFile);
                    isFileSaved = true;
                } else {
                    int input = JOptionPane.showConfirmDialog(null, "File already exists. Do you want to rewrite it?", "Attention!", JOptionPane.YES_NO_CANCEL_OPTION);
                    if (input == 0) {
                        viewManager.saveAtelierString(selectedFile);
                        isFileSaved = true;
                    }
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
        return option;
    }

    private class SaveFileListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            showSaveFileDialog();
        }
    }

    private void showText(String readString, JTextArea jTextArea) throws InterruptedException {
        jTextArea.setText(readString);
    }

    private void showOpenFileDialog() {
        var fileChooser = new JFileChooser();
        int option = fileChooser.showOpenDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            try {
                File selectedFile = fileChooser.getSelectedFile();
                //  File inFile = new File(String.valueOf(selectedFile.toPath()));
                String atelierString = viewManager.getAtelierString(selectedFile.getPath());
                inputTextArea.setText("");

                isFileOpened = true;
                saveAsFile.setEnabled(true);
                analyzeFile.setEnabled(true);
                addToAtelier.setEnabled(true);

//                ObjectInputStream ois = new ObjectInputStream(.getFileName())
                showText(atelierString, inputTextArea);
                isFileSaved = true;
            } catch (IOException | ClassNotFoundException | InterruptedException ex) {
//                ex.printStackTrace();
                JOptionPane.showMessageDialog(null, "You entered wrong format of data, please try again", "Attention!", JOptionPane.ERROR_MESSAGE);

            }
        }
    }

    private class OpenFileListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            if (!isFileSaved) {
                int input = JOptionPane.showConfirmDialog(null, "File is not saved. Do you want to save it?", "Attention!", JOptionPane.YES_NO_OPTION);
                if (input == 0) {
                    showSaveFileDialog();
                }
            }
            showOpenFileDialog();
        }
    }

    public void showRes(String res) {
        outputTextArea.setText(res);
    }

    private class AnalyzeActionListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            analyzeDialog.pack();
            analyzeDialog.setVisible(true);
        }
    }

    private class AddToAtelierActionListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            addToAtelierDialog.pack();
            addToAtelierDialog.setVisible(true);
            inputTextArea.setText(viewManager.getAtelier().toString());
            isFileSaved = false;
        }
    }
}
