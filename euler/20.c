#include <stdio.h>

int main(int argc, char **argv) {
    
    unsigned int digit[10000], start=0, end = 0, carry = 0, i = 0, j = 0, sum = 0;

    digit[0]=1;
    for(i=2; i<=100; i++) {
        carry = 0;
        for(j=start; j<=end; j++) {
            carry = digit[j] * i + carry;
            digit[j] = carry % 100;
            carry /= 100;
        }
        if (carry != 0)
            digit[++end] = carry;

    }
    for (i=start; i<=end; i++)
        sum += (digit[i] %10) + ((digit[i]/10) %10) + ((digit[i]/100) %10);
 
    printf ("SUm: %d\n", sum);
            return 0;
}
