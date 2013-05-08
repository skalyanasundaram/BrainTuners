#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

enum NumberType { NONE, DIFICIENT, PERFECT, ABUNDANT};
#define ABUNDANT_MAX_LIMIT 28123

class Number {
private:
    /* by default assigned to 0, NONE */
    NumberType list[ABUNDANT_MAX_LIMIT];

    unsigned long sumofdiv(unsigned int num) {

        //better version using number theory
        //http://mathschallenge.net/library/number/sum_of_divisors
        unsigned long sum = 1;
        
        for (unsigned int i = 2; i*i <= num; i++) {
            int pa = 1;
            
            //sumof(p^a) = ((p^a+1) - 1) / (p - 1)
            for(; num % i == 0; num /= i, pa *= i);
            pa = ((pa * i) - 1) / (i - 1);
            
            sum *= (pa?pa:1);
        }

        if (num > 1)
            sum *= (((num * num) - 1) / (num -1));

        return sum;
    }
    
    unsigned long sumofdivisor(unsigned int num) {
        unsigned long sum = 0;
        
        for (unsigned int div = 1; div <= num/2; div ++)
            if (num % div == 0) { sum +=div; }
        
        return sum;
    }

    void fillNumberList() {

        for (unsigned int i=1; i <= ABUNDANT_MAX_LIMIT; i++) {

            //property of abundant number, saves 3 micro second
            if (!(i % 2 == 0 || i % 3 == 0))
                continue;

            if (list[i] == NONE) {
                unsigned long sum = sumofdiv(i);
                if (sum > i*2)
                    list[i] = ABUNDANT; //my version
            }
        }
    }

public:
    Number() {

        fillNumberList();
    }

    bool isSumofTwoAbundant(unsigned int num) {

        /* caller should be careful */
        if (num > ABUNDANT_MAX_LIMIT)
            return false;

        for(unsigned int i = 1; i+i <= num; i++) {
            if (list[i] == ABUNDANT && list[num - i] == ABUNDANT ) {
                //                cout << num << "=" << i << "," << num-i << "(" << sumofdivisor(i) << "," << sumofdivisor(num-i) << ")" << endl;
                return true;
            }
        }
        //        cout << num << endl;
        return false;
    }


};


int main(int argc, char **argv) {

    unsigned long long sum = 0;
    clock_t start, end;
    start = clock();

    Number Numbers;

    for (unsigned int i = 1; i <= ABUNDANT_MAX_LIMIT; i++)
        if (Numbers.isSumofTwoAbundant(i) == false)
            sum += i;

    end = clock();
    cout << "sum:" <<sum << endl;

    cout << "difference:" << ((double) (end - start)) / CLOCKS_PER_SEC<< endl;


    return 0;
}
