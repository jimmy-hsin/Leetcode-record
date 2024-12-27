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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;
        
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> temp;    //用來存奇數排的Nodes
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                if(depth%2)  //當深度為奇數時，存進temp中
                    temp.push_back(curr);
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            if(depth%2){
                int x=temp.size();
                for(int i=0;i<x/2;i++)  //把temp中的node，頭尾的val交換
                    swap(temp[i]->val, temp[x-1-i]->val);
            }
            depth++;  //掃描完一排了，準備掃下一排，深度+1
        }
        return root;
    }
};
