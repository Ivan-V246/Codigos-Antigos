class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int tam = target.size();
        int pont = 0;
        vector <string> ans;
        for(int i = 1; i <= n; i++) {
            if(pont == tam) break;
            ans.emplace_back("Push");
            if(i != target[pont]) {
                ans.emplace_back("Pop");
            } else {
                pont++;
            }
        }
        return ans;
    }
};