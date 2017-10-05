Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


bool isValid(string s) {
    if(s.size() % 2 != 0)
        return false;
    if(s.size() == 0){
        return true;
    }
    stack<char> chars;
    for(char c:  s){
        if(c == '(' || c == '{' || c == '[')
            chars.push(c);
        else{
            if(chars.empty())
                return false;
            char top = chars.top();
            if(c ==  ')'){
                if(top == '(')
                    chars.pop();
            }
            else if( c == '}'){
                if(top == '{')
                    chars.pop();
            }
            else if( c == ']'){
                if(top == '[')
                    chars.pop();
            }
            else{
            }
        }
    }
    return chars.size() == 0;
}
