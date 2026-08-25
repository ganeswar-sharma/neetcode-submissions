class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        int ans = 1;
        int maxAns = INT_MIN;
        for(int i =1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            else if(nums[i] == nums[i-1]+1){
                ans++;
            }
            else{
                maxAns = max(ans, maxAns);
                ans = 1;
            }
        }
        maxAns = max(ans, maxAns);
        return maxAns;
    }
};
