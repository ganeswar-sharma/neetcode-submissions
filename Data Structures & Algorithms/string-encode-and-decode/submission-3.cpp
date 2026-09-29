class Solution {
   public:
    string encode(vector<string>& strs) {
        string hashed = "";
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            int len = strs[i].size();
            hashed = hashed + to_string(len) + "#";
            for (int j = 0; j < strs[i].size(); j++) {
                hashed = hashed + strs[i][j];
            }
        }
        return hashed;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> strs;
        for (int i = 0; i < n; i++) {
                string str = "";
                int len = 0;

                while (s[i] >= '0' && s[i] <= '9') {
                    len = len * 10 + (s[i] - '0');
                    i++;
                }
                i++;
                while (len-- && i < n) {
                    str = str + s[i];
                    i++;
                }
                i--;
                strs.push_back(str);
            
        }
        return strs;
    }
};
