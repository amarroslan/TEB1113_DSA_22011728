/*
ID: 22011728
Name: Muhammad Amar bin Roslan
Contact: 0195154165
Email: muhammad_22011728@utp.edu.my
LAb: 2
problem: https://geeksforgeeks.org/a-boolean-matrix-question/
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void updateMatrix(int matrix[][MAX_SIZE], int row, int column, bool rowMark[], bool columnMark[])
{
    cout << "Output:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (rowMark[i] || columnMark[j])
            {
                matrix[i][j] = 1;
            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int row, column;

    cout << "Input: ";
    cin >> row >> column;

    int matrix[MAX_SIZE][MAX_SIZE];
    bool rowMark[MAX_SIZE] = {false};
    bool columnMark[MAX_SIZE] = {false};

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
            {
                rowMark[i] = true;
                columnMark[j] = true;
            }
        }
    }

    updateMatrix(matrix, row, column, rowMark, columnMark);

    return 0;
}
