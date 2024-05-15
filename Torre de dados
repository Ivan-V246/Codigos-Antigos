#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
// #define vi vector <int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e4+10;
int n, m;

struct dado {
    int a, b, c, d, e, f;
};

vector <dado> lista;

int maior(int atual, int cima, int baixo) {
    int ma = -INF;
    if(lista[atual].a != cima and lista[atual].a != baixo) {
        ma = max(lista[atual].a, ma);
    }
    if(lista[atual].b != cima and lista[atual].b != baixo) {
        ma = max(lista[atual].b, ma);
    }
    if(lista[atual].c != cima and lista[atual].c != baixo) {
        ma = max(lista[atual].c, ma);
    }
    if(lista[atual].d != cima and lista[atual].d != baixo) {
        ma = max(lista[atual].d, ma);
    }
    if(lista[atual].e != cima and lista[atual].e != baixo) {
        ma = max(lista[atual].e, ma);
    }
    if(lista[atual].f != cima and lista[atual].f != baixo) {
        ma = max(lista[atual].f, ma);
    }
    return ma;
}

int solve(int baixo, int atual) {
    if(atual == n) return 0;
    int resp = -INF;
    if(baixo == lista[atual].a) {
       resp = max(solve(lista[atual].f, atual+1)+ maior(atual, lista[atual].f, lista[atual].a), resp);
    }
    if(baixo == lista[atual].f) {
       resp = max(solve(lista[atual].a, atual+1) + maior(atual, lista[atual].a, lista[atual].f), resp);
    }
    if(baixo == lista[atual].b) {
       resp = max(resp, solve(lista[atual].d, atual+1) + maior(atual, lista[atual].b, lista[atual].d));
    }
    if(baixo == lista[atual].d) {
       resp = max(resp, solve(lista[atual].b, atual+1)+ maior(atual, lista[atual].d, lista[atual].b));
    }
    if(baixo == lista[atual].c) {
       resp = max(resp, solve(lista[atual].e, atual+1)+ maior(atual, lista[atual].e, lista[atual].c));
    }
    if(baixo == lista[atual].e) {
       resp = max(solve(lista[atual].c, atual+1) + maior(atual, lista[atual].e, lista[atual].c), resp);
    }
    
    return resp;
}


signed main() { 
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
        dado sla = {a, b, c, d, e, f};
        lista.emplace_back(sla);
    }
    int ans = -INF;
    ans = max(solve(lista[0].a, 0), ans);
    ans = max(solve(lista[0].b, 0), ans);
    ans = max(solve(lista[0].c, 0), ans);
    ans = max(solve(lista[0].d, 0), ans);
    ans = max(solve(lista[0].e, 0), ans);
    ans = max(solve(lista[0].f, 0), ans);
    cout << ans << endl;
}
/*Ideia simples, mas é chata.*/
