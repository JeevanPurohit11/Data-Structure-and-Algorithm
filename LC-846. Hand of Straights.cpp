class Solution {
public:
//using priority_queue
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if ((hand.size() % groupSize) != 0) return false;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto i : hand) {
            pq.push(i);
        }
        //maintaing to store prev element and each group interval
        int curr=0,prev=-1;
        vector<int>temp;
        while(!pq.empty()){
            int small=pq.top();
            pq.pop();
//only add if the group is new or if the next number is consecutive
            if(prev==-1 || small-prev==1){
                prev=small;
                curr++;
            }else{
                //when next group interval start these element again push into pq.
                temp.push_back(small);
            }

            if(curr==groupSize){
                curr=0;
                prev=-1;
                for(auto i : temp){
                  pq.push(i);
                }
                temp={};
            }

        }
          // if a group is incomplete then curr will be > 0.
          return curr ? false : true;
    }
};
//using multiset
  multiset<int>ms;
        for(auto i : hand){
            ms.insert(i);
        }
        while(!ms.empty()){
            //gives first element
            int small=*ms.begin();
            for(int i=0;i<groupSize;i++){
                if(ms.count(small+i)==0){
                    return false;
                }
                //here directly mp.erase doesnt work(otherwise it will erase all occurance of samll+i)
                ms.erase(ms.find(small+i));
            }
        }
        return true;