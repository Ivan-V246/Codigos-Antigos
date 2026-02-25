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


signed main() { 
    int t; cin >> t;
    while(t--) {
        string n; cin >> n;
        int soma = 0;
        int s = 0;
        for(auto x : n) {
            soma += x - '0';
        }
        s = soma;
        if(soma <= 9) {
            cout << 0 << endl;
            continue;
        }
        string sla = n.substr(1);
        sort(sla.begin(), sla.end());
        reverse(sla.begin(), sla.end());
        int ans = 0;
        for(auto x : sla) {
            if(soma <= 9) break;
            soma -= (x - '0');
            ans++;
        }
        int resp = 0;
        resp++;
        s -= n[0]-'0';
        s++;
        n[0] = '1';
        for(auto x : sla) {
            if(s <= 9) break;
            s -= (x - '0');
            resp++;
        }
        cout << min(resp, ans) << endl;
    }
}