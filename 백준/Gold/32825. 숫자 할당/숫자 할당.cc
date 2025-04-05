#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> fulfill(8);

vector<bool> taken(14, false);
vector<ll> which(6);
ll depth(ll idx, ll last){
    if(idx == 6){
        ll ret = 0;
        do {
        ll l = fulfill[0] - (which[0]+which[3] + which[5]);
        ll d = fulfill[4] - (which[0]+which[1]+which[2]);
        ll h = fulfill[3] - d;
        ll m = fulfill[7] - l;
        ll j = fulfill[1] - (which[1]+which[4] +m);
        ll g = fulfill[5] - (which[3] + which[4] + h);
        ll k = fulfill[2] - (which[2] + g);
        ll k2 = fulfill[6] - (which[5] +j);
        if(k != k2) continue;

        if(l <= 0) continue;
        if(d <= 0) continue;
        if(h <= 0) continue;
        if(m <= 0) continue;
        if(j <= 0) continue;
        if(g <= 0) continue;
        if(k <= 0) continue;
        if(k2 <= 0) continue;        
        //cout << d <<" "<< h <<" "<<k<<" "<<m <<" "<<l<<"\n";
        if(taken[d]) continue;
        taken[d] = true;
        if(taken[h]) {
            taken[d] = false;
            continue;
        }
        taken[h] = true;
        if(taken[k]) {
            taken[d] = taken[h] = false;
            continue;
        }
        taken[k] = true;
        if(taken[m]) {
            taken[d] = taken[h] = taken[k] =false;
            continue;
        }
        taken[m] = true;
        if(taken[l]){
            taken[d] = taken[h] = taken[k] =taken[m] = false;
            continue;
        } 
        taken[l] = true;
        if(taken[g]){
            taken[l] = taken[d] = taken[h] = taken[k] =taken[m] = false;
            continue;
        } 
        taken[g] = true;
        if(taken[j]){
            taken[g] = taken[l] = taken[d] = taken[h] = taken[k] =taken[m] = false;
            continue;
        }

        taken[g] = taken[l] = taken[d] = taken[h] = taken[k] =taken[m] = false;
        
        ++ret;
        }while(next_permutation(which.begin(), which.end()));
        return ret;
    }    
    ll ret = 0;
    for(int i = last+1; i<=13; ++i){
        if(!taken[i]){
            taken[i] = true;
            which[idx] = i;
            ret += depth(idx+1, i);
            taken[i] = false;
        }
    }
    //cout << idx <<" "<<ret<<"\n";
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    for(int i =0; i<8; ++i)
        cin >> fulfill[i];


    for(int i =0; i<8; ++i){
        ll sum = 0;
        if(i<4){
            for(int j = 4; j<8; ++j)
                sum += fulfill[j];
            for(int j = 0; j<4; ++j){
                if(i==j) continue;
                sum -= fulfill[j];
            }
        }
        else{
            for(int j = 0; j<4; ++j)
                sum += fulfill[j];
            for(int j = 4; j<8; ++j){
                if(i==j) continue;
                sum -= fulfill[j];
            }
        }
        if(sum != fulfill[i]){
            cout << 0;
            return 0;
        }
    }
    ll ans = depth(0,0);
    

    // ll ans = 0;
    // do{
    //     if(v[0]+v[1]+v[2]+v[3] != fulfill[4]) continue;
    //     if(v[4]+v[5]+v[6]+v[7] != fulfill[5]) continue;
    //     if(v[8] + v[9]+v[10] != fulfill[6]) continue;
    //     if(v[12]+v[11] != fulfill[7]) continue;
    //     if(v[0]+v[4]+v[8]+v[11] != fulfill[0]) continue;
    //     if(v[1]+v[5]+v[9]+v[12] != fulfill[1]) continue;
    //     if(v[2]+v[6]+v[10] != fulfill[2]) continue;
    //     if(v[3]+v[7] != fulfill[3]) continue;
    //     ++ans;

    // }while(next_permutation(v.begin(), v.end()));

    // for(int i = )
    cout << ans;



    return 0;
}
/*
    A, B, C, D -> independent


*/