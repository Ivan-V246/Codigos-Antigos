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


string maldito_nove(string a) {
    string t = a;
    if(t[t.size()-1] == '9') {
        for(int i = t.size()-1; i >= 0; i--) t[i] = '0';
        t+= '1';
    } else {
        bool f = 0;
        for(int i = t.size()-1; i >= 0; i--) {
            if(!f) {
                if(t[i] == '9') {
                    t[i+1]++;
                    f = 1;
                }
            } 
            if(f) {
                t[i] = '0';
            }
        }
    }
    return t;
}

bool tem(string a) {
    for(auto x : a) {
        if(x == '9') return 1;
    }
    return 0;
}

signed main() { op
    int t; cin >> t;
    while(t--) {
        int n, d; cin >> n >> d;
        int temp = n;
        int u = 0;
        int tam = 0;
        string ori = "";
        while(temp > 0) {
            u = temp%10;
            ori += '0' + u;
            temp = temp/10;
            tam++;
        }
        if(d == 9) {
            do {
                ori = maldito_nove(ori);
            } while(tem(ori));
        } else if(d == 0) {
            bool f = 0;
            for(int i = ori.size()-1; i >= 0; i--) {
                if(!f) {
                    if(ori[i] == '0') {
                        f = 1;
                    }
                } 
                if(f) {
                    ori[i] = '1';
                }
            }
        } else {
            bool f = 0;
            for(int i = ori.size()-1; i >= 0; i--) {
                if(!f) {
                    if(ori[i] == '0'+ d) {
                        ori[i]++;
                        f = 1;
                    }
                } else {
                    ori[i] = '0';
                }
            }
        }
        reverse(ori.begin(), ori.end());
        int resp = 0;
        for(auto x : ori) {
            resp *= 10;
            resp += x-'0';
        }
        cout << resp-n << endl;
    }
}