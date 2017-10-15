Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.


Answer again, iterative:
    vector<string> letterCombinations(string digits) {
        vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        if (digits.size()) result.push_back("");
        for(int i = 0; i < digits.size(); ++i){
            vector<string> tmp;
            string s = map[digits.at(i)-'0'];
            for (int j = 0; j < s.size(); ++j){
                for (int k = 0; k < result.size(); ++k){
                    tmp.push_back(result[k]+s[j]);
                }
            }
            result = tmp;
        }
        return result;
    }
    
    
Queue:
    vector<string> letterCombinations(string digits) {
        vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        queue<string>q;
        if (digits.size()) q.push("");
        for(int i = 0; i < digits.size(); ++i){
            string c = map[digits[i]-'0'];
            while(q.front().size() == i){
                string s = q.front();
                q.pop();
                for(auto a : c){
                    q.push(s+a);
                }
            }
        }
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
