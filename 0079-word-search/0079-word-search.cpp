class Solution {
public:
    void find(vector<vector<char>>& board,string word,int ind,int i,int j,bool &flag,vector<pair<int,int>>&dir,vector<vector<int>>&vis){
        //base case
        int r=board.size(),c=board[0].size();
        if(ind==word.size()){
            flag=true;
            return;
        }
        for(int v=0;v<4;v++){
            int newi=i+dir[v].first;
            int newj=j+dir[v].second;
            if(newi>=0&&newi<r&&newj<c&&newj>=0&&board[newi][newj]==word[ind]&&vis[newi][newj]==0){
                vis[newi][newj]=1;
                if(flag==false)find(board,word,ind+1,newi,newj,flag,dir,vis);
                vis[newi][newj]=0;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool flag=false;
        int r=board.size(),c=board[0].size();
        int nochar=r*c;
        if(word.size()>nochar)return false;
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};//0-up  1-down 2-left  3-right  (i,j)
        vector<vector<int>>vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    if(flag==false)find(board,word,1,i,j,flag,dir,vis);
                    vis[i][j]=0;
                }
            }
        }
        return flag;
    }
};