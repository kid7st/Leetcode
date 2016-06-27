class Solution {
public:
    string convert(string s, int numRows) {
        int n = (int)s.size();
        string rows[numRows];
        for (int i = 0; i < n;) {
            for (int j = 0; j < numRows && i < n; ++j, ++i)
                rows[j].push_back(s[i]);
            for (int j = numRows - 2; j > 0 && i < n; --j, ++i)
                rows[j].push_back(s[i]);
        }
        return accumulate(rows + 1, rows + numRows, rows[0]);
    }
};