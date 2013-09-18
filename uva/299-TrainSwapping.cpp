#include <iostream>
using namespace std;

int train_swap_cocktail_sort(unsigned int boggies[], int size)
{
    unsigned int temp = 0, count = 0;
    int i = 0;
    bool swapped = false;

    do 
    {
        swapped = false;

        for (i = 0; i < size - 1; i++)
        {
            if (boggies[i] > boggies[i + 1])
            {
                temp = boggies[i];
                boggies[i] = boggies[i + 1];
                boggies[i + 1] = temp;
                swapped = true;
                count++;
            }
        }

        if (!swapped)
            return count;

        for (i = size - 2; i >= 0; i--)
        {
            if (boggies[i] > boggies[i + 1])
            {
                temp = boggies[i];
                boggies[i] = boggies[i + 1];
                boggies[i + 1] = temp;
                swapped = true;
                count++;
            }
        }
    }while (swapped);
}

// no need to sort, just count it.. this is still worse than the above
int train_swap_count(unsigned int boggies[], int size)
{
    int count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (boggies[i] > boggies[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N = 0, i = 0;
    unsigned int size, boggies[52] = { 0 };

    cin >> N;
    while (N) 
    {
        cin >> size;

        if (size > 50)
            return -1;

        for (i = 0; i < size; i++)
        {
            cin >> boggies[i];
        }

        cout << "Optimal train swapping takes " << train_swap_count(boggies, size) << " swaps." << endl;
        N--;
    }
    

    return 0;
}