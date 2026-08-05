class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj(n); //u -> {ngbr1, ngbr2} //O(V+E)
        vector<int> inDegree(n, 0); //O(V)
        vector<bool> suspicious(n, false);//O(V)

        for(auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        //BFS
        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while(!que.empty()) {
            int curr = que.front();
            que.pop();

            for(int &ngbr : adj[curr]) {
                inDegree[ngbr]--;
                if(!suspicious[ngbr]) {
                    que.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> result;
        bool cannotRemove = false;
        
        for(int i = 0; i < n; i++) {
            if(suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }

            if(!suspicious[i]) {
                result.push_back(i);
            }

        }

        if(cannotRemove) {
            vector<int> vec(n); 
            for(int i = 0; i < n; i++) {
                vec[i] = i;
            }
            return vec;
        }
        
        return result;


    }
};

/*
Approach:
1. Build the graph using an adjacency list and calculate the indegree of each method.
2. Start BFS from the suspicious method k and mark every reachable method as suspicious.
3. While traversing, decrease the indegree of neighbors to simulate removing edges
   coming from suspicious methods.
4. After BFS, if any suspicious method still has indegree > 0, it means it is
   still being called by a non-suspicious method, so removal is not possible.
5. In that case, return all methods. Otherwise, return only the non-suspicious methods.

Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/