package view;

import managers.ViewManager;
import models.Order;
import models.Service;
import models.ServiceType;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;

class AddToAtelierDialog extends JDialog implements ActionListener, PropertyChangeListener, ItemListener {


    private JTextField dayTextField;

    private JCheckBox tailoring;
    private JCheckBox clothingRepair;
    private JCheckBox shoesRepair;
    private JCheckBox cleaning;
    private JCheckBox zipperReplacement;
    private JOptionPane optionPane;

    private String btnString1 = "Enter";
    private String btnString2 = "Cancel";
    private String date = "";
    private JLabel dateLabel;
    private JLabel serviceTypeLabel;
    private SwingForm frame;

    private ViewManager viewManager = ViewManager.getInstance();

    private ArrayList<Service> services = new ArrayList<>();

    public AddToAtelierDialog(Frame aFrame) {
        super(aFrame, true);
        frame = (SwingForm) aFrame;
        setTitle("Add Order");
        dateLabel = new JLabel("Enter date:");
        serviceTypeLabel = new JLabel("Choose service type:");
        dayTextField = new JTextField();
        dayTextField.setVisible(true);
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

        tailoring = new JCheckBox("Tailoring");
        tailoring.addItemListener(this);
        clothingRepair = new JCheckBox("Clothing Repair");
        clothingRepair.addItemListener(this);
        shoesRepair = new JCheckBox("Shoes Repair");
        shoesRepair.addItemListener(this);
        cleaning = new JCheckBox("Cleaning");
        cleaning.addItemListener(this);
        zipperReplacement = new JCheckBox("Zipper Replacement");
        zipperReplacement.addItemListener(this);


        Object[] options = {btnString1, btnString2};
        Object[] elements = {serviceTypeLabel, tailoring, clothingRepair, shoesRepair, cleaning, zipperReplacement, dateLabel, dayTextField};


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
                String date = dayTextField.getText();
                var formatter = new SimpleDateFormat("dd-MM-yyyy");
                try {
                    if(services.isEmpty()){
                        JOptionPane.showMessageDialog(null, "You did not specify one service!", "Attention!", JOptionPane.ERROR_MESSAGE);
                    }else{
                        Order o = new Order(formatter.parse(date), services);
                        viewManager.addOrder(o);
                        clearAndHide();
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

    @Override
    public void itemStateChanged(ItemEvent e) {
        Object source = e.getItemSelectable();

        if (source == tailoring) {
            services.add(new Service(ServiceType.TAILORING));
        } else if (source == clothingRepair) {
            services.add(new Service(ServiceType.CLOTHING_REPAIR));
        } else if (source == shoesRepair) {
            services.add(new Service(ServiceType.SHOES_REPAIR));
        } else if (source == cleaning) {
            services.add(new Service(ServiceType.CLEANING));
        } else if (source == zipperReplacement) {
            services.add(new Service(ServiceType.ZIPPER_REPLACEMENT));
        }
    }
}
