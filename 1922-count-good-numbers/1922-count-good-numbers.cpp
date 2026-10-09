class Solution {
public:
    const long long mod=1e9+7;
    long long pow(long long base,long long exp){
        long long ans=1;
        while(exp){
            if(exp%2==1)ans=((ans%mod)*(base%mod))%mod;
            base=(base*base)%mod;
            exp/=2;
        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
       int flag=1;
       long long ans=1,eind=(n+1)/2,oind=n/2;
        ans=pow(5,eind)%mod;
        ans=((ans%mod)*(pow(4,oind)%mod))%mod;       
       return ans%mod;
    }
};