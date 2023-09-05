// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return true if n is an ugly number.


class Solution {
public:
    bool isUgly(int n) {

        if(n==0) return false;

        int t_c =0;
        int temp =n;

        while(temp%2==0){
            t_c++;
            temp=temp/2;
        }

        temp=n;

        int th_c=0;

        while(temp%3==0){
            th_c++;
            temp=temp/3;
        }

        temp=n;

        int f =0;

        while(temp%5==0){
            f++;
            temp=temp/5;
        }

        return n == (pow(2,t_c)*pow(3, th_c)*pow(5, f));


    }
};
