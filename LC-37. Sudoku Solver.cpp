class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                      if(isValid(i,j,board,c)){
                          board[i][j]=c;
                         //if we select any availbale element and if that element letterOn not valid ,so at the time of back track we will de again board[i][j]='.',else in all recursion call if we get true then that is our answer. their can be possible multiple solution.
                          if(solve(board)==true){
                            return true;
                          }else{
                            board[i][j]='.';
                          }
                      }
                    }
                     return false;
                }
            }
        }
         return true;
    }
    bool isValid(int row,int col,vector<vector<char>>&board,char c){
        //col ans row remain same so we can directly check whole row and whole coloum .
        for(int i=0;i<9;i++){
            if(board[row][i]==c){
                return false;
            }
            if(board[i][col]==c){
                return false;
            }
            //it will check for whole subelement box 3*3 in row/col we have do (3 *) beacuse of each subpart is of 3*3 only ,(i/3) is for which 3*3 box we are in horizontal/vertical direction .(example 1= 3 horizontal and 3 vertical 3*3 box .Now last i/3 ans i%3 to get particular row and col index respectively.) 
            if(board[3*(row/3)+ i/3][3*(col/3) + i%3]==c){
                return false;
            }
        }
        return true;
    }

};