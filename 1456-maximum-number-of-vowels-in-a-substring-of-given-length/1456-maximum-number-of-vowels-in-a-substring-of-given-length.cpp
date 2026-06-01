class Solution {
public:
    bool isVowel(char c) {
    c = tolower(c);  // convert to lowercase

    return (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u');
    }
    int maxVowels(string s, int k) {
        unordered_map<char,int>mp ; 
        int count = 0 ; 
        int l = 0 ;
        int maxCount = 0 ;
     for(int r = 0 ; r < s.size();r++){
         if(isVowel(s[r])){
           count++;
         }
         while( r - l + 1 > k){
             if(isVowel(s[l])){
                 count--;
             }
             l++;
         }
         maxCount = max(maxCount,count);
         
     }
        return maxCount ;
    }
};