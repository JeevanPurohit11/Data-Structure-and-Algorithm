//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  //LOGIC IN CODE IS USING STACK WHILE TOP ELEMENT GREATER THEN CURRENT S[i] then we do pop OPERATION else PUSH ELEMENT
    string removeKdigits(string S, int K) {
        stack<char>s;
    
        for(int i=0;i<S.size();i++){
            //EVERTHING IS BETTER BUT WHO CHAN WE COMPARE A CHARACTER INTO INTEGER.?
            char c=S[i];
              
              while(!s.empty() && K>0 && s.top()>c){
                  s.pop();
                  K--;
              }
                s.push(S[i]);
        }
        while(K--){
            s.pop();
        }
        if(s.size()==0){
            return "0";
        }
        
        string ans="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        int i=0;
        reverse(ans.begin(),ans.end());
        while(ans[i]=='0'){
            i++;
        }
        if(i==ans.size()){
            return "0";
        }
        return ans.substr(i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends