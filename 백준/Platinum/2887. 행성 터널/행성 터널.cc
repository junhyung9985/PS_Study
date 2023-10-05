#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll p[100001];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

bool u(ll a, ll b){
    ll pa = f(a);
    ll pb = f(b);
    if(pa == pb) return false;
    p[pb] = pa;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<pair<ll,ll>> x(N+1);
    vector<pair<ll,ll>> y(N+1);
    vector<pair<ll,ll>> z(N+1);
    
    deque<tuple<ll,ll,ll>> cost;
    
    for(int i =0; i<N; ++i){
        p[i] = i;
        x[i].second = y[i].second = z[i].second = i;
        cin >> x[i].first >> y[i].first >> z[i].first;
    }    
    
    x[N].first = y[N].first = z[N].first = INT_MAX;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    
    for(int i =0; i<N-1; ++i){
        cost.push_back({x[i+1].first - x[i].first, x[i+1].second, x[i].second});
        cost.push_back({y[i+1].first - y[i].first, y[i+1].second, y[i].second});
        cost.push_back({z[i+1].first - z[i].first, z[i+1].second, z[i].second});
    }
    sort(cost.begin(), cost.end());
    
    ll ans = 0;
    while(!cost.empty()){
        ll c, a, b;
        tie(c,a,b) =cost.front();
        cost.pop_front();
        if(u(a,b)){
            ans += c;
        }        
    }
    cout << ans;
    
    return 0;
} 
// Greedy, Sorting, MST
// O(NlogN)