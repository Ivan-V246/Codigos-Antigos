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
const int MAXN = 2*1e3+10;
int n, m;
int dp[MAXN][MAXN];


struct exame {
    int ini, fe, fn, pre;
};
vector <exame> provas(MAXN);

int solve(int atual, int ans) {
    if(~dp[atual][ans]) return dp[atual][ans];
    if(atual  == 0 and ans == 0) {
        return provas[1].ini;
    }
    if(atual == 0 or ans < 0) return -INF;
    

    int estudou = solve(atual-1, ans-1);
    if(estudou >= provas[atual].pre) {
        estudou = estudou - provas[atual].pre;
        estudou += provas[atual+1].ini - provas[atual].fe;
    } else {
        estudou = -INF;
    }

    int nao = solve(atual-1, ans);
    if(nao < 0) {
        nao = -INF;
    } else {
        nao += provas[atual+1].ini - provas[atual].fn;
    }

    int tempo = max(estudou, nao);

    return dp[atual][ans] = tempo;
}

signed main() { op
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        provas[i] = {a, b, c , d};
    }
    provas[n+1] = {INF, 0, 0 ,0};
    int resp = 0;
    int l = 0; 
    int r = n;
    while(l <= r) {
        int mid = (l+r)/2;
        int temp = solve(n, mid);
        if(temp >= 0) {
            resp = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout << resp << endl;
}
/*Questão de corno do krl, usa uma lógica de backtracking, pra evitar uma Dp muito grande, invertendo um parâmetro e a resposta. Vai testando todas as resps e pega a maior que der certo.*/
