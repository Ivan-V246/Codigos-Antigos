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
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = (2 << 15)+10;
int n, m, l, r;
vector <int> quest;
set <int> resp;

void solve(int mask, int atual) {
    resp.insert(mask);
    if(atual == n) return;
    solve(mask | (1 << atual), atual+1);
    solve(mask, atual+1);
}

signed main() { op
    cin >> n >> l >> r >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        quest.emplace_back(a);
    }
    sort(quest.begin(), quest.end());
    solve(0, 0);
    int ans = 0;
    for (auto x : resp) {
        int cont = 0;
        int temp = x;
        int minimo = INF;
        int maximo = -INF;
        int soma = 0;
        while(temp > 0) {
            if(temp% 2) {
                soma += quest[cont];
                minimo = min(quest[cont], minimo);
                maximo = max(quest[cont], maximo);
            }
            temp/=2;
            cont++;
        }
        if(soma >= l and soma <= r and (maximo - minimo) >= m) ans++;
    }
    cout << ans << endl;
}
/*Bruteforce de Bitmask. Esquisito, mas não tão difícil.*/
