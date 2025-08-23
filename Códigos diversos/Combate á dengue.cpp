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
const int MAXN = 1e5+10;
const int MAXL = 20;
int obj, n;
vector <pii> focos;
bool vi[16];
double dp[16][655555];
double dist[16][16];

double calc(int a, int b) {
    if(dist[a][b] != 0) return dist[a][b];
    int c1 = abs(focos[a].f - focos[b].f);
    int c2 = abs(focos[a].s - focos[b].s);

    return dist[a][b] = (sqrt((c1*c1)+ (c2*c2))); 
}



double solve(int atual, int mask) {
    if(dp[atual][mask] != 0) return dp[atual][mask];
    if(mask == obj) {
        double sla = calc(0, atual);
        return sla;
    }
    double resp = INF;
    for(int i = 1; i <= n; i++) {
        if(!vi[i]) {
            double custo = calc(i, atual);
            vi[i] = 1;
            resp = min(resp, solve(i, (mask | (1 << i))) + custo);
            vi[i] = 0;
        }
    }

    return dp[atual][mask] = resp;
}

signed main() { op
    while(true) {
    cin >> n;
    memset(dp, 0, sizeof dp);
    memset(dist, 0, sizeof dist);
    focos.clear();
    if(n == 0) return 0;
    obj = 0;
    for(int i = 0; i <= n; i++) {
        obj = (obj | (1 << i));
    }
    for(int i = 0; i <= n; i++) {
        int a, b; cin >> a >> b;
        focos.emplace_back(a, b);
    }    
    solve(0, 1);
    cout << fixed << setprecision(2) << dp[0][1] << endl;
    
    }
}
