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
        int n, k; cin >> n >> k;
        vector <int> lista;
        map <int, deque<int>> pos;
        map <int, bool> fora;
        set < pair<int, int> > mao;
        for(int i = 1; i <= n; i++) {
            int a; cin >> a;
            lista.emplace_back(a);
            fora[a] = 0;
            pos[a].emplace_front(i);
        }
        for(auto &x : pos) x.s.emplace_front(INF);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(fora[lista[i]]) {
                mao.erase(mkp( pos[lista[i]].back() , lista[i]));
                pos[lista[i]].pop_back();
                mao.insert(mkp( pos[lista[i]].back() , lista[i]));
                continue;
            }

            if(mao.size() < k) {
                pos[lista[i]].pop_back();
                mao.insert(mkp( pos[lista[i]].back() , lista[i]));
                fora[lista[i]] = 1;
                ans++;
            }
             else {
                auto pont = mao.end();
                pont--;
                fora[(*pont).second] = 0;
                mao.erase(pont);

                pos[lista[i]].pop_back();
                mao.insert(mkp( pos[lista[i]].back() , lista[i]));
                fora[lista[i]] = 1;
                ans++;
            }
        }
        cout << ans << endl;
    }
}
