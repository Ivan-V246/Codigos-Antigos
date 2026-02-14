#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e6+5;

map <char, int> mapa;; 

signed main() { 
    string s; cin >> s;
    for(auto x : s) {
        mapa[x]++;
    }
    for(auto x : mapa) {
        if(x.f == 'z') break;
        char obj = x.f;
        obj++;
        if(x.s/2 == 0) continue;
        mapa[obj] += x.s/2;
        mapa[x.f] %= 2;
    }
    string ans = "";
    for(auto x : mapa) {
        for(int i = 0; i < x.s; i++) ans+= x.f;   
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
