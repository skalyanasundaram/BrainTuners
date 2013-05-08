#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int rowcount = 1, i = 0, j = 0, rows=0;
    long **tree = NULL;
    FILE *fp = NULL;
    
    if (argc != 2) {
        printf("Not enough arguments\n");
        return -1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
        return -1;

    while(EOF != (fscanf(fp, "%*[^\n]"), fscanf(fp, "%*c")))
        rows++;
    fseek(fp, 0, SEEK_SET);

    tree = malloc(rows * sizeof (long *));

    for (i=0; i < rows; i++) {
        tree[i] = malloc((i+1) * sizeof (long));
        for (j=0; j< i+1; j++) {
            fscanf (fp, "%d ", &tree[i][j]);
        }
        fscanf(fp, "\n");
    }
    
    for (i=rows-2; i >= 0 ; i--) //row
        for (j=0; j<=i; j++)  //col
            tree[i][j] += ((tree[i+1][j] > tree[i+1][j+1])? tree[i+1][j] : tree[i+1][j+1]);

    printf("%ld\n",tree[0][0]);

    return 0;
}
