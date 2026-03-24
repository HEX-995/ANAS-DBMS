// WAP to compute matrix multiplication using constructor to initialize
// WAP by creating a class and use pointer to access class member 
// implement the different type constructor for creating object. also create const member function and try to access it

#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int mat[10][10]; 

public:
   
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        cout << "Enter elements of " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    Matrix multiply(Matrix &m2) {
        if (cols != m2.rows) {
            cout << "Matrix multiplication not possible!\n";
            exit(0);
        }
        Matrix result(rows, m2.cols, false); 
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m2.mat[k][j];
                }
            }
        }
        return result;
    }

    Matrix(int r, int c, bool inputFlag) {
        rows = r;
        cols = c;
        if (inputFlag) { 
            cout << "Enter elements of " << rows << "x" << cols << " matrix:\n";
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cin >> mat[i][j];
                }
            }
        }
    }

    
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and cols for first matrix: ";
    cin >> r1 >> c1;
    Matrix m1(r1, c1);

    cout << "Enter rows and cols for second matrix: ";
    cin >> r2 >> c2;
    Matrix m2(r2, c2);

    Matrix result = m1.multiply(m2);

    cout << "Result of multiplication:\n";
    result.display();

    return 0;
}
