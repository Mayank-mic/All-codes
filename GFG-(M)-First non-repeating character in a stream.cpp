// Given an input stream A of n characters consisting only of lower case alphabets. 
// While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. 
// If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. 
// If there is no such character then append '#' to the answer.


class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    
		       // Code here
		    if(A.size()==1) return A;
		    
		    queue<char> qu;
		    
		    string ans="";
		    
		    unordered_map<char,int> mp;
		    
		    for(auto i:A){
		        qu.push(i);
		        mp[i]++;
		       char a='#';
		        while(mp[qu.front()]!=1 && !qu.empty()) qu.pop();
		        if(!qu.empty()) a = qu.front();
		        ans+=a;
		        }
		    return ans;
		
		}

};
