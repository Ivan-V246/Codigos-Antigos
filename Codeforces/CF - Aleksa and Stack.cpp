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
const int MAXN = 3e5+5;

vector <int> resp;

signed main() { op
    resp.emplace_back(2);
    resp.emplace_back(3);
    for(int i = 4; resp.size() < MAXN; i++) {
        int a = resp[resp.size()-1];
        int b = resp[resp.size()-2];
        if((3*i) % (a+b) != 0) {
            resp.emplace_back(i);
        }
    }
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            cout << resp[i] << " ";
        }
        cout << endl;
    }
}
