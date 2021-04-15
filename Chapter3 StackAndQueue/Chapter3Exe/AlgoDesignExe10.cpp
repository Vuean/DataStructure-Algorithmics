struct LinkList{
    int data;
    LinkList* next;
};

int GetMax(LinkList* p){
    if(!p->next){
        return p->data;
    }else{
        int max = GetMax(p->next);
        return p->data >= max ? p->data : max;
    }
}

int GetNum(LinkList* p){
    if(!p->next){
        return 1;
    }else{
        return GetNum(p->next) + 1;
    }
}

int GetAvg(LinkList* p, int n){
    if(!p->next){
        return p->data;
    }else{
        double ave = GetAvg(p->next, n-1);
        return (ave * (n-1) + p->data)/n;
    }
}