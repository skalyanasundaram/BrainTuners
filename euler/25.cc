#include<iostream>
#include<iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;
class Number {
    
private:
    //5 digits in each
    unsigned long long num[1000];

public:
    Number ():num({0}) {}
    Number(int n):num({0})  { num[0] = n; }
    
    void operator=(int n) {
        num[0] = n;
    }

    void operator=(Number n) {
        for (int i=0; i<1000; i++)
            num[i] = n.num[i];
    }

    Number operator+(Number n) {
        unsigned long long carry = 0;
        int i = 0;
        Number tmp;

        for (i=0; i<900; i++) {
             carry += n.num[i] + num[i];
             
             tmp.num[i] = carry % 100000;
             carry /= 100000;
        }
        while(carry > 100000) {
            tmp.num[i++] = carry  % 100000;
            carry /= 100000;
        }
        return tmp;

    }

    int numofdigit() {
        int numofdigit = 0;
        unsigned long long tmpnum = 0;
        bool start = false;

        for (int i=1000-1; i>=0; i--) {
            if (start == true)
                numofdigit += 5;
            if (start == false && num[i] > 0) {
                start = true;
                for (tmpnum = num[i]; tmpnum > 0; tmpnum /=10)
                    numofdigit ++;
            }
        }
        return numofdigit;
    }

    void print() {
        bool start = false;
        for (int i=1000-1; i>=0; i--) {
            if (start == true)
                cout << setw(5) << setfill('0') << num[i];
            if (start == false && num[i] > 0) {
                start = true;
                cout << num[i];
            }

        }
    }
};


int main(int argc, char **argv) {
    Number a, b, c = 0;
    int max = 0;
    unsigned long seq = 0;

    if (argc < 2) {
        cerr << "enter number of digit required" << endl;
        return -1;
    }

    max = atoi(argv[1]);
    a = 1;
    b = 1;
    seq = 2;
    
    clock_t start, end;
    start = clock();

    while(c.numofdigit() < max) {
        /*        cout << a.numofdigit() << ":";
        a.print ();
        cout << "  +  " ;
        cout << b.numofdigit() << ":";
        b.print();
        cout << "  =  ";
        */
        c = a+b;

        seq ++;
        a = b;
        b = c;

        //cout << b.numofdigit() << ":";
        //b.print();
        //cout << endl;
    }

    end = clock();
    b.print();
    cout << "seq =" << seq << " numofdigit = " << b.numofdigit() << endl;
    cout << "difference:" << ((double) (end - start)) / CLOCKS_PER_SEC<< endl;

    return 0;
}
