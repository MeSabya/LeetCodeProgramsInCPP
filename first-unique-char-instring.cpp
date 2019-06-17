/* 
https://leetcode.com/problems/first-unique-character-in-a-string/submissions/ 
*/

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        int len = s.length();
        
        for (int i = 0; i<len; i++)
        {
            if (mp.find(s[i]) == mp.end())
            {
                mp[s[i]] = 1;
            }
            else{
                mp[s[i]] = mp[s[i]]+1; 
            }
        }
        
        for (int i = 0; i < len; i++)
        {
            if (mp[s[i]] == 1)
                return i;
        }
        
        return -1;
        
       
    }
};