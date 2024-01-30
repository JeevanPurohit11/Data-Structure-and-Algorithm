//stack operation
class Solution {
public:
bool operatorCheck(string optr){
    return (optr=="+" || optr=="-"||optr=="*"||optr=="/");
}
    int evalRPN(vector<string>& tokens) {
        stack<string>ans;
        for(int i=0;i<tokens.size();i++){
            if(operatorCheck(tokens[i])){
               int res=0;
               int n2=stoi(ans.top());
               ans.pop();
               int n1=stoi(ans.top());
               ans.pop();

               if(tokens[i]=="+"){
                   res =(n1 + n2);
               }else if(tokens[i]=="-"){
                   res =(n1 - n2);
               }else if(tokens[i]=="*"){
                   res =(n1 * n2);
               }else if(tokens[i]=="/"){
                   res =(n1 / n2);
               }
               ans.push(to_string(res));
            }else{
                ans.push(tokens[i]);
            }
        }
        return stoi(ans.top());
    }
};