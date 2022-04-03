package com.company;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

public class MyApp extends JFrame {
    private JList<String> list1;
    private JList<String> list2;
    private JTextField text;
    private JLabel label;
    private JButton check;
    private JButton read;
    private JButton add;
    private DefaultListModel<String> dlm1 = new DefaultListModel<String>();
    private DefaultListModel<String> dlm2 = new DefaultListModel<String>();
    private StudentsCollection studentsCollection;
    public MyApp(){
        setLayout(null);
        label=new JLabel("Term and subjects");
        label.setBounds(10,10,300,100);
        add(label);
        studentsCollection=new StudentsCollection();

        for (Student student : studentsCollection.getStudents()) {
            dlm1.add(0, student.toString());
        }
        list1=new JList(dlm1);
        list1.setFixedCellWidth(650);
        list1.setBounds(10,200,650,500);
        add(list1);
        text=new JTextField();
        text.setBounds(150,45,600,30);
        add(text);
        check=new JButton("Find Bad Students");
        check.setBounds(250,100,200,70);
        read=new JButton("Read from file");
        read.setBounds(800,45,300,30);
        add(read);
        add(check);
        add=new JButton("Add Student");
        add.setBounds(800,100,300,30);
        add(add);
        add.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                AddDialog myDialog=new AddDialog();
                if(myDialog.getStudent()!=null){
                studentsCollection.add(myDialog.getStudent());
                dlm1.add(0,myDialog.getStudent().toString());
                }
            }
        });
        check.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                studentsCollection.findBadStudents(text.getText());
                for (Student student : studentsCollection.getSortedStudents()) {
                    dlm2.add(0, student.toString());
                }

            }
        });
        read.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                final JFileChooser fc = new JFileChooser();
                int returnVal = fc.showOpenDialog(read);
                FileNameExtensionFilter filter = new FileNameExtensionFilter(
                        "Text file", "txt");
                fc.setFileFilter(filter);
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    studentsCollection.read(file.getName());
                    for (Student student : studentsCollection.getStudents()) {
                        dlm1.add(0, student.toString());
                    }
                }
            }
        });
        list2=new JList(dlm2);
        list2.setFixedCellWidth(650);
        list2.setBounds(700,200,655,500);
        add(list2);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(1370,700);
        setVisible(true);
    }
}
