


class Solution {
public:

    void gen(string &s , int open , int close , vector<string> &ans ){
        if(open==0 && close ==0){
            ans.push_back(s);
        }
        if(open > 0){
            s.push_back('(');
            gen(s,open-1,close,ans);
            s.pop_back();
        }

        if(close>0){
        if(open < close){
            s.push_back(')');
            gen(s , open , close-1,ans);
            s.pop_back();
        }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        gen( s , n , n , ans);
        return ans ;
    }
};