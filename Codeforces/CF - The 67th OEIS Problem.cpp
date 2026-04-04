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

bool primo[MAXN];

signed main() { op
    vector <int> primos;
    for(int i = 2; i < MAXN; i++) {
        if(!primo[i]) {
            primos.emplace_back(i);
            for(int j = i*i; j < MAXN; j+=i) {
                primo[j] = 1;
            }
        }
    }
    vector <int> lista;
    lista.emplace_back(1);
    int n = 10005;
    for(int i = 1; i < n; i++) {
        lista.emplace_back(primos[i]*primos[i-1]);
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            cout << lista[i] << " ";
        }
        cout << endl;
    }
}