#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define endl '\n'
#define f first
#define s second
#define int long long
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e3+5;
const int mod = 1e5+5;
const int raiz = 20;
const int MAXL = 20;
 
int n, x;
int pag[MAXN];
int pre[MAXN];
int dp[2][mod];
 
 
signed main() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> pre[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> pag[i];
    }
    for(int atual = n; atual >= 1; atual--) {
        for(int orc = 1; orc <= x; orc++) {
            dp[atual%2][orc] = 0;
            if(pre[atual] <= orc) {
                dp[atual%2][orc]= max(dp[atual%2][orc], dp[(atual+1)%2][orc-pre[atual]] + pag[atual]);
            }
            dp[atual%2][orc] = max(dp[atual%2][orc], dp[(atual+1)%2][orc]);
        }
    }
    cout << max(dp[1][x], dp[0][x]) << endl;
}
//Dp Iterativa, usa a malandragem do %2 pra evitar MLE.
