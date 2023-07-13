// You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        
        int counter=0;
        
        while(a!=0 || b!=0){
            if(a%2 != b%2) counter++;
            a=a/2;
            b=b/2;
        }
        
        return counter;
        
    }
};


// class Solution {
// public:
//                     static int countBitsFlip(int a, int b) {
//                             int n = a ^ b;
//                             int count = 0;
//                             while (n > 0) {
//                                 int bit = n % 2;
//                                 n = n / 2;
//                                 if (bit == 1) {
//                                     count++;
//                                 }
//                             }
//                             return count; 
//                 }
// };
