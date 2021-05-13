int CompareTree(TreeNode* tree1, TreeNode* tree2)
{
    bool tree1IsNull = (tree1 == NULL);
    bool tree2IsNull = (tree2 == NULL);
    if(tree1IsNull != tree2IsNull)
    {
        return 1;
    }
    if(tree1IsNull && tree2IsNull)
    {
        // Í¬Îª¿Õ
        return 0;
    }
    if(tree1->data != tree2->data)
    {
        return 1;
    }
    return (CompareTree(tree1->left, tree2->left) & CompareTree(tree1->right, tree2->right));
}