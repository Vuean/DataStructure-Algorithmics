/*
求二叉树高度的算法见上题。求最大宽度可采用层次遍历的方法，
记下各层结点数，每层遍历完毕，若结点数大于原先最大宽度，
则修改最大宽度。
*/

int MaxWidth(BiTree bt)
{
    if(bt == NULL)
    {
        return 0;
    }
    else{
        BiTree Q[]; // 队列
        front = 1; rear = 1; last = 1;
        // front队头指针，rear队尾指针，last同层最右结点在队列中的位置
        
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