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
  //BFS
//Approach-1 (Convert tree to graph)
//T.C : O(n) - visiting all nodes
//S.C : O(n) - storing all nodes in graph

        //first make adj list all all parent child relation (while calling dfs or bfs)
       //store level(surrounding element) of each node (like a adj list in gfg)
       //set using as a visited array

void makeAdjList(unordered_map<int,vector<int>>&adj,int parrent,TreeNode* root){
    if(root==NULL){
        return;
    }
    //here we are pushing parent into current Node.
    if(parrent!=-1){
        adj[root->val].push_back(parrent);
    }
    if(root->left!=NULL){
       adj[root->val].push_back(root->left->val);
    }
    if(root->right!=NULL){
       adj[root->val].push_back(root->right->val);
    }
    makeAdjList(adj,root->val,root->left);
    makeAdjList(adj,root->val,root->right);

    return;
}
    int amountOfTime(TreeNode* root, int start) {
        //BFS
        //first make adj list all all parent child relation (while calling dfs or bfs)
       //store level(surrounding element) of each node (like a adj list in gfg)
        unordered_map<int,vector<int>>adj;
        //let be -1 be parent of root node as there is no parent node for it. 
        makeAdjList(adj,-1,root);

        int minute=0;
        queue<int>q;
        q.push(start);
       set<int>visited;
       visited.insert(start);
       
        while(!q.empty()){
            //because each time we see level nodes ,therefore we count n each time.
            int n=q.size();
            while(n--){
                int curr=q.front();
                q.pop();
             for(auto neighbour : adj[curr]){
                 //If not inserted in visited.(not found)
                 if(visited.find(neighbour)==visited.end()){
                     q.push(neighbour);
                     visited.insert(neighbour); 
                 }
             }
            }
            minute++;
        }
        //at last one  time extra minute be counted.
return minute-1;
    }
};