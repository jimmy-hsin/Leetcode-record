class Solution {
public:
    bool canBeValid(string s, string locked) { 
        if(s.size()%2)  return false;//奇數個括弧當然不可能配對成功
      
        stack<int> fixed, flex;    //我們把stack分成兩種，不能改變的(fixed)，還有可以彈性變化的(flex)
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0')  flex.push(i);    //如果可以彈性變化，那就把這個index推進flex裡
            else if(s[i]=='(')   fixed.push(i);    //如果是固定的且是左括弧，把他存進fixed裡
            else if(s[i]==')'){        //如果是固定的，且是右括弧，要看看有沒有東西能跟他互相配對/抵銷，有的話優先選擇fixed裡的元素，若沒有則回傳false
                if(!fixed.empty()) fixed.pop();
                else if(!flex.empty())  flex.pop();
                else return false;
            }
        }
        //如果fixed裡還有一些左括弧沒被配對到，那就找找看他的index後面還有沒有沒配對的彈性括弧可以跟它配對
        while(!fixed.empty() && !flex.empty() && fixed.top()<flex.top()){
            fixed.pop();
            flex.pop();
        }
        //檢查fixed是不是都被配完了
        return fixed.empty();
    }
};
