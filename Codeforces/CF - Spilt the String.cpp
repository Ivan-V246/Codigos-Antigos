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
    int t; cin >> t;
    string sla;
    getline(cin, sla);
    while(t--) {
        string str;
        getline(cin, str);
        int tam = 0;
        int tot = 0;
        vector <int> pal;
        for(auto x : str) {
            if(x == ' ') {
                pal.emplace_back(tam+1);
                tot+= tam+1;
                tam = 0;
            } else {
                tam++;
            }

        }
        pal.emplace_back(tam+1);
        tot+=tam+1;
        vector <int> div;
        for(int i = 2; i*i <= tot; i++) {
            if(tot%i == 0) {
                div.emplace_back(i);
                if(tot/i != i) div.emplace_back(tot/i);
            }
        }
        bool flag = 0;
        for(auto x : div) {
            int sum = 0;
            bool certo = 1;
            for(auto y : pal) {
                sum+= y;
                if(sum == x) {
                    sum = 0;
                }
                if(sum > x) {
                    certo = 0;
                    break;
                }
            }
            if(certo) {
                flag = 1;
            }
        }
        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
