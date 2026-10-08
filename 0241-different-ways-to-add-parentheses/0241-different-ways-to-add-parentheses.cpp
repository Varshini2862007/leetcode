class Solution {
public:
    string ope="+-*";
    int cal(int n1,int n2,char ch){
        if(ch=='+')return n1+n2;
        else if(ch=='-')return n1-n2;
        return n1*n2;
    }
    vector<int> find(string exp){
        if(exp.size()<=2)return {stoi(exp)};
        vector<int>poss;
        int len=exp.size();
        for(int i=0;i<len;i++){
            if(ope.find(exp[i])!=string::npos){
                string lp=exp.substr(0,i);
                string rp=exp.substr(i+1);
                vector<int>val1=find(lp);
                vector<int>val2=find(rp);
                // cout<<exp<<" "<<i<<"   "<<lp<<"->"<<val1<<" "<<rp<<"->"<<val2<<endl;
                for(int u=0;u<val1.size();u++){
                    for(int v=0;v<val2.size();v++){
                        int val=cal(val1[u],val2[v],exp[i]);
                        poss.push_back(val);
                    }
                }
            }
        }
        return poss;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        if(expression.size()<=2){
            int val=stoi(expression);
            ans.push_back(val);
            return ans;
        }
        for(int i=0;i<expression.size();i++){
            if(ope.find(expression[i])!=string::npos){
                string lp=expression.substr(0,i);
                string rp=expression.substr(i+1);
                vector<int>val1=find(lp);
                vector<int>val2=find(rp);
                for(int u=0;u<val1.size();u++){
                    for(int v=0;v<val2.size();v++){
                        int val=cal(val1[u],val2[v],expression[i]);
                        ans.push_back(val);
                    }
                }
            }
        }
        return ans;
    }
};