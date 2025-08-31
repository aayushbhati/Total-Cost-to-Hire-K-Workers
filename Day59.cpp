class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        long long val = 0;
        int check = 0, i = 0, j = costs.size() - 1;
        while (check < k) {
            while (pq1.size() < candidates && i <= j) pq1.push(costs[i++]);
            while (pq2.size() < candidates && j >= i) pq2.push(costs[j--]);
            int a, b;
            if (pq1.size() > 0) a = pq1.top();
            else a = INT_MAX;
            
            if (pq2.size() > 0) b = pq2.top();
            else b = INT_MAX;

            if (a <= b) {
                val += a;
                pq1.pop();
            } else {
                val += b;
                pq2.pop();
            }
            check++;
        }
        return val;
    }
};
