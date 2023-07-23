// Given two integers N (1<=N<=9) and K. Find the kth permutation sequence of first N natural numbers. Return the answer in string format.



class Solution
{
public:

    string kthPermutation(int n, int k)
    {
        // code here
        
        int total_permu =1;
        string base="";
        
        for(int i=1;i<=n;++i){
            total_permu*=i;
            base+=to_string(i);
        }
            
        ///////// base=1234
    
        string ans="";
        
        int counter=k;
        int temp=n;
        
        while(temp>0){
            total_permu=total_permu/temp;
            temp--;
            
            int index = (counter-1)/total_permu ;
            
            ans+=base[index];
            
            base=base.erase(index, 1);     

            counter= counter%total_permu;
            if(counter==0) counter=total_permu;
            
        }
        
        return ans;
    }
};
