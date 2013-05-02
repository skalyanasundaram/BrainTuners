#include <iostream>

using namespace std;


#define MAX_SIZE 10000

int main() {
    int heights[MAX_SIZE + 1] = {0};
    int building = 0, chight = 0, a = 0, b = 0, c = 0;

    while(cin >> a >> b >> c) {
        if (a >= MAX_SIZE || b >= MAX_SIZE || c >= MAX_SIZE)
            continue;

        if (building > 5000)
            break;

        for(int i=a; i<c; i++)
            if (heights[i] < b)
                heights[i] = b;

        building++;

    }
    
    bool first = true;
    for(int i=0; i<MAX_SIZE; i++) {
        if(chight != heights[i]) {
            if (!first)
                cout << " ";
            else
                first = false;
            cout << i << " " << heights[i];
            chight = heights[i];
        }
    }

    cout << endl;
    return 0;
}
