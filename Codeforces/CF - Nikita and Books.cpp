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
        int q = 0;
        bool ans = 1;
        vector<int> lista(n);
        for(auto &x : lista) cin >> x;
        for(int i = 0; i < (n-1); i++) {
            if(lista[i] > i+1) {
                q += lista[i] - (i+1);
                lista[i] = i+1;
            } else if(lista[i] < i+1) {
                if(q >= (i+1) - lista[i]) {
                    q -= (i+1) - lista[i];
                    lista[i] = i+1;
                } else {
                    ans = 0;
                    break;
                }
            }
        }
        if(!ans) {
            cout << "NO" << endl; 
        } else {
            lista[n-1]+=q;
            if(lista[n-1] >= n) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}
