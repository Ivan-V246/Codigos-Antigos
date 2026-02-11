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
const int MAXN = 1e5+5;
const int MOD = 1e9+7;

int fat[MAXN];

int fexp(int x, int a) {
    if(a == 1) return x%MOD;

    int resp = fexp(x, a/2);
    resp %= MOD;
    int ans = (resp*resp)%MOD;
    ans %= MOD;
    if(a%2 == 1) ans *= x;
    return ans%MOD;
}

signed main() { 
    int val = 1;
    fat[0] = 1;
    
    for(int i = 1; i < MAXN; i++) {
        val*= i%MOD;
        fat[i] = val%MOD;
        val %= MOD;
    }
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        a--;
        int ans = 0;
        ans = fat[a];
        ans *= fexp(fat[a-b], MOD-2)%MOD;
        ans%= MOD;
        ans *= fexp(fat[b], MOD-2)%MOD;
        ans%= MOD;
        cout << (ans*2)%MOD << endl;
    }
}
