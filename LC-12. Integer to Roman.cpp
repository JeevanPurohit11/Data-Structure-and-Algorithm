class Solution {
public:
//very nice (try using map if possible?)
    string intToRoman(int num) {
     string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
     int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};

       string ans="";
       //can also write middle condition as i<13 beacuse our roman and value length is 13 only.
      for(int i=0; num!=0 ;i++){
           while(num>=value[i]){
                 ans.append(roman[i]);
                 num-=value[i];
           }
       }
       return ans;
       }
};