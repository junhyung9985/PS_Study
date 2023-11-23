#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll p[200001];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

bool u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return false;
    p[pb] = pa;
    return true;
}
 
double ret(ll x, ll y, ll x2, ll y2){
    return sqrt(1.0*(x-x2)*(x-x2)+(y-y2)*(y-y2)*1.0);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        
    ll N,M;
    double ans = 0.0;
    cin >> N >> M;
    
    vector<pair<ll,ll>> v(N);
    vector<tuple<double,ll,ll>> roads;
    
    for(int i = 1; i<=N; ++i)
        p[i] = i;
    
    
    for(int i = 0; i<N; ++i){
        ll a,b;
        cin >> a >> b;
        v[i] = {a,b};
    }
    
    for(int i =0; i<M; ++i){
        ll a, b;
        cin >> a >> b;
        u(a-1,b-1);
    }

    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            roads.push_back({ret(v[i].first, v[i].second, v[j].first, v[j].second), i, j});
        }
    }
    
    sort(roads.begin(), roads.end());

    for(auto itr : roads){
        double w,a,b;
        tie(w,a,b) = itr;
        if(u(a,b)){
            //cout << a <<" "<<b <<" : "<<ans<<"\n";
            ans += w;
        }
    }
    ans *= 100;
    ans = round(ans);
    ans /= 100;
    
    cout.precision(2);
    cout<<fixed;
    cout << ans;


    return 0;
} // MST