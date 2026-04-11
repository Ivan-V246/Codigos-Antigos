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
    int n; string str; cin >> n >> str;
    bool flag = 0;
    string ans = "";
    for(int i = 0; i < n; i++) {
        if(str[i] != 'o') {
            flag = 1;
        }
        if(flag) ans += str[i];
    }
    cout << ans << endl;
}