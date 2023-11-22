#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q;
    cin >> N >> Q;
    
    ll div = sqrt(N);
    vector<vector<ll>> v;
    vector<pair<ll,ll>> q;
    
    int idx = 0;
    for(int i =0; i<N; ++i){
        ll tmp;
        cin >> tmp;
        if(idx == 0){
            v.push_back(vector<ll>());
            q.push_back({INT_MAX, INT_MIN});
        }
        v.back().push_back(tmp);
        q.back().first = min(q.back().first, tmp);
        q.back().second = max(q.back().second, tmp);
        
        ++idx;
        idx %= div;
    }
    
    while(Q--){
        ll l, r;
        cin >> l >> r;
        --l;
        --r;
        
        ll ans1 = INT_MAX, ans2 = INT_MIN;
        ll beg = 0, end = div-1;
        for(int i =0; i<v.size(); ++i){
            //cout << i<<" "<<v[i].size()<<"\n";
            if(l <= beg && end <= r){
                ans1 = min(ans1, q[i].first);
                ans2 = max(ans2, q[i].second);
                //cout << "INCLUDED"<<"\n";
            }
            else if (beg <= l && r <= end){
                int idx = beg-1;
                for(auto itr : v[i]){
                    ++idx;
                    if(idx < l || idx > r) continue;
                    ans1 = min(ans1, itr);
                    ans2 = max(ans2, itr);
                }
                //cout << "BETWEEN"<<"\n";
            }
            else if (beg < l && l <= end && end < r){
                int idx = beg-1;
                for(auto itr : v[i]){
                    ++idx;
                    if(idx < l) continue;
                    ans1 = min(ans1, itr);
                    ans2 = max(ans2, itr);
                }
                //cout << "EXCLUDED"<<"\n";
            }
            else if (l < beg && beg <= r&& r < end){
                idx = beg-1;
                for(auto itr : v[i]){
                    ++idx;
                    if(idx > r) continue;
                    ans1 = min(ans1, itr);
                    ans2 = max(ans2, itr);
                }
                //cout << "EXCLUDED"<<"\n";
            }
            beg += div; end += div;
            end = min(end, N-1);
        }
        cout << ans1 <<" "<<ans2<<"\n";
        
    }
    
    return 0;
}
/*

Sqrt decomposition

*/
