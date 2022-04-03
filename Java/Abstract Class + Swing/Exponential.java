package com.company;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Exponential extends Series{
    private double b0=0;
    private double q=0;

    public Exponential(double b0_,double q_){
        this.b0=b0_;
        this.q=q_;
    }

    @Override
    public double getElem(int j) {
        double bj=b0*Math.pow(q,j-1);
        return bj;
    }
}
