#include <iostream>
#include <vector>

using namespace std;

void shift_down(int cur, int size, vector<int> &list)
{
    int left = (cur * 2) + 1;
    int right = (cur * 2) + 2;
    int max = cur;

    if (left < size && list[left] > list[max])
        max = left;

    if (right < size && list[right] > list[max])
        max = right;

    if (max != cur)
    {
        int t = list[max];
        list[max] = list[cur];
        list[cur] = t;
        shift_down(max, size, list);
    }
}

void max_heapfy(int size, vector<int> &list)
{
    for (int i = (size - 1) / 2; i >= 0; i--)
    {
        shift_down(i, size, list);
    }
}

void heap_sort(vector<int> &list)
{
    int size = list.size();

    while(size) 
    {
        max_heapfy(size, list);
        list.insert(list.begin() + size, list.front());
        list.erase(list.begin());
        size--;
    }
}

int main()
{
    int tests = 0, totalRelatives = 0, index = 0, temp = 0;
    vector<int> relatives;

    cin >> tests;

    while (tests)
    {
        cin >> totalRelatives;

        relatives.clear();
        for (index = 0; index < totalRelatives; index++)
        {
            cin >> temp;
            relatives.push_back(temp);
        }

        heap_sort(relatives);
        int street = 0, totalDistance = 0;

        if (totalRelatives % 2)
        {
            street = relatives[totalRelatives / 2];
        }
        else
        {
            street = (relatives[totalRelatives / 2] + relatives[(totalRelatives / 2) - 1]) / 2;
        }

        for (vector<int>::iterator it = relatives.begin();
             it != relatives.end();
             it++)
        {
            int distance = street - (*it);
            totalDistance += (distance > 0)? distance : -distance;
        }
        cout << totalDistance << endl;

        tests--;
    }

    return 0;
}
