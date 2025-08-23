#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f
#define pii pair<int, pair<int,int>>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+10;
int n, newn;
int ini = 0, obj;
vector <pii> bairro;
int dp[110][MAXN];

int join(int a) {
    int div = 2;
    int som = 1;
    int temp = ((bairro[a].f + bairro[a].s.f)/div)+som;
    return (temp - bairro[a].f);
}

int solve (int atual, int chair) {
    if(chair >= obj) return 0;
    if(~dp[atual][chair]) return dp[atual][chair];
    if(atual == newn) return 1e18;
    int resp;
    int caras = join(atual);
    int r1 = solve(atual+1, chair+bairro[atual].s.s) + caras;
    int r2 = solve(atual+1, chair);
    resp = min(r1, r2);

    return dp[atual][chair] = resp;
}

signed main() { op
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) {
            ini += c;
        } else {
            bairro.emplace_back(a, mkp(b, c));
        }
        obj += c;
    }
    obj = (obj/2) +1;
    newn = bairro.size();
    cout << solve(0, ini) << endl;
}
/*Bati cabeça de desatento. Aprendizados: na dp, olha o tamanho do INF e a ordem do casos base. Salva mó tempo de debug.*/
