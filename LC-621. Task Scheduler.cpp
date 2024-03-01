//max heap
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    //greedy approach
    //     int hash[26]={0};
    //    int chunks=INT_MIN;
    //     for(auto i : tasks){
    //         hash[i-'A']++;
    //         chunks=max(chunks,hash[i-'A']);
    //     }
    //     sort(hash,hash+26);
    //     int idle=chunks*n;
    //     for(int i=0;i<tasks.size();i++){
    //         idle-=min(hash[i-'A']
    //     }
       

       //priority queue (at each time we push element-1 in max heap and if )
       unordered_map<char,int>freq;
       for(auto i : tasks) freq[i]++;

       priority_queue<int>pq;
       for(auto i : freq){
           pq.push(i.second);
       }
       int result=0;
       while(!pq.empty()){
           int time=0;
           vector<int>temp;
           for(int i=0;i<n+1;i++){
               if(!pq.empty()){
                   temp.push_back(pq.top()-1);
                   pq.pop();
                   time++;
               }
           }
           for(auto i : temp){
               if(i) pq.push(i);
           }
           result+=pq.empty() ? time : n+1;  // IMP: if the pq is empty, it means all tasks have been completed
                                                //, so we do not have to add time(n+1) for the complete last cycle
                                                //,  only add the time for completing the remaining tasks in that cycle
       }
       return result;

    }
};