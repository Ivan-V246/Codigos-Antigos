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
const int MAXN = 21;
const int mod = 1000000007;
int n, m, s;

signed main() { 
    cin >> n >> m;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s; i++) {
        int x, y, alc; cin >> x >> y >> alc;
        ans += min(alc, n-x) * min(alc, m-y);
        ans += min(alc, x-1) * min(alc, y-1);
        ans += min(alc, x-1) * min(alc, m-y);
        ans += min(alc, y-1) * min(alc, n-x);
        ans += min(alc, x-1) + min(alc, y-1);
        ans += min(alc, n-x) + min(alc, m-y);
        ans += 1;
    }
    int grid = n*m;
    cout << (ans/grid) << endl;
}
/*Questão de corno de geometria.*/
