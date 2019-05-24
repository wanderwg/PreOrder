/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

typedef struct TreeNode Node;

void _PreOrder(Node* pRoot, int* pRes, int* index) {
	if (pRoot) {
		//���������
		pRes[*index] = pRoot->val;
		(*index)++;

		_PreOrder(pRoot->left, pRes, index);//������
		_PreOrder(pRoot->right, pRes, index);//������
	}
}

int GetTreeSize(Node* pRoot) {
	if (pRoot == NULL)
		return 0;
	return GetTreeSize(pRoot->left) + GetTreeSize(pRoot->right) + 1;
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* pRes = (int*)malloc(sizeof(int)*(*returnSize));
	if (pRes == NULL) {
		assert(0);
		return;
	}
	int index = 0;
	_PreOrder(root, pRes, &index);
	return pRes;
}