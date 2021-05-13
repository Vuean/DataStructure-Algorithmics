/*
如果某结点左右子树为空，返回，否则交换该结点左右孩子，
然后递归交换左右子树。
*/

void ChangeLR(BiTree& T)
{
    BiTree temp;
    if(T->lchild == NULL && T->rchild == NULL)
    {
        return;
    }
    else
    {
        temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
    ChangeLR(T->lchild);
    ChangeLR(T->rchild);
}