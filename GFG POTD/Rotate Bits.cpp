// Given an integer N and an integer D, rotate the binary representation of the integer N by D digits to the left as well as right and return the results in their decimal representation after each of the rotation.
// Note: Integer N is stored using 16 bits. i.e. 12 will be stored as 0000000000001100.


class Solution
{
  public:
  
        string n_b(int n){
            
            string s="";
            
            while(n!=0){
                s=to_string(n%2)+s;
                n=n/2;
            }
            
            if(s.length()==16) return s;
            
            while(s.length()!=16){
                s='0'+s;
            }
            return s;
        }
        
        int b_n(string s){
            
            int ind=15;
            
            int slow=0;
            for(auto it:s){
                slow += (it-'0')*pow(2, ind);    
                ind--;
            }
            
            return slow;
        }
  
  
        vector <int> rotate (int n, int d)
        {
            d=d%16;

            string temp = n_b(n);
            
            string b = temp.substr(d)+temp.substr(0, d);
            
            string a =temp.substr(temp.length()-d, d)+temp.substr(0, temp.length()-d);
            
         
            return {b_n(b), b_n(a)};
            
        }
};
