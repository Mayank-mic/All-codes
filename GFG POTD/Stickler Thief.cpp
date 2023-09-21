// // Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. 
// According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. 
//   The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy.
// He asks for your help to find the maximum money he can get if he strictly follows the rule. ith house has a[i] amount of money present in it.



 int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==0) return 0;
        if(n==1) return arr[0];
        if(n==2) return max(arr[0], arr[1]);
        
        int b[n];
        b[0]=arr[0];
        b[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            b[i]=max(b[i-2]+arr[i], b[i-1]);
        }
        return b[n-1];
    }
