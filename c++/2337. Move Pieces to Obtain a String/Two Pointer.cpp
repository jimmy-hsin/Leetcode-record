class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.length();
        int i=0, j=0;//在start, target上移動的指標
      
        while(i<n || j<n){
            while(i<n && start[i]=='_')     //跳過start上的空格
                i++;
            while(j<n && target[j]=='_')　  //跳過target上的空格
                j++;
            
            if(i==n || j ==n)      //如果其中一個到底了，檢查另一個有沒有也到底
                return i==j;
            
            if(start[i] != target[j]){  //檢查跳過空格之後的字母一不一樣
                return false;
            }
            if(start[i]=='L' && i<j){  //如果字母是L，那麼target的位置要在start的左邊才算合規
                return false;
            }

            if(start[i]=='R' && i>j){  //如果字母是R，那麼target的位置要在start的右邊才算合規
                return false;
            }

            i++;  //這個字母檢查完了，跳下一個
            j++;
        }

        return true;
    }
};
