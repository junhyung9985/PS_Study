#include <bits/stdc++.h>
#define ll long long
#define INF 9999999
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

class DLXSolver {
private:
	vector<node> column = {};
	vector<node *> nodes = {};
	vector<int> solution = {};

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

      // cout << "SOL : ";
      // for(int i : solution)
      //   cout << i << " ";
      // cout << endl;

			for (node *jtr = itr->right; jtr != itr; jtr = jtr->right) {
				dlx_cover(jtr->column); // delete all the columns that has 1 one
      }					// the chosen row
			if (this->dlx_search(head, k + 1)) return 1;
			else {
				solution.pop_back();
				for (node *jtr = itr->left; jtr != itr; jtr = jtr->left)
					dlx_uncover(jtr->column);
			} // If answer hasn't been found
		}
		dlx_uncover(ptr);
		return 0;
	}

public:
	DLXSolver(){};

	void clear() {
		while (!column.empty())
			column.pop_back();
		while (!solution.empty())
			solution.pop_back();
	};

	vector<int> dlx_solve(vector<vector<int>> matrix) {
		this->clear();
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
    int cnt = 0;
		dlx_search(&head, 0);

		return solution;
	};
};

// Note that to interpret the solution, mapping function may required to understand the solution

int main() {
    bool check[9][9];
    memset(check, 0, sizeof(check));
	vector<vector<int>> matrix;
	vector<tuple<int,int,int>> v;
	
	for(int i =0; i<81; i++){
	    int y,x,n;
	    cin >> y >> x >> n;
	    y--; x--;
	    if(check[y][x]) break;
	    check[y][x] = true;
	    v.push_back({y,x,n});
	    vector<int> r (324,0);
	    r[y*9+x] = 1;
	    r[81+x*9+n-1] = 1;
	    r[162+y*9+n-1] = 1;
	    r[243+((y/3)*3+x/3)*9+n-1] = 1;
	    matrix.push_back(r);
	}
	// Initialize Matrix
	
	for(int y =0;y <9; y++){
	    for(int x =0; x<9; x++){
	        if(!check[y][x]){
	            for(int j = 1; j<=9; j++){
	            vector<int> r (324, 0);
                r[y*9+x] = 1;
	            r[81+x*9+j-1] = 1;
	            r[162+y*9+j-1] = 1;
	            r[243+((y/3)*3+x/3)*9+j-1] = 1;
	            matrix.push_back(r);
            
	            }
	        }
	    }
	} // Fill Leftover blocks
	
	ll ret = v.size();
    for(int i = v.size()-1; i>=0; i--){
	    DLXSolver s;
	    vector<int> ans = s.dlx_solve(matrix);
        if(ans.size()) break;
        ret = i;
        int y,x,n;
        tie(y,x,n) = v[i];
        for(int j =1; j<=9; j++){
            if(j==n) continue;
            vector<int> r (324, 0);
            r[y*9+x] = 1;
	        r[81+x*9+j-1] = 1;
	        r[162+y*9+j-1] = 1;
	        r[243+((y/3)*3+x/3)*9+j-1] = 1;
	        matrix.push_back(r);
        }
    }
    if(ret == 81) cout << -1;
    else cout << ret+1;
    
    return 0;
	
}