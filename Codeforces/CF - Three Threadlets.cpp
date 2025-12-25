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
        vector <int> a(3); cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());
        int molde = a[0];
        priority_queue <int> fila;
        int ans = 0;
        fila.emplace(a[1]);
        fila.emplace(a[2]);
        while(!fila.empty()) {
            int atual = fila.top();
            fila.pop();
            if(atual == molde) {
                continue;
            } else {
                if(atual < molde) {
                    ans = 5;
                    break;
                } else {
                    fila.emplace(molde);
                    fila.emplace(atual-molde);
                    ans++;
                    if(ans > 3) break;
                }
            }
        }
        if(ans <= 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
