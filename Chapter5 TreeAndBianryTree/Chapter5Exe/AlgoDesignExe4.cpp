/*
����Ϊ�գ����أ���ĳ���ΪҶ�ӽ�㣬�������ý�㣻
����������ý�㣬�ݹ��������������������ý�㣬
�ݹ��������������
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