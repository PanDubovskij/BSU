package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SecondPanel extends JPanel implements MouseListener {
    private final JButton[] buttons;
    private static final String[] names=
            {"1","2","3","4","5","6","7","8","9"};
    private Color color;
    public SecondPanel() {
        setLayout(new GridLayout(3,3));
        buttons=new JButton[names.length];
        for(int count=0;count<names.length;count++){
            buttons[count]=new JButton(names[count]);
            buttons[count].addMouseListener(this);
            add(buttons[count]);
        }
        color=buttons[0].getBackground();
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {
        JButton button=(JButton) e.getSource();
        button.setText("Clicked!");
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        for(int count=0;count<names.length;count++){
            buttons[count].setText(names[count]);
        }
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        JButton button=(JButton) e.getSource();
        button.setBackground(Color.YELLOW);
    }

    @Override
    public void mouseExited(MouseEvent e) {
        JButton button=(JButton) e.getSource();
        button.setBackground(color);
    }
}
