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
#define vi vector<int>
#define dbg(x) cout << #x << " " << x << endl;
const int MAXN = 1e5+5;

signed main() { op
    int t; cin >> t;
    while(t--) {
        int n; string str; cin >> n >> str;
        bool ruim[300000];
        memset(ruim, 0, sizeof ruim);
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = res | (1LL << i);
        }
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '1') ruim[i+1] = 1;
        }   
        queue <int> fila;
        bool flag = 0;
        fila.emplace(0);
        while(fila.size()) {
            int atual = fila.front();
            if(atual == res) flag = 1;
            fila.pop();
            for(int i = 0; i < n; i++) {
                if(!ruim[(atual | (1 << i))]) {
                    ruim[(atual | (1 << i))] = 1;
                    fila.emplace((atual | (1 << i)));
                }
            }
        }
        if(flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}