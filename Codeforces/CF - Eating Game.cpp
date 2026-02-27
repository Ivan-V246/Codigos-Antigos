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
        int n; cin >> n;
        vector <int> lista;
        int tot = 0;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            tot+=a;
            lista.emplace_back(a);
        }
        int vence[15] = {0};
        for(int i = 0; i < n; i++) {
            vector <int> temp;
            for(auto x : lista) temp.emplace_back(x);
            int to = tot;
            int ini = i;
            int v = 0;
            while(to > 0) {
                if(temp[ini] > 0) {
                    to--;
                    temp[ini]--;
                    v = ini;
                }
                ini++;
                ini %= n;
            }
            vence[v]++;
        }
        int ans = 0;
        for(auto x : vence) {
            if(x > 0) ans++;
        }
        cout << ans << endl;
    }
}