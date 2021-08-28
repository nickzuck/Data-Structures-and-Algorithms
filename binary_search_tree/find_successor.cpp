TreeNode* successor(TreeNode* node){
	if(node->right == NULL){
		return NULL;
	}
	node = node->right ;
	while(node->left != NULL){
		node = node->left ;
	}
	return node ;
}