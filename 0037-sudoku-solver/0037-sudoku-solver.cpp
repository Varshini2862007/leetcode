class Solution {
public:
    bool isvalid(int i,int j,int val,vector<vector<char>>&board){
        char ch=val+'0';
        //horizontal
        int r=i,c=j;
        for(int col=0;col<9;col++){
            if(board[r][col]==ch)return false;
        }
        //vertical
        for(int row=0;row<9;row++){
            if(board[row][c]==ch)return false;
        }
        //matrix
        r=(i/3)*3,c=(j/3)*3;
        for(int u=r;u<(r+3);u++){
            for(int v=c;v<(c+3);v++){
                if(board[u][v]==ch)return false;
            }
        }
        return true;
    }
    void find(vector<vector<char>>&board,vector<pair<int,int>>&emptycells,int ind,vector<vector<char>>&ans){
        int len=emptycells.size();
        if(ind==len){
            ans=board;
        }
        else{
            int i=emptycells[ind].first;
            int j=emptycells[ind].second;
            for(int val=1;val<10;val++){
                if(isvalid(i,j,val,board)){
                    board[i][j]=val+'0';
                    find(board,emptycells,ind+1,ans);
                    board[i][j]='.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>>emptycells;
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    emptycells.push_back({i,j});
                }
            }
        }
        vector<vector<char>>ans;
        find(board,emptycells,0,ans);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j]=ans[i][j];
            }
        }
    }
};