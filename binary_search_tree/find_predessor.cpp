TreeNode* find_predecessor(TreeNode* node){
	if (node->left == NULL){
		return NULL;
	}
	node = node->left ;
	while(node->right != NULL){
		node = node->right ;
	}
	return node;
}