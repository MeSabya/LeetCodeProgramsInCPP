
/**
https://leetcode.com/problems/construct-string-from-binary-tree/submissions/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
        
        if (nullptr == t)
            return "";
        
        stack<TreeNode*> s;
        s.push(t);
        set<TreeNode*> visited;
        string res="";
        while ( !s.empty())
        {
            t = s.top();
            cout<<"s.top "<<t->val<<endl;
            if (visited.find(t) != visited.end())
            {
                s.pop();
                res.append(")");
            }else{
                visited.insert(t);
                res.append("("+to_string(t->val));
                if (t->left == nullptr && t->right != nullptr)
                    res.append("()");
                if (t->right != nullptr)
                    s.push(t->right);
                if (t->left != nullptr)
                    s.push(t->left);
                
            }
            
        }
        
        return res.substr(1, res.size()-1);
        
    }
};