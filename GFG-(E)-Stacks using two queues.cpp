// Implement a Stack using two queues q1 and q2.



void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code
        if(q1.empty()) return -1; 
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        
        int x= q1.front();
        q1.pop();
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        return x;
}
