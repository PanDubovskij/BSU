package views;

import controllers.ClassDescriptionController;
import models.ClassDescription;
import models.DescriptionSaver;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.IOException;
import java.text.NumberFormat;
import java.text.ParseException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.FormatStyle;
import java.util.Locale;
import java.util.ResourceBundle;

public class MyClass extends JFrame {
    private final Locale[] locales = {Locale.US, Locale.ITALY};
    private Locale currentLocale;
    private final JComboBox<Locale> localeCombo;
    private ResourceBundle resStrings;
    private NumberFormat currencyFormat;
    private DateTimeFormatter dateTimeFormatter;
    private final Info info;
    private final JPanel panel;
    private final JMenuBar menuBar;
    private final JMenu file;
    private final JMenuItem saveAsFile;
    private final JLabel currencyLabel;
    private final JLabel dateLabel;
//    private final JLabel classLabel;
//    private final JLabel classDescriptionLabel;
//    private final JTextField currencyField;
    private final JTextField dateField;
    private final JTextField classField;
    private final JTextArea classDescriptionArea;
    private final JScrollPane scrollPane;
    private final JButton getDescriptionButton;
    private ClassDescription classDescription;
    private final ClassDescriptionController controller;
    private boolean isFileSaved;

    public MyClass() {
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE); //ghffdg

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                if (!isFileSaved) {
                    int confirm = JOptionPane.showOptionDialog(null, "Do you want to s//ave the file before closing?", "Exit Confirmation", JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null, null, null);
//                    if (confirm == 0) {
                        if (showSaveFileDialog() != JFileChooser.APPROVE_OPTION) {
                            return;
                        }
                        System.exit(0);
//                    }
//                    if (confirm == 1) {
//                        System.exit(0);
                    }
                } else {
                    System.exit(0);
                }
            }
        });
        isFileSaved = true;
        info = new Info();
        localeCombo = new JComboBox<>(locales);
        controller = new ClassDescriptionController();

        menuBar = new JMenuBar();
//        file = new JMenu("File");
//        saveAsFile = new JMenuItem("Save As...");
        saveAsFile.setEnabled(false);
        saveAsFile.addActionListener(e -> showSaveFileDialog());
        file.add(saveAsFile);
        menuBar.add(file);
//
        currencyLabel = new JLabel("Currency:");
        currencyField = new JTextField("$5,000.00");

        dateLabel = new JLabel("Date:");
        dateField = new JTextField("Jan 12, 1952");
        classLabel = new JLabel("Enter the class:");
        classField = new JTextField();
        classDescriptionLabel = new JLabel("Class description:");
        getDescriptionButton = new JButton("Get Description!");
        classDescriptionArea = new JTextArea();
        scrollPane = new JScrollPane(classDescriptionArea);
        classDescriptionArea.setEditable(false);
        panel = new JPanel();
        panel.setPreferredSize(new Dimension(750, 600));
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        panel.add(localeCombo);
        panel.add(currencyLabel);
        panel.add(currencyField);
        panel.add(dateLabel);
        panel.add(dateField);
        panel.add(classLabel);
        panel.add(classField);
        panel.add(classDescriptionLabel);
        panel.add(getDescriptionButton);
        panel.add(scrollPane);
        getContentPane().add(panel);
        setJMenuBar(menuBar);
        getDescriptionButton.setEnabled(false);
        classField.addKeyListener(new KeyListener() {
//            @Override
//            public void keyTyped(KeyEvent e) {
//            }
//
//            @Override
//            public void keyPressed(KeyEvent e) {
            }

            @Override
            public void keyReleased(KeyEvent e) {
                getDescriptionButton.setEnabled(!classField.getText().isEmpty());
            }
        });
        getDescriptionButton.addActionListener(e -> {
            classDescription = new ClassDescription(classField.getText());
            try {
                controller.updateModel(classDescription);
                classDescriptionArea.setText(classDescription.getClassDescription());
                saveAsFile.setEnabled(!classDescriptionArea.getText().isEmpty());
                isFileSaved = false;
            } catch (Exception exception) {
//                JOptionPane.showMessageDialog(null, "You entered wrong format of data, please try again", "Attention!", JOptionPane.ERROR_MESSAGE);
//
            }

        });

        currentLocale = Locale.US;
        currencyFormat = NumberFormat.getCurrencyInstance(currentLocale);
        dateTimeFormatter = DateTimeFormatter.ofLocalizedDate(FormatStyle.MEDIUM).localizedBy(currentLocale);
        localeCombo.addActionListener(e -> {
            setCurrentLocale((Locale) localeCombo.getSelectedItem());
            validate();
        });

//    }
//
//    private int showSaveFile//Dialog() {
//        var fileChooser = new JFileChooser();
        fileChooser.setSelectedFile(new File(classDescription.getClassName()));
        int option = fileChooser.showSaveDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            try {
                if (!selectedFile.exists()) {
                    controller.saveToFileModel(selectedFile.getPath(), new DescriptionSaver(classDescription));
                    isFileSaved = true;
                } else {
                    int input = JOptionPane.showConfirmDialog(null, "File already exists. Do you want to rewrite it?", "Attention!", JOptionPane.YES_NO_CANCEL_OPTION);
                    if (input == 0) {
                        controller.saveToFileModel(selectedFile.getPath(), new DescriptionSaver(classDescription));
                        isFileSaved = true;
                    }
                }
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(null, "Error! File wasn't saved!", "Attention!", JOptionPane.ERROR_MESSAGE);
            }
        }
        return option;
    }

    private void setCurrentLocale(Locale locale) {
        currentLocale = locale;
        localeCombo.setLocale(currentLocale);
        localeCombo.setSelectedItem(currentLocale);
        resStrings = ResourceBundle.getBundle("language_settings", currentLocale);
        currencyFormat = NumberFormat.getCurrencyInstance(currentLocale);
        dateTimeFormatter = DateTimeFormatter.ofLocalizedDate(FormatStyle.MEDIUM).localizedBy(currentLocale);
        getInfo();
        updateDisplay();
        updateInfo();
    }

    private void updateDisplay() {
        currencyLabel.setText(resStrings.getString("currency"));
        dateLabel.setText(resStrings.getString("date"));
        classLabel.setText(resStrings.getString("enterLabel"));
        classDescriptionLabel.setText(resStrings.getString("description"));
        getDescriptionButton.setText(resStrings.getString("button"));
        file.setText(resStrings.getString("file"));
        saveAsFile.setText(resStrings.getString("saveAs"));

    }

    private void updateInfo() {
        currencyField.setText(currencyFormat.format(info.getCurrency()));
        dateField.setText(dateTimeFormatter.format(info.getDate()));
    }

    private class Info {
        private double currency;
        private LocalDate date;

        public double getCurrency() {
            return currency;
        }

        public void setCurrency(double aCurrency) {
            currency = aCurrency;
        }

        public LocalDate getDate() {
            return date;
        }

        public void setDate(LocalDate date) {
            this.date = date;
        }
    }

    private void getInfo() {
        try {
            info.setCurrency(currencyFormat.parse(currencyField.getText()).doubleValue());
            info.setDate(LocalDate.parse(dateField.getText().trim(), dateTimeFormatter));
        } catch (ParseException e) {
            JOptionPane.showMessageDialog(null, "You entered wrong format of data, please try again", "Attention!", JOptionPane.ERROR_MESSAGE);
        }
    }
}
