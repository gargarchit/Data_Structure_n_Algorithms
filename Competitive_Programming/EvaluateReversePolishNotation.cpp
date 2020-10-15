class Solution {
public:
    public:
    bool isdigit(string s)
    {
		//to check if it's negative(the second condition)
        if(s[0]>='0' && s[0]<='9' || s[0]=='-' && 1<s.length()) return true;
        
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        
        stack<int> symbol;
        int size = tokens.size();
        int i = 0;
    
        while(size--)
        {
            string c = tokens[i];
            
            if(isdigit(c))
            {
                symbol.push(stoi(c));
            }
            else
            {
                int num1 = symbol.top();
                symbol.pop();
                int num2 = symbol.top();
                symbol.pop();
              
                switch(c.at(0))
                {
                    case '+' : symbol.push(num1+num2);
                               break;
                        
                    case '-' : symbol.push(num2-num1);
                               break;
                        
                    case '/' : symbol.push(num2/num1);
                               break;
                        
                    case '*' : symbol.push(num1*num2);
                               break;
                }   
            }   
            i++;
			}
        return symbol.top(); 
    }
};
