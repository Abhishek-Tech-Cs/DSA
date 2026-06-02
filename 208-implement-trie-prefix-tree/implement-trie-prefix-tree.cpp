class trieNode{
    public: 
        trieNode* children[26];
        bool isEnd;

        trieNode(){
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isEnd=false;
        }
};

class Trie {
public:
    trieNode* root;
    Trie() {
        root=new trieNode();
    }
    
    void insert(string word) {
        trieNode* tempRoot=root;
        for(auto i:word){
            int idx=i-'a';
            if(tempRoot->children[idx]!=NULL) tempRoot=tempRoot->children[idx];
            else{
                tempRoot->children[idx]=new trieNode();
                tempRoot=tempRoot->children[idx];
            }
        }
        tempRoot->isEnd=true;
    }
    
    bool search(string word) {
        trieNode* tempRoot=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(tempRoot->children[idx]==NULL) return false;
            tempRoot=tempRoot->children[idx];
        }
        return tempRoot->isEnd;
    }
    
    bool startsWith(string prefix) {
        trieNode* temp=root;
        for(auto i:prefix){
            int idx=i-'a';
            if(temp->children[idx]==NULL) return false;
            
            temp=temp->children[idx];
        }
        return true;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */