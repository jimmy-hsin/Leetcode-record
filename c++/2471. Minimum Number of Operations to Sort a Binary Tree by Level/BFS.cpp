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
    int minimumOperations(TreeNode* root) {
        //BFS
        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> temp(n,-1);
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                temp[i]=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            cnt+=minSwap(temp);
        }
        return cnt;
    }

//逆向倒回: 把排列好的想辦法回復成原始狀態
    int minSwap(vector<int>& arr){
        int n=arr.size();
      //先記住每個數字的數值，及其對應的原始位置
        vector<pair<int,int>> sorted(n);
        for(int i=0;i<n;i++){
            sorted[i]={arr[i],i};
        }
      //把它由大到小排列好之後
        sort(sorted.begin(), sorted.end());
        int count=0;
        for(int i=0;i<n;i++){
            auto [val, index]=sorted[i];
            while(i!=index){  //只要sorted[i] 換到的數字不是原本的arr[i] 就一直swap下去
                swap(sorted[i],sorted[index]);  //把sorted[i] 轉到原本的位置上
                index=sorted[i].second; //會換到一個原本在sorted[index]上的數，一樣把他換到原本的位置
                count++;
            }
        }
        return count;
    }

//正向排序: 把原始狀態想辦法擺成排列好的
    int minSwap2(vector<int>& arr){
        vector<int> sorted=arr;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int> hash;
        for(int i=0;i<arr.size();i++)   hash[arr[i]]=i;

        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=sorted[i]){
                int index=hash[sorted[i]]; //sorted[i] 是這個位置的正確的數字， index是sorted[i]在原始數列中的位置
                swap(arr[i],arr[index]);   //把正確的數字換到i位
                hash[arr[index]]=index;    //更新被換走的數字的位置
                count++;
            }
        }
        return count;
    }

};
