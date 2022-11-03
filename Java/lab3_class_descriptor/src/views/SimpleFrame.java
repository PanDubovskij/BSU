package views;

import controllers.ClassDescriptionController;
import models.ClassDescription;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.text.NumberFormat;
import java.util.Locale;
import java.util.ResourceBundle;

public class SimpleFrame extends JFrame {
    private Locale[] locales = {Locale.ENGLISH, Locale.ITALIAN};
    private Locale currentLocale;
    private JComboBox<Locale> localeCombo = new JComboBox<>(locales);
    private ResourceBundle resStrings;
    private ResourceBundle res;
    private NumberFormat currencyFormat;
    private NumberFormat numberFormat;
    private NumberFormat percentFormat;
    private Info info = new Info();
    private JLabel currencyLabel;
    private JLabel dateLabel;
    private JLabel classLabel;
    private JLabel classDescriptionLabel;
    private JTextField currencyField;
    private JTextField dateField;
    private JTextField classField;
    private JTextArea classDescriptionArea;
    private JScrollPane scrollPane;
    private JButton getDescriptionButton;
    private ClassDescription classDescription;
    private ClassDescriptionController controller;

    public SimpleFrame() {
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        controller = new ClassDescriptionController();
        var panel = new JPanel();
        currencyLabel = new JLabel("Currency:");
        currencyField = new JTextField();

        dateLabel = new JLabel("Date:");
        dateField = new JTextField();
        classLabel = new JLabel("Enter the class:");
        classField = new JTextField();
        classDescriptionLabel = new JLabel("Class description:");
        getDescriptionButton = new JButton("Get Description!");
        classDescriptionArea = new JTextArea();
        scrollPane = new JScrollPane(classDescriptionArea);
        classDescriptionArea.setEditable(false);
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
        pack();
        setVisible(true);
        getDescriptionButton.addActionListener(e -> {
            classDescription = new ClassDescription(classField.getText());
            try {
                controller.updateModel(classDescription);
            } catch (Exception exception) {
                System.out.println(exception.getMessage());

            }

            classDescriptionArea.setText(classDescription.getClassDescription());
        });
        currentLocale = Locale.ENGLISH;
        localeCombo.addActionListener(e -> {
            setCurrentLocale((Locale) localeCombo.getSelectedItem());
            validate();
        });

    }

    private void setCurrentLocale(Locale locale) {
        currentLocale = locale;
        localeCombo.setLocale(currentLocale);
        localeCombo.setSelectedItem(currentLocale);
        resStrings = ResourceBundle.getBundle("language_settings", currentLocale);
        currencyFormat = NumberFormat.getCurrencyInstance(currentLocale);
        numberFormat = NumberFormat.getNumberInstance(currentLocale);
        updateDisplay();
        updateInfo();
    }

    private void updateDisplay() {
        currencyLabel.setText(resStrings.getString("currency"));
        dateLabel.setText(resStrings.getString("date"));
        classLabel.setText(resStrings.getString("enterLabel"));
        classDescriptionLabel.setText(resStrings.getString("description"));
        getDescriptionButton.setText(resStrings.getString("button"));
    }

    private void updateInfo() {
        currencyField.setText(currencyFormat.format(info.getCurrency()));
        //for date
    }

    private class Info {
        private double currency;
        //date

        public double getCurrency() {
            return currency;
        }

        public void setCurrency(double aCurrency) {
            currency = aCurrency;
        }

    }
}
