/*matrix multiplication using constructor to initialize
create a class and use pointer to access its member
implement different type of constructor for creating object also create const member function and object and try to access it*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int matrix_1[3][3], matrix_2[3][3], matrix_3[3][3];
    cout << "Enter elements for first 3x3 matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix_1[i][j];
        }
    }
    cout << "Enter elements for second 3x3 matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix_2[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            int sum=0;
            for (int k = 0; k < 3; k++)
            {
                sum += matrix_1[i][k] * matrix_2[k][j];
            }
            matrix_3[i][j] = sum;
        }
        
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix_3[i][j];
        }
    }
    return 0;
}