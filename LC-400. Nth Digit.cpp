class Solution {
public:
//TRY using BINary serch
//Here we do 3 thing
//1st= finding the number comes in which range of digits
//i.e 1 digit Range={1,9} =9 number
   // 2 digit Range={10,99}=90 number
   // 3 digit Range={100,999}=900 number
//then
//2nd step Find that number in n- previous digit range( Inshort find number)
//3rd step find that number index .
    int findNthDigit(int n) {
        //Here we use total for separating the not using digit range. 
        //finding range
        long long digit=1,base=9,total=0;
        while(total+ base*digit <n){
            total+=(digit*base);
            base*=10;
            digit++;
        }
        //finding number from range
        n-=total;
        int num=pow(10,digit-1);
        num+=(n-1)/digit;
        //finging index;
        int index=(n-1)%digit;
        string ans=to_string(num);
        
        return ans[index]-'0';


    }
};

//binary search
