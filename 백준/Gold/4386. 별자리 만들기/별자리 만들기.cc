#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll p[101];

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

double distance(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1-x2) + (y1-y2) * (y1-y2));
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<pair<double, double>> v(N);
    vector<tuple<double,ll,ll>> dist;
    for(int i =0; i<N; ++i){
        cin >> v[i].first >> v[i].second;
        p[i] = i;
    }
    
    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            dist.push_back({distance(v[i].first, v[i].second, v[j].first, v[j].second), i, j});
        }
    }
    
    sort(dist.begin(), dist.end());
    double ans = 0.0;
    for(auto itr : dist){
        double d, a, b;
        tie(d,a,b) = itr;
        if(u(a,b)){
            ans += d;
        }
    }
    cout.precision(16);
    cout << fixed;
    cout << ans;
    return 0;
} // MST