typedef int DataType;

struct QueueNode{
    DataType data;
    QueueNode* next;
};

struct LinkQueue{
    QueueNode* rear;    // ֻ��һ��ָ���βԪ�ص�ָ��
};

// �ÿն�
void InitQueue(LinkQueue* Q){
    QueueNode* s;
    Q->rear = Q->rear->next;    // ����βָ��ָ��ͷ���
    while(Q->rear != Q->rear->next){    // ���зǿ�
        s = Q->rear->next;
        Q->rear->next = s->next;
        delete s;
    }
}

// �п�
bool IsEmptyQueue(LinkQueue* Q){
    // ͷ���ָ��ָ���Լ�ʱΪ��
    return (Q->rear->next->next == Q->rear->next);
}

// ���
void EnQueue(LinkQueue* Q, DataType e){
    QueueNode* p = new QueueNode;
    p->data = e;
    p->next = Q->rear->next;
    Q->rear->next = p;
    Q->rear = p;
}

// ����
void DeQueue(LinkQueue* Q, QueueNode &e){
    if(!IsEmptyQueue(Q))
        return;
    QueueNode* p = Q->rear->next->next; // pָ������ӵĽ��
    e = *(p);
    if(p == Q->rear){
        // ���н����һ�����
        Q->rear = Q->rear->next;    // β�ڵ�ָ��ͷ���
        Q->rear->next = p->next;    // ͷ����next������
    }else{
        Q->rear->next->next = p->next;  // ͷ���ָ��p����һ�����
    }
    delete p;
}