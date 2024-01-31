class Solution {
public:
//backtracking IMP
//love babbar (here first we take empty string temp and  element at current number [that is number in map/keypad ]  then taking that element and making pair of it with
//all of element at currentindex+1 and when element at that index in finish we will pop first element from index at the time of backtracking.)
//example "23" we take a and then join element at currentIndex+1(ad,ae,af)then
//when backtrack we remove "a" and then join b + d,e,f same for c .  
void solve(vector<string>&ans,string temp,string map[],int currentIndex,string digits){
    if(currentIndex>=digits.size()){
        ans.push_back(temp);
        return;
    }
    //doing this because to optain the number beacuse either we will get here charcter.
    //converting character into number
    int number=digits[currentIndex]-'0';
    string curr=map[number];
    for(int i=0;i<curr.size();i++){
        temp.push_back(map[number][i]);
        solve(ans,temp,map,currentIndex+1,digits);
        temp.pop_back();
    }
    return;
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        string map[10]= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp="";
        solve(ans,temp,map,0,digits);
        return ans;
        }
};