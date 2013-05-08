#include <iostream.h>
using namespace std;

typedef struct mynode{
    char *name;
    unsigned long long alphasum;
    struct mynode *left;
    struct mynode *right;
}Treenode;

unsigned long long alphasum(char *str) {
    return 0;
}

Treenode *BSTinsert(Treenode *head, char *name) {
    Treenode *start = head;
    Treenode *ptr = head;
    Treenode *node = malloc(sizeof(Treenode));
    int len = strlen(name) + 1;

    if (len < 1) {
        fprintf(stderr, "invalid string");
        return NULL;
    }

    node->name = malloc(len);
    strcpy(node->name, len, 0);
    strcpy(node->name, name);
    node->alphasum = alphasum(name);

    if (head != NULL)
        while(1){
            if (ptr->left == NULL && ptr->right == NULL)
                p
        }


    return node;

}

int main(int argc, char **argv) {
    FILE *fp = NULL;
    char a[100];
    Treenode *head = NULL;

    if (argc != 2) {
        printf("Wrong input\n");
        return -1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
        return -1;

    while ( EOF != (fscanf(fp, "\"%[A-Z]\",", a))) {
        printf("%s\n", a);
        Treenode *node = BSTinsert(head, a);
        if (head == NULL) head = node;
    }

    return 0;
}
