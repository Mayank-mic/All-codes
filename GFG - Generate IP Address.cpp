// Given a string S containing only digits, Your task is to complete the function 
// genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses and takes only a string S as its only argument.
// Note: Order doesn't matter. A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. 
// The numbers cannot be 0 prefixed unless they are 0.


class Solution{
    
    bool validx(string p){
        int len = p.length();
        
        if(len==0 || len>3 ||(p[0]=='0' && len>1) || stoi(p)>255) return false;
        return true;

    }
    
  public:
    vector<string> genIp(string &s) {
        
        vector<string> ans;
        
        int n= s.length();
        
        if(n>12) return {"-1"};
        
        for(int i=1; i<=3 && i<n-2 ; ++i){
            for(int j=i+1; j<=i+3 && j<n-1; ++j){
                for(int k=j+1; k<=j+3 && k<n; ++k){
                    
                    string a = s.substr(0, i);
                    string b = s.substr(i, j-i);
                    string c = s.substr(j, k-j);
                    string d = s.substr(k, n-k);
                    
                    if(validx(a) && validx(b) && validx(c) && validx(d)){
                        ans.push_back(a+"."+b+"."+c+"."+d);
                    }
                }
            }
        }
        return ans;
    }
};
