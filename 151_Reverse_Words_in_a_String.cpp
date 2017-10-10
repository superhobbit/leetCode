Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.


完全看答案抄的
void reverseWords(string &s) {
    reverse(s.begin(),s.end());
    int empty = 0;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] != ' '){
            if (empty != 0) s[empty++] = ' ';
            int j = i;
            while(s[j] != ' ' && j < s.size()){
                s[empty++] = s[j++];
            }
            reverse(s.begin()+empty-(j-i),s.begin()+empty);
            i = j;
        }

    }
    s.erase(s.begin()+empty,s.end());
}
