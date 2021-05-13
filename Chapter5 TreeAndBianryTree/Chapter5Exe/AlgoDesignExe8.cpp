void AllPath(BiTNode *p, TElemType *data, int len)
{
    if (p)
    {
        if (p->lchild == NULL && p->rchild == NULL)
        {
            visit(p);
            for (int i = len - 1; i >= 0; i--)
                printf("%d ", data[i]);

            printf("\n");
        }

        else
        {
            data[len++] = p->data;
            AllPath(p->lchild, data, len);
            AllPath(p->rchild, data, len);
        }
    }
}