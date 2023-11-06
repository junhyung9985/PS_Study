#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

void 재귀(ll i, ll n){
    for(int j=0; j<i; ++j)
        cout <<"____";
    cout<<"\"재귀함수가 뭔가요?\"\n";
    for(int j=0; j<i; ++j)
        cout <<"____";
    if(i == n){
        cout <<"\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    }
    else {
        cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";    
        for(int j=0; j<i; ++j)
            cout <<"____";
        cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        for(int j=0; j<i; ++j)
            cout <<"____";
        cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
        재귀(i+1, n);
    }
    for(int j=0; j<i; ++j)
        cout <<"____";
    cout <<"라고 답변하였지.\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    cout <<"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    재귀(0, N);

    return 0;
} // Recursion, UTF-8