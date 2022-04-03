package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        double x=0.;
        double eps=0.1;
        if(args.length!=2){
            throw new ArrayIndexOutOfBoundsException("args.length!=2");
        }
        try {
            x = Double.parseDouble(args[0]);
            eps = Double.parseDouble(args[1]);
        } catch (NumberFormatException exc){
            System.err.println(exc.toString());
        }
        System.out.println("x=" + x +" eps=" + eps );
        System.out.println("sum=" + sum(x,eps));
    }
    public static double sum(double x, double eps){
        double sum=0;
        double elem=0;
        elem=(-2*x)/3;
        sum+=elem;
        for(int k=2;Math.abs(elem)>=eps;k++){
            elem*=((-x)*(k+1)/(3*k));
            sum+=elem;
        }
        return sum;
    }
}
