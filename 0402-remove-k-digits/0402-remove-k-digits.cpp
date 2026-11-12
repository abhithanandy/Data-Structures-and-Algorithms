class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        // Process each digit
        for (int i = 0; i < num.size(); i++) {

            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // If k is still left, remove digits from the end
        while (k > 0) {
            st.pop();
            k--;
        }

        // Store stack in a string
        // Store stack in a string
        string ans = "";
        
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        while (ans.size() > 0 && ans[0] == '0') {
            ans.erase(0, 1);
        }

        // If nothing is left
        if (ans == "") {
            return "0";
        }

        return ans;
    }
};