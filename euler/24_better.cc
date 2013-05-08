#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef struct {
    vector<int> taker;
    vector<int> giver;
}elements;

int main(int argc, char **argv) {

    unsigned long long million = 1;
    elements element;
    stack <elements> opstack;
    clock_t start, end;

    start = clock();

    for (int i=0; i<10; i++)
        if (i != 2)
            element.giver.push_back(i);

    opstack.push(element);

    while(!opstack.empty()) {
        element = opstack.top();
        opstack.pop();

        vector<int> taker = element.taker;
        vector<int> giver = element.giver;

        /*        cout << "popup from stack" << endl;
        for(vector<int>::iterator it = taker.begin(); it < taker.end(); it++)
            cout << *it << ",";
        cout << " -- ";
        for(vector<int>::iterator it = giver.begin(); it < giver.end(); it++)
            cout << *it << ",";
        cout << endl;
        */

        if (giver.empty()) {
            if (million == 274240) {

                cout << million << ":2";
                for(vector<int>::iterator it = taker.begin(); it < taker.end(); it++)
                    cout << *it;
                cout << endl;
                break;
            }
            else 
                million ++;

        }

        vector<int>::reverse_iterator it;
        //        for(it = giver.rbegin(); it < giver.rend(); it++) {
        for(int i = giver.size() - 1; i >= 0; i--) {
            elements newelement;
            newelement.taker = taker;
            newelement.giver = giver;

            newelement.taker.push_back(giver[i]);
            newelement.giver.erase(newelement.giver.begin() + i);
            opstack.push(newelement);
        }
    }

    end = clock();
    cout << "difference:" << ((double) (end - start)) / CLOCKS_PER_SEC<< endl;
}

/*
 *since lexicographic, 1/10 will start with 0 which is 362880 elements
 * and another         1/10 will start with 1 which is 362880 + 362880 = 725760
 * and to reach 1000000 we get 1000000 - 725760 =  274240 th permutation starting with 2
 * so we remove the 2 from the list, and permutate 0,1,3,4,5,6,7,8,9 for 274240 times  - 36 seconds - 7 seconds 
 */
