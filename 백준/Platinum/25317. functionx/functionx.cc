
#include <bits/stdc++.h>
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll Q;
    ordered_set plus;
    ordered_set minus;
    set<ll> occured;
    ll coef = 1;
    cin >> Q;
    while(Q--){
        ll a, b, c;
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            if(b < 0){
                ll tmp = (-c)/(b);
                if(-c%b != 0 && c != 0){ 
                    if( c >0) tmp++; //  - + -  -> + 
                }
                else occured.insert(tmp);
                minus.insert(tmp);
                //cout << minus[minus.size()-1]<<"\n";
            }
            else if(b > 0){
                ll tmp = (-c)/(b);
                if(-c%b != 0 && c!=0){
                    if(c >0)
                    tmp--; // - + + -> -

                }
                else occured.insert(tmp);
                plus.insert(tmp);
                //cout << plus[plus.size()-1]<<"\n";
            }
            else {
                coef *= c;
                if(coef > 0) coef = 1;
                else if (coef <0) coef = -1;
            }
        }
        else {
            cin >> b;
            
            ll ans = coef;
            auto itr1 = minus.order_of_key(b+1); //...?
            auto itr2 = plus.order_of_key(b);
            
            ans *= ((itr1)%2) ? -1 : 1;
            ans *= ((plus.size()-itr2)%2) ? -1 : 1;
            
            if(occured.find(b) != occured.end()) ans *= 0;
            
            
            //cout << itr1 <<" "<<itr2 <<"\n";
            if(ans > 0) cout << "+\n";
            else if (ans < 0) cout <<"-\n";
            else cout <<"0\n";
        }
    }
    
    
    return 0;
}
/*

Case-working + PBDS

*/