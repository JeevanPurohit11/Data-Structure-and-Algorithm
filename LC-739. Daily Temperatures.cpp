class Solution {
public:
//Aditiya verma (Next greater to right )
//start from back.
//at the time of iteration only find the index by j-i i.e st.top().second as j and i as loop
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
         vector<int>ans;
         int n=temperatures.size();
         for(int i=n-1;i>=0;i--){
             if(st.empty()){
                 ans.push_back(0);
             }else if( !st.empty() && st.top().first>temperatures[i]){
                 ans.push_back(st.top().second-i);
             }else if(!st.empty() && st.top().first<=temperatures[i]){
                 while(!st.empty() && st.top().first<=temperatures[i]){
                     st.pop();
                 }
                 if(st.empty()){
                     ans.push_back(0);
                 }else{
                     ans.push_back(st.top().second-i);
                 }
             }
             st.push({temperatures[i],i});
         }
         reverse(ans.begin(),ans.end());
         return ans;
 
//Aditiya verma (Next greater to right )
//start from back.
//solution aakash
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
         vector<int>ans;
         int n=temperatures.size();
         for(int i=n-1;i>=0;i--){
             if(st.empty()){
                 ans.push_back(-1);
             }else if( !st.empty() && st.top().first>temperatures[i]){
                 ans.push_back(st.top().second);
             }else if(!st.empty() && st.top().first<=temperatures[i]){
                 while(!st.empty() && st.top().first<=temperatures[i]){
                     st.pop();
                 }
                 if(st.empty()){
                     ans.push_back(-1);
                 }else{
                     ans.push_back(st.top().second);
                 }
             }
             st.push({temperatures[i],i});
         }
         reverse(ans.begin(),ans.end());
         for(int i=0;i<n;i++){
             ans[i]=ans[i]-i;
             if(ans[i]<0) ans[i]=0;
         }
         return ans;



        //brute force
        // bool flag=false;
        // for(int i=0;i<temperatures.size();i++){
        //     flag=false;
        //     for(int j=i+1;j<temperatures.size();j++){
        //         if(temperatures[j]>temperatures[i]){
        //               flag=true;
        //               ans.push_back(j-i);
        //               break;
        //         }
        //     }
        //       if(!flag) ans.push_back(0);
        // }
        // return ans;
    }
};




        //brute force
        // bool flag=false;
        // for(int i=0;i<temperatures.size();i++){
        //     flag=false;
        //     for(int j=i+1;j<temperatures.size();j++){
        //         if(temperatures[j]>temperatures[i]){
        //               flag=true;
        //               ans.push_back(j-i);
        //               break;
        //         }
        //     }
        //       if(!flag) ans.push_back(0);
        // }
        // return ans;
    }
};