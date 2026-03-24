#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int **data;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }

        cout << "Enter elements of " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> data[i][j];
            }
        }
    }

    Matrix multiply(Matrix &other)
    {
        if (cols != other.rows)
        {
            cout << "Matrix multiplication not possible!\n";
            exit(0);
        }

        Matrix result(rows, other.cols, false);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix(int r, int c, bool input)
    {
        rows = r;
        cols = c;
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }
        if (input)
        {
            cout << "Enter elements of " << rows << "x" << cols << " matrix:\n";
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cin >> data[i][j];
                }
            }
        }
    }

    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main()
{
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;

    Matrix m1(r1, c1);

    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    Matrix m2(r2, c2);

    Matrix result = m1.multiply(m2);

    cout << "Resultant Matrix:\n";
    result.display();

    return 0;
}
