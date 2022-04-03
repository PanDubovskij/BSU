package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Random;

public class MyApp1 extends JFrame {
    private JFrame frame;
    private JButton yesButton;
    private JButton noButton;
    private JLabel question;
    public MyApp1(){
        createFrame();
        initListeners();
        showGUI();
    }
    private void createFrame(){
        frame = new JFrame("MyApp1");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);
        yesButton=new JButton("Yes");
        yesButton.setBounds(80,200,100,50);
        noButton=new JButton("No");
        noButton.setBounds(200,200,100,50);
        frame.add(yesButton);
        frame.add(noButton);
        question=new JLabel("Are you satisfied with the size of the scholarship?");
        question.setBounds(50,140,280,50);
        frame.add(question);
    }
    private void initListeners(){
        noButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null,"You should study better","Message",JOptionPane.INFORMATION_MESSAGE);
            }
        });
        yesButton.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {

            }

            @Override
            public void mousePressed(MouseEvent e) {

            }

            @Override
            public void mouseReleased(MouseEvent e){
            }

            @Override
            public void mouseEntered(MouseEvent e) {
                Random rand=new Random();
                yesButton.setBounds(rand.nextInt(300),rand.nextInt(400),100,50);
            }

            @Override
            public void mouseExited(MouseEvent e) {
                Random rand=new Random();
                yesButton.setBounds(rand.nextInt(300),rand.nextInt(400),100,50);
            }
        });
    }
    private void showGUI(){
        frame.pack();
        frame.setSize(400,500);
        frame.setVisible(true);
    }
}
