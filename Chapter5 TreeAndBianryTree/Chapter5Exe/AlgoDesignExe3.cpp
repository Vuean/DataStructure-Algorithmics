/*
���ĳ�����������Ϊ�գ����أ����򽻻��ý�����Һ��ӣ�
Ȼ��ݹ齻������������
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