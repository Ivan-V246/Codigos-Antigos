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
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e2+10;
const int sla = 1e4+10;
int n, m;
vector <int> estante[MAXN];
vector <int> ps[MAXN];
vector <pii> moedas[MAXN];
int dp[MAXN][sla]; 

int solve(int est, int resto) {
    if(~dp[est][resto]) return dp[est][resto];
    if(resto < 0) return -INF;
    if(est > n) return 0;
    if(resto == 0) return 0;
    int resp = -INF;
    for(auto x : moedas[est])  {
        resp = max(resp, solve(est+1, resto-x.s)+x.f);
    }
    resp = max(resp, solve(est+1, resto));
    return dp[est][resto] = resp;
}

signed main() { op
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (int j = 1; j <= n; j++) {
        ps[j].emplace_back(0);
        int tam; cin >> tam;
        for (int i = 0; i < tam; i++) {
            int a;
            cin >> a;
            estante[j].emplace_back(a);
            ps[j].emplace_back(a+*(ps[j].end()-1));
        } 
        for (auto x : estante[j]) {
            ps[j].emplace_back(x+*(ps[j].end()-1));
        }
        for (int i = 1; i <= m; i++) {
            if(i == tam) {
                moedas[j].emplace_back(ps[j][tam], i);
                break;
            }
            int resp = -INF;
            int x = tam;
            int y = tam-i;
            while(y <= tam) {
                resp = max(resp, ps[j][x]- ps[j][y]);
                x++;
                y++;
            }
            moedas[j].emplace_back(resp, i);
        }
    }
    cout << solve(1, m) << endl;
}
/*Tive que me preocupar com memória, e reduzir a amarzenagem em troca de tempo, embora a complexidade tenha ficado a mesma.*/
