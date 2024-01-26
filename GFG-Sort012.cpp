///important asked in interview for 0 1,2,3,4 more number and then sort 
//next time using binary search and slow with O(N) time complexcity 
// and below code complexcity is O(N)+O(N)

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here
       int first=0,second=0,third=0;
       for(int i=0;i<n;i++){
           if(a[i]==0){
               first++;
           }else if(a[i]==1){
               second++;
           }else{
               third++;
           }
       }
       for(int i=0;i<first;i++){
           a[i]=0;
       }
       for(int i=first;i<first+second;i++){
           a[i]=1;
       }
      for(int i=first+second;i<n;i++){
           a[i]=2;
       }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends