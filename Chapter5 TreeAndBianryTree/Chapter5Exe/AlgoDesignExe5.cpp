/*
��������߶ȵ��㷨�����⡣������ȿɲ��ò�α����ķ�����
���¸���������ÿ�������ϣ������������ԭ������ȣ�
���޸�����ȡ�
*/

int MaxWidth(BiTree bt)
{
    if(bt == NULL)
    {
        return 0;
    }
    else{
        BiTree Q[]; // ����
        front = 1; rear = 1; last = 1;
        // front��ͷָ�룬rear��βָ�룬lastͬ�����ҽ���ڶ����е�λ��
        
        temp = 0; maxNum = 0;
        Q[rear] = bt;
        while(front <= last)
        {
            p = Q[front];
            temp++;
            if(p->lchild != NULL) Q[++rear] = p->lchild;
            if(p->rchild != NULL) Q[++rear] = p->rchild;
            if(front > last)
            {
                last = rear;
                if(temp > maxNum)
                {
                    maxNum = temp;
                    temp = 0;
                }
            }
        }
        return maxNum;
    }
}