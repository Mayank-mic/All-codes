// Given a stack, the task is to sort it such that the top of the stack has the greatest element.

void insert(int a, stack<int>& s){
    stack<int> temp;
    
    while(!s.empty()&&a<s.top()){
        temp.push(s.top());
        s.pop();
    }
    s.push(a);
    
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
    
}

void SortedStack :: sort()
{
   //Your code here
     if(s.empty()) return ;
    
    int a = s.top();
    s.pop();
    sort();
    insert(a, s);
    return;
    
}
