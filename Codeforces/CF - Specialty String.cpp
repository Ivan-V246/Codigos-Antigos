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
const int MAXN = 5e3+5;

signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        stack <char> pilha;
        for(auto x : str) {
            if(pilha.empty()) {
                pilha.emplace(x);
            } else {
                if(x == pilha.top()) {
                    pilha.pop();
                } else {
                    pilha.emplace(x);
                }
            }
        }
        if(pilha.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}