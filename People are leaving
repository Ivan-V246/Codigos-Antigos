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
const int MAXN = 1e6+10;
int n, m;
vector <int> pai(MAXN);
 
int find(int x) {
    if(pai[x] == x or pai[x] == -1) return pai[x];
    return pai[x] = find(pai[x]);
}
 
void unir (int x, int y) {
    int a = find(x), b = find(y);
    if(a == b) return;
    pai[a] = b;
}
 
 
signed main() { op
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        pai[i] = i;
    }
    for (int i = 0; i < m; i++) {
        char com;
        int a;
        cin >> com >> a;
        if(com == '?') {
            cout << find(a) << endl;
        } else {
            if(a == n) {
                pai[n] = -1;
            } else {
                unir(a, a+1);
            }
        }
    }
}
/*Dsu utilizando Path Compression.*/
