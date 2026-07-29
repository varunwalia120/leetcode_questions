class Solution {
public:
    int manDist(vector<vector<int>>& points, int p1, int p2) {
        return abs(points[p1][0] - points[p2][0]) +
               abs(points[p1][1] - points[p2][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<bool> inMST(n, false);
        int minMST = 0;

        pq.push({0, 0});

        while (pq.size() > 0) {
            auto p = pq.top();
            int wt = p.first;
            int node = p.second;

            pq.pop();

            if (inMST[node])
                continue;
            inMST[node] = true;
            minMST += wt;

            for (int i = 0; i < n; i++) {
                if (!inMST[i]) {
                    int edgeWt = manDist(points, node, i);
                    pq.push({edgeWt, i});
                }
            }
        }
        return minMST;
    }
};