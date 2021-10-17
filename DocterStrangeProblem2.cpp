

 // } Driver Code Ends

class Solution{
    public:
    vector<bool> vis;
    vector<int> dis;
    vector<bool> ans;
    vector<int> low;
    vector<int> par;
    int as;
    int t=0;
    int fa  =0;
    void dfs(vector<vector<int>> & graph , int i){
        vis[i] = true;
        dis[i] = t;
        low[i] = t;
        t++;
        int c=0;
        for(int j=0;j<graph[i].size();j++){
            if(vis[graph[i][j]]){
                if(par[i] == graph[i][j]){
                    continue;
                }
                else{
                    low[i] = min(low[i] , dis[graph[i][j]]);
                }
            }
            else{
                c++;
                par[graph[i][j]] = i;
                dfs(graph , graph[i][j]);
                low[i] = min(low[i] , low[graph[i][j]]);
                if(i!= as && low[graph[i][j]] > dis[i]){
                    ans[i] = true;
                    // fa++;
                }
            }
        }
        if(i==as && c>=2){
            ans[i] = true;
            // fa++;
        }
        
    }
    int doctorStrange(int N, int M, vector<vector<int>> & graph1)
    {
         //Write your code here
         vector<vector<int> > graph(N);
         for(int i=0;i<M;i++){
             graph[graph1[i][0]-1].push_back(graph1[i][1]-1);
             graph[graph1[i][1]-1].push_back(graph1[i][0]-1);
         }
         vis.resize(N,false);
         dis.resize(N);
         ans.resize(N,false);
         low.resize(N);
         par.resize(N,-1);
         for(int i = 0 ; i <  N ; i++) {
            if(!vis[i]) 
                as = i;
                dfs(graph , i);
                // util(gr , N , low , disc , visited , -1 , ant , tm , i);
        }
         int a = 0;
         for(int i=0;i<N;i++){
             if(ans[i]){
                 a++;
             }
         }
         return a;
    }
};


// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        for(i=0;i<m;i++)
        {
            int a,b;cin>>a>>b;
            g[i].push_back(a);
            g[i].push_back(b);
        }
        Solution ob;
        int ans = ob.doctorStrange(n, m, g);
        cout<<ans<<endl;
    }
	return 0;
}  // } Driver Code Ends
