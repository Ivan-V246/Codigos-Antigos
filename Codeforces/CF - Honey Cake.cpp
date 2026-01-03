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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

signed main() { op
    int dim[3], n;
    for(int i = 0; i < 3; i++) {
        cin >> dim[i];
    }
    cin >> n;
    int resp[3];
    for(int i = 0; i < 3; i++) {
        int g = gcd(dim[i], n);
        resp[i] = g-1;
        n/= g;
    }
    if(n == 1) {
        for(int i = 0; i < 3; i++) {
            cout << resp[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
