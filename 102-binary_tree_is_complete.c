#include "binary_trees.h"

/**
 * countNodes - function that count the number of nodes
 * @root: pointer to the root node of the tree to check
 * Return: number of nodes
 */
size_t countNodes(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + countNodes(root->left) + countNodes(root->right));
}

/**
 * is_complete - sub function that check if the binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 * @idx: index.
 * @num_nodes: number of nodes.
 * Return: returns 1 if is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, int idx, int num_nodes)
{
	if (tree == NULL)
		return (1);

	if (idx >= num_nodes)
		return (0);

	return (is_complete(tree->left, 2 * idx + 1, num_nodes) &&
			is_complete(tree->right, 2 * idx + 2, num_nodes));
}

/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int count_nodes = countNodes(tree);

	if (tree == NULL)
		return (0);
	return (is_complete(tree, 0, count_nodes));
}
