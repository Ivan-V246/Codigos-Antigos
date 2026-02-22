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
    fstream final;
    fstream vali_input;
    vali_input.open("final_product_chapter_1_input.txt", ios::in);
    final.open("Final_Product_1.txt", ios::out);
    int t; vali_input >> t;
    for(int j = 0; j < t; j++) {
        int n, a, b; vali_input >> n >> a >> b;
        final << "Case #" << j+1 << ": ";
    }
    final.close();
    vali_input.close();
    return 0;
}