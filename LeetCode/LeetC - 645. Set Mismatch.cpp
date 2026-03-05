class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int freq[nums.size()];
        for(auto& x : freq) x = 0;
        vector <int> ans(2);
        for(auto x : nums) {
            freq[x-1]++;
            if(freq[x-1] == 2) ans[0] = x;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(freq[i] == 0) ans[1] = i+1; 
        }
        return ans;
    }
};