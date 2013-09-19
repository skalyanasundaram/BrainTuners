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

void swap(unsigned int boggies[], int left, int right)
{
    int temp = boggies[left];
    boggies[left] = boggies[right];
    boggies[right] = temp;
}

int merge(unsigned int boggies[], int start, int mid, int end)
{
    int invertion = 0, i = 0, j = 0, k = 0;
    int s1 = mid - start + 1,
        s2 = end - mid;
    unsigned int left[50], right[50];

    for (i = 0; i < s1; i++)
    {
        left[i] = boggies[i + start];
    }
    for (i = 0; i < s2; i++)
    {
        right[i] = boggies[i + mid + 1];
    }

    i = j = 0;
    k = start;
    while (i < s1 && j < s2)
    {
        if (left[i] > right[j])
        {
            invertion += s1 - i;
            boggies[k++] = right[j++];
        }
        else
        {
            boggies[k++] = left[i++];
        }
    }

    while (i < s1)
    {
        boggies[k++] = left[i++];
    }
    while (j < s2)
    {
        boggies[k++] = right[j++];
    }

    return invertion;
}

// still that not useful
int train_swap_merge_sort(unsigned int boggies[], int start, int end)
{
    int invertion = 0;

    if (start < end)
    {
        int mid = (start + end) / 2;
        invertion += train_swap_merge_sort(boggies, start, mid);
        invertion += train_swap_merge_sort(boggies, mid + 1, end);
        invertion += merge(boggies, start, mid, end);
    }

    return invertion;
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

        cout << "Optimal train swapping takes " << train_swap_merge_sort(boggies, 0, size-1) << " swaps." << endl;
        N--;
    }
    

    return 0;
}