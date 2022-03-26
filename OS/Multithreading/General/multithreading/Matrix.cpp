#include <thread>
#include <exception>
#include "Matrix.h"

std::mutex lock_;

Matrix::Matrix(int m, int n) : values(m, std::vector<double>(n)) {}

double Matrix::operator()(int i, int j) const {
    if (i < 0 || i >= GetRows() || j < 0 || j >= GetColumns()) {
        std::cout<<"Error: index out of range";
    }
    return values[i][j];
}
double &Matrix::operator()(int i, int j) {
    if (i < 0 || i >= GetRows() || j < 0 || j >= GetColumns()) {
        std::cout<<"Error: index out of range";
    }
    return values[i][j];
}

int Matrix::GetRows() const { return values.size(); }
int Matrix::GetColumns() const { return values[0].size(); }

Matrix Matrix::Read(int n) {
    Matrix result_matrix(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> result_matrix(i, j);
        }
    }
    return result_matrix;
}


Matrix Matrix::Multiply(const Matrix &matrix1, const Matrix &matrix2) {
    Matrix product = Matrix(matrix1.GetRows(), matrix2.GetColumns());
    for (int i = 0; i < product.GetRows(); ++i) {
        for (int j = 0; j < product.GetColumns(); ++j) {
            for (int k = 0; k < product.GetColumns(); ++k) {
                product(i, j) += matrix1(i, k) * matrix2(k, j);
            }
        }
    }
    return product;
}

Matrix Matrix::MultiplyBlockMatrixes(const Matrix &matrix1, const Matrix &matrix2, int blocks_number) {

    int block_size = matrix1.GetRows() / blocks_number;
    Matrix product = Matrix(matrix1.GetRows(), matrix2.GetColumns());
    std::vector<std::thread> threads;
    for (int i = 0; i < product.GetRows(); i += block_size) {
        for (int j = 0; j < product.GetColumns(); j += block_size) {
            for (int k = 0; k < product.GetColumns(); k += block_size) {
                std::thread thread(&Matrix::MultiplyBlocks, this, std::ref(product),
                                   std::ref(matrix1), std::ref(matrix2), i, k, k, j, block_size);
                threads.push_back(std::move(thread));
            }
        }
    }
    for (auto &thread: threads) {
        thread.join();
    }
    return product;
}

void Matrix::MultiplyBlocks(Matrix &result, const Matrix &matrix1, const Matrix &matrix2,
                            int row1, int column1, int row2, int column2, int block_size) {
    for (int i = row1; i < row1 + block_size; ++i) {
        for (int j = column2; j < column2 + block_size; ++j) {
            double temp = 0;
            for (int k = 0; k < block_size; ++k) {
                temp += matrix1(i, column1 + k) * matrix2(row2 + k, j);
            }
            std::lock_guard<std::mutex> locker(lock_);
            result(i, j) += temp;
        }
    }
}


std::ostream &operator<<(std::ostream &out, const Matrix &matrix) {
    for (int i = 0; i < matrix.GetRows(); i++) {
        for (int j = 0; j < matrix.GetColumns(); j++) {
            out << matrix(i, j) << " ";
        }
        out << std::endl;
    }
    return out;
}
