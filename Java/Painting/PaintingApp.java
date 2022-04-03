package com.company;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class PaintingApp extends JFrame {
    private JFrame frame;
    private JMenuBar menuBar;
    private JMenuItem colorChooser;
    private JMenuItem save;
    private JMenuItem open;
    private JMenu menu;
    private PaintingPanel paintPanel;
    private JScrollPane scroller;
    private Color c;
    public PaintingApp(){
//        paintPanel = new PaintingPanel();
//        scroller=new JScrollPane(paintPanel,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
//        scroller.setPreferredSize(new Dimension(1000,1000));
//        c = new Color(0, 0, 0);
        createFrame();
//        save();
//        open();
//        chooseColor();

    }
    private void save(){
        save.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                final JFileChooser fc = new JFileChooser();
                FileNameExtensionFilter filter = new FileNameExtensionFilter(
                        "Image file", "png", "jpg", "jpeg");
                fc.setFileFilter(filter);
                int returnVal = fc.showOpenDialog(save);
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    try {
                        ImageIO.write(paintPanel.getBufimage(), "png", file);
                    } catch (IOException ex) {
                        JOptionPane.showMessageDialog(null,ex.getMessage(),"ERROR",JOptionPane.ERROR_MESSAGE);
                    }
                }
            }
        });
    }
    private void open(){
        open.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                final JFileChooser fc = new JFileChooser();
                FileNameExtensionFilter filter = new FileNameExtensionFilter(
                        "Image file", "png", "jpg", "jpeg");
                fc.setFileFilter(filter);
                int returnVal = fc.showOpenDialog(open);
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fc.getSelectedFile();
                    try {
                        BufferedImage buf = ImageIO.read(file);
                        paintPanel.setBufimage(buf);
                    } catch (IOException ex) {
                        JOptionPane.showMessageDialog(null,ex.getMessage(),"ERROR",JOptionPane.ERROR_MESSAGE);
                    }
                }
            }
        });
    }
    private void createMenu(){
        menuBar = new JMenuBar();
        menu=new JMenu("Menu");
        menuBar.add(menu);
        colorChooser=new JMenuItem("Choose color");
        menu.add(colorChooser);
        menu.addSeparator();
        open=new JMenuItem("Open");
        save=new JMenuItem("Save");
        menu.add(open);
        menu.add(save);
        frame.add(menuBar);
        frame.setJMenuBar(menuBar);
    }
    private void createFrame(){
        frame = new JFrame("Painting App");
       // createMenu();
        //frame.add(scroller);
        setLayout(new GridLayout(2,1));
        add(new PaintingPanel());
        add(new PaintingPanel());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setSize(600,700);
        frame.setVisible(true);
    }
    private void chooseColor(){
        colorChooser.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                c = JColorChooser.showDialog(null, "Choose a Color", c);
                paintPanel.setColor(c);
            }

        });
    }

}
