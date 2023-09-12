#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll N, M, R;
ll m[101][101];
ll f[101];
ll path[100002];
ll prefix_sum[100002];
vector<pair<ll, ll>> v;

bool cmp(pair<ll,ll> a, pair<ll, ll> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
    
}

ll can(ll start, ll mid){
    ll ret = prefix_sum[N] + m[path[start]][path[mid+1]] - prefix_sum[mid+1] ;
    return ret;
}


void check(ll s){
    ll R_new = prefix_sum[s] + f[path[s]];
    //cout << s <<" "<<R_new<<" ";

    if(R_new > R) {
    //    cout<<"\n";
        return;
    }
    ll lo = s-1;
    ll hi = N;
    //cout << s <<" "<< R_new <<"\n";
    while(lo+1 < hi){
        ll mid = (lo+hi)/2;
        ll ret = can(s, mid);
        //cout << mid <<" "<<ret+R_new<<"\n";
        if(ret+R_new > R) lo = mid;
        else hi = mid;
    }
    //cout <<hi<<"\n";
    v.push_back({hi-s,R_new+can(s, hi) });
    //cout << v[v.size()-1].first <<" "<<v[v.size()-1].second <<"\n\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> R;
    memset(m, 0, sizeof(m));
    for(int i =1; i<=M; i++){
        for(int j =1; j<=M; j++){
            cin >> m[i][j];
        }
    }
    
    
    
    for(int i =1; i<=M; i++){
        for(int j =1; j<=M; j++){
            for(int k =1; k<=M; k++){
                m[j][k] = min(m[j][i]+m[i][k], m[j][k]);
            }
        }
    }

    
    f[0] = 0;
    for(int i =1; i<=M; i++)
        cin >> f[i];
    
    path[0] = 1;
    prefix_sum[0] = 0;
    for(int i =1; i<=N; i++){
        cin >> path[i];
        prefix_sum[i] = m[path[i-1]][path[i]]+prefix_sum[i-1];
    }
    path[N+1] = 0;
    prefix_sum[N+1] = prefix_sum[N];
    for(int i =1 ; i<=N; i++){
        check(i);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    // for(int i =0; i<v.size(); i++)
    //     cout << v[i].first <<" "<<v[i].second <<"\n";
    if(v.size() == 0){
        cout << -1;
    }
    else cout << v[0].first <<" "<<v[0].second <<"\n";
    
    
    
    // ai에서 쉴때 K-fi계산 및 아래와 같은 계산
        // k까지 쉴때 dik + dkk+1 ... <= dii+1 + .. dk-1k + dkk+1 ... 를 만족함
        // 이분탐색으로 logN 가능
            
    
    return 0;
}
/*
G번

M - 구역 -> i,j구역 사이에는 dij만큼의 연료가 필요함
N의 비행경로 아마 중복해서 다니는듯?
한번은 fi 써야함

포함되지 않는 구역도 경유 가능



*/