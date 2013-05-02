//http://cr.yp.to/arith.html
//http://cr.yp.to/lineartime/powers2-20050509.pdf
//http://cr.yp.to/papers/powers.pdf
//http://math.stackexchange.com/questions/65137/question-about-the-cat-in-the-hat-problem

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

unsigned long long primecache[100000] = {2,0};
unsigned int prime_count = 1, prime_index = 0;

int powerOf2 (double h)
{
    int p = 0;
    while ( true )
 {
        int res = (1 << p) ;
        if ( res > h )
            return p - 1;
        p++;
    }
}

inline unsigned long long apowerbmodc(unsigned long long a, unsigned long long b, unsigned long long c) {
    unsigned long long x = 1, y = a;

    while(b > 0) {
        
        if(b % 2 != 0) 
            x = (x*y) % c;

        y = (y*y) % c;
        b >>= 1;
    }
    return x % c;
}

inline bool is_prime(unsigned long long n) {
    
    //fermets little theorm

    for (int i = 0; i < 10; i++) {
        //to avoid fermet liars we test 10 iterations

        unsigned long long p = (rand() % (n-1)) + 1;
        if (apowerbmodc(p, n-1, n) != 1)
            return false;
    }
    
    return true;
}

unsigned long long get_next_prime() {
    if (prime_index < prime_count)
        return primecache[prime_index++];
    else {
        unsigned long long i = 0;
        for(i = primecache[prime_count - 1] + 1; is_prime(i) != true; i++)
            ;//do nothing
        primecache[prime_count++] = i;
        prime_index++;
        return i;
    }
    
}

unsigned int GCD(unsigned int x, unsigned int y) {
    
    unsigned int temp = 0;

    while(y > 0) {
        temp = y;
        y = x % y;
        x = temp;
    }
    
    return x;
}


int main() {
    long long first_cat_hight = 0, worker_cat = 0;
    unsigned int factor_count[100000];
    
    while(true) {
        cin >> first_cat_hight >> worker_cat;
        if (first_cat_hight == 0 || worker_cat == 0)
            break;

        unsigned long long lazy_cats = 0;
        unsigned long long total_height = 0;
        unsigned long long height = first_cat_hight;

        if (worker_cat == 1) {
            //oops we have to handle this differently because
            //we can't find factors of 1 its not prime
            //but its sure that each cat has one cat on its head
            lazy_cats = powerOf2(first_cat_hight);

            while(height >= 1) {
                total_height += height;
                height /= 2;
            }
            cout << lazy_cats << " " << total_height+height << endl;
            continue;
        }

        prime_index = 0;
        unsigned long long temp  = worker_cat;
        unsigned long long p = 0;

        for(p = get_next_prime(); temp > 1; p = get_next_prime()) {
            while(temp % p == 0) {
                temp /= p;
                factor_count[prime_index-1]++;
            }
        }

        unsigned int gcd_x = 0;
        bool min_fact = true;

        for(unsigned long long i = 0; i < prime_index; i++) {
            if (factor_count[i]) {

                if (factor_count[i] > 1)
                    min_fact = false;

                if (gcd_x == 0)
                    gcd_x = factor_count[i];
                else
                    gcd_x = GCD(gcd_x, factor_count[i]);
                
                factor_count[i] = 0;
            }
        }

        //this is not a perfect power
        //10 - 2^1 * 5^1 so its 10^1 gcd is 1 but still this is perfect power
        //to detect if see factor_count is all 1 then we include even the gcd is 1
        if (gcd_x == 1 && min_fact == false)
            continue;

        unsigned int x = floor(pow((double)worker_cat, ((double)1/gcd_x)) + 0.5);

        //for 1000 worker cats we know its 1, 10, 100, 1000 x^y, 10^3
        //lazy_cats = 10^1 + 10^1 + 10^2 

        unsigned int xgcd_x = gcd_x;
        unsigned int xx = x;
        
        for(unsigned int i = 1; i <= gcd_x/2 + 1; i++) {
            //we do this because 64 can be represented as 2^6
            //so if the height is not according the level then we try (2^2)^3

            if (gcd_x % i == 0) {
                xx = pow(x, i);
                xgcd_x = gcd_x / i;
            }

            unsigned int j = 0;
            lazy_cats = 0;
            total_height = 0;
            height = first_cat_hight;

            for(j = 0; j < xgcd_x; j++) {
                lazy_cats += pow(xx, j);
                total_height += height * pow(xx, j);
                height /= (xx+1);
            }
            
            total_height += height * pow(xx, j);

            if (height == 1)
                break;
        }

        cout << lazy_cats << " " << total_height << endl;
    }

    return 0;
}


//best approach
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
using namespace std;


int powerOf2 (double h)
{
    int p = 0;
    while ( true )
 {
        int res = (1 << p) ;
        if ( res > h )
            return p - 1;
        p++;
    }
}

int main ()
{
    long double H;
    long double x;

    while ( cin >> H >> x )
   {
        if ( H == 0 && x == 0 )
            break;

        if ( H == 1 )
        {
            printf ("0 1\n");
            continue;
        }
        if ( x == 1 )
       {
            int t = powerOf2 (H);

            int k = 0;
            while ( H >= 1 )
            {
                k += H;
                H /= 2;
            }
            printf ("%d %d\n", t , k);
            continue;
        }

        double n = 2.0;
        long double rightSide = log (x) / log (H);

        while ( fabs (log (n) / log (n + 1) - rightSide) > 1e-12  )
            n += 1;

        int generation = 0;
        int dummy = (int)x;
        while ( dummy % (int)n == 0 )
        {
            dummy /= (int)n;
            generation++;
        }

        int notWorking = 0;
        generation--;
        while ( generation > -1)
       {
            notWorking += (int)ceil (pow (n, generation));
            generation--;
        }

        double totalHeight = 0;
        int p = 0;
        double height = H;
        while ( pow (n, p) <= x )
       {
            totalHeight += (height * pow (n, p));
            height /= (n + 1);
            p++;
        }

        printf ("%d %0.lf\n", notWorking, totalHeight);

    }

    return 0;
}
*/
