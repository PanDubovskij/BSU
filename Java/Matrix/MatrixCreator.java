package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class MatrixCreator {
    public void fillRandomized(Matrix matrix, double minValue, double maxValue) {
        int v = matrix.getVerticalSize();
        int h = matrix.getHorizontalSize();
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < h; j++) {
                try {
                    double value = (double) ((Math.random() * (maxValue - minValue)) + minValue);
                    matrix.setElement(i, j, value);
                } catch (MatrixException e) {
                    // log: exception impossible
                }
            }
        }
    }
    public void createFromFile(Matrix matrix, File f) throws MatrixException {
        try {
            Scanner scanner = new Scanner(f);
            int v = matrix.getVerticalSize();
            int h = matrix.getHorizontalSize();
            for(int i = 0; i < v; i++) {
                for(int j = 0; j < h; j++) {
                    try {
                        matrix.setElement(i, j, scanner.nextDouble());
                    }  catch(NoSuchElementException e){
                        throw new MatrixException("not correct data"+" i="+i+" j="+j);
                    }
                }
            }
        } catch(FileNotFoundException ex){
            System.err.println("File not found");
        }
    }
}
