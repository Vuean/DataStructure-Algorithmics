int Depth(BiTree T)/* ��� */
{
    if(T==NULL)
        return(0);
    return 1+(Depth(T->lchild)>Depth(T->rchild)? Depth(T->lchild):Depth(T->rchild));
//ѡ�����Һ�����ȸߵ�Ȼ����ϸ��ڵ���һ����������
}
void Long(BiTree T)
{
    if(T!=NULL)//��T��Ϊ�յ������
    {
        visit(T->data);//���ʽڵ�
        if(Depth(T->lchild)>Depth(T->rchild))//�ж������߻���������
            Long(T->lchild);
        else
            Long(T->rchild);
    }
}

void LongestPath(BiTree bt)//��������еĵ�һ���·������
{
    BiTree p=bt,l[],s[];
    //l, s��ջ��Ԫ���Ƕ��������ָ�룬l�б�����ǰ�·���еĽ��
    int i��top=0,tag[],longest=0;
    while(p || top>0)
    {
        while(p) 
        {
            s[++top]=p;
            tag[top]=0; 
            p=p->Lc;
        } //�����֦����
        if(tag[top]==1) //��ǰ�����ҷ�֦�ѱ���
        {
            if(!s[top]->Lc && !s[top]->Rc) //ֻ�е�Ҷ�ӽ��ʱ���Ų鿴·������
            if(top>longest)
            {
                for(i=1;i<=top;i++) 
                {
                    l[i]=s[i]; longest=top; top--;
                }
            }
        //������ǰ�·����lջ����ס���ջ��ָ�룬��ջ
        }
        else if(top>0) 
        {
            tag[top]=1; 
            p=s[top].Rc;
        } //�����ӷ�֦����
    }//while(p!=null||top>0)
}//����LongestPath