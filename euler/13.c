#include <stdio.h>
//id:13
int main(int argc, char **argv) {
    unsigned int start = 0, end = 0, carry = 0;
    int i = 0, j = 0;
    int num[1000];
    char digit[100][50], a;
    FILE *fp;

    if (argc != 2)
        return -1;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
        return -1;

    for (i=0; i<100; i++) {
        for (j=0; j<50; j++)
            fscanf(fp, "%c", &digit[i][j]);
        fscanf(fp, "%c", &a);
    }

    carry = 0;
    for (i=0; i<50; i++) {
        for(j=0;j<100;j++) {
            carry = (digit[j][49-i] - 48) + carry;
        }
        
        printf("%d\t", carry);
        num[end++] = carry % 10;
        carry /= 10;
    }
    if (carry != 0)
        num[end] = carry;

    printf("\n");
    for (i=0; i<=end; i++)
        printf("%d", num[end-i]);

    printf("\n");
    return 0;
}
