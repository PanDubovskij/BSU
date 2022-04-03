package com.company;

public class SolveSystem {
    private static double determinant(Matrix matrix) throws MatrixException{
        if (matrix.getVerticalSize()!= matrix.getHorizontalSize())
            throw new MatrixException("invalid dimensions");
        if (matrix.getVerticalSize() == 2)
            return matrix.getElement(0,0) * matrix.getElement(1,1) -
                    matrix.getElement(0,1) * matrix.getElement(1,0);

        double det = 0;
        for (int i = 0; i < matrix.getHorizontalSize(); i++)
            det += Math.pow(-1, i) * matrix.getElement(0,i)
                    * determinant(minor(matrix, 0, i));
        if(det==0){
            throw new MatrixException("determinat = 0");
        } else {
        return det;
        }
    }
    private static Matrix inverse(Matrix matrix) throws MatrixException{
        if (matrix.getVerticalSize()!= matrix.getHorizontalSize())
            throw new MatrixException("invalid dimensions");
        Matrix inverse = new Matrix(matrix.getVerticalSize(), matrix.getHorizontalSize());

        for (int i = 0; i < matrix.getVerticalSize(); i++)
            for (int j = 0; j < matrix.getColumn(i).length; j++)
                inverse.setElement(i,j,Math.pow(-1, i + j)*determinant(minor(matrix, i, j)));

        double det = 1.0 / determinant(matrix);
        for (int i = 0; i < inverse.getVerticalSize(); i++) {
            for (int j = 0; j <= i; j++) {
                double temp = inverse.getElement(i,j);
                inverse.setElement(i,j,inverse.getElement(j,i) * det);
                inverse.setElement(j,i,temp*det);
            }
        }
        return inverse;
    }

    private static Matrix minor(Matrix matrix, int row, int column) throws MatrixException{
        Matrix minor = new Matrix(matrix.getVerticalSize() - 1, matrix.getHorizontalSize() - 1);
        for (int i = 0; i < matrix.getVerticalSize(); i++)
            for (int j = 0; i != row && j < matrix.getColumn(i).length; j++)
                if (j != column)
                    minor.setElement(i < row ? i : i - 1,j < column ? j : j - 1, matrix.getElement(i,j));
        return minor;
    }

    private static Matrix multiply(Matrix p, Matrix q) throws MatrixException {
        int v = p.getVerticalSize();
        int h = q.getHorizontalSize();
        int controlSize = p.getHorizontalSize();
        if (controlSize != q.getVerticalSize()) {
            throw new MatrixException("incompatible matrices");
        }
        Matrix result = new Matrix(v,h);
        try {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < h; j++) {
                    int value = 0;
                    for (int k = 0; k < controlSize; k++) {
                        value += p.getElement(i, k) * q.getElement(k, j);
                    }
                    result.setElement(i, j, value);
                }
            }
        } catch (MatrixException e) {
            // log: exception impossible
        }
        return result;
    }
    public Matrix solveSystem(Matrix a,Matrix b)  throws MatrixException{
        Matrix matrix = multiply(inverse(a), b);
        return matrix;
    }
}
