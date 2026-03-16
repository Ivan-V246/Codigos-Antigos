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
    int t; cin >> t; 
    while(t--) {
        string str; cin >> str;
        bool resp = 0;
        for(int i = 0; i < str.size()-1; i++) {
            if(str[i] == '1') resp = 1;
        }
        if(resp) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}