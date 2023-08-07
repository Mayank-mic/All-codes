// Given an integer N. The task is to return the position of first set bit found from the right side in the binary representation of the number.
// Note: If there is no set bit in the integer N, then return 0 from the function.  

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int counter=0;
        while(n!=0){
            counter++;
            if(n%2==1) return counter;
            n=n/2;
        }
        return 0;
    }
};
