//Author kalyan - s.kalyanasundaram
#include <iostream>
#include <string>

#define MAX_BLOCK 24

using namespace std;

static int stacks[25][25];
static unsigned int blocks;

int find_stack_id(unsigned block_id, unsigned &x, unsigned &y) {
    
    for (int i=0; i<blocks; i++)
        if (stacks[i][0])
            for(int j=1; stacks[i][j] != -1; j++)
                if (stacks[i][j] == block_id) {
                    x = i;
                    y = j;
                    return 0; 
                }

    return 1;
}

void clear(unsigned stack_id, unsigned from) {
    unsigned j = stacks[stack_id][0];
    while(j > from) {
        unsigned row = stacks[stack_id][j];
        unsigned col = stacks[row][0];
        stacks[row][col+1] = row;
        stacks[row][0]++;
        stacks[stack_id][0]--;
        stacks[stack_id][j--] = -1;
    }
}

void move(unsigned i, unsigned j, unsigned k) {
    unsigned jcounter = stacks[k][0] + 1;
    while(stacks[i][j] != -1) {
        stacks[k][jcounter++] = stacks[i][j++];
        stacks[k][0]++;
        stacks[i][0]--;
        stacks[i][j-1] = -1;
    }
}
int main() {
    
    unsigned int blockX = 0, blockY = 0;
    string op, op_target;

    cin >> blocks;

    if (blocks < 1 || blocks > MAX_BLOCK )
        return -1;

    for (int i=0; i<blocks; i++) {
        stacks[i][0] = 1;
        stacks[i][1] = i;
        for (int j = 2; j<blocks; j++)
            stacks[i][j] = -1;
    }

    while(1) {

        cin >> op;

        if (op.compare("quit") == 0) {
            break;
        }
        else { 
            cin >> blockX >> op_target >> blockY;

            //wrong blocks
            if (blockX > blocks || blockY > blocks || blockX == blockY)
                continue;

            unsigned int i, j, k, l;
            find_stack_id(blockX, i, j);
            find_stack_id(blockY, k, l);

            //source and target stacks are same
            if (i == k)
                continue;

            if(op.compare("move") == 0) {
                
                if (op_target.compare("onto") == 0) {
                    clear(i,j);
                    clear(k,l);
                    move(i,j,k);
                }
                else if (op_target.compare("over") == 0) {
                    clear(i,j);
                    move(i,j,k);
                }
            }
            else if (op.compare("pile") == 0) {

                if (op_target.compare("onto") == 0) {
                    clear(k, l);
                    move(i,j,k);
                }
                else if (op_target.compare("over") == 0) {
                    move(i,j,k);
                }
                
            }

            //else wrong ops ignore and read next op
        }
    }

    for (int i=0; i<blocks; i++) {
        cout << i << ":";
        for(int j=1; j <= stacks[i][0]; j++)
            cout << " " << stacks[i][j];

        cout << endl;
    }
    return 0;
}
