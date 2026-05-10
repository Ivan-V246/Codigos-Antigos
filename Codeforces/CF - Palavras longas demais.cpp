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
const int MAXN = 1e6+5;


signed main() { 
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string a; cin >> a;
        int tam = a.size();
        if(tam > 10) {
            cout << a[0] << tam-2 << a[tam-1] << endl;
        } else {
            cout << a << endl;
        }
    }
}