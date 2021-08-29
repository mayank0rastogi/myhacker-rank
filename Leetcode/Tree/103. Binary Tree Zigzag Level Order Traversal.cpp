// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>zigzag;
        
        if(root==NULL)

        {
            return zigzag;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        //flag variable is for reversing the value at every level 
        int flag=1;
      //flag=1 means left to right 
      //flag=0 means right to left
        while(!q.empty())
        {
            int size=q.size();
            vector<int>row(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                //where i belongs to front and size-1-i means back
                int idx= (flag)? i : (size-1-i);
                
                row[idx]=node->val;
                
                
                if(node->left)
                {
                    q.push(node->left);
                }
                
                if(node->right)
                {
                    q.push(node->right);
                }
                
                
            }
            //switch the flag after every level 
            
            flag=!flag;
            zigzag.push_back(row);
        }
        return zigzag;
    }
};
