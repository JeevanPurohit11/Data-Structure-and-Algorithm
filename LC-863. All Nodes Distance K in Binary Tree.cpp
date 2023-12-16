
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
//Whole question is based on on by using map making undirected graph to go back .And then using queue and set doing further operation
unordered_map<TreeNode*,TreeNode*>parent;
//store child ->parent relation
void inorder(TreeNode* root){
    if(root==NULL)  return;
    if(root->left!=NULL){
        parent[root->left]=root;
    }
    inorder(root->left);
    if(root->right!=NULL){
        parent[root->right]=root;
    }
    inorder(root->right);
}
vector<int> BSF(TreeNode* target, int k,vector<int>&ans){
     queue<TreeNode*>q;
     q.push(target);

     unordered_set<int>visited;
     visited.insert(target->val);

     while(!q.empty()){
          int n=q.size();
          if(k==0) {
              break;
          }
          while(n--){
               TreeNode* curr=q.front();
               q.pop();
               //left
               if(curr->left!=NULL && visited.count(curr->left->val)==0){
                     q.push(curr->left);
                     visited.insert(curr->left->val);
               }
               //right
                if(curr->right!=NULL && visited.count(curr->right->val)==0){
                       q.push(curr->right);
                     visited.insert(curr->right->val);
               }
               //parent
                if(parent.count(curr)!=0 && visited.count(parent[curr]->val)==0){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
               }
          }          
             k--;
     }
     while(!q.empty()){
         TreeNode* remainElement=q.front();
         q.pop();
         ans.push_back(remainElement->val);
     }
     return ans;
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        //first we create a parent child relation using map;
        inorder(root);

        BSF(target,k,ans);
        return ans;
    }
};