class Solution {
   public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        set<string> st;
        for (int i = 0; i < n; i++) {
            string email = emails[i];
            string s = "";
            for (int j = 0; j < email.size(); j++) {
                if (email[j] == '+') {
                    while (email[j] != '@') {
                        j++;
                    }
                }
                else if (email[j] == '.' && s.find('@') == string::npos) {
                    continue;
                }
                s = s+ email[j];
            }
            st.insert(s);
        }
        return st.size();
    }
};