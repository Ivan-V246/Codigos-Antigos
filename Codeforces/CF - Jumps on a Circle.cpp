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
const int MAXN = 1e7+5;

bool vis[MAXN];

signed main() { op
    int n, k; cin >> n >> k;
    int atual = 0;
    vis[0] = 1;
    int ans = 1;
    for(int i = 1; i <= min(n, k); i++) {
        atual += i;
        atual %= n;
        if(!vis[atual]) {
            vis[atual] = 1;
            ans++;
        }
    }
    cout << ans << endl;
}