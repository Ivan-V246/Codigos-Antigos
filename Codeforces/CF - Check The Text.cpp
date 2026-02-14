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
    int n; cin >> n;
    string s;
    getline(cin, s);
    getline(cin, s);
    bool cap = 0;
    int m; cin >> m;
    stack <char> frase;
    while(m--) {
        string con; cin >> con;
        if(con == "CapsLock") {
            cap = !cap;
            continue;
        }
        if(con == "Backspace") {
            if(frase.size()) frase.pop();
            continue;
        }
        if(con == "Space") {
            frase.push(' ');
            continue;
        }
        if(cap) {
            frase.push(con[0]-32);
        } else {
            frase.push(con[0]);
        }
    }
    string ans = "";
    while(frase.size()) {
        ans += frase.top();
        frase.pop();
    }
    reverse(ans.begin(), ans.end());
    if(ans == s) {
        cout << "Correct" << endl;
    } else {
        cout << "Incorrect" << endl;
    }
}
