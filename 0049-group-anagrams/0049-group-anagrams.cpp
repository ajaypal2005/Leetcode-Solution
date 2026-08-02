class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Stores:
        // sorted word -> list of original words
        unordered_map<string, vector<string>> groups;

        // Visit every word in the input
        for (string word : strs) {

            // Make a copy because we do not want
            // to change the original word
            string key = word;

            // Anagrams become equal after sorting
            // Example: "eat", "tea", "ate" -> "aet"
            sort(key.begin(), key.end());

            // Add the original word to its anagram group
            groups[key].push_back(word);
        }

        // Store the final groups
        vector<vector<string>> answer;

        // Copy every anagram group into the answer
        for (auto& group : groups) {
            answer.push_back(group.second);
        }

        return answer;
    }
};