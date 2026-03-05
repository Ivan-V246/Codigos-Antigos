class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int um = 0;
        for(auto x : nums) {
            if(x == 1) {
                um++;
            } else {
                um = 0;
            }
            ans = max(ans, um);
        }
        return ans;
    }
};