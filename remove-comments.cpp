//https://leetcode.com/problems/remove-comments/submissions/
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool in_block = false;
        for (auto str:source)
        {
            int i = 0;
            static string temp ;
            if (!in_block)
                    temp = "";            
            
            while (i < str.length())
            {
                if ( (str[i] == '/') && (str[i+1] == '/') && !in_block)
                     break;
                else if ( (str[i] == '/') && (str[i+1] == '*') && !in_block)
                {
                    in_block = true;
                    i+=1;                    
                }
                else if ( (str[i] == '*') && (str[i+1] == '/') && in_block)
                {
                    in_block = false;
                    i+=1;
                    
                }
                else if(!in_block)                
                    temp += str[i];
                
                i +=1;
            }
            
            if (temp.size() > 0 && !in_block)
                res.push_back(temp);
        }
        
        return res;
    }
};