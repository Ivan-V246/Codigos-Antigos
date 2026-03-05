class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        bool existe[nums.size()];
        for(auto& x : existe) x = 0;
        for(auto x : nums) existe[x-1] = 1;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(!existe[i]) ans.emplace_back(i+1);
        }
        return ans;
    }
};