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

int ada[26], py[26], ta, tp;

int comp() {
    int a = ta;
    int p = tp;
    for(int i = 0; i < 26; i++) {

        if(a == 0 and p != 0) return 1;
        if(p == 0 and a != 0) return 2;

        if(ada[i] > py[i]) {
            if(tp == py[i]) {
                return 2;
            } else {
                return 1;
            }
        }
        if(py[i] > ada[i]) {
            if(ta == ada[i]) {
                return 1;
            } else {
                return 2;
            }
        }

        a -= ada[i];
        p -= py[i];
    }
    return 0;
}

signed main() { op
    string str;
    cin >> str;
    for(auto x : str) {
        ada[x - 'a']++;
        ta++;
    }
    cin >> str;
    for(auto x : str) {
        py[x - 'a']++;
        tp++;
    }
    int n; cin >> n;
    while(n--) {
        int ope; cin >> ope;
        if(ope == 3) {
            int ans = comp();
            if(ans == 1) {
                cout << "ADA" << endl;
            } else if(ans == 2) {
                cout << "PY" << endl;
            } else {
                cout << "EMPATE" << endl;
            }
        } else {
            int k; string s; cin >> k >> s;
            if(ope == 1) {
                for(auto x : s) {
                    ada[x-'a'] += k;
                    ta += k;
                }
            } else {
                for(auto x : s) {
                    py[x-'a'] += k;
                    tp += k;
                }
            }
        }
    }
}
