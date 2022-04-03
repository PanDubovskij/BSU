package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;

public class PaintingPanel extends JPanel implements MouseMotionListener, MouseListener
{
    private BufferedImage bufimage;
    private Point first;
    private Point second;
    private Color c=new Color(0,0,0);
    public PaintingPanel() {
        first=new Point();
        second=new Point();
        bufimage=new BufferedImage(4000,4000,BufferedImage.TYPE_INT_ARGB);
        addMouseMotionListener(this);
        addMouseListener(this);
    }
    public void setColor(Color c_){
        c=c_;
    }
    public void setBufimage(BufferedImage bufimage_){
        bufimage=bufimage_;
        setPreferredSize(new Dimension(bufimage_.getWidth(),bufimage_.getHeight()));
        scrollRectToVisible(new Rectangle(0,0,bufimage_.getWidth(),bufimage_.getHeight()));
        revalidate();
    }

    @Override
    public void mousePressed(MouseEvent e) {
        first=e.getPoint();
    }
    @Override
    public void mouseDragged(MouseEvent e) {
        second = e.getPoint();
        Graphics2D g = (Graphics2D) bufimage.getGraphics();
        g.setStroke(new BasicStroke(5));
        g.setColor(c);
        g.drawLine(first.x, first.y, second.x, second.y);
        //setPreferredSize(new Dimension(bufimage.getWidth(),bufimage.getHeight()));
        //scrollRectToVisible(new Rectangle(0,0,bufimage.getWidth(),bufimage.getHeight()));
        //revalidate();
        repaint();
        first = second;
    }

    public BufferedImage getBufimage() {
        return bufimage;
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawImage(bufimage,0,0,null);
        //repaint();
    }

    @Override
    public void mouseReleased(MouseEvent e) {
    }
    @Override
    public void mouseEntered(MouseEvent e) {

    }
    @Override
    public void mouseClicked(MouseEvent e) {

    }
    @Override
    public void mouseExited(MouseEvent e) {
    }
    @Override
    public void mouseMoved(MouseEvent e) {

    }
}
