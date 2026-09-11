class Solution {
public:
    void help(vector<int>& digits, int &ans, vector<int>& temp, vector<int>& vis){
        
        // We have created a 3-digit number
        if(temp.size() == 3){
            // Last digit must be even
            // First digit must not be 0
            if(temp[2] % 2 == 0 && temp[0] != 0){
                ans++;
            }
            return;
        }

        // Try every digit
        for(int i = 0; i < digits.size(); i++){
            
            // This copy of the digit is already being used
            if(vis[i]) continue;

            // Skip duplicate branches
            if(i > 0 && digits[i] == digits[i-1] && !vis[i-1])
                continue;

            // First digit cannot be 0
            if(temp.size() == 0 && digits[i] == 0)
                continue;

            // Choose this digit
            vis[i] = 1;
            temp.push_back(digits[i]);

            // Choose the next digit
            help(digits, ans, temp, vis);

            // Undo the choice
            temp.pop_back();
            vis[i] = 0;
        }
    }

    int totalNumbers(vector<int>& digits) {
        
        // Put equal digits next to each other
        sort(digits.begin(), digits.end());

        vector<int> vis(digits.size(), 0);
        vector<int> temp;

        int ans = 0;

        help(digits, ans, temp, vis);

        return ans;
    }
};