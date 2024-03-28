class Solution {
public:
//3 thing IMP (striver)
//lower diagnoal  (row+col)
//Upper diagonal (n-1)+(col-row)
//left row  (n)
//here row + col == will see all place lower diagonally does the queen is in this diagonal index
//also same for n-1 +col-row will check for upper diagnoal index have a queen or not .

void solve(int col,vector<vector<string>>&ans,vector<string>&board,vector<int>&leftRow,vector<int>&lowerDiagonal,vector<int>&upperDiagonal ,int n ){

     if(col==n){
        ans.push_back(board);
        return;
     }

    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1 + col-row]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiagonal[row + col]=1;
            upperDiagonal[n-1 +col-row]=1;
            solve(col+1,ans,board,leftRow,lowerDiagonal,upperDiagonal,n);
            board[row][col]='.';
            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1 +col-row]=0;
        }
    }
  
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftRow(n,0);
        vector<int>lowerDiagonal(2*n-1,0);  //0 to 2*n-1 all summation form from col + row will be same help to obtain the lower diagonal has a queen or not .same for upper . ex for n=4 ,the range of array lower=2*4-1=7.
        vector<int>upperDiagonal(2*n-1,0);  
        solve(0,ans,board,leftRow,lowerDiagonal,upperDiagonal,n);
        return ans;

    }
};