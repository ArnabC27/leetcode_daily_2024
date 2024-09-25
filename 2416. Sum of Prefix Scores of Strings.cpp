class Solution {
    struct trienode{
        int pc;
        map<int,trienode*> child;
        trienode(){
            this->pc=0;
        }
    };
    void trie_insert(trienode* curr,string& s){
        int idx;
        for(int i=0;s[i]!='\0';++i){
            idx = s[i]-'a';
            if(!curr->child.count(idx))
                curr->child[idx] = new trienode;
            curr = curr->child[idx];
            curr->pc++;
        }
    }
    int trie_search(trienode* curr,string& s){
        int idx;
        int count=0;
        for(int i=0;s[i]!='\0';++i){
            idx = s[i]-'a';
            // if(!curr->child.count(idx))
            //     return count;
            curr=curr->child[idx];
            count += curr->pc;
        }
        return count;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        trienode* root = new trienode;

        int n=words.size();
        for(int i=0;i<n;++i)
            trie_insert(root,words[i]);
        
        vector<int> ans(n);
        for(int i=0;i<n;++i)
            ans[i] = trie_search(root,words[i]);
        
        return ans;
    }
};
