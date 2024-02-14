#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T;
    scanf("%lld\n", &T);
	char s[1002];
    
    while(T--){
		fgets(s, sizeof(s), stdin);
		printf("%c%c\n",s[0], s[strlen(s)-2]);
	}
		
	return 0;
}