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

    if (argc < 2) {
        cerr << "No argument to generate lexicographic order, enter some numer" << endl;
        return -1;
    }

    start = clock();
    for (int i=0; i<atoi(argv[1]); i++)
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
            if (million == 1000000) {

                cout << million << ":";
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
 * x - 0,1,2
 *
 * 0 - 1,2
 * 1 - 0,2
 * 2 - 0,1
 *
 * 0,1 - 2
 * 0,2 - 1
 * 1 - 0,2
 * 2 - 0,1
 *
 * 0,1,2 - x
 * 0,2 - 1
 * 1 - 0,2
 * 2 - 0,1
 * 
 * 0,2 - 1
 * 1 - 0,2
 * 2 - 0,1
 *.....
 * */
