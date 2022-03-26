#include "Matrix.h"

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    Matrix matrix1 = Matrix::Read(n);
    Matrix matrix2 = Matrix::Read(n);

    int start1 = clock();
    Matrix matrix3 = Matrix::Multiply(matrix1, matrix2);
    int end1 = clock();
    std::cout << "Common multiplication: " << end1 - start1 << std::endl;

    if (n % k == 0) {
        int start2 = clock();
        Matrix matrix4(n,n);
        matrix4.MultiplyBlockMatrixes(matrix1, matrix2, k);
        int end2 = clock();
        std::cout << k * k << " blocks, time: " << end2 - start2 << std::endl;
    } else { std::cout << "incompatible n and k"; }
    return 0;
}
