// GFG
// Dijkstra Algorithm is used to find the shortest distance from the source node to all Nodes
// It Can't be used for Negeative Cycles because It will go into Infinite Loop.
// We Generally have 3 approaches:

// 1. Using Queue.  -> This take more time than other Approaches.
// 2. Using Priority Queue -> This is the 2nd Best Approach.
// 3. Using Set -> There is slight Difference Between Priority Queue and Set . It is Somewhat Faster than Priority Queue Because We will remove all the Duplicate Occurences.

// Time Complexity ---> O ( E x Log(V) )

// Space Complexity ---> O (E + V)

class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s){
        // Code here
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dist(v,INT_MAX);
        pq.push({0,s});
        dist[s] = 0;
        while(!pq.empty()){
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            for(auto it : adj[y]){
                int weight = it[1];
                int node = it[0];
                if((x + weight) < dist[node]){
                    dist[node] = x + weight;
                    pq.push({dist[node] , node});
                }
            }
        }
        return dist;
    }
};
