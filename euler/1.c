#include <stdio.h>

int main() {
    int i = 0;
    long tot=0;

    for(; i<1000; i++) {
        if (i%3 == 0 || i%5 == 0)
            tot += i;
    }

    printf("Sum of natural numbers <1000 which are %% of 3 || 5 is %ld\n", tot);

    return 0;
}
