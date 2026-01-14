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
    string hash = "##";
    string pont = "..";
    int t; cin >> t;
    while(t--) {
        int a; cin >> a;
        for(int j = 1; j <= a; j++) {

            if(j%2 == 1) {
                for(int i = 1; i <= a; i++) {
                    if(i%2 == 1) {
                        cout << hash;
                    } else {
                        cout << pont;
                    }
                }
                cout << endl;
                for(int i = 1; i <= a; i++) {
                    if(i%2 == 1) {
                        cout << hash;
                    } else {
                        cout << pont;
                    }
                }

                cout << endl;
            } else {
                for(int i = 1; i <= a; i++) {
                    if(i%2 == 1) {
                        cout << pont;
                    } else {
                        cout << hash;
                    }
                }
                cout << endl;
                for(int i = 1; i <= a; i++) {
                    if(i%2 == 1) {
                        cout << pont;
                    } else {
                        cout << hash;
                    }
                }

                cout << endl;
            }
        }
    }
}
