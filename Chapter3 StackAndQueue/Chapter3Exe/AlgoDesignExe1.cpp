#include <iostream>
using namespace std;

typedef int SElemType;

struct DblStack{
    int top[2], bot[2]; // 栈顶和栈底指针
    SElemType* V;       // 栈数组
    int m;              // 栈最大可容纳元素个数
};