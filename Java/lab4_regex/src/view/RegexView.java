package view;

import controller.Controller;
import model.FileModel;
import model.ModelReader;
import model.ModelSaver;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

public class RegexView extends JFrame {
    private JMenuBar menuBar;
    private JMenu file;
    private JMenuItem openFile;
    private JMenuItem saveAsFile;
    private JPanel panel;
    private JPanel centerPanel;
    private JScrollPane inputScrollPane;
    private JScrollPane outputScrollPane;
    private JTextArea inputTextArea;
    private JTextArea outputTextArea;
    private JButton deleteComments;
    private boolean isFileSaved;
    private final JFileChooser fileChooser;
    private final Controller controller;
    private final FileModel fileModel;
    private final ModelReader modelReader;
    private final ModelSaver modelSaver;

    public RegexView() {
        super("Regex");
        setSize(1920, 1080);
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                showOptionDialog();
            }
        });
        setJMenuBar(createMenuBar());
        getContentPane().add(createPanel());
        fileChooser = new JFileChooser();
        isFileSaved = true;
        fileModel = new FileModel();
        modelReader = new ModelReader(fileModel);
        modelSaver = new ModelSaver(fileModel);
        controller = new Controller();
    }

    private JMenuBar createMenuBar() {
        openFile = new JMenuItem("Open");
        openFile.addActionListener(e -> {
            if (!isFileSaved && !outputTextArea.getText().isEmpty()) {
                int confirm = JOptionPane.showOptionDialog(
                        null,
                        "Do you want to save the file before closing?",
                        "Exit Confirmation",
                        JOptionPane.YES_NO_CANCEL_OPTION,
                        JOptionPane.QUESTION_MESSAGE,
                        null,
                        null,
                        null
                );
                if (confirm == JOptionPane.YES_OPTION) {
                    if (showSaveFileDialog() != JFileChooser.APPROVE_OPTION) {
                        return;
                    }
                    showOpenFileDialog();
                }
                if (confirm == JOptionPane.NO_OPTION) {
                    showOpenFileDialog();
                }
            } else {
                showOpenFileDialog();
            }
        });

        saveAsFile = new JMenuItem("Save As...");
        saveAsFile.setEnabled(false);
        saveAsFile.addActionListener(e -> {
            showSaveFileDialog();
        });

        file = new JMenu("File");
        file.add(openFile);
        file.add(saveAsFile);

        menuBar = new JMenuBar();
        menuBar.add(file);
        return menuBar;
    }

    private JPanel createPanel() {

        inputTextArea = new JTextArea(45, 70);
        inputTextArea.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {

            }

            @Override
            public void keyPressed(KeyEvent e) {

            }

            @Override
            public void keyReleased(KeyEvent e) {
                deleteComments.setEnabled(!inputTextArea.getText().isEmpty());
            }
        });
        inputScrollPane = new JScrollPane(inputTextArea);

        outputTextArea = new JTextArea(45, 70);
        outputTextArea.setEditable(false);
        outputScrollPane = new JScrollPane(outputTextArea);

        deleteComments = new JButton("Delete comments!");
        deleteComments.setEnabled(false);
        deleteComments.addActionListener(e -> {
            String input = inputTextArea.getText();
            fileModel.setClassDescription(input);
            controller.updateModel(fileModel);
            outputTextArea.setText(fileModel.getClassDescriptionWithoutComments());
            saveAsFile.setEnabled(true);
            isFileSaved = false;
        });

        centerPanel = new JPanel();
        centerPanel.add(deleteComments);

        panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.add(centerPanel, BorderLayout.CENTER);
        panel.add(inputScrollPane, BorderLayout.LINE_START);
        panel.add(outputScrollPane, BorderLayout.LINE_END);

        return panel;
    }

    private int showSaveFileDialog() {
        int option = fileChooser.showSaveDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            try {
                if (!selectedFile.exists()) {
                    controller.writeToFile(selectedFile.getPath(), modelSaver);
                    isFileSaved = true;
                } else {
                    int input = JOptionPane.showConfirmDialog(
                            null,
                            "File already exists. Do you want to rewrite it?",
                            "Attention!",
                            JOptionPane.YES_NO_CANCEL_OPTION
                    );
                    if (input == JOptionPane.YES_OPTION) {
                        controller.writeToFile(selectedFile.getPath(), modelSaver);
                        isFileSaved = true;
                    }
                }
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(
                        null,
                        "Error! File wasn't saved!",
                        "Attention!",
                        JOptionPane.ERROR_MESSAGE
                );
            }
        }
        return option;
    }

    private void showOpenFileDialog() {
        int option = fileChooser.showOpenDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            try {
                controller.readFromFile(selectedFile.getPath(), modelReader);
                inputTextArea.setText(fileModel.getClassDescription());
                outputTextArea.setText("");
                isFileSaved = true;
            } catch (FileNotFoundException e) {
                JOptionPane.showMessageDialog(
                        null,
                        "Error! File wasn't opened!",
                        "Attention!",
                        JOptionPane.ERROR_MESSAGE
                );
            }
        }
    }

    private void showOptionDialog() {
        if (!isFileSaved && !outputTextArea.getText().isEmpty()) {
            int confirm = JOptionPane.showOptionDialog(
                    null,
                    "Do you want to save the file before closing?",
                    "Exit Confirmation",
                    JOptionPane.YES_NO_CANCEL_OPTION,
                    JOptionPane.QUESTION_MESSAGE,
                    null,
                    null,
                    null
            );
            if (confirm == JOptionPane.YES_OPTION) {
                if (showSaveFileDialog() != JFileChooser.APPROVE_OPTION) {
                    return;
                }
                System.exit(0);
            }
            if (confirm == JOptionPane.NO_OPTION) {
                System.exit(0);
            }
        } else {
            System.exit(0);
        }
    }
}
