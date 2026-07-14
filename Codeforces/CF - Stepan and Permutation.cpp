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
        int n, x, y; cin >> n >> x >> y;
        vector <int> lista(n);
        for(auto &x : lista) cin >> x;
        int gc = gcd(x, y);
        bool ans = 1;
        for(int i = 0; i < n; i++) {
            int pos = i+1;
            if(pos != lista[i]) {
                if(pos%gc != lista[i]%gc) {
                    ans = 0;
                    break;
                }
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}
