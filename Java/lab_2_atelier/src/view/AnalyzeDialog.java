package view;

import managers.ViewManager;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.text.ParseException;
import java.util.Objects;

class AnalyzeDialog extends JDialog implements ActionListener, PropertyChangeListener {

    private JComboBox<String> periodCombobox;
    private JComboBox<String> monthCombobox;
    private JComboBox<String> quarterCombobox;
    private JTextField dayTextField;
    private JOptionPane optionPane;

    private String btnString1 = "Enter";
    private String btnString2 = "Cancel";
    private String date = "";
    private SwingForm frame;

    private ViewManager viewManager = ViewManager.getInstance();

    public AnalyzeDialog(Frame aFrame) {
        super(aFrame, true);
        frame = (SwingForm) aFrame;
        setTitle("Analyze");
        String[] periodStrings = {"Day", "Month", "Quarter"};
        periodCombobox = new JComboBox<>(periodStrings);
        String[] quarterStrings = {"Jan-Mar", "Apr-Jun", "Jul-Sep", "Oct-Dec"};
        String[] monthStrings = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        quarterCombobox = new JComboBox<>(quarterStrings);
        monthCombobox = new JComboBox<>(monthStrings);
        dayTextField = new JTextField();
        dayTextField.setVisible(true);
        quarterCombobox.setVisible(false);
        monthCombobox.setVisible(false);
        dayTextField.setText("dd-MM-yyyy");
        dayTextField.addFocusListener(new FocusListener() {
            @Override
            public void focusGained(FocusEvent e) {
                if (date.equals("")) {
                    dayTextField.setText("");
                }
            }

            @Override
            public void focusLost(FocusEvent e) {
                date = dayTextField.getText();
            }
        });

        Object[] options = {btnString1, btnString2};
        Object[] elements = {periodCombobox, monthCombobox, quarterCombobox, dayTextField};

        periodCombobox.addItemListener(e -> {
            String period = (String) e.getItem();
            switch (period) {
                case "Day" -> {
                    dayTextField.setVisible(true);
                    quarterCombobox.setVisible(false);
                    monthCombobox.setVisible(false);
                }
                case "Month" -> {
                    dayTextField.setVisible(false);
                    quarterCombobox.setVisible(false);
                    monthCombobox.setVisible(true);
                }
                case "Quarter" -> {
                    dayTextField.setVisible(false);
                    quarterCombobox.setVisible(true);
                    monthCombobox.setVisible(false);
                }
            }
        });

        optionPane = new JOptionPane(elements, JOptionPane.INFORMATION_MESSAGE, JOptionPane.YES_NO_OPTION, null, options, options[0]);

        setContentPane(optionPane);
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                optionPane.setValue(JOptionPane.CLOSED_OPTION);
            }
        });
        optionPane.addPropertyChangeListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        optionPane.setValue(btnString1);
    }

    public void propertyChange(PropertyChangeEvent e) {
        String prop = e.getPropertyName();

        if (isVisible() && (e.getSource() == optionPane) && (JOptionPane.VALUE_PROPERTY.equals(prop) || JOptionPane.INPUT_VALUE_PROPERTY.equals(prop))) {
            Object value = optionPane.getValue();

            if (value == JOptionPane.UNINITIALIZED_VALUE) {
                return;
            }
            optionPane.setValue(JOptionPane.UNINITIALIZED_VALUE);

            if (btnString1.equals(value)) {
                String period = (String) periodCombobox.getSelectedItem();
                try {
                    switch (Objects.requireNonNull(period)) {
                        case "Day" -> {
                            var dayText = dayTextField.getText();
                            viewManager.showResults(period, dayText);
                            frame.showRes(viewManager.getResults());
                            clearAndHide();
                        }
                        case "Month" -> {
                            var month = String.valueOf(monthCombobox.getSelectedIndex());
                            viewManager.showResults(period, month);
                            frame.showRes(viewManager.getResults());
                            clearAndHide();
                        }
                        case "Quarter" -> {
                            var quarter = String.valueOf(quarterCombobox.getSelectedIndex());
                            viewManager.showResults(period, quarter);
                            frame.showRes(viewManager.getResults());
                            clearAndHide();
                        }
                        default -> clearAndHide();
                    }
                } catch (ParseException ex) {
                    JOptionPane.showMessageDialog(null, "You entered wrong format of data, please try again", "Attention!", JOptionPane.ERROR_MESSAGE);

                }

            } else {
                clearAndHide();
            }
        }

    }
    public void clearAndHide() {
        setVisible(false);
    }
}
