#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define inf 0x3f3f3f3f
#define pii pair <int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = (1e5+5);
const int mod = 1e9+7;
const int raiz = 1000;
const int MAXL = 20;

struct sla{
    int x, y, q;
};

vector <sla> lista;
vector <sla> blocos[raiz+5];
bool flag = 1;

bool comp(sla n1, sla n2) {
    return n1.x < n2.x;
}

bool fun(sla n1, sla n2) {
    if(flag) return n1.y < n2.y;
    return n1.y > n2.y;
}

signed main() { op
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b, c; cin >> a >> b;
        sla temp = {a, b, i};
        lista.emplace_back(temp);
    }
    sort(lista.begin(), lista.end(), comp);
    int cont = 1;
    int ind = 0;
    sla temp = {inf, inf, 0};
    lista.emplace_back(temp);
    for(int i = 0; i <= 1000000; i+=raiz) {
        while(lista[ind].x <= (i+raiz)) {
            blocos[cont].emplace_back(lista[ind]);
            ind++;
        }
        cont++;
    }
    for(int i = 1; i <= 1000; i++) {
        if(blocos[i].size() > 0) {
            sort(blocos[i].begin(), blocos[i].end(), fun);
        }
        int pos = 0;
        for(auto x : blocos[i]) {
            cout << x.q << " ";
            pos = x.y;
        }
        if(pos > 1000) {
            flag = 0;
        } else {
            flag = 1;
        }
    }
}
