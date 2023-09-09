#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed;
    cout.precision(3);

    ll N, W;
    cin >> W >> N;
    if(N == 0){
        cout << W*1.0/2.0<<" "<< 0<<"\n";
        return 0;
    }
    vector<pair<double,double>> v(N);
    vector<vector<double>> E(N, vector<double>(N, INT_MAX));
    for(int i =0; i<N ;i++){
        double a, b;
        cin >> a >> b;
        v[i] = {a,b};
    }

    sort(v.begin(), v.end());
    for(int i =0; i<N; i++){
        for(int j =i+1; j<N; j++){
            double x_d = (v[i].first-v[j].first)*1.0;
            double y_d = (v[i].second-v[j].second)*1.0;
            E[i][j] = sqrt(x_d*x_d+y_d*y_d);
            E[j][i] = E[i][j];
        }
    }

    priority_queue<tuple<double, ll, ll>> pq; // {largest, node, cost}
    vector<vector<double>> dist(2, vector<double>(N, INT_MAX));
    vector<pair<double,double>> halfs(N);
    for(int i =0; i<N; i++){
        pq.push({-v[i].first, i, 0});
        pq.push({-v[i].first/2.0, i, 1});
        dist[0][i] = v[i].first;
        dist[1][i] = v[i].first/2.0;
        halfs[i] = {-1,i};
    }
    

    while(!pq.empty()){
        double largest, node, cost;
        tie(largest, node,cost) = pq.top();
        pq.pop();
        largest *= -1.0;
        if(largest > dist[cost][node]) continue;
        dist[cost][node] = largest;
        //cout << node <<" "<<largest <<" "<<cost <<" "<< halfs[node].first <<" "<<halfs[node].second<<"\n";
        for(int i  = node+1; i<N; i++){
            if(!cost){
                if(dist[cost+1][i] > max(largest, E[node][i]/2.0)){
                    dist[cost+1][i] = max(largest, E[node][i]/2.0);
                    if(E[node][i]/2.0 > largest)
                        halfs[i] = {node, i};
                    else halfs[i] = halfs[node];
                    pq.push({-dist[cost+1][i], i, cost+1});
                }
            }
            if(dist[cost][i] > max(largest, E[node][i])){
                dist[cost][i] = max(largest, E[node][i]);
                if(!cost){
                    if(dist[cost+1][i] > dist[cost][i]){
                        dist[cost+1][i] = dist[cost][i];
                        halfs[i] = {i,i};                        
                    }
                    // dist[cost+1][i] = min(dist[cost+1][i], dist[cost][i]);
                }
                pq.push({-dist[cost][i], i, cost});
            }
        }
    }

    for(int i =0; i<N; i++){
        if(max((W-v[i].first) / 2.0, dist[0][i]) < max(W-v[i].first, dist[1][i])){
            halfs[i] = {i, N};
        }
        dist[1][i] = min(max((W-v[i].first) / 2.0, dist[0][i]), max(W-v[i].first, dist[1][i]));
        
        dist[0][i] = max(W-v[i].first, dist[0][i]);
        //cout << dist[0][i]<<" "<<dist[1][i]<<"\n";
    }
    int least_idx = 0;
    double least_val = dist[1][0];

    for(int i =0; i<N; i++){
        if(dist[1][i] < least_val){
            least_val = dist[1][i];
            least_idx = i;
        }
    }

    ll a, b;
    tie(a, b) = halfs[least_idx];
    
    if(a == -1){
        if(b == N){
            cout << W/2.0<<" "<<0.0<<"\n";
        }
        else cout << v[a].first/2.0 <<" "<<v[a].second<<"\n";
    }
    else if (b == N){
        cout << (v[a].first+W)/2.0<<" "<<v[a].second<<"\n";
    }
    else{
        cout<< (v[a].first+v[b].first) / 2.0 <<" "<<(v[a].second+v[b].second)/2.0;
    }

    return 0;
}
