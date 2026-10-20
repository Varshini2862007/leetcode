class Solution {
public:
    bool f(int i,int j,string &s,string &p,vector<vector<int>>&dp){
        //base case
        if(i>=0&&j<0)return false;
        if (i<0&&j>=0){
            for(int v=0;v<=j;v++){
                if(p[v]!='*')return false;
            }
            return true;
        }
        if(i<0&&j<0)return true;
        int val;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==p[j]||p[j]=='?')return dp[i][j]=f(i-1,j-1,s,p,dp);
        else if(s[i]!=p[j]&&p[j]!='*')return dp[i][j]=false;
        return dp[i][j]=f(i-1,j,s,p,dp)||f(i,j-1,s,p,dp);
    }
    bool isMatch(string s, string p) {
        int i=s.size(),j=p.size();
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return f(i-1,j-1,s,p,dp);
    }
};