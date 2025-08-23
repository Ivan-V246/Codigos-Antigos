#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int> 
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e3+10;
const int MAXL = 18;
const int raiz = 318;

vector <int> causa[MAXN];
vector <int> cons[MAXN];
bitset <MAXN> bits[MAXN];
vector <int> vdd;
int grau[MAXN];


signed main() { op
    int n, m, q; cin >> n >> m >> q;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        causa[a].emplace_back(b);
        cons[b].emplace_back(a);
        grau[b]++;
    }
    for(int i = 0; i < q; i++) {
        int a; cin >> a;
        vdd.emplace_back(a);
    }
    queue <int> fila;
    for(int i = 1; i <= n; i++) {
        if(grau[i] == 0) {
            fila.emplace(i);
            bits[i][i] = 1;
        }
    }
    while(!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        for(auto x : causa[atual]) {
            bits[x] |= bits[atual];
            grau[x]--;
            if(grau[x] == 0) {
                fila.emplace(x);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(auto x : vdd) {
            if((bits[i] & bits[x]) == bits[x]) {
                cout << i << " ";
                break;
            }
        }
    }   
}

// Codar é arte. Enxugar Bit faz parte;
