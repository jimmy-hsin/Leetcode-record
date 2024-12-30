class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence); // stringstream 是用來分隔字串成單字的工具，預設分割符號為空格
        string word;  //用來裝載ss分割出來的單字
        int n=searchWord.length();
        int count=1;
        while(ss>>word){
            if(word.substr(0,n)==searchWord)  //如果word長度不足n，他會自己調整
                return count;
            count++;
        }
        return -1;
    }
};
