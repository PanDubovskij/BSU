package com.company;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Liner extends Series{
    private double a0=0;
    private double d=0;

    public Liner(double a0_, double d_){
        this.a0=a0_;
        this.d=d_;
    }

    @Override
    public double getElem(int j) {
        if(j==0){
            return a0;
        }else{
        double aj=a0+d*(j-1);
        return aj;
        }
    }
}
