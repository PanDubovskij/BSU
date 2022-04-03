package com.company;

import javax.swing.*;

public class ThirdPanel extends JPanel {
    private ButtonGroup radioButtonGroup;
    private JRadioButton[] radioButtons;
    private ImageIcon[] icons;
    public final static int NUM = 3;
    public ThirdPanel() {
        radioButtonGroup = new ButtonGroup();
        icons = new ImageIcon[NUM + 1];
        for (int i = 0 ; i < NUM + 1 ; i++){
            String path = "src\\icon" + i +".png";
            icons[i] = new ImageIcon(path);
        }

        radioButtons = new JRadioButton[NUM];
        for (int i = 0 ; i < NUM ; i++){
            radioButtons[i] = new JRadioButton("My RadioButton");
            radioButtons[i].setIcon(icons[0]);
            radioButtons[i].setSelectedIcon(icons[1]);
            radioButtons[i].setPressedIcon(icons[2]);
            radioButtons[i].setRolloverIcon(icons[3]);
            radioButtonGroup.add(radioButtons[i]);
            add(radioButtons[i]);
        }
    }
}
