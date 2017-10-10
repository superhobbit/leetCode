Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.


class TriesNode
{
public:
    TriesNode* next[26];
    bool end;
    int count;
    TriesNode(int x, bool y) : count(x), end(y){
        memset(next , 0 , sizeof(next));
    } 
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root  = new TriesNode(0,false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TriesNode* tmp = root;
        for (int i = 0; i < word.size(); ++i){
            int index = word[i]-'a';
            if (index >= 0){
                if (tmp->next[index] == NULL){
                    tmp->next[index] = new TriesNode(1,false);
                    tmp = tmp->next[index];
                } else {
                    tmp->next[index]->count += 1;
                    tmp = tmp->next[index];
                }                
            }            
        }
        tmp->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TriesNode* tmp = root;
        for (int i = 0; i < word.size(); ++i){
            int index = word[i] - 'a';
            if (index >= 0){
                if (tmp->next[index] != NULL) {
                    tmp = tmp->next[index];
                }else return false;                
            }
        }
        if (tmp->end) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TriesNode* tmp = root;
        for (int i = 0; i < prefix.size(); ++i){
            int index = prefix[i] - 'a';
            if (index >= 0){
                if (tmp->next[index] != NULL) {
                    tmp = tmp->next[index];
                }else return false;                 
            }        
        }
    }
private:
    TriesNode *root;
};
