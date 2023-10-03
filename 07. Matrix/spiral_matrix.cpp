#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> ans;
        int n = matrix.size();
        if (n == 0)
            return ans;

        int m = matrix[0].size();
        if (m == 0)
            return ans;
        
        int top = 0;
        int left = 0;
        int right = m - 1;
        int bottom = n - 1;

        while (top <= bottom && left <= right) {
            // Traverse top row
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++; // Increment top row index

            // Traverse rightmost column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Decrement rightmost column index

            // Traverse bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // Decrement bottom row index
            }

            // Traverse leftmost column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Increment leftmost column index
            }
        }
        
        return ans;
    }
};

int main() {
    Solution solution;

    // Create a sample matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Call the spiralOrder function to get the spiral order traversal
    vector<int> result = solution.spiralOrder(matrix);

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
