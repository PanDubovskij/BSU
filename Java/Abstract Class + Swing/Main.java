package com.company;

import javax.swing.*;
import java.io.IOException;

public class Main {

    public static void main(String[] args) {
	// write your code here
        /*Series liner=new Liner(1,1);
        liner.setN(5);
        System.out.println(liner.toString());
        System.out.println("sum="+liner.getSum());
        try{
            liner.save("out.txt");
        }catch(IOException ex){
            System.err.println(ex.getMessage());
        }
        Series exp=new Exponential(1,2);

        exp.setN(5);
        System.out.println(exp.toString());
        System.out.println("sum="+exp.getSum());
        try{
            exp.save("out1.txt");
        }catch(IOException ex){
            System.err.println(ex.getMessage());
        }*/
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                WindowApp app = new WindowApp();
                app.setVisible(true);
            }
        });

    }
}
