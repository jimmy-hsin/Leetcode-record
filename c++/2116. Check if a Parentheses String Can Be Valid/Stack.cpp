class Solution {
public:
    bool canBeValid(string s, string locked) { 
        if(s.size()%2)  return false;
      
        stack<int> fixed, flex;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0')  flex.push(i);
            else if(s[i]=='(')   fixed.push(i);
            else if(s[i]==')'){
                if(!fixed.empty()) fixed.pop();
                else if(!flex.empty())  flex.pop();
                else return false;
            }
        }
        while(!fixed.empty() && !flex.empty() && fixed.top()<flex.top()){
            fixed.pop();
            flex.pop();
        }
        if(flex.size()%2)   return false;
        return fixed.empty();
    }
};
