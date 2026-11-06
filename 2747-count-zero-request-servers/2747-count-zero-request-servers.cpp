class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {

        // Sort logs by request time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();

        // Store {queryTime, originalIndex}
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        // Process queries in increasing order of time
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(q);

        // freq[server] = number of logs of that server
        // currently inside the sliding window
        unordered_map<int, int> freq;

        // activeServers = count of distinct servers that
        // have at least one request inside current window
        int activeServers = 0;

        // Two pointers over sorted logs:
        // right -> adds logs entering the window
        // left  -> removes logs leaving the window
        int left = 0, right = 0;

        for (auto& [queryTime, idx] : sortedQueries) {

            int windowStart = queryTime - x;

            /*
             * STEP 1:
             * Expand window on the right.
             * Include all logs with time <= queryTime.
             */
            while (right < logs.size() && logs[right][1] <= queryTime) {
                int server = logs[right][0];

                freq[server]++;

                // First occurrence of this server in window
                if (freq[server] == 1)
                    activeServers++;

                right++;
            }

            /*
             * STEP 2:
             * Shrink window from the left.
             * Remove logs with time < windowStart.
             * (Logs must stay inside [queryTime-x, queryTime])
             */
            while (left < right && logs[left][1] < windowStart) {
                int server = logs[left][0];

                freq[server]--;

                // Server no longer appears in window
                if (freq[server] == 0)
                    activeServers--;

                left++;
            }

            /*
             * activeServers = servers having at least one log
             * in the current interval.
             *
             * Therefore:
             * zero-request servers = total servers - active servers
             */
            ans[idx] = n - activeServers;
        }

        return ans;
    }
};