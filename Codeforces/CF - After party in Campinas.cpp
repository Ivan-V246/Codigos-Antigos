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
	int n, m; cin >> n >> m;
	vector <pii> bares;
	vector <int> lugares;
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		bares.emplace_back(a, b);
		lugares.emplace_back(a);
	}	
	vector <int> difere;
	difere.emplace_back(-2);
	
	int ant = bares[n-1].s;

	for(int i = n-2; i >= 0; i--) {
		if(bares[i].s == ant) {
			difere.emplace_back(difere[difere.size()-1]);
		} else {
			difere.emplace_back(i+1);
			ant = bares[i].s;
		}
	}
	

	reverse(difere.begin(), difere.end());
	auto bs = [&](int val) -> int{
		int l = 0, r = lugares.size()-1;
		int ans = INF;
		while(l <= r) {
			int mid = l+(r-l)/2;
			if(lugares[mid] > val) {
				l = mid+1;
			} else {
				r = mid-1;
				ans = min(ans, mid);
			}
		}
		return ans;
	};

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		int pos = bs(a);
		if(pos == INF) {
			cout << -1 << endl;
			continue;
		}
		if(bares[pos].s != b) {
			cout << pos+1 << endl;
		} else {
			cout << difere[pos]+1 << endl;
		}
	}
}
