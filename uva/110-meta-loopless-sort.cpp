#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

void print_condition(vector<char> ordered, vector<char> unordered) {

    string space = "";
    for(int i=0; i<ordered.size(); i++)
        space += "  ";

    if(unordered.empty()) {
        cout << space << "writeln(";
        for(int i = 0; i < ordered.size(); i++) {
            if(i) cout << ",";
            cout << ordered.at(i);
        }
        cout << ")" << endl;
    }
    else {
        char y = unordered.front();
        unordered.erase(unordered.begin());

        vector <char>::iterator it;
        for (it = ordered.end(); it != ordered.begin(); it--) {

            cout << space;
            if (it != ordered.end())
                cout << "else ";
            cout << "if " << *(it-1) << " < " << y << " then" << endl;

            it = ordered.insert(it, y);
            print_condition(ordered, unordered);
            it = ordered.erase(it);
        }
        cout << space << "else\n";
        it = ordered.insert(it, y);
        print_condition(ordered, unordered);
        it = ordered.erase(it);

    }
    
}

int main() {
    
    int M, n;
    vector<char> ordered, unordered;
    int *N;

    cin >> M;

    N = new int[M];

    for(int i=0; i<M; i++) {
        cin >> N[i];

        if (N[i] < 1 || N[i] > 8)
            continue;

    }

    for(int i=0; i<M; i++) {
        n = N[i];

        ordered.clear();
        unordered.clear();

        cout << "program sort(input,output);" << endl;
        cout << "var" << endl;
        for(int j=0; j<n; j++) {
            if (j) cout << ",";
            printf("%c", 'a' + j);
            unordered.push_back('a' + j);
        }

        cout << " : integer;" << endl;
        cout << "begin" << endl;
        cout << "  readln(";

        for(int j=0; j<n; j++) { 
            if(j) cout << ",";
            printf("%c", 'a'+j);
        }
        cout << ");" << endl;

        ordered.push_back('a');
        unordered.erase(unordered.begin());
        print_condition(ordered, unordered);

        cout << "end." << endl;

        if (i+1 < M)
            cout << endl;
    }
}
