class Solution {
public:
    int minimizeXor(int num1, int num2) {
      /*
        簡單的bit manipultaion，首先我們要計算兩個數字各有多少個set bit
        然後我們要找出一個x，這個x的set bit 數量跟num2一樣多，還必須符合跟num1做XOR operation之後能得到最小值
        我們的辦法就是先找出set1 和set2的差距，由於同樣的數字做XOR之後會互相抵消，所以我們從num1的低位元開始操作，想辦法把num1的set bit數量達到跟num2一樣
        更改過後的num1就是我們要找的x，
        由於我們是從低位元開始改，理論上x的高位元仍會跟原本的num1一樣，因此在做XOR之後，高位員會互相抵消，留下最小的數字
      */
      //先找出兩個set bit的數量
        int set1=setCnt(num1);
        int set2=setCnt(num2);
      //從低位元開始操作
        int bit=0;  //控制要操作的位元
        while(set1<set2){
            if((num1 & 1<<bit) == 0){
                num1 |= 1<<bit;  //set bit 
                set1++;
            }
            bit ++;
        }
        while(set1>set2){
            if(num1 & 1<<bit){
                num1 &= ~(1<<bit);  //unset bit
                set1--;
            }
            bit++;
        }
        return num1;
    }

//function, 用來計算一個數字有幾個set bit
    int setCnt(int x){
        int cnt=0;
        while(x){
            x &=(x-1);
            cnt++;
        }
        return cnt;
    }
};
