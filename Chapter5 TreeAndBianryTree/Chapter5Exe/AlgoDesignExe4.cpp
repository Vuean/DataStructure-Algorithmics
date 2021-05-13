/*
若树为空，返回；若某结点为叶子结点，则仅输出该结点；
否则先输出该结点，递归遍历其左子树，再输出该结点，
递归遍历其右子树。
*/

void DoubleTraverse(BiTree T)
{
    if(T == NULL)
    {
        return;
    }
    else if(T->lchild == NULL && T->rchild == NULL)
    {
        cout << T->data;
    }
    else
    {
        cout << T->data;
        DoubleTraverse(T->lchild);
        cout << T->data;
        DoubleTraverse(T->rchild);
    }
}