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
    string a, b; cin >> a >> b;
    for(int i = 0; i < a.size(); i++) {
        if(!(a[i] >= 'a' and a[i] <= 'z')) {
            int deslocamento = a[i] - 'A';
            a[i] = 'a'+deslocamento;
        }

        if(!(b[i] >= 'a' and b[i] <= 'z')) {
            int deslocamento = b[i] - 'A';
            b[i] = 'a'+deslocamento;
        }
    }
    if(a == b) {
        cout << 0 << endl;
    } else if(a > b) {
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }
}