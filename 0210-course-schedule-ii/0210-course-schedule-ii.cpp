class Solution {
public:
    bool isCycleDFS(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& edges){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0; i < edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(src == u){
                if(!vis[v]){
                    if(isCycleDFS(v, vis, recPath, edges)){
                        return true;
                    }
                } else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    void topoOrder(int src, vector<bool>& vis, stack<int>& s, vector<vector<int>>& edges){
        vis[src] = true;

        for(int i = 0; i < edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(src == u){
                if(!vis[v]){
                    topoOrder(v, vis, s, edges);
                }
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);
        vector<int> ans;

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(isCycleDFS(i, vis, recPath, edges)){
                    return ans; // cycle found, return empty
                }
            }
        }

        stack<int> s;
        vis.assign(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                topoOrder(i, vis, s, edges);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};