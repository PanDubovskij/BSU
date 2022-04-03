package com.company;

import javax.swing.*;

public class MyApp extends JFrame {
    private JTabbedPane pane;
    private FirstPanel panel1;
    private SecondPanel panel2;
    private ThirdPanel panel3;

    MyApp(){
        pane=new JTabbedPane();
        add(pane);
        panel1=new FirstPanel();
        panel2=new SecondPanel();
        panel3=new ThirdPanel();
        pane.addTab("1", null, panel1);
        pane.addTab("2",null,panel2);
        pane.addTab("3",null,panel3);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600,700);
        setVisible(true);
    }
}
