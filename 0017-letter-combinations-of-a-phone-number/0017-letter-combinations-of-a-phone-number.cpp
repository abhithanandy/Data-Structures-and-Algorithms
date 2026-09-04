class Solution {
public:
    void solve(
        int index,
        string &digits,
        vector<string>&ans,
        string &path,
        vector<string>&mp
    ){
        if(index==digits.size()){
            ans.push_back(path);
            return;
        }
        string letters=mp[digits[index]-'0'];
        for(int i=0;i<letters.size();i++){
            char ch=letters[i];

            path.push_back(ch);
            solve(index+1,digits,ans,path,mp);
            path.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return{};
        }
        vector<string>ans;
        string path;

        vector<string>mp={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };

        solve(0,digits,ans,path,mp);
        return ans;
        
    }
};