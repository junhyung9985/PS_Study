#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;
// length

ll b1;
ll b2, b2_cnt;
ll b3, r3, b3_cnt;
// Bullets Info

vector<ll> z;
// Power of Zombie

void can(ll turn, ll curr){
    ll new_curr = 0;
    if(turn == N){
        cout<<"YES";
        exit(0);
        
    }
    z[curr] -= b1;
    if(curr == turn && z[curr] > 0) ;
    else{
        new_curr = curr;
        while(new_curr < N){
            if(z[new_curr] > 0) break;
            ++new_curr;
        }
        if(new_curr== N){
            cout <<"YES";
            exit(0);
        }
        can(turn+1, new_curr);
    } 
    z[curr] += b1;

    if(b2_cnt > 0 && b2 > b1){
        --b2_cnt;
        z[curr] -= b2;
        if(curr == turn && z[curr] > 0) ;
        else{
            new_curr = curr;
            while(new_curr < N){
                if(z[new_curr] > 0) break;
                ++new_curr;
            }
            if(new_curr== N){
                cout <<"YES";
                exit(0);
            }
            can(turn+1, new_curr);
        }
        ++b2_cnt;
        z[curr] += b2;

    }

    if(b3_cnt > 0 && z[turn] <= b3){
        --b3_cnt;
        for(int i = curr; i< curr+r3; ++i){
            if(i == N) break;
            z[i] -= b3;
        }
        if(curr ==  turn && z[curr] > 0) ;
        else{
            new_curr = curr;
            while(new_curr < N){
                if(z[new_curr] > 0) break;
                ++new_curr;
            }
            if(new_curr== N){
                cout <<"YES";
                exit(0);
            }
            can(turn+1, new_curr);
        } 
        ++b3_cnt;
        for(int i = curr; i< curr+r3; ++i){
            if(i == N) break;
            z[i] += b3;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> b1 >> b2 >> b2_cnt >> b3 >> r3 >> b3_cnt;
    z.resize(N);

    for(int i =0; i<N; ++i)
        cin >> z[i];

    ll init_locked_on = 0;
    while(init_locked_on < N){
        if(z[init_locked_on] >0 ) break;
        ++init_locked_on;
    }
    if(init_locked_on == N){
        cout <<"YES";
        return 0;
    }
    can(0, init_locked_on);
    cout <<"NO";

    return 0;
} // Recursion, Simulation