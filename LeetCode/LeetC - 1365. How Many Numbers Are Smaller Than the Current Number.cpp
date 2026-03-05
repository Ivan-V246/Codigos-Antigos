class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        set <int> con;
        int quant[105];
        for(auto& x : quant) {
            x = 0;
        }
        for(auto x : nums) {
            con.insert(x);
            quant[x]++;
        }
        int resp[105];
        int temp = 0;
        for(auto x : con) {
            resp[x] = temp;
            temp+=quant[x];;
        }
        vector <int> ans;
        for(auto x : nums) {
            ans.emplace_back(resp[x]);
        }
        return ans;
    }
};