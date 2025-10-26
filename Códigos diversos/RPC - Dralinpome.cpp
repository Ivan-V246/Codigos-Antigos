#include <bits/stdc++.h>
using namespace std;

int freq[26];

signed main() {
    string str; cin >> str;
    for(auto x : str) {
        freq[x-'a']++;
    }
    int c = 0;
    for(int i = 0; i < 26; i++) {
        c+= freq[i]%2 == 1;
    }
    if(c < 2) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}