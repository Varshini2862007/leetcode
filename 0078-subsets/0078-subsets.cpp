class Solution {
public:
    void find(vector<int>& nums,int ind,set<vector<int>>&ans,vector<int>&sub){
        if(ind==nums.size()){
            ans.insert(sub);
            return;
        }
        //take
        sub.push_back(nums[ind]);
        find(nums,ind+1,ans,sub);
        sub.pop_back();
        //not take
        find(nums,ind+1,ans,sub);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>sub;
        find(nums,0,ans,sub);
        vector<vector<int>>v;
        for(const vector<int>&vec:ans){
            v.push_back(vec);
        }
        return v;
    }
};