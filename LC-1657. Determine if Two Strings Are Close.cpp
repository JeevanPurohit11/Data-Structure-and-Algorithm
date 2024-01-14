class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // each char in word1 must also be in word2 and totalfreq count must be same (not matter ,which char it is)ex. aacabb->freq=a=3,b=2,c=1  freqcount=6 (we can do here swap oper.
                           //bbcbaa->freq=a=2,b=3,c=1  freqcount=6  and make equal

        int n=word1.size(),m=word2.size();
        if(m!=n) return false;
        
        vector<int>freq1(26),freq2(26);
        for(int i=0;i<n;i++){
            char w1=word1[i];
            char w2=word2[i];

            int index1=w1-'a';
            int index2=w2-'a';

            freq1[index1]++;
            freq2[index2]++;
        }
        //1st point (if any char present in word1 but not present in word2) then return false;
        //because here we cannot bring new char in words
        for(int i=0;i<26;i++){
            if(freq1[i]!=0 && freq2[i]!=0) continue;
            if(freq1[i]==0 && freq2[i]==0) continue;

            return false;
        }
        //2nd point freq count is equal then we can able to do sort operation
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());

        return freq1==freq2;


    }
};