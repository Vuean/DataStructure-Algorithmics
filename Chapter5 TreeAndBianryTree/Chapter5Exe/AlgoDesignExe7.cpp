int Depth(BiTree T)/* 深度 */
{
    if(T==NULL)
        return(0);
    return 1+(Depth(T->lchild)>Depth(T->rchild)? Depth(T->lchild):Depth(T->rchild));
//选择左右孩子深度高的然后加上根节点这一层就是深度了
}
void Long(BiTree T)
{
    if(T!=NULL)//在T不为空的情况下
    {
        visit(T->data);//访问节点
        if(Depth(T->lchild)>Depth(T->rchild))//判断往左走还是往右走
            Long(T->lchild);
        else
            Long(T->rchild);
    }
}

void LongestPath(BiTree bt)//求二叉树中的第一条最长路径长度
{
    BiTree p=bt,l[],s[];
    //l, s是栈，元素是二叉树结点指针，l中保留当前最长路径中的结点
    int i，top=0,tag[],longest=0;
    while(p || top>0)
    {
        while(p) 
        {
            s[++top]=p;
            tag[top]=0; 
            p=p->Lc;
        } //沿左分枝向下
        if(tag[top]==1) //当前结点的右分枝已遍历
        {
            if(!s[top]->Lc && !s[top]->Rc) //只有到叶子结点时，才查看路径长度
            if(top>longest)
            {
                for(i=1;i<=top;i++) 
                {
                    l[i]=s[i]; longest=top; top--;
                }
            }
        //保留当前最长路径到l栈，记住最高栈顶指针，退栈
        }
        else if(top>0) 
        {
            tag[top]=1; 
            p=s[top].Rc;
        } //沿右子分枝向下
    }//while(p!=null||top>0)
}//结束LongestPath