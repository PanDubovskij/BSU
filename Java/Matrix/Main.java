package com.company;

import java.io.File;

public class Main {
    public static void main(String[] args) {
        try {
            MatrixCreator creator = new MatrixCreator();
            Matrix p = new Matrix(3,3);
            File f = new File("C:\\фпми учеба\\лабы\\прога 3 сем\\Lab3\\src\\com\\company\\Matrix.txt");
            creator.createFromFile(p,f);
            System.out.println("Matrix first is: " + p);
            Matrix q = new Matrix(3,1);
            File f1=new File("C:\\фпми учеба\\лабы\\прога 3 сем\\Lab3\\src\\com\\company\\MatrixB.txt");
            creator.createFromFile(q, f1);
            System.out.println("Matrix second is: " + q);
            SolveSystem solver = new SolveSystem();
            Matrix result = solver.solveSystem(p, q);
            System.out.println("Matrix x is " + result);
        } catch (MatrixException e) {
            System.err.println("Error of creating matrix " + e);
        }
    }
}
