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
	vector <int> lista(n+2);
	int s = -1;
	for(auto &x : lista) {
		cin >> x;
		s = max(s, x);
	} 
	bool f1 = 0;
	multiset <int> s1, s2;
	for(auto x : lista) {
		if(x == s and !f1) {
			f1 = 1;
			continue;
		}
		s1.insert(x);
		s2.insert(x);
	}
	auto pont = s1.begin();
	
	int m = *pont;
	m = s-m;
	s1.erase(s1.lower_bound(m));
	vector<int> ans;
	int soma = 0;
	int maior = -1;
	for(auto x : s1) {
		int a = s-x;
		maior = max(maior, a);
		soma += a;
		ans.emplace_back(a);
	}
	if(s == soma and m == maior) {
		cout << s << " " << m << endl;
		sort(ans.begin(), ans.end());
		for(auto x : ans) {
			cout << x << " ";
		}
		cout << endl;
		return 0;
	}
	pont = s2.begin();
	pont++;
	m = *pont;
	m = s-m;
	s2.erase(s2.lower_bound(m));
	ans.clear();
	soma = 0;
	maior = -1;
	for(auto x : s2) {
		int a = s-x;
		maior = max(maior, a);
		soma += a;
		ans.emplace_back(a);
	}
	sort(ans.begin(), ans.end());
	cout << s << " " << m << endl;
	for(auto x : ans) {
		cout << x << " ";
	}
	cout << endl;
}
