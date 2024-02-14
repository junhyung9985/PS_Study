
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> p(100'001);
vector<ll> sz(100'001);

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

bool u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return false;
    if(sz[pa] < sz[pb]) swap(a,b);
    p[pb] = pa;
    sz[pa] += sz[pb];
    sz[pb] = 0;
    return true;
}

// map<pair<ll,ll>, ll> m;

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    if(N <= 2){
        cout << -1;
        return 0;
    }
    
    iota(p.begin(), p.end(), 0);
    fill(sz.begin(), sz.end(), 1);

    vector<pair<ll,ll>> E(M+1);
    vector<ll> hubo;
    for(int i =1; i<=M; ++i){
        ll a,b;
        cin >> a >> b;
        E[i] = {a,b};
        if(u(a,b)){
            hubo.push_back(i); // 컴포넌트 한 개면 leaf node 찾아야 하므로...
        } // 일단 컴포넌트 몇 개인지 확인.
    }
    
    ll which = 0; // 0 번째 노드는 아무도 안 쓰므로...
    
    for(int i = 1; i<=N; ++i){
        if(f(i) != f(1)){
            if(f(i) == f(which)) continue;
            else if(which == 0) which = f(i);
            else{
                cout << -1;
                return 0;
            } // 컴포넌트 세 개 이상 -> 불가능.
        } // 컴포넌트 두 개 이상
    }
    
    if(which == 0){
        
        vector<ll> leaf(N+1);
        for(auto itr : hubo){
            ll a, b;
            tie(a,b) = E[itr];
            ++leaf[a];
            ++leaf[b];
        }
        ll pivot = 0;
        for(int i =1; i<=N; ++i)
            if(leaf[i] == 1){
                pivot = i;
                break;
            }
        
        cout << 1 <<" "<<N-1 <<"\n";
        
        cout << pivot <<"\n";
        cout <<"\n";  
        
        for(int i = 1; i<=N; ++i)
            if(i != pivot) cout << i<<" ";
        cout<<"\n";

        iota(p.begin(), p.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        
        for(int i =1; i<=M; ++i){
            ll a,b;
            tie(a,b) = E[i];
            if(a == pivot || b == pivot) continue;
            if(u(a,b)){
                cout << i <<" ";
            }
        }
        cout<<"\n";
        
    } // 하나로 통합된 상태라면... 리프 노드와 나머지로 분할이 가능함.
    
    else{
        
        ll pwhich = f(which), p1 = f(1);
        ll which_sz = sz[pwhich];
        ll other_sz = sz[p1];

        if(which_sz == other_sz){
            cout << -1;
            return 0;
        } // 사이즈가 같은 경우
        
        set<ll> v_which;
        set<ll> v_1;
        vector<ll> e_which;
        vector<ll> e_1;
        
        for(int i =1; i<=N; ++i){
            if(f(i) == pwhich) v_which.insert(i);
            if(f(i) == p1) v_1.insert(i);
        }

        iota(p.begin(), p.end(), 0);
        fill(sz.begin(), sz.end(), 1);

        for(int i =1; i<=M; ++i){
            ll a, b;
            tie(a, b) = E[i];
            if(u(a,b)){
                if(v_which.find(a) != v_which.end()){
                    e_which.push_back(i);
                }
                else e_1.push_back(i);
            }
        }

        cout << other_sz <<" "<<which_sz<<"\n";
        for(auto itr : v_1) cout << itr <<" ";
        cout<<"\n";
        for(auto itr : e_1) cout << itr <<" ";
        cout<<"\n";
        for(auto itr : v_which) cout << itr <<" ";
        cout<<"\n";
        for(auto itr : e_which) cout << itr <<" ";
        cout<<"\n";
        
        
    } // 아니라면 두 개의 컴포넌트로 이루어져 있으므로, 각 컴포넌트 별로의 트리를 찾아야함.
    // 즉, 이미 트리의 노드들은 이미 구성된 상태이므로 크기 확인한 후에 트리를 찾아줘야함.
    
    
    return 0;
} // Constructive, Implementation, DSU