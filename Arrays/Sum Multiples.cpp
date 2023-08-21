// Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.

// Return an integer denoting the sum of all numbers in the given range satisfying the constraint.


class Solution {
public:
    int sumOfMultiples(int n) {

        int counter=0;

        while(n>=1){
            if(n%3==0 || n%5==0 || n%7==0) counter+=n;
            n--;
        }

        return counter;
        
    }
};
