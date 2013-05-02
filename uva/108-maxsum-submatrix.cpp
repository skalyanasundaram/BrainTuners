#include <iostream>

using namespace std;

int kadane(int* array, int size) {
    int max = array[0], max_ends_here = array[0];

    for(int i=1; i<size; i++) {
        max_ends_here += array[i];

        if(array[i] > max_ends_here)
            max_ends_here = array[i];

        if(max_ends_here > max)
            max = max_ends_here;
    }
    return max;
}

int main() {
    int matrix[100][100] = {0};
    int N = 0, max = 0;
    int temp[100] = {0};


    cin >> N;
    
    if(N < 1 || N > 100)
        return -1;

    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] > 127 || matrix[i][j] < -127)
                return -1;
        }

    for(int i=0; i < N; i++) {

        for(int j=0; j < N; j++)
            temp[j] = 0;

        for(int j=i; j < N; j++) {
            for(int k=0; k < N; k++)
                temp[k] += matrix[j][k];

            int submax = kadane(temp, N);
            if (submax > max)
                max = submax;
        }
    }

    cout << max << endl;
    return 0;
}
