#include <stdio.h>
#include <math.h>
long long F(int a, int b, int c, long long n) {
    if (n > b) return n-c;
    else return F(a,b,c,a + F(a,b,c, a + F(a,b,c, a + F(a,b,c, a + n))));
}

long long S(int a,int b,int c) {
    int n=0;
    long long sum;

    for(; n<=b; n++) {
        printf ("%ld\t", n);
        sum += F(a, b, c, n);
    }

    printf("\n%ld\n", sum);
}

int main(int argc, char **argv) {
    long long b = pow(7,21);
    printf("%ld \n",  F(50, 2000, 40, 2000));
    S(pow(21,7), b, pow(12,7));
}
