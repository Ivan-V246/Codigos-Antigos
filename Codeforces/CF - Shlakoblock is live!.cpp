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
        int n; cin >> n;
        vector <pair<int, int> > p;
        vector <int> v(n);
        double soma = 0;
        double total = 0;
        for(int i = 1; i <= n; i++) {
            int a; cin >> a >> v[i-1];
            total += v[i-1];
            soma += a*v[i-1];
            p.emplace_back(a, i);
        }

        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());

        pii ans = mkp(soma, total);
        double sla = (double)soma/(double)total;
        double ps = 0;
        int ind = 0;

        for(int i = 0; i < n; i++) {
            ps += p[i].first;

            if((soma + ps) / (total + i+1) > sla) {
                sla = (soma + ps) / (total + i+1);
                ans = mkp((soma + ps), (total + i + 1));
                ind = i+1;
            }
        }
        int div = gcd(ans.first, ans.second);
        cout << ans.first/div << "/" << ans.second/div << endl;
        cout << ind << endl;
        vector <int> resp;
        for(int i = 0; i < ind; i++) {
            resp.emplace_back(p[i].second);
        }
        sort(resp.begin(), resp.end());
        for(auto x : resp) {
            cout << x << " ";
        }
        cout << endl;
    }
}