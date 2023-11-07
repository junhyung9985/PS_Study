#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N;
ll D = 0, G = 0;
map < int, vector < int >>m;
vector < pair < int, int >>p;
map < int, vector < int >>m2;
//int MAX_DEPTH = 0;

bool visited[300001];
int deep[300001];
ll child[300001];

ll
bfs (int curr_node)
{
  ll ans = m[curr_node].size ();
  ans = (ans * (ans - 1) * (ans - 2)) / 6;
  if (ans < 0)
    ans = 0;
  return ans;
}

void
dfs (int curr_node, int depth)
{
  //MAX_DEPTH = max(depth, MAX_DEPTH);
  if(depth >= 3) D++;
  visited[curr_node] = true;
  deep[curr_node] = depth;
  m2[depth].push_back (curr_node);
for (int i:m[curr_node])
    {
      if (visited[i])
	continue;
      dfs (i, depth + 1);
      child[curr_node]++;
    }
  return;
}

int
main ()
{
  int a, b;
  cin >> N;
  for (int i = 0; i < N - 1; i++)
    {
      cin >> a >> b;
      m[a].push_back (b);
      m[b].push_back (a);
      p.push_back (
		    {
		    a, b});

    }

  dfs (1, 0);

  // for(int i =1; i<=N; i++){
  //     cout << i <<" : ";
  //     for(int j : m2[deep[i+3]]){
  //         cout << j <<" ";
  //     }
  //     cout<<"\n";
  // }

  for (int i = 1; i <= N; i++)
    {


      G += bfs (i);
      //D += (ll)m2[deep[i] + 3].size();
    for (int j:m[i]){
	if (deep[j] == deep[i] + 1)
	  {
	    D += (ll)(child[i] - 1) * child[j];
	  }
    }
    }

  // D /=2;

  //cout << D << " " << G << "\n";
  if (D < 3 * G)
    cout << "G";
  else if (D > 3 * G)
    cout << "D";
  else
    cout << "DUDUDUNGA";

  return 0;
}
