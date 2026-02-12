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


signed main() { op
    int t; cin >> t;
    while(t--) {
        int n; string s; cin >> n >> s;
        int c = 0;
        for(auto x : s) {
            if(x == 'a') {
                c++;
            } else {
                c--;
            }
        }
        map <int, int> mapa;
        int ans = INF;
        mapa[0] = 0;
        int atual = 0;
        for(int i = 0; i < n; i++) {
            char x = s[i]; 
            if(x == 'a') {
                atual++;
            } else {
                atual--;
            }
            mapa[atual] = i+1;
            if(mapa.count(atual-c)) {
                ans = min(ans, mapa[atual] - mapa[atual-c]);
            }
        }
        if(ans == n) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}
