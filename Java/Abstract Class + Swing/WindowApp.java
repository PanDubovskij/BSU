package com.company;

import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.io.File;
import java.io.IOException;

import static javax.swing.JOptionPane.showMessageDialog;

public class WindowApp extends JFrame{
    private JPanel myPanel;
    private JTextField firstText;
    private JTextField stepText;
    private JTextField numberText;
    private JTextField showText;
    private JButton showButton;
    private JTextField sumText;
    private JComboBox typeComboBox;
    private JButton saveButton;
    private Series series;

    public WindowApp(){
        add(myPanel);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("SeriesGUI");
        setSize(500,500);
        initListeners();
    }
    private void initListeners(){
        showButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    double first_=Double.parseDouble(firstText.getText());
                    double step_=Double.parseDouble(stepText.getText());
                    int n_=Integer.parseInt(numberText.getText());
                    if (typeComboBox.getSelectedItem() == "Exponential") {
                        series = new Exponential(first_, step_);
                        series.setN(n_);
                        showText.setText(series.toString());
                        sumText.setText(Double.toString(series.getSum()));
                    } else if (typeComboBox.getSelectedItem() == "Linear") {
                        series = new Liner(first_, step_);
                        series.setN(n_);
                        showText.setText(series.toString());
                        sumText.setText(Double.toString(series.getSum()));
                    }
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null,ex.getMessage(),"ERROR",JOptionPane.ERROR_MESSAGE);
                }
            }
        });
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                final JFileChooser fc = new JFileChooser();
                int returnVal = fc.showOpenDialog(saveButton);
                FileNameExtensionFilter filter = new FileNameExtensionFilter(
                        "Text file", "txt");
                fc.setFileFilter(filter);
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    try {
                        series.save(file.getName());
                    } catch (IOException ex) {
                        JOptionPane.showMessageDialog(null,ex.getMessage(),"ERROR",JOptionPane.ERROR_MESSAGE);
                    }
                }
            }
        });
        typeComboBox.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                sumText.setText("");
                showText.setText("");
            }
        });
        firstText.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void changedUpdate(DocumentEvent e) {
                clear();
            }
            public void removeUpdate(DocumentEvent e) {
                clear();
            }
            public void insertUpdate(DocumentEvent e) {
                clear();
            }
            public void clear() {
                showText.setText("");
                sumText.setText("");
            }
        });
        stepText.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void changedUpdate(DocumentEvent e) {
                clear();
            }
            public void removeUpdate(DocumentEvent e) {
                clear();
            }
            public void insertUpdate(DocumentEvent e) {
                clear();
            }
            public void clear() {
                showText.setText("");
                sumText.setText("");
            }
        });
        numberText.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void changedUpdate(DocumentEvent e) {
                clear();
            }
            public void removeUpdate(DocumentEvent e) {
                clear();
            }
            public void insertUpdate(DocumentEvent e) {
                clear();
            }
            public void clear() {
                showText.setText("");
                sumText.setText("");
            }
        });
    }
}
