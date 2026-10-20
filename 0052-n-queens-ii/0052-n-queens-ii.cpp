class Solution {
public:
    bool issafe(vector<vector<int>>&v,int r,int c){
        int i=r,j=c,n=v.size();
        //vertical
        while(i>=0){
            if(v[i][j]==1)return false;
            i--;
        }
        i=r,j=c;
        //top left corner
        while(i>=0&&j>=0){
            if(v[i][j]==1)return false;
            i--;
            j--;
        }
        i=r,j=c;
        //top right corner
        while(i>=0&&j<n){
            if(v[i][j]==1)return false;
            i--;
            j++;
        }
        return true;
    }
    void find(int row,vector<vector<int>>&v,int &count){
        int n=v.size();
        if(row==n){
            count++;
            return;
        }
        //check which col is safe
        for(int col=0;col<n;col++){
            if(issafe(v,row,col)){
                v[row][col]=1;
                find(row+1,v,count);
                v[row][col]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>>v(n,vector<int>(n,0));
        int count=0;
        find(0,v,count);
        return count;
    }
};