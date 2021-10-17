//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> graycode(int n)
    {
        //code here
        queue<string> q;
        q.push("0");
        q.push("1");
        vector<string> vect;
        bool zero = true;
        while(q.size()!=pow(2,n)){
            int size = q.size();
            while(size){
                string front = q.front();
                q.pop();
                if(zero){
                    q.push(front+"0");
                    q.push(front+"1");
                    zero = false;
                }
                else{
                    q.push(front+"1");
                    q.push(front+"0");
                    zero = true;
                }
                size--;
            }
        }
        while(!q.empty()){
            vect.push_back(q.front());
            q.pop();
        }
        return vect;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}



  // } Driver Code Ends
