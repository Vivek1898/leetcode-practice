class WordDictionary {
public:
    
    class Node{
        public:
        Node* link[26];
        bool flag;
    };
    
    Node *head;

    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        Node *root = head;
        for(int i = 0; i < word.length(); i++){
            if(!root->link[word[i]-'a']) root->link[word[i] - 'a'] = new Node();
            root = root->link[word[i] - 'a'];
        }
        root->flag = true;
    }
    
    bool search(string word) {
        return searchHelp(word, head);
    }

    bool searchHelp(string word, Node *root){
        for(int i = 0; i < word.length(); i++){
            if(word[i] == '.'){
                bool x = false;
                for(int j = 0; j < 26; j++){
                    if(root->link[j] != NULL)
                    x = x || searchHelp(word.substr(i+1), root->link[j]);
                    if (x == true) return true;
                }
                return false;
            }
            else{
                if(root == NULL) return false;
                if(!root->link[word[i]-'a']) return false;
                root = root->link[word[i] - 'a'];
            }
        }
        return root->flag;
    }
};