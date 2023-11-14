#include <iostream>
#include <vector>
#include <tuple>

#define INF 987654321
using namespace std;

struct node {
	int row;	  // Identifier for node's row, used for printing an answer;
	int size;	 // # of 1s on its column, used by column header nodes
	node *column; // a pointer towards its column header node
	node *up;
	node *down;
	node *left;
	node *right;
};


vector<node> column = {};
vector<node *> nodes = {};
vector<int> solution = {};
vector<tuple<int,int,int>> mapping= {};

void dlx_cover(node *c) {
    c->right->left = c->left;
    c->left->right = c->right;
    // Delete column header node

    for (node *itr = c->down; itr != c; itr = itr->down) {
        for (node *jtr = itr->right; jtr != itr; jtr = jtr->right) {
            jtr->down->up = jtr->up;
            jtr->up->down = jtr->down;
            jtr->column->size--;
        }
    } // Delete all the nodes on the row where covering node resides
    return;
};

void dlx_uncover(node *c) {
    for (node *itr = c->up; itr != c; itr = itr->up) {
        for (node *jtr = itr->left; jtr != itr; jtr = jtr->left) {
            jtr->down->up = jtr;
            jtr->up->down = jtr;
            jtr->column->size++;
        }
    }

    c->right->left = c;
    c->left->right = c;
    return;
} // Roll back all the nodes

bool dlx_search(node *head, int k) {
    if (head->right == head)
        return 1; // Found an answer

    node *ptr = nullptr; // Column node to search
    int low = INF;

    for (node *itr = head->right; itr != head; itr = itr->right) {
        if (itr->size < low) {
            if (itr->size == 0)
                return 0; // Wrong answer
            low = itr->size;
            ptr = itr;
        }
    } // Find a column node to search that has smallest size

    dlx_cover(ptr);

    for (node *itr = ptr->down; itr != ptr; itr = itr->down) {
        // Choose one row with 1, on the chosen column
        solution.push_back(itr->row);

        for (node *jtr = itr->right; jtr != itr; jtr = jtr->right) {
            dlx_cover(jtr->column); // delete all the columns that has 1 one
        }					// the chosen row
        if (dlx_search(head, k + 1)) return 1;
        else {
            solution.pop_back();
            for (node *jtr = itr->left; jtr != itr; jtr = jtr->left)
                dlx_uncover(jtr->column);
        } // If answer hasn't been found
    }
    dlx_uncover(ptr);
    return 0;
}

vector<int> dlx_solve(vector<vector<int>> matrix) {
    int n = matrix[0].size();
    column.resize(n);
    node head;

    head.right = &column[0];
    head.left = &column[n - 1];
    // Initialize header node

    for (int i = 0; i < n; ++i) {
        column[i].size = 0;
        column[i].up = &column[i];
        column[i].down = &column[i];
        column[i].left = (i == 0) ? &head : &column[i - 1];
        column[i].right = (i == n - 1) ? &head : &column[i + 1];
    } // Initialize column nodes

    for (int i = 0; i < matrix.size(); ++i) {
        node *last = nullptr;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j]) {
                node *now = new node;
                now->row = i;
                now->column = &column[j];
                now->up = column[j].up;
                now->down = &column[j];
                // Create new node for 1

                if (last) {
                    now->left = last;
                    now->right = last->right;
                    last->right->left = now;
                    last->right = now;
                } // Connect with other nodes on the same row

                else {
                    now->left = now;
                    now->right = now;
                } // If it is only node on the same row

                column[j].up->down = now;
                column[j].up = now;
                // Connect with other nodes on the same column
                column[j].size++;
                last = now;
                nodes.push_back(now);
            }
        }
    }

    dlx_search(&head, 0);

    return solution;
};

// Note that to interpret the solution, mapping function may required to understand the solution

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    while(cin >> s){

        column.clear();
        nodes.clear();
        solution.clear();
        mapping.clear();

        if(s == "end") break;

        vector<vector<int>> matrix;
        int solved[9][9] = {0};
        int mx_size = 0;

        int idx = 0;
        for (int i =0; i<9; i++){
            for(int j =0; j<9; j++){
                char ch = s[idx++];
                if(ch == '.') ch ='0';
                solved[i][j] = ch -'0';
            }
        }
                
        
    
        for (int cnt = 0; cnt < 81; cnt++) {
            int row = cnt / 9;
            int col = cnt % 9;
            int block = col / 3 + 3 * (row / 3);
            if(solved[row][col]!= 0){
            int num = solved[row][col]-1;
            matrix.push_back(vector<int>(324, 0));
                    mx_size++;
                    matrix[mx_size - 1][num + row * 9] = 1;
                    matrix[mx_size - 1][81+num + col * 9] = 1;
                    matrix[mx_size - 1][162+num + block * 9] = 1;
            matrix[mx_size - 1][243 + cnt] = 1;
            mapping.push_back(make_tuple(num+1,row,col));
            
        } // If that cell is already filled, only add one row.
        else {
            for (int num = 0; num < 9; num++) {
                matrix.push_back(vector<int>(324, 0));
                mx_size++;
                matrix[mx_size - 1][num + row * 9] = 1;
                matrix[mx_size - 1][81+num + col * 9] = 1;
                matrix[mx_size - 1][162+num + block * 9] = 1;
            matrix[mx_size - 1][243 + cnt] = 1;
            mapping.push_back(make_tuple(num+1,row,col));
            }
        } // Else, we should count all the possible number for that cell
            
        }


        for (int i : dlx_solve(matrix)){
        int num = get<0>(mapping[i]);
        solved[get<1>(mapping[i])][get<2>(mapping[i])] = num;
        }
    
        for (int i =0; i < 9; i++){
            for (int j = 0; j < 9 ; j++)
                cout << solved[i][j];
        }
        cout << "\n";
    }
} // Knuth-X, Dancing Link, Backtracking

/*
How I interpreted sudoku board
cols     0 1 2 3 4 5 6 7 8
rows   0 0 0 0 1 1 1 2 2 2
       1 0 0 0 1 1 1 2 2 2
	   2 0 0 0 1 1 1 2 2 2
	   3 3 3 3 4 4 4 5 5 5
	   4 3 3 3 4 4 4 5 5 5
	   5 3 3 3 4 4 4 5 5 5
	   6 6 6 6 7 7 7 8 8 8
	   7 6 6 6 7 7 7 8 8 8
	   8 6 6 6 7 7 7 8 8 8

cols   0 1 2 3 4 5 6 7 8
rows 0 0 1 2 3 4 5 6 7 8
	   ...

*/