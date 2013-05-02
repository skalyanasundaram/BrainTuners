#include <iostream>
#include <math.h>

//http://www.mathopenref.com/coordpolygonarea.html - to find the area of polygon
//http://www.topcoder.com/tc?d1=tutorials&d2=geometry1&module=Static -- vectors
//http://stackoverflow.com/questions/11107687/implementing-graham-scan-to-find-the-convex-hull - to find angle
//http://tixxit.net/2010/03/graham-scan/

using namespace std;

struct point {
    int x;
    int y;
};

bool operator<(point &p1, point &p2) {
    if (p1.x < p2.x) return true;
    if (p1.x > p2.x) return false;

    if (p1.y < p2.y) return true;
    if (p1.y > p2.y) return false;
}

double angle(point p1, point p2) {
    //see vectors :: vectorx = x2 - x1
    return (p2.x - p1.x) / sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void shift_down(point *array, point p, int current, int size) {
    int left = 2*current + 1;
    int right = 2*current + 2;
    int max = current;

    if (left < size && angle(p, array[max]) < angle(p, array[left]))
        max = left;
    if (right < size && angle(p, array[max]) < angle(p, array[right]))
        max = right;

    // if (left < size && array[max] < array[left])
    //     max = left;
    // if (right < size && array[max] < array[right])
    //     max = right;

    if (max != current) {
        point temp = array[max];
        array[max] = array[current];
        array[current] = temp;

        shift_down(array, p, max, size);
    }
}
void max_heapify(point *array, point p, int size) {
    for(int point = size/2 - 1; point >= 0; point--)
        shift_down(array, p, point, size);
}

void heap_sort(point *array, point p, int size) {
    
    max_heapify(array, p, size);

    while(size > 1) {
        point temp = array[0];
        array[0] = array[size - 1];
        array[size - 1] = temp;
        max_heapify(array, p,  --size);
    }
}

int ccw(point p1, point p2, point p3) {
    //x1y2 - y1x2
    int x1 = p2.x - p1.x;
    int y1 = p2.y - p1.y;

    int x2 = p3.x - p1.x;
    int y2 = p3.y - p1.y;

    return ((x1 * y2) - (y1 * x2));
}

int main() {
    point array[100];
    int N;

    while(true) {
        cin >> N;

        if (N < 3 || N > 100)
            continue;

        for(int i=0; i < N; i++) {
            cin >> array[i].x >> array[i].y;
        }
        
        //choosing the smallest y (x if more than one smallest y)
        point p = array[0];
        int p_loc = 0;
        for(int i=1; i < N; i++) {
            if(array[i].y < array[p_loc].y)
                p_loc = i;
            else if(array[i].y == array[p_loc].y && array[i].x < array[p_loc].x)
                p_loc = i;
        }

        p = array[p_loc];
        array[p_loc] = array[N-1];
        array[N-1] = p;

        heap_sort(array, p,  N-1);

        point hull[100];
        int j = 0;
        hull[j++] = p;
        hull[j++] = array[N-2];

        for(int i = N-3; i>=0; i--) {
            if (array[i].x == p.x && array[i].y == p.y)
                continue;

            if (ccw(hull[j-2], hull[j-1], array[i]) > 0) {
                hull[j++] = array[i];
            }
            else {
                hull[j-1] = array[i];
            }
        }

        double area = 0;
        for(int i = 1 ; i<N; i++) {
            area += ((array[i-1].x * array[i].y) - (array[i-1].y * array[i].x)) / 2.0;
            //cout << hull[i].x << " " << hull[i].y << endl;
        }
        cout << fabs(area) << endl;

    }

    return 0;
}
