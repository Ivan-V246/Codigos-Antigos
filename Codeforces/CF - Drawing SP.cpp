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
	for(int i = 0; i < n; i++) cout << " ";
	for(int i = 0; i < n+1; i++) cout << "_";
	cout << endl;
	int k = n+1;
	for(int i = 0, j = n-1; i < n-1; i++, j--, k+=2) {
		for(int a = 0; a < j; a++) cout << " ";
		cout << "/";
		for(int a = 0; a < k; a++) cout << " ";
		cout << "\\" << endl;
	}
	cout << "/";
	for(int i = 0; i < n; i++) cout << "_";
	for(int i = 0; i < k-n; i++) cout << " ";
	cout << "\\";
	for(int i = 0; i < n+1; i++) cout << "_";
	cout << endl;
	int esp = n+1;
	for(int i = 0; i < n-1; i++, esp++, k-=2) {
		for(int a = 0; a < esp; a++) cout << " ";
		cout << "\\";
		for(int a = 0; a < k; a++) cout << " ";
		cout << "/" << endl;
	}
	for(int i = 0; i < esp; i++) cout << " ";
	cout << "\\";
	for(int i = 0; i < n+1; i++) cout << "_";
	cout << "/" << endl;
} 
