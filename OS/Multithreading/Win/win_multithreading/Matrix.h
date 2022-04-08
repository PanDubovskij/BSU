//
// Created by Jan on 08.04.2022.
//

#ifndef WIN_MULTITHREADING_MATRIX_H
#define WIN_MULTITHREADING_MATRIX_H


#pragma once

#include <windows.h>
#include <ctime>
#include <vector>
#include <iostream>
//#include <mutex>

class Matrix {

public:

    Matrix(int m, int n);

    ~Matrix() { CloseHandle(lock_); }

    double &operator()(int i, int j);

    double operator()(int i, int j) const;

    int GetRows() const;

    int GetColumns() const;

    static Matrix Read(int n);

    static Matrix Multiply(const Matrix &matrix1, const Matrix &matrix2);

    Matrix MultiplyBlockMatrixes(const Matrix &matrix1, const Matrix &matrix2, int blocks_number);

    struct ThreadFunctionArgument {
        HANDLE HLock;
        Matrix &Result;
        const Matrix &Matrix1;
        const Matrix &Matrix2;
        int Row1;
        int Column1;
        int Row2;
        int Column2;
        int BlockSize;

        ThreadFunctionArgument(HANDLE lock, Matrix &result, const Matrix &matrix1, const Matrix &matrix2,
                               int row1, int column1, int row2, int column2, int block_size) :
                HLock(lock), Result(result), Matrix1(matrix1), Matrix2(matrix2), Row1(row1), Column1(column1),
                Row2(row2),
                Column2(column2), BlockSize(block_size) {}
    };

private:
    std::vector<std::vector<double>> values;

    static DWORD WINAPI MultiplyBlocks(LPVOID arg);

    HANDLE lock_ = CreateMutex(NULL, FALSE, NULL);

};

std::ostream &operator<<(std::ostream &out, const Matrix &matrix);


#endif //WIN_MULTITHREADING_MATRIX_H
