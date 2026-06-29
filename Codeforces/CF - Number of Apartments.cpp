#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define  int ll
#define op cin.tie(0); ios::sync_with_stdio(0);

signed main() {
    int n; cin >> n;
    if(n == 1 or n == 2 or n == 4) {
        cout << -1 << endl;
        return 0;
    } else if(n%3 == 0) {
        cout << n/3 << " " << 0 << " " << 0 << endl;
        return 0;
    } else if(n%5 == 0) {
        cout << 0 << " " << n/5 << " " << 0 << endl;
        return 0;
    } else if(n%7 == 0) {
        cout << 0 << " " << 0 << " "  << n/7 << endl;
        return 0;
    } else {
        int n1 = n - 3;
        if(n1%5 == 0) {
            cout << 1 << " " << n1/5 << " " << 0 << endl;
            return 0;
        } else if(n1%7 == 0) {
            cout << 1 << " " << 0 << " " << n1/7 << endl;
            return 0;
        }

        int n2 = n - 5;
        if(n2%3 == 0) {
            cout << n2/3 << " "  << 1 << " "  << 0 << endl;
            return 0;
        } else if(n2%7 == 0) {
            cout << 0 << " "  << 1 << " "  << n2/7 << endl;
            return 0;
        }

        int n3 = n - 7;
        if(n3%3 == 0) {
            cout << n3/3 << " " << 0 << " "  << 1 << endl;
            return 0;
        } else if(n3%5 == 0) {
            cout << 0 << " "  << n3/5 << " "  << 1 << endl;
            return 0;
        }

    }
}