#include<bits/stdc++.h>
using namespace std;



class Trie{
    public:
      char data;
      int endHere;
      vector<Trie*> children;
      Trie(char a){
          data = a;
          children = vector<Trie*>(26,NULL);
          endHere = 0;
      }
};

void insert(Trie* root, string &s){
    Trie *curr = root;
    for(int i=0;i<s.size();i++){
        int index = s[i]-'a';
        if(curr->children[index] == NULL){
            curr->children[index] = new Trie(s[i]);
        }
        curr = curr->children[index];
    }
    curr->endHere = 1;
}


bool find(Trie* root, string &s){
    Trie *curr = root;
    for(int i=0;i<s.size();i++){
        int index = s[i]-'a';
        if(curr->children[index] == NULL){
            return false;
        }
        curr = curr->children[index];
    }
    if(curr->endHere > 0){
        return true;
    }
    return false;
}
bool preFixFind(Trie* root, string &s){
    Trie *curr = root;
    for(int i=0;i<s.size();i++){
        int index = s[i]-'a';
        if(curr->children[index] == NULL){
            return false;
        }
        curr = curr->children[index];
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    Trie* root = new Trie('/');
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        string s;
        cin>>s;
        if(ch == 'i'){
            insert(root,s);
        }
        else if(ch == 'f'){
            if(find(root,s)){
                cout<<"String Exist"<<endl;
            }
            else{
                cout<<"String does not Exist"<<endl;
            }
        }
        else if(ch =='p'){
            if(preFixFind(root,s)){
                cout<<"Prefix String Exist"<<endl;
            }
            else{
                cout<<"Prefix String does not Exist"<<endl;
            }
        }
    }
}
