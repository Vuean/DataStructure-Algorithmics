typedef int DataType;

struct QueueNode{
    DataType data;
    QueueNode* next;
};

struct LinkQueue{
    QueueNode* rear;    // 只设一个指向队尾元素的指针
};

// 置空队
void InitQueue(LinkQueue* Q){
    QueueNode* s;
    Q->rear = Q->rear->next;    // 将队尾指针指向头结点
    while(Q->rear != Q->rear->next){    // 队列非空
        s = Q->rear->next;
        Q->rear->next = s->next;
        delete s;
    }
}

// 判空
bool IsEmptyQueue(LinkQueue* Q){
    // 头结点指针指向自己时为空
    return (Q->rear->next->next == Q->rear->next);
}

// 入队
void EnQueue(LinkQueue* Q, DataType e){
    QueueNode* p = new QueueNode;
    p->data = e;
    p->next = Q->rear->next;
    Q->rear->next = p;
    Q->rear = p;
}

// 出队
void DeQueue(LinkQueue* Q, QueueNode &e){
    if(!IsEmptyQueue(Q))
        return;
    QueueNode* p = Q->rear->next->next; // p指向待出队的结点
    e = *(p);
    if(p == Q->rear){
        // 队中仅最后一个结点
        Q->rear = Q->rear->next;    // 尾节点指向头结点
        Q->rear->next = p->next;    // 头结点的next即自身
    }else{
        Q->rear->next->next = p->next;  // 头结点指向p的下一个结点
    }
    delete p;
}