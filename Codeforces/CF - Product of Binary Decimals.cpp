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

vector <string> num;
string sla = "";
set <int> bin;

void solve(int c) {
    if(c == 8) {
        return;
    }
    num.emplace_back(sla);
    string ori = sla;
    sla+= "0";
    solve(c+1);
    sla = ori;

    sla += "1";
    solve(c+1);
    sla = ori;
}

signed main() { op
    int t; cin >> t;
    solve(0);
    for(auto x : num) {

        int b = 0;
        for(auto y : x) {
            b *= 10;
            b+= ( y - '0');
        }
        bin.insert(b);
    }
    bin.erase(0);
    bin.erase(1);
    vector <int> nbin;

    for(auto x : bin) {
        nbin.emplace_back(x);
    }

    while(t--) {
        int a; cin >> a;
        auto pont = lower_bound(nbin.begin(), nbin.end(), a);
        if((*pont) == a) {
            a = 1;
        }   
        bool flag = 0;
        int cont = 0;
        while(cont < nbin.size()) {
            if(a % nbin[cont] == 0) {
                a /= nbin[cont];
            } else {
                cont++;
            }
        }
        if(a == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
