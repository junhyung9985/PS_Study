#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int min_x = 40001, min_y = 40001;
deque<pair<int,int>> coords;

double angle(pair<long long, long long> a){
  if(a.first < min_x) {return M_PI - asin(((a.second-min_y)*(1) - (a.first-min_x)*0) /(sqrt((a.first-min_x)*(a.first-min_x) + (a.second-min_y)*(a.second-min_y))));}
  return asin(((a.second-min_y)*(1) - (a.first-min_x)*0) /(sqrt((a.first-min_x)*(a.first-min_x) + (a.second-min_y)*(a.second-min_y))));
} // [참고] : https://darkpgmr.tistory.com/121


bool cmp(pair<long long, long long> a, pair<long long, long long> b){
  double d_a = angle(a);
  double d_b = angle(b);
  if (d_a == d_b) return  sqrt((a.first - min_x) * (a.first - min_x) + (a.second - min_y) *(a.second-min_y)) > sqrt((b.first - min_x) * (b.first - min_x) + (b.second - min_y) *(b.second-min_y));
  return  d_a < d_b;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long N, tmp1, tmp2;
    vector<pair<long long, long long>> stck;
    long long s_size = 2;
    cin >> N;
    
    for(int i =0; i < N; i++){
        cin >> tmp1 >> tmp2;
        if(min_y > tmp2 || (min_y == tmp2) && (min_x > tmp1)){
            if(min_x < 40001) coords.push_back({min_x, min_y});
            min_y = tmp2;
            min_x = tmp1;
        }
        else coords.push_back({tmp1, tmp2});
    }
    
    sort(coords.begin(), coords.end(), cmp);
  coords.push_back({min_x, min_y});
    // for (int i =0; i<N ;i++)
    // cout << coords[i].first <<" " << coords[i].second <<"\n";  
  stck.push_back({min_x, min_y});
    stck.push_back(coords[0]);
    coords.pop_front();
    
    while(!coords.empty()){
        long long p3_x = coords[0].first, p3_y = coords[0].second;
        coords.pop_front();
        while(true){
            long long p1_x = stck[s_size-2].first, p1_y = stck[s_size-2].second;
            long long p2_x = stck[s_size-1].first, p2_y = stck[s_size-1].second;
            stck.pop_back();
            stck.pop_back();
            s_size -=2;
            if(angle({p2_x,p2_y}) == angle({p3_x,p3_y})){
              stck.push_back({p1_x, p1_y});
              stck.push_back({p2_x, p2_y});
              s_size +=2;
              break;              
            }
            long long determine = (p2_x - p1_x)*(p3_y - p1_y) - (p2_y - p1_y)*(p3_x - p1_x);
            if(determine > 0){
                stck.push_back({p1_x, p1_y});
                stck.push_back({p2_x, p2_y});
                stck.push_back({p3_x, p3_y});
                s_size +=3;
                break;
            }
            else if (determine == 0){
                stck.push_back({p1_x, p1_y});
                stck.push_back({p3_x, p3_y});
                s_size +=2;
                break;
            }
            else {
                stck.push_back({p1_x, p1_y});
                s_size ++;
            }
        }
    }

  // cout <<"\n\nSTACK\n\n";

  // for (int i =0; i<stck.size() ;i++)
  //   cout << stck[i].first <<" " << stck[i].second <<"\n";
    
    cout << s_size-1 <<"\n";
    return 0;
    
}