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
const int MAXN = 1e5;
int n;
set <int> resp;
vector <int> ativos;


void solve(int mask, int atual) {
    resp.insert(mask);
    if(atual == -1) return;
    solve(mask, atual-1);
    solve((mask & (~(1LL << (ativos[atual])))), atual-1);
}

signed main() { op 
    cin >> n;
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < 61; i++) {
        if((n | (1LL << i)) == n) {
            ativos.emplace_back(i);
        }
    }
    solve(n, ativos.size()-1);
    for (auto x : resp) {
        cout << x << endl;
    }
}
