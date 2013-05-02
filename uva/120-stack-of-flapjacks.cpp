#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
//pancake sorting

using namespace std;

void flip(vector<int> &stk, int pos) {
    queue<int> q;

    for(int n = stk.size(); n >= pos; n--) {
        q.push(stk.back());
        stk.pop_back();
    }

    while(!q.empty()) {
        stk.push_back(q.front());
        q.pop();
    }
}

void pancake_sort(vector<int> &res, vector<int> &stk) {

    for(int stk_pos = 1; stk_pos < stk.size(); stk_pos++) {

        int max = 0, max_pos = stk_pos;
        for(int cur_pos = stk_pos; cur_pos <= stk.size(); cur_pos++) {

            if(stk[cur_pos - 1] > max) {
                max = stk[cur_pos - 1];
                max_pos = cur_pos;
            }
        }

        if(max_pos != stk_pos) {

            if (max_pos < stk.size()) {
                flip(stk, max_pos);
                res.push_back(max_pos);
            }

            flip(stk, stk_pos);
            res.push_back(stk_pos);
        }
    }

    res.push_back(0);
}

int main() {
    vector<int> res, stk;
    string s;

    while(getline(cin, s)) {
        stringstream stream(s);
        int n, count = 0;
        
        stk.clear();

        while(true) {
            stream >> n;
            if (!stream)
                break;

            if (n < 1 || n > 100)
                continue;

            res.push_back(n);
            stk.insert(stk.begin(), n);
        }

        if (stk.size() < 1 || stk.size() > 30)
            return -1;

        res.push_back(-1); //delimeter to say the next is answer

        pancake_sort(res, stk);
    }

    for(vector<int>::iterator it = res.begin();
        it != res.end();
        it++) {
        
        if (*it < 0)
            cout << endl;
        else {
            cout << *it << " ";
            if (*it == 0)
                cout << endl;
        }
        
    }
    return 0;
}
