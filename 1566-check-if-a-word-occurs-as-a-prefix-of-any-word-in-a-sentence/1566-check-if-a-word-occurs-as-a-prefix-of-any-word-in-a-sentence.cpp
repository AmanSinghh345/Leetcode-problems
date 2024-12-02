class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size();
        int m=searchWord.size();
        
         istringstream stream(sentence);
         string word;
         int i=1;
         while(stream>>word){
            if(word.find(searchWord)==0) return i;
         i++;
         }
       return -1; 
    }
};