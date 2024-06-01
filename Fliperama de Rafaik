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
int n;
int a[MAXN];
int b[MAXN];


signed main() { 
    cin >> n;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    if(tot % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    int l = 0;
    int r = n-1;
    int ans = 0;
    while(tot > 0) {
        if(l == r) {
            ans += (a[l] - b[l])/2;
            tot -= a[l]- b[l];
            b[l] = a[l];
        } else {
            int esq = a[l] - b[l]; 
            int dir = a[r] - b[r];
            if(esq == 0 and dir == 0) {
                ans+= 2;
                l++;
                r--;
            } else if (esq == 0) {
                ans++;
                l++;
            } else if(dir == 0) {
                ans++;
                r--;
            } else if(esq < dir) {
                b[l] += esq;
                b[r] += esq;
                tot -= esq*2;
                ans += esq;
            } else if(dir < esq) {
                b[r] += dir;
                b[l] += dir;
                tot -= dir*2;
                ans+= dir;
            } else {
                b[r] += dir;
                b[l] += esq;
                tot -= dir + esq;
                ans += dir;
            }
        }
    }
    if(tot == 0) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}
