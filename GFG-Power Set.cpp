//same as subset in leetcode 78 ,
//whole question is based on the bit magic i.e number of set bits from 1 to n-1 are the one subsequences .
//and the number of subsequenece exist are (2^n-1)
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    int n=pow(2,s.size());
		    int flag=0;
		    for(int i=1;i<n;i++){
		        int x=i;
		        int j=0;
		        string temp="";
		        while(x>0){
		            if(x&1){
		                temp+=s[j];
		            }
		             j++;
		             x=x>>1;
		        }
		          ans.push_back(temp);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//2 loop
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
        int n = s.size();

        // Iterate through all possible subsets
        for (int i = 1; i < (1 << n); i++) {
            string temp = "";
            // Iterate through each index of the input string
            for (int j = 0; j < n; j++) {
                // Check if the j-th bit of i is set
                if (i & (1 << j)) {
                    temp += s[j]; // Include the character at index j in the current subset
                }
            }
            ans.push_back(temp); // Add the generated string to the vector
        }

        // Sort the vector of strings
        sort(ans.begin(), ans.end());

        return ans;
		}
};