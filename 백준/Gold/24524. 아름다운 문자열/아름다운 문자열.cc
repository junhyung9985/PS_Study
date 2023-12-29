#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s, t;
  cin >> s >> t;

  ll N = s.size();
  vector<deque<ll>> q(26, deque<ll>());

  for(int i =0; i<N; ++i){
    q[s[i]-'a'].push_back(i);
  }

  ll ans = 0;
  while(true){
    int last_idx = -1;
    for(int i =0; i<t.size(); ++i){
      while(!q[t[i]-'a'].empty()){
        if(q[t[i]-'a'].front() < last_idx) q[t[i]-'a'].pop_front();
        else break;
      }
      last_idx = q[t[i]-'a'].front();
      if(q[t[i]-'a'].empty()){
        cout << ans;
        return 0;
      }
    }
    ++ans;
    for(int i =0; i<t.size(); ++i){
      q[t[i]-'a'].pop_front();
    }
  }


  return 0;
}