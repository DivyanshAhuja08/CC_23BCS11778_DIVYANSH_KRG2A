class Solution {
public:
  void dfs(int node,vector<vector<int>>&adj,vector<int>&dd){
    dd[node]=1;
    for(auto it:adj[node]){
        if(!dd[it]){
            dfs(it,adj,dd);
        }
    }
  }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    
        int count=0;
        vector<int>dd(n,0);
        for(int i=0;i<n;i++){
            if(!dd[i]){
                dfs(i,adj,dd);
                count++;
            }
        }
        return count;
        
    }
};