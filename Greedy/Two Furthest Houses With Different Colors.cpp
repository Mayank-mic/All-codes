// There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.

// Return the maximum distance between two houses with different colors.

// The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.


class Solution {
public:
    int maxDistance(vector<int>& colors) {
        /*

        int n=colors.size();

        vector<vector<int>> vec(101);

        for(int i=0;i<n;++i){
            vec[colors[i]].push_back(i);
        }

        int ans=INT_MIN;

        for(int i=0;i<100;++i){
            for(int j=i+1;j<101;++j){
                if(vec[i].size()==0 || vec[j].size()==0) continue;

                for(int c1=0;c1<vec[i].size();++c1){
                    for(int c2=0;c2<vec[j].size();++c2){
                        ans=max(ans, abs(vec[i][c1]-vec[j][c2]));
                    }
                }

            }
        }

        return ans;
        */


         int i =0;
        int j =colors.size()-1;
        int ans1 = 0;
        while(i<j){
            if(colors[i]!=colors[j]){
                 ans1 = max(ans1,abs(j-i));
            }
            j--;
        }

        i =0;
        j =colors.size()-1;
        int ans2 = 0;
        while(i<j){
            if(colors[i]!=colors[j]){
                 ans2 = max(ans2,abs(j-i));
            }
            i++;
        }
        return max(ans1,ans2);
    }
};
