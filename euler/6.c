#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    
    unsigned long long sumofsqaure = 0;
    unsigned long squareofsum = 0;
    int i = 0;

    for (i=1; i<=100; i++) {
        sumofsqaure += pow(i,2);
        squareofsum += i;
    }
    squareofsum = pow(squareofsum,2);

    printf("Difference of +of^ and ^of+ is %ld\n", abs(sumofsqaure - squareofsum));

    return 0;
}
