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
    int n; cin >> n;
    vector <int> p1(n), p2(n), lista(n);
    for(auto &x : p1) cin >> x;
    for(auto &x : p2) cin >> x;
    for(int i = 1; i <= n; i++) lista[i-1] = i;
    int ans = 0;
    do {
        bool ma = 0, me = 0;
        bool f1 = 1, f2 = 1;
        for(int i = 0; i < n; i++) {
            if(p1[i] != lista[i] and f1) {
                ma = lista[i] > p1[i];
                f1 = 0;
            }
            if(p2[i] != lista[i] and f2) {
                me = lista[i] < p2[i];
                f2 = 0;
            }
        }
        ans += (ma and me);
        // for(auto x : lista) cout << x << " ";
        // cout << endl;
        // cout << ma and me << endl;
    } while(next_permutation(lista.begin(), lista.end()));
    cout << ans << endl;
}
