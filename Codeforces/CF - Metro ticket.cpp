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
	int n, c, k; cin >> n >> c >> k;
	int total = k+c;
	int atual; cin >> atual;
	n--;
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		total += c;
		int dias = (a - atual);
		dias--;
		dias *= c;
		total += min(dias, k);
		atual = a;
	}
	cout << total << endl;
}
