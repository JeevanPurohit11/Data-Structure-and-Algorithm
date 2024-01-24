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
//here crust of code is that if any number oddcount ==1 then we make a palindrome number from it.otherwise not possible
bool checkPalindrome(int freq[]){
    int oddCount=0;
    for(int i=1;i<=9;i++){
        if(freq[i]%2==1){
            oddCount++;
        }
    }
    if(oddCount>1) return false;
    else return true;
}
void dfs(TreeNode* root,int freq[],int& ans){
    if(root==NULL){
        return;
    }
     // node exists, so include in path
    freq[root->val]++;
     // check if current node is leaf node
    if(root->left==NULL && root->right==NULL){
        if(checkPalindrome(freq)){
            ans++;
        }
    }
    dfs(root->left,freq,ans);

    //backtracking
    dfs(root->right,freq,ans);
    freq[root->val]--;

}
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        int freq[10]={0};
        dfs(root,freq,ans);
        return ans;
    }
};