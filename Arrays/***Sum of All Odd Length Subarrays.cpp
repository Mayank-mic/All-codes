// Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

// A subarray is a contiguous subsequence of the array.


class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int n = arr.size();
        if(n==1) return arr[0];


        int ind = (n%2==0)? n/2: (n+1)/2;

        int sum =0;

        int i=1;

        while(i<=n){

            int temp=0;

            for(int k=0;k<i;++k){
                temp+=arr[k];
            }

            sum+=temp;

            for(int j=i;j<n;++j){
                temp-=arr[j-i];
                temp+=arr[j];
                sum+=temp;
            }
            
            i+=2;
        }


        return sum;

    }
};



//////// Method 2:



 int sumOddLengthSubarrays(vector<int>& arr) {
        int ans{};
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            int start = i;
            int end = n - i;
            int total = (start + 1) * (end);
            int odd = total / 2;

            if(total % 2 != 0) {
                odd++;
            }
			
            ans += arr[i] * odd;
        }
		
        return ans;
    }


