#include<iostream>
#include<math.h>
#include<stdlib.h>

#define phi ((1 + sqrt(5)) / 2) 

using namespace std;

int main(int argc, char ** argv) {
    int n = 0;

    if (argc < 2) {
        cerr << "invalid argument, enter number of digit required" << endl;
        return -1;
    }
    
    n = atoi (argv[1]);
    
    double nthnumber = ( (((n-1) * 2) + log10(5))  / (2 * log10(phi)));
    cout << floor (nthnumber + 0.5) << endl;

    return 0;
}

/*
 * binet's therom
 * golden ratio phi = 1+sqrt5  / 2
 * nth fib is phi^n / sqrt 5
 * if it has 1000 digit then phi^n/sqrt5 > 10^999
 *
 * taking log10 on both sides to solve exponentiation
 *
 * log10 [(phi^n/sqrt 5)] > log 10^999 //[] approximate
 * log10 phi^n - log sqrt 5 > log 10 ^ 999 //log nature log xy = log x + log y
 * n log phi - log sqrt 5 > 999 log 10 //log nature log x^y = y log x
 * n log phi - log 10 ^ (log 5/ 2) > 999 //sqrt x = 10 ^ (log x/2)
 * n log phi - log 5 / 2 log 10 > 999
 * n log phi - log 5 / 2 > 999
 * n log phi > 999 + log 5 / 2 
 * n log phi > (999 * 2 + log 5 )/2
 * n > (999 * 2 + log 5 )/ (2 * log phi)
 */
