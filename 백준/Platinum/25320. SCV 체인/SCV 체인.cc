#include<bits/stdc++.h>
#define ll long long

using namespace std;

// 38분 23초 걸림

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    set<ll> s;
    vector<pair<ll,ll>> v(2*N+1);
    vector<ll> v2(M,0);
    vector<bool> occupied_A(M, false);

    for(int i =1; i<=2*N; i++)
        s.insert(i);

    for(int i =0; i<M ; i++){
        char who;
        string block;
        ll tmp;
        cin >> who >> block >> tmp;
        if(who == 'A') occupied_A[i] = true;
        v[tmp] = {i+1, tmp};
        s.erase(tmp); 
        v2[i] = tmp;   
    }
    bool flag = true;
    for(int i =0; i<M-1; i++){
        if(occupied_A[i] == occupied_A[i+1]){
            auto itr = s.lower_bound(v2[i]+1);
            if(itr == s.end()){
                flag = false;
                break;
            }
            v[*itr] = {i+1, *itr};
            s.erase(itr);
        }
    }

    if(s.find(1) != s.end()) flag = false;

    if(!flag){
        cout <<"NO";
        return 0;
    }

    ll bef = -1; // chain 할거면 두번씩은 해야 하므로
    while (!s.empty()){
        auto itr2 = s.begin();
        ll itr = *itr2;
        s.erase(itr2);
        if(bef == -1){
            if(s.empty()){
                if(v2[M-1] < itr){
                    v[itr] = {M, itr};
                    continue;
                }
            }
            bef = v[itr-1].first;
            v[itr] = {bef, itr};
        }
        else {

            v[itr] = {bef, itr};
            bef = -1;
        }
    }

    // for(int i =1; i<=2*N; i++)
    //     cout << v[i].first <<" "<<v[i].second<<"\n";

    if(bef != -1){
        cout << "NO";
        return 0;
    }

    cout <<"YES\n";
    sort(v.begin(), v.end());
    bool A = true;
    for(int i =1; i<=2*N; i++){
        if(A){
            cout <<"A";
        }
        else cout <<"B";
        if(i == 0) cout <<" BLOCK ";
        else if(v[i].first == v[i-1].first) cout << " CHAIN ";
        else cout <<" BLOCK ";
        cout << v[i].second<<"\n";
        A = !A;
    }



    return 0;
}
/*

block 사이를 일단 채울 수 있는지 확인 
-> 이후에 남은 얘들을 잘 박을 수 있는지 확인

Constructive + Sort / Greedy + Data Structure(Set)

*/