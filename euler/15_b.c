#include <stdio.h>

int main(char argc, char **argv) {
    
    unsigned long long arr[21][21];
    int i, j;

    for (i=0; i<21; i++) {
        arr[0][i] = 1;
        arr[i][0] = 1;
    }
    
    for (i=1; i<21; i++) 
        for (j=1; j<21; j++)
            arr[i][j] = arr[i][j-1] + arr[i-1][j];

    printf("sum %llu\n", arr[20][20]);
            
    
}
