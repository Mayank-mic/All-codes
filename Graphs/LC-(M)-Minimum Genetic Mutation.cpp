// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

// Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene 
// where one mutation is defined as one single character changed in the gene string.

// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. 
// A gene must be in bank to make it a valid gene string.

// Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. 
// If there is no such a mutation, return -1.

// Note that the starting point is assumed to be valid, so it might not be included in the bank.


class Solution {
public:
     struct PairHash {
        template <typename T1, typename T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };



    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_map<char, vector<char>> mp;

        unordered_set<pair<int, string>, PairHash> st;

        for(int i=0;i<bank.size();++i){
            st.insert({0, bank[i]});
        }


        mp['A'] = {'C', 'G', 'T'};
        mp['C'] = {'A', 'G', 'T'};
        mp['T'] = {'C', 'G', 'A'};
        mp['G'] = {'C', 'T', 'A'};


        queue<pair<int, string>> q;

        q.push({0, startGene});

        while(!q.empty()){
            int steps = q.front().first;
            string curr = q.front().second;

            q.pop();

            if(curr==endGene) return steps;

            for(int i=0;i<8;++i){
                for(auto it: mp[curr[i]]){
                    char temp = curr[i];
                    curr[i]=it;
                    if(st.find({0, curr})!=st.end()){
                        q.push({steps+1, curr});
                        st.erase({0, curr});
                    }
                    curr[i]=temp;
                }
            }
        }

        return -1;

    }
};
