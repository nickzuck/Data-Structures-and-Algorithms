#include<iostream>
#include<vector>

using namespace std ;

struct TrieNode { 
	bool isLeaf ; 
	vector<TrieNode*> children  ;
} ;

TrieNode* createNode(){
	TrieNode* node = new TrieNode() ;
	for(int i = 0 ; i < 26 ; i++){
		node->children.push_back(NULL) ;
	}
	node->isLeaf = false ;
	return node ;
}

void add(TrieNode* root, string s){
	for(int i = 0 ; i < s.size() ; i++){
		int val = s[i]-'a' ;
		if(root->children[val] == NULL){
			root->children[val] = createNode();
		}
		root = root->children[val];
	}
	root->isLeaf = true ;
}


bool isStringPresent(TrieNode* root, string s){
	for(int i = 0 ; i < s.size() ; i ++){
		int val = s[i] - 'a' ;
		if (root->children[val] == NULL){
			return false ;
		}
		root = root->children[val] ;
	}
	return root->isLeaf ;
}

int main(){
	TrieNode* root = createNode() ;
	
	add(root, "hello" ) ;
	add(root, "hell") ;
	add(root, "boy");
	add(root, "hellboy") ;

	cout << isStringPresent(root, "hell")  << endl ; // true
	cout << isStringPresent(root, "hellb") << endl ; // false 
	cout << isStringPresent(root, "hello") << endl ; // true
	cout << isStringPresent(root, "boy") << endl ; // true 

	return 0 ;
}