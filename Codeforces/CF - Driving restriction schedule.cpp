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


signed main() { op
	int n; cin >> n;
	int tempo = 0;
	bool p1 = 0, p2 = 0;
	while(n--) {
		int a; cin >> a;
		tempo += a;
		if(!p1 and tempo > 120) {
			p1 = 1;
			tempo += 180;
		}
		if(!p2 and tempo > 720) {
			p2 = 1;
			tempo += 180;
		}
	}
	cout << tempo << endl;
}
