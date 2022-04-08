#include <pthread.h>
#include <exception>
#include "Matrix.h"


Matrix::Matrix(int m, int n) : values(m, std::vector<double>(n)) {}

double Matrix::operator()(int i, int j) const {
    if (i < 0 || i >= GetRows() || j < 0 || j >= GetColumns()) {
        std::cout << "Error: index out of range";
    }
    return values[i][j];
}

double &Matrix::operator()(int i, int j) {
    if (i < 0 || i >= GetRows() || j < 0 || j >= GetColumns()) {
        std::cout << "Error: index out of range";
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
    std::vector<pthread_t> threads;
    std::vector<ThreadFunctionArgument *> args;
    for (int i = 0; i < product.GetRows(); i += block_size) {
        for (int j = 0; j < product.GetColumns(); j += block_size) {
            for (int k = 0; k < product.GetColumns(); k += block_size) {
                auto *arg = new ThreadFunctionArgument(lock_, product, matrix1, matrix2, i, k, k, j, block_size);
                pthread_t thread;
                pthread_create(&thread, nullptr, &MultiplyBlocks, arg);
                threads.push_back(thread);
                args.push_back(arg);
            }
        }
    }
    for (auto &thread: threads) {
        pthread_join(thread, nullptr);
    }
    for (auto &arg: args) {
        delete arg;
    }
    return product;
}

void* Matrix::MultiplyBlocks(void* arg) {
    auto* arg_ = (ThreadFunctionArgument*)arg;
    for (int i = arg_->Row1; i < arg_->Row1 + arg_->BlockSize; ++i)
    {
        for (int j = arg_->Column2; j < arg_->Column2 + arg_->BlockSize; ++j)
        {
            double temp = 0;
            for (int k = 0; k < arg_->BlockSize; ++k)
            {
                temp += arg_->Matrix1(i, arg_->Column1 + k) * arg_->Matrix2(arg_->Row2 + k, j);
            }
            pthread_mutex_lock(&arg_->Lock);
            arg_->Result(i, j) += temp;
            pthread_mutex_unlock(&arg_->Lock);
        }
    }
    pthread_exit(nullptr);
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
