#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Node {
private:
    char c;
    int refCount;
public:
    Node():refCount(0), c(0){}

    char getChar() { return c; }
    void setChar(char c) { this->c = c; }

    int getRefCount() { return refCount; }
    void IncreaseRefCount() { refCount++; }

    bool operator<(Node &rhs) {
        if (rhs.refCount > this->refCount || (rhs.refCount == this->refCount && rhs.c < this->c))
            return true;
        else
            return false;
    }

    void swap(Node &rhs) {
        int t = this->refCount;
        this->refCount = rhs.refCount;
        rhs.refCount = t;

        char c = this->c;
        this->c = rhs.c;
        rhs.c = c;
    }
};

int partition(Node (&lst)[26], int lo, int hi) {
    int i = lo, j = hi + 1;

    while(true) {
        while(lst[++i] < lst[lo])
            if (i == hi)
                break;

        while(lst[lo] < lst[--j])
            if (j == lo)
                break;

        if (i >= j)
            break;

        lst[i].swap(lst[j]);
    }

    lst[lo].swap(lst[j]);
    return j;
}

void qsort(Node (&lst)[26], int lo, int hi) {

    if ( lo >= hi)
        return;

    int p = partition(lst, lo,hi);
    qsort(lst, lo, p-1);
    qsort(lst, p+1, hi);
}

int main() {

    Node lst[26];
    int N = 0;

    cin >> N;
    cin.ignore(256, '\n');

    string s;

    while(N) {
        getline(cin, s);

        for(int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                char c = toupper(s[i]);
                int index =  c - 'A';
                lst[index].setChar(c);
                lst[index].IncreaseRefCount();
            }
        }
        N--;
    }

    qsort(lst, 0, 25);

    for(int i = 25; i >=0; i--) {
        if (lst[i].getRefCount() > 0)
            cout << lst[i].getChar() << " " << lst[i].getRefCount() << endl;
    }

    return 0;
}
