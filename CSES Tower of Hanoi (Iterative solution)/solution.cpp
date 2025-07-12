/// designed by Oruc Cabbarli
/// github.com/orucexe

#include <bits/stdc++.h>
using namespace std;

#define vi      vector<int>
#define pii     pair<int,int>
#define vpii    vector<pii>
#define pb      push_back
#define fi      first
#define se      second
#define endl    '\n'
#define all(v)  v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define int long long


pii nxt(int a, int b, int p){
    if(p == 1){
        a = a % 3 + 1;
        b = b % 3 + 1;
    }
    else{
        a = (a + 1) % 3 + 1;
        b = (b + 1) % 3 + 1;
    }
    return {a,b};
}


void solve(){
    int n;
    cin >> n;
    int k = pow(2,n)-1;
    cout << k << endl;
    vi m(pow(2,17));
    vector<vpii> v(n+1);
    for(int i = 1; i <= (pow(2,16)); i++){
        if((i-1) % 2 == 0) { m[i] = 1; }
        else if((i-2) % 4 == 0) { m[i] = 2; }
        else if((i-4) % 8 == 0) { m[i] = 3; }
        else if((i-8) % 16 == 0) { m[i] = 4; }
        else if((i-16) % 32 == 0) { m[i] = 5; }
        else if((i-32) % 64 == 0) { m[i] = 6; }
        else if((i-64) % 128 == 0) { m[i] = 7; }
        else if((i-128) % 256 == 0) { m[i] = 8; }
        else if((i-256) % 512 == 0) { m[i] = 9; }
        else if((i-512) % 1024 == 0) { m[i] = 10; }
        else if((i-1024) % 2048 == 0) { m[i] = 11; }
        else if((i-2048) % 4096 == 0) { m[i] = 12; }
        else if((i-4096) % 8192 == 0) { m[i] = 13; }
        else if((i-8192) % 16384 == 0) { m[i] = 14; }
        else if((i-16384) % 32768 == 0) { m[i] = 15; }
        else if((i-32768) % 65536 == 0) { m[i] = 16; }

    }
    if(n % 2 == 0){
        for(int i = 1; i <= k; i++){
            if(v[m[i]].size() == 0){
                if(m[i] % 2 == 1){
                    v[m[i]].pb({1,2});
                }
                else{
                    v[m[i]].pb({1,3});
                }
            }
            else{
                if(m[i] % 2 == 1){
                    v[m[i]].pb(nxt(v[m[i]].back().fi,v[m[i]].back().se,1));
                }
                else{
                    v[m[i]].pb(nxt(v[m[i]].back().fi,v[m[i]].back().se,2));
                }
            }
            cout << v[m[i]].back().fi << " " << v[m[i]].back().se << endl;
        }
    }
    else{
        for(int i = 1; i <= k; i++){
            if(v[m[i]].size() == 0){
                if(m[i] % 2 == 1){
                    v[m[i]].pb({1,3});
                }
                else{
                    v[m[i]].pb({1,2});
                }
            }
            else{
                if(m[i] % 2 == 1){
                    v[m[i]].pb(nxt(v[m[i]].back().fi,v[m[i]].back().se,2));
                }
                else{
                    v[m[i]].pb(nxt(v[m[i]].back().fi,v[m[i]].back().se,1));
                }
            }
            cout << v[m[i]].back().fi << " " << v[m[i]].back().se << endl;
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
