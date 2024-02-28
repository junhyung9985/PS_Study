#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll A,B,C;
    cin >> A >> B >> C;
    
    map<string, pair<ll,ll>> m;
    
    for(int i =0; i<A; ++i){
        string tmp;
        ll val;
        cin >> tmp >> val;
        m[tmp] = {0,val};
    }
    for(int i =0; i<B; ++i){
        string tmp;
        ll val;
        cin >> tmp >> val;
        m[tmp] = {1,val};
    }
    for(int i =0; i<C; ++i){
        string tmp;
        cin >> tmp;
        m[tmp] = {2,0};
    }
    
    ll Q;
    cin >> Q;
    
    ll cost = 0;
    bool flag = false;
    vector<pair<ll,ll>> order(Q);
    for(int i =0 ;i<Q; ++i){
        string tmp;
        cin >> tmp;
        order[i] = m[tmp];
    }
    
    sort(order.begin(), order.end());
    for(int i = 0; i<Q; ++i){
        if(order[i].first == 1){
            if(cost < 20'000){
                cout << "No";
                return 0;
            }
        }
        else if(order[i].first == 2){
            if(flag || cost < 50'000){
                cout << "No";
                return 0;
            }
            flag = true;
        }
        cost += order[i].second;
    }
    
    cout <<"Okay";
    
    return 0;
} // Hash_set, Sorting, Implementation
