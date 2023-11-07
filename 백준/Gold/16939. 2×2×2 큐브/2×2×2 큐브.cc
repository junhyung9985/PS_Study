/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int arr[25];
int _u[8] = {1,3,5,7,9,11,24,22};
int _u2[8] = {2,4,6,8,10,12,23,21};
int _r[8] = {13, 14, 5, 6, 17, 18, 21, 22};
int _r2[8] = {15, 16, 7, 8, 19, 20, 23, 24};
int _c[8] = {3,4,17,19,10,9,16,14};
int _c2[8] = {1,2,18,20,12,11,15,13};

deque<int> u;
deque<int> u2;
deque<int> r;
deque<int> r2;
deque<int> c;
deque<int> c2;

int main()
{
    int ans = 0;
    bool can = true;
    
    for(int i =1; i<=24; i++)
        cin >> arr[i];
    
    for(int i =0; i<8; i++){
        u.push_back(arr[_u[i]]);
        u2.push_back(arr[_u2[i]]);
        r.push_back(arr[_r[i]]);
        r2.push_back(arr[_r2[i]]);
        c.push_back(arr[_c[i]]);
        c2.push_back(arr[_c2[i]]);
    }
    
    can = true;
    u.push_front(u.back());
    u.pop_back();
    u.push_front(u.back());
    u.pop_back();

    for(int i =0; i<8; i++){
        can = can && (u[i] == u2[i]);
    }
    
    can = can && (arr[13] == arr[14]);
    can = can && (arr[14] == arr[15]);
    can = can && (arr[15] == arr[16]);
    
    can = can && (arr[17] == arr[18]);
    can = can && (arr[18] == arr[19]);
    can = can && (arr[19] == arr[20]);
    
    if(can) ans = 1;
    
    can = true;
    u.push_back(u.front());
    u.pop_front();
    u.push_back(u.front());
    u.pop_front();
    u.push_back(u.front());
    u.pop_front();
    u.push_back(u.front());
    u.pop_front();

    for(int i =0; i<8; i++){
        can = can && (u[i] == u2[i]);
    }

    can = can && (arr[13] == arr[14]);
    can = can && (arr[14] == arr[15]);
    can = can && (arr[15] == arr[16]);
    
    can = can && (arr[17] == arr[18]);
    can = can && (arr[18] == arr[19]);
    can = can && (arr[19] == arr[20]);
    
    if(can) ans = 1;
    
    
    can = true;
    r.push_front(r.back());
    r.pop_back();
    r.push_front(r.back());
    r.pop_back();

    for(int i =0; i<8; i++){
        can = can && (r[i] == r2[i]);
    }
    can = can && (arr[1] == arr[2]);
    can = can && (arr[2] == arr[3]);
    can = can && (arr[3] == arr[4]);
    
    can = can && (arr[9] == arr[10]);
    can = can && (arr[10] == arr[11]);
    can = can && (arr[11] == arr[12]);
    
    
    if(can) ans = 1;
    
    can = true;
    r.push_back(r.front());
    r.pop_front();
    r.push_back(r.front());
    r.pop_front();
    r.push_back(r.front());
    r.pop_front();
    r.push_back(r.front());
    r.pop_front();
    
    for(int i =0; i<8; i++){
        can = can && (r[i] == r2[i]);
    }
    can = can && (arr[1] == arr[2]);
    can = can && (arr[2] == arr[3]);
    can = can && (arr[3] == arr[4]);
    
    can = can && (arr[9] == arr[10]);
    can = can && (arr[10] == arr[11]);
    can = can && (arr[11] == arr[12]);
    
    if(can) ans = 1;

    can = true;
    c.push_front(c.back());
    c.pop_back();
    c.push_front(c.back());
    c.pop_back();
    
    for(int i =0; i<8; i++){
        can = can && (c[i] == c2[i]);
    }
    
    can = can && (arr[5] == arr[6]);
    can = can && (arr[6] == arr[7]);
    can = can && (arr[7] == arr[8]);
    
    can = can && (arr[21] == arr[22]);
    can = can && (arr[22] == arr[23]);
    can = can && (arr[23] == arr[24]);
    
    if(can) ans = 1;
    
    can = true;
    c.push_back(c.front());
    c.pop_front();
    c.push_back(c.front());
    c.pop_front();
    c.push_back(c.front());
    c.pop_front();
    c.push_back(c.front());
    c.pop_front();
    
    for(int i =0; i<8; i++){
        can = can && (c[i] == c2[i]);
    }

    can = can && (arr[5] == arr[6]);
    can = can && (arr[6] == arr[7]);
    can = can && (arr[7] == arr[8]);
    
    can = can && (arr[21] == arr[22]);
    can = can && (arr[22] == arr[23]);
    can = can && (arr[23] == arr[24]);

    if(can) ans = 1;

    cout << ans;


    return 0;
} // Simulation, Implementation