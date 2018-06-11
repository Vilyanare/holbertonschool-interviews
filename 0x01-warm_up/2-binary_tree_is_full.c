#include "binary_trees.h"

    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
/**
 * recurse_help - recursive function to check if a binary tree is full
 * @tree: tree to check
 * Return: 1 if full 0 otherwise
 */
int recurse_help(const binary_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left && tree->right)
		return (recurse_help(tree->left) & recurse_help(tree->right));
	return (0);
}
/**
 * binary_tree_is_full - validator to check if a binary tree is full
 * @tree: root node of the tree
 * Return: 1 if full 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (recurse_help(tree));
}
