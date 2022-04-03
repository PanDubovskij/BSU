package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Objects;
import java.util.TreeMap;

public class AddDialog extends JDialog {
    private JButton buttonOK=new JButton("OK");
    private JButton buttonCancel=new JButton("Cancel");
    private JTextField textField1=new JTextField();
    private JTextField textField2=new JTextField();
    private JTextField textField3=new JTextField();
    private JTextField textField4=new JTextField();
    private JLabel label1=new JLabel("Id number");
    private JLabel label2=new JLabel("Surname");
    private JLabel label3=new JLabel("Term");
    private JLabel label4=new JLabel("Subjects");
    private Student st;
    public AddDialog() {
        setModal(true);
        getRootPane().setDefaultButton(buttonOK);
        add(label1);
        add(textField1);
        add(label2);
        add(textField2);
        add(label3);
        add(textField3);
        add(label4);
        add(textField4);
        setLayout(new GridLayout(5,2));
        buttonOK.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onOK();
            }
        });

        buttonCancel.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onCancel();
            }
        });

        // call onCancel() when cross is clicked
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                onCancel();
            }
        });
        add(buttonOK);
        add(buttonCancel);
        pack();
        setVisible(true);
    }

    private void onOK() {
        // add your code here
        if (textField1.getText().equals("") && textField2.getText().equals("") && textField3.getText().equals("") && textField4.getText().equals("")) {
            JOptionPane.showMessageDialog(null,"Empty fields","ERROR",JOptionPane.ERROR_MESSAGE);
        }else{
        int number=Integer.parseInt(textField1.getText());
        String surname= textField2.getText();
        int term=Integer.parseInt(textField3.getText());
        st=new Student(number,surname,term);
        String[] subjects=textField4.getText().split("\\s");
        TreeMap<String, Integer> exams = new TreeMap<>();
        exams.put(subjects[0],Integer.valueOf(subjects[1]));
        st.setExams(exams);
        }
        dispose();
    }
    public Student getStudent(){
        return st;
    }
    private void onCancel() {
        // add your code here if necessary
        dispose();
    }

}
