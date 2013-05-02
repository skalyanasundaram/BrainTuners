#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;


struct node {
    int value;
    string path;
    node *left;
    node *right;
};

void delete_tree(node *node) {
    
    if (node == NULL)
        return;

    delete_tree(node->left);
    node->left = NULL;
    
    delete_tree(node->right);
    node->right = NULL;

    delete node;
}
bool is_tree_completely_specified(vector<node> &inp) {
    
    node *root = NULL, *cur = NULL, *prev = NULL;
    for(vector<node>::iterator it = inp.begin();
        it != inp.end();
        it++) {
        
        node n = *it;
        if (n.path.size() == 0) {
            if (root != NULL) {
                return false;
            }
            else {
                root = &(*it);
            }
        }
        else {
            cur = root;
            for(string::iterator pit = n.path.begin();
                pit != n.path.end(); pit++) {

                if (cur == NULL)
                    return false;

                prev = cur;

                if (*pit == 'L') 
                    cur = cur->left;
                else if (*pit == 'R')
                    cur = cur->right;
            }

            //node already mentioned
            if (cur != NULL)
                return false;

            if (n.path[n.path.size() - 1] == 'L') 
                prev->left = &(*it);
            else if (n.path[n.path.size() - 1] == 'R') 
                prev->right = &(*it);
        }
    }

    //delete_tree(root);
    return true;
}

int main() {
    char node_data[1000];
    char temp[100];
    vector<node> inp;
    vector<int> out;

    while(cin >> node_data) {

        if (node_data[0] == '(' && node_data[1] == ')') {

            if (is_tree_completely_specified(inp)) {
                for(vector<node>::iterator it = inp.begin();
                    it != inp.end(); it++) 
                    cout << (it == inp.begin() ? "" : " ") << (*it).value;
            }
            else
                cout << "not complete";

            cout << endl;

            inp.clear();
            continue;
        }

        node n;
        sscanf(node_data, "(%d,%s)", &n.value, temp);
        temp[strlen(temp) - 1] = '\0';
        n.path = temp;
        n.left = n.right = NULL;

        //insertion sort
        vector<node>::iterator it;
        for(it = inp.begin();
            inp.size() > 0 && it != inp.end();
            it++) {

            if((*it).path.length() > n.path.length() || ((*it).path.length() == n.path.length() && (*it).path > n.path)) {
                inp.insert(it, n);
                break;
            }
        }

        if(inp.size() == 0 || it == inp.end())
            inp.push_back(n);


    }
    return 0;
}
