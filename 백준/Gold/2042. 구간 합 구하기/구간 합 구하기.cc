#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> v;
vector<ll> q;
    

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q, K;
    cin >> N >> Q >> K;
    Q+=K;
    ll div = sqrt(N);
    
    int idx = 0;
    for(int i =0; i<N; ++i){
        ll tmp;
        cin >> tmp;
        if(idx == 0){
            v.push_back(vector<ll>());
            q.push_back(0);
        }
        v.back().push_back(tmp);
        q.back() += tmp;
        ++idx;
        idx %= div;
    }
    
    while(Q--){
        ll query;
        cin >> query;
        if(query==1){
            ll idx, val;
            cin >> idx >> val;
            --idx;
            ll which = idx / div;
            ll idxx = idx % div;
            q[which] -= v[which][idxx];
            v[which][idxx] = val;
            q[which] += val;
        }
        if(query == 2){
            ll l, r;
            cin >> l >> r;
            --l; --r;
            ll ans = 0;
            ll beg = 0, end = div-1;
            for(int i =0; i<v.size(); ++i){
                if(l <= beg && end <= r){
                    ans += q[i];
                }
                else if (beg <= l && r <= end){
                    int idx = beg-1;
                    for(auto itr : v[i]){
                        ++idx;
                        if(idx < l || idx > r) continue;
                        ans += itr;
                    }
                }
                else if (beg < l && l <= end && end < r){
                    int idx = beg-1;
                    for(auto itr : v[i]){
                        ++idx;
                        if(idx < l) continue;
                        ans += itr;
                    }
                }
                else if (l < beg && beg <= r&& r < end){
                    int idx = beg-1;
                    for(auto itr : v[i]){
                        ++idx;
                        if(idx > r) continue;
                        ans += itr;
                    }
                }
                beg += div; end += div;
                end = min(end, N-1);
            }
            cout << ans <<"\n";
        }
    }
    
    return 0;
}
/*

Sqrt decomposition

*/
