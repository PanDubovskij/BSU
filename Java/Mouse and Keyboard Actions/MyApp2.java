package com.company;

import javax.swing.*;
import java.awt.event.*;

public class MyApp2 extends JFrame {
    private JFrame frame;
    private JButton button;
    private JLabel statusBar;
    public MyApp2(){
        createFrame();
        changeButtonName();
        dragDrop();
        changeButtonLocation();
        showStatusBar();
        showGUI();
    }
    private void changeButtonLocation(){
        frame.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int x=e.getX();
                int y=e.getY();

                button.setLocation(x-50,y-50);
            }
        });
    }
    private void showStatusBar(){
        frame.addMouseMotionListener(new MouseMotionListener() {

            @Override
            public void mouseDragged(MouseEvent e) {
            }

            @Override
            public void mouseMoved(MouseEvent e) {
                statusBar.setText("X="+e.getX()+" Y="+e.getY());
            }
        });
    }
    private void dragDrop(){
        MouseAdapter mouseDrag = new MouseAdapter() {
            int clickX, clickY;
            boolean isClicked;
            @Override
            public void mousePressed(MouseEvent e) {
                if ( (e.getModifiersEx() & InputEvent.CTRL_DOWN_MASK) != 0 ) {
                    isClicked = true;
                    clickX=e.getX();
                    clickY=e.getY();
                }
            }
            @Override
            public void mouseReleased(MouseEvent e) {
                isClicked=false;
            }

            @Override
            public void mouseMoved(MouseEvent e) {
                statusBar.setText("X="+e.getXOnScreen()+" Y="+e.getYOnScreen());
            }
            @Override
            public void mouseDragged(MouseEvent e) {
                if(isClicked){
                    int dx = e.getX() - clickX;
                    int dy = e.getY() - clickY;
                    button.setLocation( button.getX() + dx, button.getY() + dy );
                }
            }
        };
        button.addMouseListener( mouseDrag );
        button.addMouseMotionListener( mouseDrag );
    }
    private void changeButtonName(){
        button.addKeyListener(new KeyListener() {
            String str=new String("My Button");
            @Override
            public void keyTyped(KeyEvent e) {
                if(e.getKeyChar()==KeyEvent.VK_BACK_SPACE){
                    if (str.length()>0) {
                        str = str.substring(0, str.length() - 1);
                        button.setSize(button.getWidth()-6,button.getHeight());
                    }
                }else {
                    str += e.getKeyChar();
                    button.setText(str);
                    button.setSize(button.getWidth()+6,button.getHeight());
                }
            }

            @Override
            public void keyPressed(KeyEvent e) {

            }

            @Override
            public void keyReleased(KeyEvent e) {
                button.setText(str);
            }
        });
    }
    private void createFrame(){
        frame = new JFrame("MyApp1");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);
        button=new JButton("My Button");
        button.setBounds(100,100,100,50);
        frame.add(button);
        statusBar=new JLabel(" ");
        statusBar.setBounds(110,320,100,20);
        frame.add(statusBar);

    }
    private void showGUI(){
        frame.pack();
        frame.setSize(300,400);
        frame.setVisible(true);
    }
}
