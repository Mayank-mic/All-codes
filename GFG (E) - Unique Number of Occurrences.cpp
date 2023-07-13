// Given an array arr of N integers, the task is to check whether the frequency of the elements in the array is unique or not. 
// Or in other words, there are no two distinct numbers in array with equal frequency. 
// If all the frequency is unique then return true, else return false.

class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int, int> mp;
        
        for(int i=0;i<n;++i){
            mp[arr[i]]++;
        }
        
        
        unordered_set<int> st;
        
        for(auto it: mp){
            st.insert(it.second);
        }
        
        if(st.size()==mp.size()) return true;
        return false;
        
    }
};
