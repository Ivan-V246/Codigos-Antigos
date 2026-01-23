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
        vector <int> lista;
        set <int> con;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            con.insert(a);
        }
        for(auto x : con) {
            lista.emplace_back(x);
        }
        int tam = 1;
        int inter = 1;
        for(int i = 0; i < lista.size()-1; i++) {
            if(lista[i+1] == lista[i]+1) {
                inter++;
            } else {
                inter = 1;
            }
            tam = max(inter, tam);
        }
        cout << tam << endl;
    }
}
