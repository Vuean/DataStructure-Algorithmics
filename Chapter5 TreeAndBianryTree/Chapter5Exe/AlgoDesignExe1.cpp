int LeafNodeCount(BiTree T)
{
    if(T == NULL)
    {
        return 0;
    }
    else if(T->lchild == NULL && T->rchild == NULL)
    {
        return 1;
    }
    else
    {
        return LeafNodeCount(T->lchild) + LeafNodeCount(T->rchild);
    }
}