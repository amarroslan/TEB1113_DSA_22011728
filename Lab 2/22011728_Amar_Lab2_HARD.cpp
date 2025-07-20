/*
id: 22011705
name: amir
group: g1
lab: L2 (Hard) - A Boolean Matrix Question
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