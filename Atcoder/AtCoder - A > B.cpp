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

struct BIT {
	int N;
	vector<int> bit;

	BIT(){}
	BIT(int n) : N(n+1), bit(n+1){}

	void update(int pos, int val){
		for(; pos < N; pos += pos&(-pos))
			bit[pos] += val;
	}

	int query(int pos){
		int sum = 0;
		for(; pos > 0; pos -= pos&(-pos))
			sum += bit[pos];
		return sum;
	}

};

signed main() { op
    int n; string str; cin >> n; cin >> str;

    BIT bit(1e6+10);

    int ans = 0;
    int valor = 0;
    bit.update(n+1, 1);
    for(auto x : str) {
        if(x == 'A') valor++;
        if(x == 'B') valor--;
        ans += bit.query(valor+n);
        bit.update(valor+n+1, 1);
    }
    cout << ans << endl;
}