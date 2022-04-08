//#include <thread>
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
    std::vector<HANDLE> threads;
    std::vector<ThreadFunctionArgument *> args;
    for (int i = 0; i < product.GetRows(); i += block_size) {
        for (int j = 0; j < product.GetColumns(); j += block_size) {
            for (int k = 0; k < product.GetColumns(); k += block_size) {
                ThreadFunctionArgument *arg = new ThreadFunctionArgument(lock_, product, matrix1, matrix2, i, k, k, j,
                                                                         block_size);
                HANDLE thread = CreateThread(NULL, 0, MultiplyBlocks, arg, 0, NULL);
                threads.push_back(thread);
                args.push_back(arg);
            }
        }
    }
    WaitForMultipleObjects(threads.size(), &threads[0], TRUE, INFINITE);
    for (int i = 0; i < threads.size(); ++i) {
        CloseHandle(threads[i]);
        delete args[i];
    }
    return product;
}

DWORD WINAPI Matrix::MultiplyBlocks(LPVOID arg) {
    auto *arg_ = (ThreadFunctionArgument *) arg;
    for (int i = arg_->Row1; i < arg_->Row1 + arg_->BlockSize; ++i) {
        for (int j = arg_->Column2; j < arg_->Column2 + arg_->BlockSize; ++j) {
            double temp = 0;
            for (int k = 0; k < arg_->BlockSize; ++k) {
                temp += arg_->Matrix1(i, arg_->Column1 + k) * arg_->Matrix2(arg_->Row2 + k, j);
            }
            WaitForSingleObject(arg_->HLock, INFINITE);
            arg_->Result(i, j) += temp;
            ReleaseMutex(arg_->HLock);
        }
    }
    ExitThread(0);
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
