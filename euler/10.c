#include <stdio.h>
#include <stdlib.h>

int apowerbmodc(long long a,long long b,long long c) {
    
    unsigned long long x = 1, y = a;

    while (b > 0) {
        if (b%2 == 1)
            x = (x*y) % c;

        y = (y*y) % c;

        b /= 2;
    }

    return x%c;
}

int isprime(unsigned long long prime) {
    
    unsigned long long a = 0;
    int i =0;

    //to avoid fermat liars
    for (i=0; i<100; i++) {
        a = rand() % (prime-1) + 1;

        if (apowerbmodc(a, prime-1, prime) != 1) 
            return 0;
    }

    return 1;
}

int main(int argc, char **argv) {
    unsigned long prime = 2;
    unsigned long long sum = 0;

    for (prime = 2; prime < 2000000; prime++)
        if (isprime(prime) == 1) {
            sum += prime;
            //printf("prime %ld %llu\n", prime, sum);
        }
    printf("sum %llu\n", sum);
    return 0;
}
//142916147964 -20 iteration
//142917763916 -30
//142920868437 -60

