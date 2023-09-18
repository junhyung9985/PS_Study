#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, A, B, M;
    cin >> N >> A >> B >> M;

    vector<pair<ll,ll>> v(N);
    for(int i =0; i<N; ++i){
        ll a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());

    if(M == 0){
        ll gajum = 0;
        ll curr = 0;
        ll spare_day = 0;
        ll spare_sat = 0;
        ll ans = 0;
        for(int i =0; i<N; ++i){
            ll dead, t;
            tie(dead, t) = v[i];
            while(t > 0 && curr < dead){
                if(curr%7 == 5 || curr%7 == 6) ++spare_sat;
                else {
                    ++spare_day;
                    --t;
                }
                ++curr;
            }
            if((curr == dead) && t){
                if(t <= spare_day){
                    spare_day -= t;
                    gajum += A * t;
                }
                else if (t <= (spare_day+spare_sat)){
                    gajum += A*spare_day;            
                    t -= spare_day;
                    spare_day = 0;
                    gajum += B*t;
                    ans += t;
                    spare_sat -=t;
                }
                else {
                    cout << -1;
                    return 0;
                }
            }
        }
        if(gajum == M) cout << ans;
        else cout << -1;
        return 0;
    }
    else if(M > 0 && A ==0 && B == 0){
        cout << -1;
        return 0;
    }
    else if(M > 0 && A == 0 && B > 0){

        if(M%B){
            cout << -1;
            return 0;
        }
        ll curr = 0;
        ll spare_day = 0;
        ll spare_sat = 0;
        ll ans = 0;
        ll cover = 0;
        ll day_time = 0;
        
        for(int i =0; i<N; ++i){
            ll dead, t;
            tie(dead, t) = v[i];
            while(t > 0 && curr < dead){
                if(curr%7 == 5 || curr%7 == 6) ++spare_sat;
                else {
                    ++spare_day;
                    --t;
                    ++day_time;
                }
                ++curr;
            }
            //cout << dead <<" "<<curr<<" "<<t<<"\n";
            if((curr == dead) && t){
                cover += t;
                if(t <= spare_day){
                    spare_day -= t;
                    day_time -= t;
                    
                }
                else if (t <= (spare_day+spare_sat)){
                    t -= spare_day;
                    day_time -= spare_day;
                    spare_day = 0;
                    ans += t;
                    spare_sat -=t;
                }
                else {
                    cout << -1;
                    return 0;
                }
            }
        }
        
        if(M > B * ans){
            if(spare_sat >= M/B-ans && cover+day_time >= M/B-ans){
                ans = M/B;
            }
        }
        
        if(ans * B == M) cout << ans;
        else cout << -1;
        return 0;

    }
    else if(M > 0 && A > 0 && B > 0){
        
        for(int to_work =0; to_work<=M; ++to_work){
            if((M-to_work*B)%A) continue;

            ll to_worka = (M-to_work*B)/A;
            bool can = true;
            ll curr = 0;
            ll spare_day = 0;
            ll spare_sat = v[N-1].first/7*2;
            if((v[N-1].first)%7>4){
                spare_sat += v[N-1].first%7-4;
            }
            ll ans = 0;
            ll coverA = 0;
            ll day_time = 0;

            for(int i =0; i<N; ++i){
                ll dead, t;
                tie(dead, t) = v[i];
                while(t > 0 && curr < dead){
                    if(curr%7 == 5 || curr%7 == 6) {
                        if(ans < to_work){
                            ++ans;
                            -- t;    
                            --spare_sat;
                        }
                    }
                    else {
                        ++spare_day;
                        --t;
                        ++day_time;
                    }
                    ++curr;
                }
                //cout << dead <<" "<<curr<<" "<<t<<"\n";
                if((curr == dead) && t){
                    if(t <= spare_day && to_worka >= coverA+t){
                        coverA+= t;
                        spare_day -= t;
                        day_time -= t;                        
                    }
                    else if (t <= (spare_day+spare_sat)){
                        if(to_worka >= coverA+spare_day){
                            t -= spare_day;
                            day_time -= spare_day;
                            coverA += spare_day;
                            spare_day = 0;
                        }
                        else {
                            t -= to_worka-coverA;
                            day_time -= to_worka - coverA;
                            spare_day -= to_worka - coverA;                        
                            coverA = to_worka;
                        }
                        if(t > spare_sat){
                            can = false;
                        }
                        ans += t;
                        spare_sat -=t;
                    }
                    else {
                        can = false;
                    }
                }
            }
            if(!can) continue;
            
            if(to_worka > coverA){
                if(day_time+coverA >= to_worka){
                    day_time -= to_worka - coverA;
                    coverA = to_worka;
                }
            }
            //cout <<to_work<<" "<< coverA <<" "<<ans<<" " << spare_sat <<" " << day_time<<"\n";

            if(to_work > ans){
                if(spare_sat+ans >= to_work){
                    ll need = to_work-ans;
                    if(day_time >= need){
                        ans = to_work;
                    }
                }
            }
            if(coverA == to_worka && to_work == ans) {
                cout << ans;
                return 0;
            }            
        }
        cout << -1;
        return 0;
    }
    return 0;
}