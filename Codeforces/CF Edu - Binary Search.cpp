#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k; 
    vi lista(n+1, 0);
    for(int i = 0 ; i < n; i++) {
        cin >> lista[i+1];
    }
    while(k--) {
        int a; cin >> a;
        int l = 1, r = n;
        bool flag = 0;
        while(l <= r){
            int mid = (r-l)/2 + l;
            if(lista[mid] == a) {
                flag = 1;
                break;
            }
            if(lista[mid] > a) {
                r = mid -1;
            } else {
                l = mid+1;
            }
        }
        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}