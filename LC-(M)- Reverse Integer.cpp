// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



class Solution {
public:
    int reverse(int x) {

        int flag=1;
        long r=x;

        if(r<0){
            r=r*-1;
            flag=-1;
        }

        long n=0;

        while(r!=0){
            n=n*10+r%10;
            r=r/10;
        }

        if(n>INT_MAX) return 0;

        if(flag==-1) return n*(-1);

        return n;
       
    }
};
