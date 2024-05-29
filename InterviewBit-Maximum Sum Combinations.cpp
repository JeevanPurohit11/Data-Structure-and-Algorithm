vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
   sort(A.rbegin(),A.rend());
   sort(B.rbegin(),B.rend());
   
   priority_queue<pair<int,pair<int,int>>>max_heap; // sum,{i,j}
   max_heap.push({A[0]+B[0],{0,0}});
   set<pair<int,int>>st; //store indexs
   st.insert({0,0});
   vector<int>ans;
   while(C--){
       int sum=max_heap.top().first;
       int i=max_heap.top().second.first;
       int j=max_heap.top().second.second;
       max_heap.pop();
       ans.push_back(sum);
       if(st.find({i+1,j})==st.end()) {       // we are just seeing for diagonal adjacent pair,beacuse it would be less time consuming rather then checking each element of A with whole array of B or visa versa.
          max_heap.push({A[i+1]+B[j],{i+1,j}});
          st.insert({i+1,j});
       }
        if(st.find({i,j+1})==st.end()) {       // we are just seeing for diagonal adjacent pair,beacuse it would be less time consuming rather then checking each element of A with whole array of B or visa versa.
          max_heap.push({A[i]+B[j+1],{i,j+1}});
          st.insert({i,j+1});
       }  
   }
   return ans;
}