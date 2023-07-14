// Given a string Str which may contains lowercase and uppercase chracters. 
//   The task is to remove all duplicate characters from the string and find the resultant string. 
//   The order of remaining characters in the output should be same as in the original string.


class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    
	    vector<int> alphaU(26, 0);
	    vector<int> alphaL(26, 0);
	    
	    string ans="";
	    
	    for(int i=0;i<str.length();++i){
	        
	        if((int)str[i]>=97){
	            if(alphaL[str[i]-'a']==-1) continue;
	            alphaL[str[i]-'a']=-1;
	            ans+=str[i];
	        }else{
	            if(alphaU[str[i]-'A']==-1) continue;
	            alphaU[str[i]-'A']=-1;
	            ans+=str[i];
	        }   
	    }
    
	    return ans;
	}
};


class Solution{
public:
    string removeDuplicates(string str) {
        // code here
       unordered_set<char> s;
       string ans;
       for(auto i:str){
           if(s.find(i)==s.end()){
               ans.push_back(i);
               s.insert(i);
           }
       }
       return ans;
    }
};

