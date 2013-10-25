#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Person
{
    string name;
    int day, month, year;
    bool operator> (Person &p)
    {
        return (year > p.year ? true : 
                (year < p.year ? false : 
                 (month > p.month ? true : 
                  (month < p.month ? false : 
                   (day > p.day ? true : false)))));
    }
};

// void shift_down(Person *p, int cur, int n, bool max_heapify)
// {
//     int left = cur * 2 + 1,
//         right = cur * 2 + 2,
//         max = cur;

//     if (left < n)
//     {
//         if (max_heapify && p[left] > p[max])
//         {
//             max = left;
//         }
//         if (!max_heapify && !(p[left] > p[max]))
//         {
//             max = left;
//         }
//     }
//     if (right < n)
//     {
//         if (max_heapify && p[right] > p[max])
//         {
//             max =right;
//         }
//         if (!max_heapify && !(p[right] > p[max]))
//         {
//             max = right;
//         }
//     }

//     if (max != cur)
//     {
//         Person t = p[max];
//         p[max] = p[cur];
//         p[cur] = t;
//         shift_down(p, max, n, max_heapify);
//     }
// }
// void max_heapify(Person *p, int n, bool max_heapify)
// {
//     for (int i = (n - 1) / 2; i >= 0; i--)
//     {
//         shift_down(p, i, n, max_heapify);
//     }
// }

int main()
{
    Person p, max = { "", 0, 0, 0}, min = { "", 0, 0, 0};
    int n;
    string s;

    cin >> n;
    getline(cin, s);
    while (n)
    {
        getline(cin, s);
        stringstream stream(s);
        stream >> p.name >> p.day >> p.month >> p.year;
        n--;

        if (min.year == 0)
        {
            min = p;
            max = p;
            continue;
        }

        if (p > max)
        {
            max = p;
        }
        if (min > p)
        {
            min = p;
        }
    }
    cout << max.name << endl;
    cout << min.name << endl;

    return 0;
}
