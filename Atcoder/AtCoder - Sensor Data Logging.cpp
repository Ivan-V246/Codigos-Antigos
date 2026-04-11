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
    int n, dif;  cin >> n >> dif;
    vector <pii> ans;
    int a; cin >> a;
    ans.emplace_back(0, a);
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        if(abs(a - ans[ans.size()-1].second) >= dif) ans.emplace_back(i, a);
    }
    for(auto x : ans) {
        cout << x.first << " " << x.second << endl;
    }
}