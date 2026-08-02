class Solution {
public:
    bool isAnagram(string s, string t)
     {
     vector<int> arr(256,0) ;
     for(int i = 0; i<s.size(); i++)
     {
        arr[s[i]]++;
     } 
     
     for(int i = 0; i<t.size(); i++)
     {
        arr[t[i]]--;
     } 
     
     for(int i = 0; i<256; i++){
        if(arr[i]!=0) return false;
     } 
    return true;
    }
};