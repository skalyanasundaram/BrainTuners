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
    int prev=0, div=1000;
    strcpy(str, "");
    
    while(div) {
        
        if ((num / div) % 10 > 0 || (div == 10 && (num%100) > 0)) { 

            if (prev) {
                strcat(str, "and");
                prev = 0;
            }
        
            switch(div) {
            case 1000:
                strcat(str, digit[(num / div) % 10]);     
                strcat(str, "thousand");
                prev = 1;
                break;
            case 100:
                strcat(str, digit[(num / div) % 10]);     
                strcat(str, "hundred");
                prev = 1;
                break;
            case 10:
                if ( (num%100) >= 10 && (num%100) <= 19)
                    strcat(str, digit[num%100]);
                else {
                    strcat(str, tens[(num%100)/10]);
                    strcat(str, digit[num%10]);
                }
                break;
            }
        }

        div /= 10;
    }
    printf("%d %s\n", num, str);
    return  strlen(str);
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
