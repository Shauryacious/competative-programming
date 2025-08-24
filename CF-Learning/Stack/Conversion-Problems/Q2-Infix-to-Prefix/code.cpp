class Solution {
    bool isOperand(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
public:
    string infixToPrefix(string s) {
        int n = s.size();
        stack<char> st;
        string ans = "";

        map<char, int> precedence = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3}
        };

        // Step 1: Reverse the string
        reverse(s.begin(), s.end());

        // Step 2: Replace '(' with ')' and vice versa
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                s[i] = ')';
            } else if (s[i] == ')') {
                s[i] = '(';
            }
        }

        // Step 3: Process the string
        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (isOperand(ch)) {
                ans += ch;
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // FIX: guard pop on empty
            } else { // Operator case
                if (s[i] == '^') {
                    while (!st.empty() && st.top() != '(' && precedence[st.top()] >= precedence[ch]) {
                        ans += st.top();
                        st.pop();
                    }
                } else {
                    while (!st.empty() && st.top() != '(' && precedence[st.top()] > precedence[ch]) {
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(ch);
            }
        }

        while (!st.empty()) {
            if (st.top() != '(') ans += st.top(); // harmless if any stray '('
            st.pop();
        }

        // Step 4: Reverse the result to get the prefix expression
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
