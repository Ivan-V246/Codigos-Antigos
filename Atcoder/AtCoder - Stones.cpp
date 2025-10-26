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
#define vi vector<int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+5;

bool dp[MAXN];
int n, k; 

signed main() {
    cin >> n >> k;
    vi lista(n); for(auto &x : lista) cin >> x;
    sort(lista.begin(), lista.end());
    memset(dp, -1, sizeof dp);
    int i = 0;
    for(; i < lista[0]; i++) {
        dp[i] = 0;
    }
    for(; i <= k; i++) {
        bool flag = 1;
        for(auto x : lista){
            if(i-x < 0) break;
            flag = flag and dp[i-x];
        }
        dp[i] = !flag;
    }
    cout << (dp[k] ? "First" : "Second") << endl;
}