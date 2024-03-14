#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll p[2'250'001];
ll sz[2'250'001];

ll dy[4] = {-1,1,0,0};
ll dx[4] = {0,0,1,-1};

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

void u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return;
    if(sz[pa] < sz[pb]) swap(pa, pb);
    sz[pa] += sz[pb];
    sz[pb] = 0;
    p[pb] = pa;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    vector<vector<char>> m(N, vector<char>(M));
    vector<vector<ll>> d(N, vector<ll>(M,-1));
    ll y1=-1,y2=-1,x1=-1,x2=-1;
    vector<list<pair<ll,ll>>> q(2);

    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            cin>>m[i][j];
            if(m[i][j] == 'L'){
                if(y1 == -1) y1 = i, x1=j;
                else y2=i, x2 = j;
            }
            if(m[i][j] != 'X'){
                d[i][j] = 0;
                q[0].push_back({i,j});
            }
            p[i*M+j] = i*M+j;
            sz[i*M+j] = 1;
        }
    }
    
    ll day = 0;
    while(1){
        while(!q[day%2].empty()){
            ll y, x;
            tie(y,x) = q[day%2].front();
            q[day%2].pop_front();
            for(int k = 0; k<4; ++k){
                ll ny = y + dy[k], nx = x + dx[k];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(d[ny][nx] == -1){
                    d[ny][nx] = day+1;
                    q[1-day%2].push_back({ny,nx});
                }
                else{
                    if(d[ny][nx] > day) continue;
                    else u(ny*M+nx, y*M+x);
                }
            }
        }
        ll p1 = f(y1*M+x1), p2 = f(y2*M+x2);
        //cout << day <<" : " <<y1*M+x1 <<" "<< y2*M+x2<<" "<<p1 <<" "<<p2<<"\n";

        if(p1 == p2){
            break;
        }
        ++day;
    }
    cout << day;
    
    return 0;
}
/*

BFS, DSU


*/