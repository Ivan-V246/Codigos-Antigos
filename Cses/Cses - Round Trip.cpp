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
const int MAXN = 1e5+5;

vector <int> grafo[MAXN];
bool con[MAXN];
int pai[MAXN];
int prof[MAXN];
vector <int> ans;

void enraizar(int ini) {
    queue <pii> fila;
    con[ini] = 1;
    pai[ini] = -1;
    fila.emplace(mkp(ini, 0LL));
    while(fila.size()) {
        int atual = fila.front().f;
        int deep = fila.front().s;
        fila.pop();
        for(auto x : grafo[atual]) {
            if(!con[x]) {
                pai[x] = atual;
                con[x] = 1;
                prof[x] = deep+1; 
                fila.emplace(mkp(x, prof[x]));
            }
        }
    }
}

void rec_resp(int x, int y) {
    if(prof[x] > prof[y]) swap(x, y); //Y é o mais profundo;

    while(prof[y] > prof[x]) {
        ans.emplace_back(y);
        y = pai[y];
    }

    if(y == x) {
        ans.emplace_back(y);
        return;
    }
    vector <int> aux;
    while(y != x) {
        ans.emplace_back(y);
        y = pai[y];
        aux.emplace_back(x);
        x = pai[x];
    }   
    ans.emplace_back(y);
    reverse(aux.begin(), aux.end());
    for(auto z : aux) {
        ans.emplace_back(z);
    }
}

signed main() { 
    int n, m; cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        grafo[a].emplace_back(b);
        grafo[b].emplace_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(!con[i]) {
            enraizar(i);
        }
    }
    bool flag = 0;
    for(int i = 1; i <= n; i++) {
        for(auto x : grafo[i]) {
            if(x != pai[i] and pai[x] != i) {
                rec_resp(i, x);
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    if(flag) {
        cout << ans.size()+1 << endl;
        for(auto x : ans) {
            cout << x << " ";
        }
        cout << ans[0] << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}