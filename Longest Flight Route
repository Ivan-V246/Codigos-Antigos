#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define INF 0x3f3f3f3f
#define pii pair<int, pair<int, int>>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+10;
int n, m;
vector <int> grafo[MAXN];
int dp[MAXN];
vector <int> resp;

int solve(int atual) {
    if(~dp[atual]) return dp[atual];
    if (atual == 1) return dp[atual] = 1;
    int res = -INF;

    for (auto x : grafo[atual]) 
        res = max(res, solve(x)+1);

    return dp[atual] = res;
}

void rec(int atual) {
    bool flag = 0;
    for (auto x : grafo[atual]) {
        if (solve(atual)-1 == solve(x) and !flag) { 
            rec(x);
            flag = 1;
        }
    }
    resp.push_back(atual);
    return;
}

signed main() {
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grafo[b].push_back(a);
    }
    solve(n);
    rec(n);
    if (dp[1] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dp[n] << endl;
        for (auto x : resp) {
            cout << x << " ";
        }
        cout << endl;
    }
}

/*Questão em que eu usei a técnica de recuperar a resposta numa DP.*/
