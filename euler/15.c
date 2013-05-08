#include <stdio.h>
#include <stdlib.h>

#define N 20



/*int travel(int x, int y) {
    int count = 0;

    if (!(x <= ROW && y <= COL))
        return 0;

    if (x == ROW && y == COL) {
        //printf("path\t");
        return 1;
    }
    else {
        printf ("%d %d \t", x, y);
        count = travel(x, y+1);
        count += travel (x+1, y);
        return count;
    }
}
*/

struct node {
    int x, y;
    struct node *next;
};

struct node *push(struct node *head, int x, int y) {

    struct node *mynode = NULL;

    if (x > N || y > N)
        return head;

    mynode = malloc(sizeof(struct node));
    mynode->x = x;
    mynode->y = y;
    mynode->next = head;
    return mynode;
}

inline struct node *pop(struct node *head) {
    if (head == NULL) 
        return NULL;
    else {
        return head->next;
    }
}

int main(int argc, char **argv) {
    
    struct node *head = NULL;
    struct node *ptr;
    long sum = 0;

    head = push(head, 0, 0);

    for (; head != NULL; ) {
        printf("%d %d %ld\n", head->x, head->y, sum);
        if (head->x == N && head->y == N) {
            sum ++;
            head = pop(head);
        }
        else {
            ptr = head;
            head = pop(head);
            head = push(head, ptr->x+1, ptr->y);
            head = push(head, ptr->x, ptr->y+1);
        }
    }
    printf("sum %ld\t", sum);

    return 0;
}
