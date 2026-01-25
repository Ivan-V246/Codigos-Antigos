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
        vector <int> espadas;
        vector <int> monstros;
        monstros.emplace_back(0);
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            espadas.emplace_back(a);
        }
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            monstros.emplace_back(monstros[monstros.size()-1]+a);
        }
        sort(espadas.begin(), espadas.end());
        int val = espadas[0];
        int quant = 0;
        vector <pii> novo;
        for(auto x : espadas) {
            if(val != x) {
                novo.emplace_back(mkp(val, quant));
                val = x;
                quant = 1;
            } else {
                quant++;
            }
        }
        novo.emplace_back(mkp(val, quant));
        int qesp = n;
        int ans = 0; 
        for(auto x : novo) {
            auto pont = upper_bound(monstros.begin(), monstros.end(), qesp);
            int d = distance(monstros.begin(), pont);
            d--;
            ans = max(ans, d*x.f);
            qesp-=x.s;
        }
        cout << ans << endl;
    }
}
