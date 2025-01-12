class Solution {
public:
    bool canBeValid(string s, string locked) { 
        if(s.size()%2)  return false;
      
        stack<int> st, flex;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0')  flex.push(i);
            else if(s[i]=='(')   st.push(i);
            else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else if(!flex.empty())  flex.pop();
                else return false;
            }
        }
        while(!st.empty() && !flex.empty() && st.top()<flex.top()){
            st.pop();
            flex.pop();
        }
        if(flex.size()%2)   return false;
        return st.empty();
    }
};
