#include <bits/stdc++.h>
using namespace std;
#define op ios_base::sync_with_stdio(0); cin.tie(0);
#define INF 0x3f3f3f3f
#define pii pair<int, pair<int, int>>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e8;
int n1, n2, k1, k2;
int dp[101][101][11][11];

int solve(int man, int hor, int car, int cav ) {
    if(~dp[man][hor][car][cav]) return dp[man][hor][car][cav];
    if(man + hor == 0) return 1;
    
    int resp = 0;
    if (man > 0 and car > 0) {
            resp += solve(man-1, hor, car-1, k2);
    }
    if(hor > 0 and cav > 0) {
        resp += solve(man, hor-1, k1, cav-1);
    }
    
    return dp[man][hor][car][cav] = (resp%MAXN); 
}


signed main() { 
    memset(dp, -1, sizeof dp);
    cin >> n1 >> n2 >> k1 >> k2;
    cout << solve(n1, n2, k1, k2) << endl;
}
/*DP fácil, só tem muitos argumentos.*/
