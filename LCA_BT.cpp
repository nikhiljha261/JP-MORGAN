TreeNode<int> *findLCA(TreeNode<int> *root, int node1, int node2)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->val == node1 || root->val == node2)
    {
        return root;
    }
    TreeNode<int> *left = findLCA(root->left, node1, node2);
    TreeNode<int> *right = findLCA(root->right, node1, node2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left != NULL)
    {
        return left;
    }

    return right;
}
