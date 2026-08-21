class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        int n = strs.size();
        for(int i =0;i<n;i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            mpp[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto& it : mpp){
            vector<string> subAns;
            for(int i =0;i<it.second.size();i++){
                subAns.push_back(it.second[i]);
            }
            ans.push_back(subAns);
        }
        return ans;
    }
};
