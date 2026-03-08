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
        string s, t; cin >> s >> t;
        map<char, char> sai;
        bool flag = 1;
        for(int i = 0; i < s.size(); i++) {
            if(sai.count(s[i]) == 0) {
                sai[s[i]] = t[i];
            } else {
                if(sai[s[i]] != t[i]) {
                    flag = 0;
                }
            }
        }
        sai.clear();
        swap(s, t);
        for(int i = 0; i < s.size(); i++) {
            if(sai.count(s[i]) == 0) {
                sai[s[i]] = t[i];
            } else {
                if(sai[s[i]] != t[i]) {
                    flag = 0;
                }
            }
        }
        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}