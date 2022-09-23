#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise.
 * If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	else if (binary_tree_is_leaf(tree))
		return (1);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left != right)
		return (0);
	return (1);
}

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree:  is a pointer to the root node of the tree to measure
 * the balance factor
 * Return: If tree is NULL, the function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else if (binary_tree_is_leaf(tree))
		return (1);
	return (binary_tree_height(tree->left) *
		binary_tree_height(tree->right));
}
