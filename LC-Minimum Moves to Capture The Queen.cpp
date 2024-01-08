class Solution {
public:
//3 main case 
//As bishof can travel diagnoally
// if bishop is at index and 0,0 and queen is at 7,7 and inbetween there is rook any place diagnoally ex.3,3  then there will be 2 move to get to queen 
// //As rook can travel  horizontally 
// let rook is at index 0,0 and queen is at 7,7 thn if there is no bishop in between horizontally then to get queen is directly 1 move if(there have bishop in between ex.0,3) then there required 2 moves
// //As rook can travel vertically 
// let rook is at index 0,0 and queen is at 7,7 thn if there is no bishop in between horizontally then to get queen is directly 1 move if(there have bishop in between ex.3,0) then there required 2 moves
// //In any other cases answer will be 2 only 
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        //again run whole code by own see your previous submission error test case
        if (abs(e - c) == abs(f - d)) {
            if (abs(e - a) == abs(f - b) && ((a < e && a > c) || (a > e && a < c))) {
                return 2;
            }
            return 1;
        }
        if (a == e) {
            if (c == e && ((d < b && d > f) || (d > b && d < f))) {
                return 2;
            }
            return 1;
        }
        if (b == f) {
            if (d == f && ((a < c && e > c) || (a > c && e < c))) {
                return 2;
            }
            return 1;
        }
        return 2;
    }
};