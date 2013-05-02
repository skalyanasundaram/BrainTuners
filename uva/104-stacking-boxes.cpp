#include <iostream>

using namespace std;
#define MAX_BOX 30

void print (int length, int *array) {
    
    for (int i=0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

}

inline bool can_fit(int length, int *array1, int *array2) {
    
    for(int i=0; i < length; i++)
        if (array1[i] > array2[i])
            return false;
    return true;
}

inline bool is_less(int length, )
inline void sort(int length, int *array) {
    
    for (int i=1; i < length; i++) {
        int item = array[i];
        int hole = i;

        while(hole > 0 && array[hole-1] > item) {
            array[hole] = array[hole-1];
            hole--;
        }
        array[hole] = item;
    }
}


int sequence(int boxes, int dimension, int **array,int *out) {
    int box_seq[MAX_BOX];

    for (int i = 1; i <= boxes; i++)
        box_seq[i] = i;

    
    
}

int main() {
    int boxes = 0, dimension = 0;
    int **entry;
    int *out;

    while(cin >> boxes >> dimension) {
        if (dimension < 1 || dimension > 10 ||
            boxes < 1 || boxes > MAX_BOX)
            continue;

        out = new int[boxes];
        entry = new int*[boxes];
        for(int i=0; i<boxes; i++) {
            entry[i] = new int[dimension];
            for (int j=0; j < dimension; j++)
                cin >> entry[i][j];
            sort(dimension, entry[i]);
        }
        
        int count = sequence(boxes, dimension, entry, out);
        cout << count << endl;
        for(int i=0; i < count; i++)
            cout << out[i] << " ";
        cout << endl;


        for(int i=0; i<boxes; i++)
            delete [] entry[i];
        delete [] entry;
        delete [] out;
    }

    return 0;
}
