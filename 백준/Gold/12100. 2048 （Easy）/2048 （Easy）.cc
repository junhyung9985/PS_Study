#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS


ll find_max(vector<vector<ll>> board, ll N){
    ll maxx = 0;
    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            maxx = max(maxx, board[i][j]);
        }
    }
    return maxx;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    deque<pair<vector<vector<ll>>, ll>> q;

    ll N;
    cin >> N;
    vector<vector<ll>> init(N, vector<ll>(N));

    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            cin >> init[i][j];
        }
    }
    ll ans = 0;
    q.push_back({init, 0});
    while(!q.empty()){
        vector<vector<ll>> c;
        ll cnt;
        tie(c, cnt) = q.front();
        q.pop_front();
        // cout << "------"<<cnt<<"------"<<"\n";
        // for(int i = 0; i<N; ++i){
        //     for(int j=0; j<N; ++j){
        //         cout << c[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";

        ans = max(ans, find_max(c, N));
        if(cnt == 5) continue;
        
        vector<vector<ll>> n1(N, vector<ll>(N));
        vector<vector<ll>> n2(N, vector<ll>(N));
        vector<vector<ll>> n3(N, vector<ll>(N));
        vector<vector<ll>> n4(N, vector<ll>(N));
        vector<vector<bool>> c1(N, vector<bool>(N, false));
        vector<vector<bool>> c2(N, vector<bool>(N, false));
        vector<vector<bool>> c3(N, vector<bool>(N, false));
        vector<vector<bool>> c4(N, vector<bool>(N, false));
        
        // n1 -> push_right, n2 -> push_left, n3 -> push_down, n4 -> push_up

        for(int i =0; i<N; ++i)
            for(int j=0; j<N; ++j)
                n1[i][j] = n2[i][j] = n3[i][j] = n4[i][j] = c[i][j];

        for(int k =0; k<N; ++k){
            for(int i =0; i<N; ++i){
                for(int j=1; j<N ; ++j){
                    if(n1[i][j] == 0 && n1[i][j-1] != 0){
                        n1[i][j] = n1[i][j-1];
                        n1[i][j-1] = 0;
                    }
                }
            }
        } // push to the right until there is no more zeros between numbers

        for(int i=0; i<N; ++i){
            for(int j =N-1; j>0; --j){
                if(n1[i][j] == n1[i][j-1] && n1[i][j] != 0){
                    n1[i][j] += n1[i][j-1];
                    n1[i][j-1] = 0;
                }
            }
        } // from right to left, check if there are two numbers equal

        for(int k =0; k<N; ++k){
            for(int i =0; i<N; ++i){
                for(int j=1; j<N ; ++j){
                    if(n1[i][j] == 0 && n1[i][j-1] != 0){
                        n1[i][j] = n1[i][j-1];
                        n1[i][j-1] = 0;
                    }
                }
            }
        } // push to the right until there is no more zeros between numbers

        q.push_back({n1, cnt+1});

        for(int k =0; k<N; ++k){
            for(int i =0; i<N; ++i){
                for(int j=N-2; j>-1 ; --j){
                    if(n2[i][j] == 0 && n2[i][j+1] != 0){
                        n2[i][j] = n2[i][j+1];
                        n2[i][j+1] = 0;
                    }
                }
            }
        }

        for(int i =0; i<N; ++i){
            for(int j=0; j<N-1 ; ++j){
                if(n2[i][j] == n2[i][j+1] && n2[i][j+1] != 0){
                    n2[i][j] += n2[i][j+1];
                    n2[i][j+1] = 0;
                }
            }
        }

        for(int k =0; k<N; ++k){
            for(int i =0; i<N; ++i){
                for(int j=N-2; j>-1 ; --j){
                    if(n2[i][j] == 0 && n2[i][j+1] != 0){
                        n2[i][j] = n2[i][j+1];
                        n2[i][j+1] = 0;
                    }
                }
            }
        }

        q.push_back({n2, cnt+1});

        for(int k =0; k<N; ++k){
            for(int i =0; i<N; ++i){
                for(int j=1; j<N ; ++j){
                    if(n3[j][i] == 0 && n3[j-1][i] != 0){
                        n3[j][i] = n3[j-1][i];
                        n3[j-1][i] = 0;
                    }
                }
            }
        }
        for(int i =0; i<N; ++i){
            for(int j=N-1; j>0 ; --j){
                if(n3[j][i] == n3[j-1][i] && n3[j][i] != 0){
                    n3[j][i] += n3[j-1][i];
                    n3[j-1][i] = 0;
                }
            }
        }

        for(int k =0; k<N; ++k){
            for(int i =0; i<N; ++i){
                for(int j=1; j<N ; ++j){
                    if(n3[j-1][i] != 0 && n3[j][i] == 0){
                        n3[j][i] = n3[j-1][i];
                        n3[j-1][i] = 0;
                    }
                }
            }
        }
        q.push_back({n3, cnt+1});

        for(int k =0; k<N; ++k){
            for(int i =0; i<N; ++i){
                for(int j=N-2; j>-1 ; --j){
                    if(n4[j][i] == 0 && n4[j+1][i] != 0){
                        n4[j][i] = n4[j+1][i];
                        n4[j+1][i] = 0;
                    }                    
                }
            }
        }

        for(int i =0; i<N; ++i){
            for(int j=0; j<N-1 ; ++j){
                if(n4[j][i] == n4[j+1][i] && n4[j+1][i] != 0){
                    n4[j][i] += n4[j+1][i];
                    n4[j+1][i] = 0;
                }                    
            }
        }

        for(int k =0; k<N; ++k){
            for(int i =0; i<N; ++i){
                for(int j=N-2; j>-1 ; --j){
                    if(n4[j][i] == 0 && n4[j+1][i] != 0){
                        n4[j][i] = n4[j+1][i];
                        n4[j+1][i] = 0;
                    }                    
                }
            }
        }

        q.push_back({n4, cnt+1});

    }

    cout << ans;

    return 0;
}// 밀기 : O(N^3)
// 전체 경우의 수 : (최댓값 찾는데 O(N^2) + 미는데, O(N^3)) * (미는 조합, 4^5) = 1024 * 20^3 = 8000*1024 = 8,192,000
// 충분히 다 찾을 수 있다!

// Simulation, Implementation