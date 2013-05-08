#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node {
private:
    string name;
    
    Node *left;
    Node *right;

    static unsigned long id;
    unsigned long long getAlphaSum();

public:

    Node(string s) : name(s, 1, s.length()-2) { left = right = NULL; }
    void print() { cout << name << endl; }
    void insert(Node *node) {
        
        Node *ptr = this;
        
        if (node->name.compare(this->name) < 0)
            if (this->left != NULL)
                this->left->insert(node);
            else
                this->left = node;
        else if (node->name.compare(this->name) > 0)
            if (this->right != NULL)
                this->right->insert(node);
            else
                this->right = node;
        else
            cout << "Repeated : " << node->name << ", ingnoring" << endl;
    }

    unsigned int getalphasum() {
        unsigned int sum = 0;
        for (string::iterator it = this->name.begin(); it < this->name.end(); it++)
                 sum += (int)(*it) - 64; //Assuming all caps char

        return sum;
    }

    unsigned long long inorderprint() {

        unsigned int alphasum = getalphasum();
        unsigned long long sum = 0;

        if (this->left != NULL) sum += this->left->inorderprint();

        cout << Node::id  << ":" << this->name << ":" << alphasum << " = " << Node::id * alphasum << endl;
        sum += Node::id * alphasum;
        Node::id ++; 

        if (this->right != NULL) sum += this->right->inorderprint();

        return sum;
    }
};

unsigned long Node::id = 1;

int main(int argc, char **argv) {
    char a[100];
    Node *head = NULL;
    
    if (argc != 2) {
        cout << "Wrong input\n";
        return -1;
    }

    ifstream fp(argv[1]);

    if (! fp.good()) {
        cout << "invalid file" << endl;
        return -1;
    }
    
    while (! fp.eof()) {
        fp.getline(a, 100, ',');
        Node *node = new Node(string(a));

        if (head == NULL)
            head = node;
        else
            head->insert(node);
    }

    cout << "total sum:" << head->inorderprint() << endl;
    return 0;
}
