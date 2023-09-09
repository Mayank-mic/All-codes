// // There is a special typewriter with lowercase English letters 'a' to 'z' arranged in a circle with a pointer. 
// A character can only be typed if the pointer is pointing to that character. The pointer is initially pointing to the character 'a'.


class Solution {
public:
    int minTimeToType(string word) {

        int pointer = 97;

        int time =0;

        for(int i=0;i<word.length();++i){

            int diff = abs(pointer-word[i]);
            
            time +=min(diff, 26-diff);

            pointer = char(word[i]);
            
            time++;
        }

        return time;
        
    }
};
