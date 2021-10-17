#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       int dp[n];
       dp[0]=1;
       for(int i=0;i<n;i++)
       {
           dp[i]=1;
           for(int j=0;j<i;j++)
           {
               if(arr[i]>arr[j] and dp[i]<dp[j]+1)
               {
                   dp[i]=dp[j]+1;
               }
           }
       }
       return *max_element(dp,dp+n);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
