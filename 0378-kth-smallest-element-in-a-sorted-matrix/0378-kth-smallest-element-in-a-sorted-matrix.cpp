class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Max Heap to store k smallest elements
        priority_queue<int> pq;

        int n = matrix.size();
        int cnt = 0;

        // Phase 1: Push first k elements into the heap
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cnt != k) {
                    pq.push(matrix[i][j]);
                    cnt++;
                } else {
                    // Exit early once k elements are pushed
                    i = n;
                    break;
                }
            }
        }

        // Phase 2: Process the remaining elements in matrix
        for (int i = k / n; i < n; i++) {
            // Determine starting column for the current row
            int startCol = (i == k / n) ? k % n : 0;
            for (int j = startCol; j < n; j++) {
                // If the current element is smaller than the largest in heap
                if (pq.top() > matrix[i][j]) {
                    pq.pop();                 // Remove the largest
                    pq.push(matrix[i][j]);    // Insert the current smaller element
                }
            }
        }

        // The top element is the kth smallest
        return pq.top();
    }
};