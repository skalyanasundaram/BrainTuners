#include <iostream>
#include <string.h>

using namespace std;

void SetCount(int row, int col, int crow, int ccol, int *matrix)
{
    if (crow >= 0 && crow < row && ccol >=0 && ccol < col)
    {
        if (matrix[crow * col + ccol] != '*')
        {
            matrix[crow * col + ccol]++;
        }
    }
}

void SetMatrix(int row, int col, int index, int *matrix)
{
    int crow = index / col;
    int ccol = index % col;
    
    SetCount(row, col, crow - 1, ccol-1, matrix);
    SetCount(row, col, crow - 1, ccol, matrix);
    SetCount(row, col, crow - 1, ccol+1, matrix);

    SetCount(row, col, crow, ccol-1, matrix);
    SetCount(row, col, crow, ccol+1, matrix);

    SetCount(row, col, crow + 1, ccol-1, matrix);
    SetCount(row, col, crow + 1, ccol, matrix);
    SetCount(row, col, crow + 1, ccol+1, matrix);
}

int main()
{
    int matrix[10000], row = 0, col = 0, index = 0, field = 1, tests = 0;
    char t;
    
    while (true)
    {
        cin >> row >> col;
        if (!row && !col)
        {
            break;
        }

        memset(matrix, 0, sizeof(matrix));

        for (index = 0; index < row * col; index++)
        {
            cin >> t;

            if (t == '*')
            {
                matrix[index] = t;
                SetMatrix(row, col, index, matrix);
            }
        }

        if (tests > 0)
        {
            cout << endl;
        }
        tests++;

        cout << "Field #" << field <<":" << endl;
        field++;

        for (index = 0; index < row * col; index++)
        {

            if ((char)matrix[index] == '*')
            {
                cout << (char) matrix[index];
            }
            else
            {
                cout << matrix[index];
            }

            if (!((index + 1) % col))
            {
                cout << endl;
            }
        }
    }
    return 0;
}
