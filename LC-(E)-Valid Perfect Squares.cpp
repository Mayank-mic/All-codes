// Given a positive integer num, return true if num is a perfect square or false otherwise.

// A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

// You must not use any built-in library function, such as sqrt.

class Solution {
public:
     bool isPerfectSquare(int num) {
        int start=0;
        if(num==1) return true;
        int end=num/2;
        while(start<=end)
        {
            long long int  mid=start+(end-start)/2;
            
                if(mid*mid==num) return true;
                else if(mid*mid<num) start=mid+1;
                else end=mid-1;
                
        }
        return false;
    }
};
