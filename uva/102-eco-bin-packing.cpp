//Author Kalyan - s.kalyanasundaram@gmail.com
///#include <stdio.h>
#include <iostream>
#include <sstream>
///#include <queue>

using namespace std;
#define BROWN 0
#define GREEN 1
#define CLEAR 2

#define BCG 0
#define BGC 1
#define CBG 2
#define CGB 3
#define GBC 4
#define GCB 5

int main() {
    int bin1[3] = {0}, bin2[3] = {0},bin3[3] = {0};
    ///queue <char*> qout;
    string names[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    int combination[6];
    stringstream oss;

    while(cin >> bin1[BROWN] >> bin1[GREEN] >> bin1[CLEAR] >> 
          bin2[BROWN] >> bin2[GREEN] >> bin2[CLEAR] >> 
          bin3[BROWN] >> bin3[GREEN] >> bin3[CLEAR]) {


        //BCG
        combination[BCG] = (bin2[BROWN] + bin3[BROWN]) + (bin1[CLEAR] + bin3[CLEAR]) + (bin1[GREEN] + bin2[GREEN]);
        //BGC
        combination[BGC] = (bin2[BROWN] + bin3[BROWN]) + (bin1[GREEN] + bin3[GREEN]) + (bin1[CLEAR] + bin2[CLEAR]);
        
        //CBG
        combination[CBG] = (bin2[CLEAR] + bin3[CLEAR]) + (bin1[BROWN] + bin3[BROWN]) + (bin1[GREEN] + bin2[GREEN]);
        //CGB
        combination[CGB] = (bin2[CLEAR] + bin3[CLEAR]) + (bin1[GREEN] + bin3[GREEN]) + (bin1[BROWN] + bin2[BROWN]);
        
        //GBC
        combination[GBC] = (bin2[GREEN] + bin3[GREEN]) + (bin1[BROWN] + bin3[BROWN]) + (bin1[CLEAR] + bin2[CLEAR]);
        //GCB
        combination[GCB] = (bin2[GREEN] + bin3[GREEN]) + (bin1[CLEAR] + bin3[CLEAR]) + (bin1[BROWN] + bin2[BROWN]);

        int min = combination[0], j = 0;
            
        for(int i=1; i<6; i++) {
            if (combination[i] < min) {
                min = combination[i];
                j = i;
            }
        }

        ////char *out = new char[10];
        ///sprintf(out, "%s %d", (j == 0?"BCG" : j==1?"BGC" : j==2?"CBG" : j==3?"CGB" : j==4?"GBC" : j==5?"GCB": ""), min);
        ///qout.push(out);
        ////oss << (j == 0?"BCG" : j==1?"BGC" : j==2?"CBG" : j==3?"CGB" : j==4?"GBC" : j==5?"GCB": "") << " " << min << endl;
        oss << names[j] << " " << min << endl;
    }

    /// while(!qout.empty()) {
    ///     cout << qout.front() << endl;
    ///     qout.pop();
    /// }
    cout << oss.str();
    return 0;
}
