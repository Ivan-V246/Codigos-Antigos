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
	int n, a, b; cin >> n >> a >> b;
	vector <bool> vis(1e6+10);
	int ans = 0;
	queue <int> fila;
	fila.emplace(0);
	while(fila.size()) {
		int atual = fila.front();
		fila.pop();
		ans = max(ans, atual);
		if(vis[atual]) continue;
		vis[atual] = 1;
		if(atual >= b) {
			if(!vis[atual-b]) {
				fila.emplace(atual-b);
			}
		}
		if(n-atual >= a) {
			if(!vis[atual+a]) {
				fila.emplace(atual+a);
			}
		}
	}
	cout << ans << endl;
}
