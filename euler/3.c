#include <stdio.h>

int main(int argc, char **argv) {
    
    unsigned long long num = 600851475143, half = 600851475143 / 2;

    long maxprime = 1, div = 0;

    while(1) {
        
        for (div = 2; div < half; div++)
            if (num % div == 0)
                break;

        if (div > maxprime)
            maxprime = div;

        if (div == num)
            break;
        else 
            num = num /div;
        
    }

    printf("BIG PRIME FACTOR of 600851475143 is %ld\n", maxprime);
    return 0;
}
