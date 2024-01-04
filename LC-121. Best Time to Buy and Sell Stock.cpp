class Solution {
public:
//using Recersion +DP memo RK

    int maxProfit(vector<int>& prices) {
        unordered_map<string,int>mp;
       return maxProfitObtain(prices,0,1,1,mp);
    }
    int maxProfitObtain(vector<int>& prices,int currentDay,int canBuy,int transactionCount,unordered_map<string,int>&mp){
        if(currentDay>=prices.size() || transactionCount==0){
            return 0;
        }
        //buying
        string currentKey=to_string(currentDay)+"#"+to_string(canBuy)+"#"+to_string(transactionCount);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        int ans=0;
        if(canBuy==1){
            //here we make changes as in if statement canBuy became 0 and in else statement canBuy became 1 .to make (our increment value will stored in previous value.when we return at last it store wrong value.)example on RK 
            int nothingDone=maxProfitObtain(prices,currentDay+1,canBuy,transactionCount,mp);
            int buy=-prices[currentDay] + maxProfitObtain(prices,currentDay+1,0,transactionCount,mp);
            ans= max(nothingDone,buy);
        }else{
            int nothingDone=maxProfitObtain(prices,currentDay+1,canBuy,transactionCount,mp);
            int sell=prices[currentDay]+maxProfitObtain(prices,currentDay+1,1,transactionCount-1,mp);
            ans= max(nothingDone,sell);
        }
        mp[currentKey]=ans;
        return mp[currentKey];
  
    }
};