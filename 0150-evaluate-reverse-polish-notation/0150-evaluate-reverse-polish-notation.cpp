class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a=0;
        int b=0;
        stack<int>st;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="/"||tokens[i]=="*"){
    
                if(st.size()>=2){
                    b=st.top();
                    st.pop();
                    a=st.top();
                    st.pop();
                    int ans;

                    if(tokens[i]=="+"){
                        ans=a+b;
                    }
                    if(tokens[i]=="-"){
                        ans=a-b;
                    }
                    if(tokens[i]=="/"){
                        ans=a/b;
                    }
                    if(tokens[i]=="*"){
                        ans=a*b;
                    }
                    
                    st.push(ans);
                }
            }
            else{
                st.push(stoi(tokens[i])); //convert to integer
            }
            
        }
        return st.top();
        
    }
};