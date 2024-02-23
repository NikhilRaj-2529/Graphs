// GFG
// Bell Man Ford Algorithm also used for find the Minimum path from the given source path.
// It is used for Negative Cycle also.
// It is advanced Version of Dijkstra's Algorithm
// Time Complexity = O(V*E)

// Space Complexity = O(V)

class Solution {
  public:
    vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s) {
        // Code here
        vector<int> dist(v,1e8);
        dist[s] = 0;
        for(int i = 0 ; i < v - 1 ; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int weight = it[2];
                if(dist[u] != 1e8 and (dist[u] + weight) < dist[v]){
                    dist[v] = dist[u] + weight;
                }
            }
        }
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int weight = it[2];
            if(dist[u] != 1e8 and (dist[u] + weight) < dist[v]) return {-1} ;
        }
        return dist;
    }
};
