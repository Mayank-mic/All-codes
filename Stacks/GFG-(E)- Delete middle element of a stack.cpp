// Given a stack, delete the middle element of the stack without using any additional data structure.
// Middle element:- ceil((size_of_stack+1)/2) (1-based indexing) from bottom of the stack.

// Note: The output shown by the compiler is the stack from top to bottom.
class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int num = sizeOfStack/2;
        
        stack<int> tempo;
        
        int counter=0;
        
        while(counter!=num){
            tempo.push(s.top());
            s.pop();
            counter++;
        }
        
        s.pop();
        
        while(!tempo.empty()){
            s.push(tempo.top());
            tempo.pop();
        }
        
    }
};
