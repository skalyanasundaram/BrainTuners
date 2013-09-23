#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>

using namespace std;

int roman_to_arabic[26] = { 0 };
map<int, char> arabic_to_roman;

string convert_arabic_to_roman(int num)
{
    string s;
    int divider = 1000, reduce = 100, step = 2, n;

    while (num)
    {
        n = num / divider;
        while (n)
        {
            s.push_back(arabic_to_roman[divider]);
            n--;
        }
        num %= divider;

        if (divider - reduce <= 0)
            reduce /= 10;

        if (divider - reduce <= num)
        {
            s.push_back(arabic_to_roman[reduce]);
            s.push_back(arabic_to_roman[divider]);
            num -= (divider - reduce);
        }

        divider /= step;
        step = step == 2 ? 5 : 2; //1000, 500, 100.. divided by 2 and 5 alternatively
    }

    return s;
}

int convert_roman_to_arabic(string s)
{
    int value = 0, prev_value = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (i + 1 < s.length())
        {
            if (roman_to_arabic[s[i]] < roman_to_arabic[s[i + 1]])
            {
                prev_value += roman_to_arabic[s[i]]; 
                continue;
            }
        }

        value += roman_to_arabic[s[i]] - prev_value;
        prev_value = 0;
    }
    return value;
}

int main()
{
    string s;

    roman_to_arabic['I'] = 1;
    roman_to_arabic['V'] = 5;
    roman_to_arabic['X'] = 10;
    roman_to_arabic['L'] = 50;
    roman_to_arabic['C'] = 100;
    roman_to_arabic['D'] = 500;
    roman_to_arabic['M'] = 1000;

    arabic_to_roman[1] = 'I';
    arabic_to_roman[5] = 'V';
    arabic_to_roman[10] = 'X';
    arabic_to_roman[50] = 'L';
    arabic_to_roman[100] = 'C';
    arabic_to_roman[500] = 'D';
    arabic_to_roman[1000] = 'M';

    while (cin >> s)
    {
        if (s[0] >= 'A' && s[0] <= 'Z')
            cout << convert_roman_to_arabic(s) << endl;
        else
            cout << convert_arabic_to_roman(atoi(s.c_str())) << endl;
        s.clear();
    }
    return 0;
}