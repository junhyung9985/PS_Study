#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll diff = 0;
    ll y1,m1,d1, y2,m2,d2;
    cin >> y1 >>m1 >> d1 >> y2 >> m2 >> d2;
    struct tm  stime, etime;

    stime.tm_year = y1-1900;
    stime.tm_mon = m1-1;
    stime.tm_mday = d1;
    stime.tm_hour = stime.tm_min = stime.tm_sec = stime.tm_isdst = 0;

    etime.tm_year = y2-1900;
    etime.tm_mon = m2-1;
    etime.tm_mday = d2;
    etime.tm_hour = etime.tm_min = etime.tm_sec = etime.tm_isdst = 0;
    //cout << y1 <<" "<<y2 << " "<<m1 <<" "<<m2 <<" "<<d1 <<" "<<d2;
    time_t s, e;
    s = mktime(&stime);
    e = mktime(&etime);
    diff = difftime(e,s)  / (60 * 60 * 24);
    // cout << diff;
    // return 0;

    ll T, N;
    cin >> T >> N;

    vector<vector<ll>> dp(2, vector<ll>(10001));
    for(int i =0; i<N; ++i){

        for(int j =0; j<=10000; ++j)
            dp[i%2][j] = dp[1-i%2][j];

        ll a, b, c;
        cin >> a >> b >> c;

        // if(b > T) continue;
        if(a == 3) c *= 30;
        for(int j = b; j<=10000; ++j){
            if(j > 0) dp[i%2][j] = max(dp[i%2][j], dp[i%2][j-1]);
            dp[i%2][j] = max(dp[i%2][j], dp[1-i%2][j-b] + c);
        }

    }

    cout << abs(diff - dp[(N+1)%2][T]);

    return 0;
} // Parsing + Knapsack DP