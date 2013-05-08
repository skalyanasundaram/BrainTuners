#include <stdio.h>

long d(int n) {
    long i = 1, sum = 0;
    
    for (i=1; i<=n/2; i++)
        if (n % i == 0)
            sum += i;

    return sum;
}
int main(int argc, char **argv) {
    
    int i = 0;
    long sum = 0, a = 0, b = 0;

    for (i=1; i<10000; i++) {
        a = d(i);
        b = d(a);
        if (a != b && i == b) {
            printf("amicable pair is (%ld, %ld)\n", i, a);
            sum += i;
        }
    }

    printf("sum %ld\n", sum);
    return 0;
}
