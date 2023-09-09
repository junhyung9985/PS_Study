#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<pair<ll, ll>> v;

int ccw(pair<ll,ll> a, pair<ll, ll> b , pair<ll,ll> c){
    ll tmp = (b.first - a.first) * (c.second - a.second);
    tmp -= (c.first - a.first) * (b.second - a.second);
    if(tmp > 0) return 1;
    else if (tmp == 0) return 0;
    else return -1;
    
}

bool cmp (pair<ll, ll> a, pair<ll, ll> b){
    return a.first == b.first && a.second == b.second;
}

bool larger(pair<ll, ll> a , pair<ll, ll> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}
bool same_dir(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
    pair<ll,ll> v1 = {b.first- a.first, b.second - a.second};
    pair<ll,ll> v2 = {c.first- a.first, c.second - a.second};
    
    ll dot_p = v1.first*v2.first + v2.second *v1.second;
    if(dot_p > 0) return true;
    else return false;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(16);
    for(int i =0; i<4; i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
   if(larger(v[0], v[1])){
        swap(v[0], v[1]);
    }
    if(larger(v[2], v[3])){
        swap(v[2], v[3]);
    }
    
    ll c1 = ccw(v[0], v[1], v[2]) * ccw(v[0], v[1], v[3]);
    ll c2 = ccw(v[2], v[3], v[0]) * ccw(v[2], v[3], v[1]);
    if(c1 > 0 || c2 > 0){
        cout << "0";
        return 0;
    }
    
    vector<pair<ll, ll>> ans;
    if(c1 == 0 && c2 == 0){

       if(larger(v[2], v[1]) || larger(v[0], v[3])){
            cout << "0";
            return 0;
        } // 아에 안 만남
    }
    cout <<"1\n";
    
    ll x1, y1;
    ll x2, y2;
    ll x3, y3;
    ll x4, y4;
    tie(x1, y1) = v[0];
    tie(x2, y2) = v[1];
    tie(x3, y3) = v[2];
    tie(x4, y4) = v[3];
    
    double new_x = (x1*y2 - x2*y1) *(x3-x4) - (x1-x2)*(x3*y4-y3*x4);
    double new_y = (x1*y2 - x2*y1) *(y3-y4) - (y1-y2)*(x3*y4-y3*x4);
    double p = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
    
    if(p == 0){
        if(cmp(v[1], v[2]) && v[0] <= v[2] ) cout << x2 <<" "<<y2;
        else if (cmp(v[0], v[3]) && v[2] <= v[0]) cout << x1 <<" "<<y1;
        return 0;
    }
    
    double x = new_x/ p;
    double y = new_y / p;
    cout << x <<" "<< y;
    
    
    return 0;
}
/*

두 직선의 교점 공식 : https://cocoon1787.tistory.com/489


*/