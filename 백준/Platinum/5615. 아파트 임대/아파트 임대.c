#include <stdio.h>
typedef long long ll;
 
ll prime[3]={2,7,61};
 
ll gob(ll x,ll y,ll MOD)
{
    return (ll)((__int128)x*y%MOD);
} 
 
ll jegob(ll x,ll y, ll MOD)
{
    if(y<=0) return 1;
    
    ll ret=jegob(x,y/2,MOD);
    
    if(y%2) return gob(gob(ret,ret,MOD),x,MOD);
    return gob(ret,ret,MOD);
} 
 
int Miller_Rabin(ll n, ll p)
{
    if(n%p==0) return 1;
    
    ll d=n-1;
    while(d%2==0) d/=2;
    
    ll imsi=jegob(p,d,n);
    if(imsi==1||imsi==n-1) return 1;
    
    while(d*2<n-1)
    {
        d*=2;
        if(jegob(p,d,n)==n-1) return 1;
    } return 0;
} 
 
int Check_Prime(ll n)
{
    for(int i=0;i<3;i++)
    {
        if(n==prime[i]) return 1;
        if(!Miller_Rabin(n,prime[i])) return 0;
    } return 1;
}

int main(){
    int N;
    int ans = 0;
    scanf("%d", &N);
    for(int tmp = 0; tmp<N; tmp++){
        ll i;
        scanf("%lld", &i);
        if(Check_Prime(2*i+1)) ans+=1;
        
    }
    printf("%d\n", ans);
}