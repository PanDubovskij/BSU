package com.company;

public class Matrix {
    private double[][] a;
    public Matrix(double[][] a) {
        this.a = a;
    }
    public Matrix(int n,int m) throws MatrixException {
        if (n < 1 || m < 1) {// check input
            throw new MatrixException();
        }
        a = new double[n][m];
    }
    public int getVerticalSize() {
        return a.length;
    }
    public int getHorizontalSize() {
        return a[0].length;
    }
    public double getElement(int i, int j) throws MatrixException {
        if (checkRange(i, j)) { // check i & j
            return a[i][j];
        } else {
            throw new MatrixException();
        }
    }
    public double[] getColumn(int i)  {
        return a[i];
    }
    public void setElement(int i, int j, double value) throws MatrixException {
        if (checkRange(i, j)) {
            a[i][j] = value;
        } else {
            throw new MatrixException();
        }
    }
    @Override
    public String toString() {
        final String BLANK = " ";
        StringBuilder s = new StringBuilder("\nMatrix : " + a.length + "x"
                + a[0].length + "\n");
        for (double [ ] row : a) {
            for (double value : row) {
                s.append(value).append(BLANK);
            }
            s.append("\n");
        }
        return s.toString();
    }
    private boolean checkRange(int i, int j) {// check matrix range
        return (i >= 0 && i < a.length && j >= 0 && j < a[0].length);
    }
}
