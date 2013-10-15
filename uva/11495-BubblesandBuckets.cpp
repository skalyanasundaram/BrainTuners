#include <iostream>
#include <vector>
#include <string>
using namespace std;

unsigned long merge(vector < unsigned long> &numbers, unsigned long start, unsigned long mid, unsigned long end)
{
    vector <unsigned long> left, right;
    unsigned long s1 = 0, s2 = 0, i = 0, j = 0, k = 0, swaps = 0;

    s1 = mid - start + 1;
    s2 = end - mid;

    for (i = 0; i < s1; i++)
    {
        left.push_back(numbers[i + start]);
    }
    for (i = 0; i < s2; i++)
    {
        right.push_back(numbers[i + mid + 1]);
    }

    k = start;
    i = j = 0;
    k = start;
    while (i < s1 && j < s2)
    {
        if (left[i] > right[j])
        {
            swaps += s1 - i;
            numbers[k++] = right[j++];
        }
        else
        {
            numbers[k++] = left[i++];
        }
    }

    while (i < s1)
    {
        numbers[k++] = left[i++];
    }
    while (j < s2)
    {
        numbers[k++] = right[j++];
    }

    return swaps;
}

unsigned long merge_sort_get_swap_count(vector<unsigned long> &numbers, unsigned long start, unsigned long end)
{
    unsigned long mid = (start + end) / 2,
        swaps = 0;

    if (start < end)
    {
        swaps += merge_sort_get_swap_count(numbers, start, mid);
        swaps += merge_sort_get_swap_count(numbers, mid + 1, end);
        swaps += merge(numbers, start, mid, end);
    }
    return swaps;
}
int main()
{
    vector<unsigned long> numbers;
    unsigned long n, v, i;
    string s;

    while (true)
    {
        getline(cin, s);

        numbers.clear();
        v = 0, n = 0;
        for (i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (!n)
                {
                    n = v;
                }
                else
                {
                    numbers.push_back(v);
                }
                v = 0;
            }
            else
            {
                v = v * 10 + (s[i] - '0');
            }
        }
        numbers.push_back(v);

        if (!n)
        {
            return 0;
        }

        cout << ((merge_sort_get_swap_count(numbers, 0, n - 1) % 2) ? "Marcelo" : "Carlos") << endl;
    }
    return 0;
}