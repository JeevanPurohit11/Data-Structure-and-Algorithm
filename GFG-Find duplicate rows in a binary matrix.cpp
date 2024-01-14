class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        vector<int>ans;
        unordered_set<string>st;
        
        for(int i=0;i<M;i++){
            string curr_Row="";
            for(int j=0;j<N;j++){
                curr_Row += to_string(matrix[i][j]);
            }
            
            if(st.count(curr_Row)>0){
                ans.push_back(i);
            }else{
                st.insert(curr_Row);
            }
        }
        return ans;
      
    } 
};
