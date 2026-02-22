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
const int MAXN = 1e3+5;

signed main() {
    fstream Snake_Scales_1;
    Snake_Scales_1.open("Snake_Scales_1", ios::out);
    int t; cin >> t;
    for(int j = 0; j < t; j++) {
        int n; cin >> n;
        int resp = 0;
        int ant; cin >> ant;
        for(int i = 1; i < n; i++) {
            int a; cin >> a;
            resp = max(resp, abs(ant -a));
            ant = a;
        }
        Snake_Scales_1 << "Case #" << j+1 << ": " << resp << endl;
    }
    Snake_Scales_1.close();
    return 0;
}