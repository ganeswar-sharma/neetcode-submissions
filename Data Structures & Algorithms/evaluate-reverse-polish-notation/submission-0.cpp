class Solution {
public:
    int evalRPN(vector<string>& arr) {
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] == "+") {
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();

                st.push(second + first);
            }
            else if (arr[i] == "-") {
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();

                st.push(second - first);
            }
            else if (arr[i] == "/") {
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();

                st.push(second / first);
            }
            else if (arr[i] == "*") {
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();

                st.push(second * first);
            }
            else {
                st.push(stoi(arr[i]));
            }
        }

        return st.top();
    }
};