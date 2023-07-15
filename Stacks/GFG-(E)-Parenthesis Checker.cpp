// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

// Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        
        stack<char> st;
        int len = x.length();
        
        for(int i=0; i<len;++i){
            
            if(st.empty()){
                st.push(x[i]);
                continue;
            }
            
            if((st.top()=='[' && x[i]==']') || (st.top()=='{' && x[i]=='}') || (st.top()=='(' && x[i]==')')) st.pop();
            else{
                st.push(x[i]);
            }
            
        }
        
        return st.empty();
        
        
    }

};
