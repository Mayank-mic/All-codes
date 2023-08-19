// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.



// Method 1:

class Solution {
public:
    int maxArea(vector<int>& height) {


        int n= height.size();

        int ans= INT_MIN;

        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){

                ans=max(ans, min(height[i], height[j])*(j-i));

            }
        }
        

        return ans;
    }
};




// TLE




Method 2:
Sliding window


class Solution {
public:
    int maxArea(vector<int>& height) {

        int n= height.size();

        int ans= INT_MIN;

        int start=0;
        int end=n-1;

        while(start<end)
        {
            ans=max(ans, min(height[start], height[end])*(end-start));

            if(height[start]<height[end]){
                start++;
            }else{
                end--;
            }
        }
        

        return ans;
    }
};


