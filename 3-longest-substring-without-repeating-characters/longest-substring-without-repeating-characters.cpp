class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int left = 0, right = 0;
        vector<int> hash(256, 0);
        
        while (right < s.size()) {
            if (hash[s[right]] == 0) {
                hash[s[right]]++;
                int len = right - left + 1;
                maxLen = max(len, maxLen);
                right++;
            } else {
                hash[s[left]]--;
                left++;
            }
        }
        
        return maxLen;
    }
};