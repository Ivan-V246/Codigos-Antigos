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

string bina(int num) {
    string resp = "";
    while(num > 0) {
        resp += '0'+(num%2);
        num = num/2;
    }
    // while(resp.size() < 15) {
    //     resp += '0';
    // }
    // reverse(resp.begin(), resp.end());
    return resp;
}

signed main() {
    int t; cin >> t;
    vector <int> primo;
    for(int i = 2; i <= 50; i++) {
        bool flag = 1;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                flag = 0;
                break;
            }
        }
        if(flag) primo.emplace_back(i);
    }
    // reverse(primo.begin(), primo.end());
    // cout << endl;
    while(t--) {
        int n; cin >> n;
        set <int> num;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            num.insert(a);
        }
        vector <int> can;
        for(int i = 1; i < (1 << 15); i++) {
            string sla = bina(i);
            int a = 1;
            for(int j = 0; j < sla.size(); j++) {
                if(sla[j] == '1') a*= primo[j];
            }
            can.emplace_back(a);
        }
        sort(can.begin(), can.end());
        for(auto x : can) {
            bool flag = 1;
            for(auto y : num) {
                if(gcd(y, x) == 1) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                cout << x << endl;
                break;
            }
        }
    }
}