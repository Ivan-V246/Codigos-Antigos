class Solution {
puAblic:
    vector<int> getConcatenation(vector<int>& nums) {
        vector <int> ans;
        for(auto x : nums) {
            ans.emplace_back(x);
        }
        for(auto x : nums) {
            ans.emplace_back(x);
        }
        return ans;
    }
};