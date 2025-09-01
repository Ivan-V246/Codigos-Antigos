#include <bits/stdc++.h>
using namespace std;
#define op ios::sync_with_stdio(false); cin.tie(NULL);
#define inf 0x3f3f3f3f
#define pii pair <int, int>
#define ll long long
#define mkp make_pair 
#define endl '\n'
#define f first
#define s second 
#define tam 5
#define db cout << "blz" << endl;
const int MAXN = 2e5+5;
const int MAXL = 17;
const int MOD = 1e9+7; 
const int RAIZ = 1000;

signed main() {
    int n; cin >> n;
    int ans = 0;
    int val = 2;
    for(int i = 1; i <= n; i++) {
        if(i %2 == 0) {
            val*=2;
            val%= MOD;
        }
        ans += val;
        ans%= MOD;
    }
    cout << (ans-n)%MOD << endl;
}