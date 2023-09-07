#include <bits/stdc++.h> 
string findMissingNumber(vector<string> &binaryNums, int n) 
{
    // Write your code here.

    vector<int> store;

    long long temp = 0;


    for(int it = 0;it<n;++it){
            int po = binaryNums[it].length()-1;
           // cout<<po<<endl;
            int num =0;
        for(int i=0;i<binaryNums[it].length();++i){
            num += (binaryNums[it][i]-48)*pow(2, po);
           // cout<<num<<" =";
            po--; 
        }
           temp+=num;
    }


    long long sum = (n*(n+1))/2;

    long long num = sum-temp;

    if(num==0) return "0";

    
    string ans="";

    while(num!=0){
        ans=to_string(num%2)+ans;
        num = num/2;
    }
    //ans+=num/2;


    return ans;
}
