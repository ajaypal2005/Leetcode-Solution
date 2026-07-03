class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        int dpNoDel = arr[0];       // max sum ending at i without deletion
        int dpOneDel = 0;           // max sum ending at i with one deletion
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            // Update dpOneDel first to avoid using updated dpNoDel
            dpOneDel = max(dpOneDel + arr[i], dpNoDel);  

            // Standard Kadane’s update
            dpNoDel = max(dpNoDel + arr[i], arr[i]);

            ans = max(ans, max(dpNoDel, dpOneDel));
        }

        return ans;
    }
};
