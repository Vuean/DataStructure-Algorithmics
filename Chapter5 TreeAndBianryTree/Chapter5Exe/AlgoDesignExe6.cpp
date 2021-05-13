int Level(BiTree bt)
{
    int num = 0;
    if(bt)
    {
        queue<BiTree> q;
        q.push(bt);
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            if((p->lchild && !p->rchild) || (!p->lchild && p->rchild))
            {
                num++;
            }
            if(p->lchild) q.push(p->lchild);
            if(p->rchild) q.push(p->rchild);
        }
    }
    return num;
}