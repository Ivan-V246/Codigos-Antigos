#include <bits/stdc++.h>
using namespace std;

#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define mkp make_pair
#define f first
#define s second
#define endl '\n'

#define dbg(x) cout << #x << " -> " << x << endl;
#define dbgv(x) cout << #x << endl; for(auto y : x) cout << y << " "; cout << endl;
#define ALL(x) (x).begin(), (x).end()

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

signed main() { 
    int t; cin >> t;
    while(t--) {
        multiset <pii> con;
        int n, k; cin >> n >> k;
        for(int i = 0; i < n; i++) {
            int a, b, c; cin >> a >> b >> c;
            if((a > b) or (a > c) or (b > c)) {
                con.insert(mkp(a+b+c, 0));
            } else {
                int sla = INF;
                if(a < c) {
                    sla = min(sla, (b - a)+1);
                }
                if(a < b) {
                    sla = min(sla, (c - b)+1);
                } 
                con.insert(mkp(a+b+c, sla));
            } 
        }
        int tam = 0; 
        auto [v, pode] = *(con.begin());
        tam = 1;
        if(k < 2*pode) {
            k = 0;
        } else {
            k -= 2*pode;
        }
        tam = 1;
        con.erase(con.begin());
        while(k) {
            if(con.empty()) break;
            auto [x, y] = *(con.begin());
            if(v == x) {
                if(k < 2*y) {
                    break;
                } else {
                    k -= 2*y;
                    tam++;
                    con.erase(con.begin());
                }
            } else {
                if(k >= (x - v)*tam) {
                    k -= (x - v)*tam;
                    v = x;
                } else {
                    v += (k/tam);
                    k = 0;
                }
            }
        }
        if(con.empty()) v += (k/tam);
        cout << v << endl;
    }
}
