#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int eW = 0;
    int cP = 0;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void increasePrefix(){
        cP++;
    }
    void increaseEnd(){
        eW++;
    }
    int getEnd(){
        return eW;
    }
    int getP(){
        return cP;
    }
    void reducePrefix(){
        cP--;
    }
    void reduceEnd(){
        eW--;
    }
    
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
        // Write your code here.
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
         Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
         Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        node->getP();
    }

    void erase(string &word){
        // Write your code here.
         Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }else{
                return ;
            }
        }
        node->reduceEnd();
    }
};
