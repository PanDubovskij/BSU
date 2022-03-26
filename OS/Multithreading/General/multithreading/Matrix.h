#ifndef MULTITHREADING_MATRIX_H
#define MULTITHREADING_MATRIX_H

#pragma once

#include <ctime>
#include <vector>
#include <iostream>
#include <mutex>

class Matrix {

public:

    Matrix(int m, int n);
    double &operator()(int i, int j);
    double operator()(int i, int j) const;
    int GetRows() const;
    int GetColumns() const;

    static Matrix Read(int n);

    static Matrix Multiply(const Matrix &matrix1, const Matrix &matrix2);

    Matrix MultiplyBlockMatrixes(const Matrix &matrix1, const Matrix &matrix2, int blocks_number);

private:
    std::vector<std::vector<double>> values;

    void MultiplyBlocks(Matrix &result, const Matrix &matrix1, const Matrix &matrix2,
                        int row1, int column1, int row2, int column2, int block_size);

};

std::ostream &operator<<(std::ostream &out, const Matrix &matrix);


#endif //MULTITHREADING_MATRIX_H
