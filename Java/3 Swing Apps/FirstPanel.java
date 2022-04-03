package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FirstPanel extends JPanel {
    private final String[] data1 = { "Чай" ,"Кофе"  ,"Минеральная","Морс"};
    private final String[] data2 = { "Ясли","Детсад", "Школа"     , "Институт",
            "Университет"};
    private DefaultListModel<String> dlm1 = new DefaultListModel<String>();
    private DefaultListModel<String> dlm2 = new DefaultListModel<String>();
    private JButton button1;
    private JButton button2;
    private JPanel panel1;
    private JList list1;
    private JList list2;
    public FirstPanel() {
        button1=new JButton(">");
        button2=new JButton("<");
        panel1=new JPanel();
        for (String string : data1) {
            dlm1.add(0, string);
        }
        list1=new JList(dlm1);
        list1.setFixedCellWidth(250);
        for (String string : data2) {
            dlm2.add(0, string);
        }
        list2=new JList(dlm2);
        list2.setFixedCellWidth(250);
        list1.setSelectionMode(
                ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
        list2.setSelectionMode(
                ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
        setLayout(new BorderLayout());
        add(list1,BorderLayout.WEST);
        add(list2,BorderLayout.EAST);
        add(panel1,BorderLayout.CENTER);
        panel1.setLayout(new BorderLayout());
        panel1.add(button1,BorderLayout.NORTH);
        panel1.add(button2,BorderLayout.SOUTH);
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                list2.setListData(
                        list1.getSelectedValuesList().toArray(
                                new String[0]));
                for (Object selectedValue:list1.getSelectedValuesList()){
                    dlm1.removeElement(selectedValue);
                }
            }
        });
        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                list1.setListData(
                        list2.getSelectedValuesList().toArray(
                                new String[0]));
                for (Object selectedValue:list2.getSelectedValuesList()){
                    dlm2.removeElement(selectedValue);
                }
            }
        });
    }

}
