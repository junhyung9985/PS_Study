#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    cin >> N;
    vector<pair<ll,ll>> act(N); // N 
    vector<ll> act_w(N+1); // prefix sum of width
    for(int i =0; i<N; i++){
        ll a, b;
        cin >> a >> b;
        act[i] = {a,b};
        act_w[i] = a;
        if(i > 0) act_w[i]+=act_w[i-1];
    }
    act_w[N] = INT_MAX; // INT_MAX -> 벽

    cin >> M; 
    vector<pair<ll,ll>> will(M); // M bl
    vector<ll> will_act(M); // M block -> N block
    for(int i =0; i<M; i++){
        ll a, b;
        cin >> a >> b;
        will[i] = {a,b};
    }
    int idx = 0;
    ll width_sum = 0 ;
    for(int i =0; i<M; i++){
        ll width, height;
        ll minn = INT_MAX;
        tie(width, height) = will[i];
        width_sum += width;
        int first = 0;
        bool flag = false;
        while(width_sum >= act_w[idx]){
            first ++;
            if(act[idx].second == height){
                will_act[i] = idx+1;
            }
            if(act_w[idx] == width_sum){
                flag = true;
            }
            minn = min(minn, act[idx].second);
            if(act[idx].second != height){
                bool flag = false;
                if(i>0 && first == 1){
                    flag = flag || (will[i-1].second > height);
                }
                if(i<M-1&& idx < N-1){
                    if(act_w[idx+1] > width_sum)
                    flag = flag || (will[i+1].second > height);
                }
                if(flag){
                    cout << -1;
                    return 0;
                }
            }
            idx++;
        }
        if((!flag)||minn != height){
            cout << -1;
            return 0;
        }
    }

    priority_queue<pair<ll, ll>> pq;
    vector<bool> visited(M);
    for(int i =0; i<M; i++){
        pq.push({will[i].second , i});
    }
    vector<ll> ans;
    while(!pq.empty()){
        ll height, node;
        tie(height, node) = pq.top();
        pq.pop();
        if(visited[node]) continue;
        ans.push_back(node);
        visited[node] = true;
        ll curr_height = height;
        for(int i =node-1; i>-1; i--){
            if(visited[i]) break;
            if(curr_height < will[i].second ) break;
            visited[i] = true;
            curr_height = min(curr_height, will[i].second);
        }
        curr_height = height;
        for(int i =node+1; i<M; i++){
            if(visited[i]) break;
            if(curr_height < will[i].second ) break;
            visited[i] = true;
            curr_height = min(curr_height, will[i].second);
        }
        
    }
    cout << ans.size()<<"\n";
    for(int i : ans){
        cout << will_act[i] <<" ";
    }
    


}