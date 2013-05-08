#include <stdio.h>
#include <string.h>

int getcountofwords(int num) {
    char digit [21][10] = { "", "one", "two", "three", "four", "five", "six", "seven",
                            "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
                            "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                            "nineteen"};
    char tens [11][10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", 
                           "seventy", "eighty", "ninety"};
    char str[1000] = {0};
    int n = num, rest = 0;
    
    strcat(str, "");
    while (n > 0) {
        if (n == 1000)
            return strlen("onethousand");
    
        else if (n >= 100) {
            rest = n % 100;
            strcat(str, digit[(n/100)]);
            strcat(str, "hundrand");
            if (rest > 0)
                strcat(str, "and");
            n = rest;
        }

        else if (n >= 20) {
            rest = n % 10;
            strcat(str, tens[(n/10)]);
            n = rest;
        }
        
        else if (n > 0) {
            strcat(str, digit[n]);
            n = 0;
        }
    }
    return strlen(str);
}

int main(int argc, char **argv) {
    
    long sum = 0;
    int count = 0;

    for (count = 1; count <= 1000; count++) {
        sum += getcountofwords(count);
    }

    printf("final count %d\n", sum);
    
    return 0;
}
