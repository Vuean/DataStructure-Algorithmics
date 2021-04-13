# 第三章 栈和队列

栈和队列是两种重要的线性结构。从数据结构角度看，栈和队列也是线性表，其特殊性在于栈和队列的基本操作是线性表操作的子集，它们是操作受限的线性表，因此，可称为**限定性的数据结构**。但从数据类型角度看，它们是和线性表不相同的两类重要的抽象数据类型。

## 3.1 栈和队列的定义和特点

### 3.1.1 栈的定义和特点

**栈**(**stack**)是限定仅在**表尾进行插入或删除**操作的线性表。因此，对栈来说，表尾端有其特殊含义，称为**栈顶**(**top**)，相应地，表头端称为**栈底**(**bottom**)。不含元素的空表称为**空栈**。

栈的修改是按后进先出的原则进行的，因此，栈又称为**后进先出**(Last In First Out, LIFO)的线性表。

> 栈与一般线性表的区别

栈与一般线性表的区别：**仅存在运算规则不同**。

||一般线性表|栈|
|:---|:---:|:---:|
|逻辑结构|一对一|一对一|
|存储结构|顺序表、链表|顺序表、链表|
|运算规则|随机存取|后进先出(LIFO)|

### 3.1.2 队列的定义和特点

**队列**(**queue**)是一种**先进先出**(**First In First Out, FIFO**)的线性表。它只允许在表的一端进行插入，而在另一端删除元素。

在队列中，允许插入的一端称为**队尾**(**rear**)，允许删除的一端则称为**队头**(**front**)。

## 3.2 案例引入

### 案例3.1 进制转换

![进制转换](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter3%20StackAndQueue/%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2.png)

### 案例3.2 括号匹配的检验

- 假设表达式中允许包含两种括号：圆括号和方括号

- 其嵌套的顺序随意，即：

    1. ([ ] ( ))或[ ( [ ] [ ] ) ]为正确格式；

    2. [ ( ] )为错误格式；

    3. ( [ () )或(()])为错误格式。

![括号匹配](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter3%20StackAndQueue/%E6%8B%AC%E5%8F%B7%E5%8C%B9%E9%85%8D.png)

### 案例3.3 表达式求值

- 表达式求值是程序设计语言编译中一个最基本的问题，它的实现需要运用栈。

- 这里介绍的算法是由运算符优先级确定运算顺序的对表达式求值算法——算符优先算法。

- 表达式的组成

  - 操作数(operand)：常数、变量。

  - 运算符(operator)：算术运算符、关系运算符和逻辑运算符。

  - 界限符(delimiter)：左右括弧和表达式结束符。

- 任何一个算术表达式都由**操作数**(常数、变量)、算术**运算符**(+、-、*、/)和界限符(括号、表达式结束符'#'、虚设的表达式起始符'#')组成。后两者统称为算符。

- 为了实现表达式求值。需要设置两个栈：

    一个是算符栈OPTR，用于寄存运算符。

    另一个称为操作数栈OPND，用于寄存运算数和运算结果。

- 求值的处理过程是自左至右扫描表达式的每一个字符

  - 当扫描到的是运算数，则将其压入栈OPND，

  - 当扫描到的是运算符时

    - 若这个运算符比OPTR栈顶运算符的优先级高，则入栈OPTR，继续向后处理

    - 若这个运算符比OPTR栈顶运算符优先级低，则从OPND栈中弹出两个运算数，从栈OPTR中弹出栈顶运算符进行运算，并将运算结果压入栈OPND。

  - 继续处理当前字符，直到遇到结束符为止。

### 案例3.4 舞伴问题

假设在舞会上，男士和女士各自排成一队。舞会开始时，依次从男队和女队的队买务出一人配成舞伴。如果两队初始人数不相同，则较长的那一队中未配对者等待下一轮舞曲。现要求写一算法模拟上述舞伴配对问题。

显然，先入队的男士或女士先出队配成舞。因此该问题具有典型的先进先出特性，可以用队列作为算法的数据结构。

- 首先构造两个队列

- 依次将从男元素出队配成舞伴

- 某队为空，则另外一队等待着则是下一舞曲第一个可获得舞伴的人。

## 3.3 栈的表示和操作的实现

### 3.3.1 栈的抽象数据类型的类型定义

```C++
    ADT Stack{
    数据对象：
        D = {ai | ai ∈ ElemSet, i = 1,2,...,n, n≥0}
    数据关系：
        R1 = {<ai-1, ai> | ai-1, ai∈D, i = 1,2,...,n}
        约定an端为栈顶，a1端为栈底
    基本操作：
        初始化、进栈、出栈、取栈顶元素等
    }ADT Stack
```

![栈的基本操作](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter3%20StackAndQueue/%E6%A0%88%E7%9A%84%E6%93%8D%E4%BD%9C.png)

### 3.3.2 顺序栈的表示和实现

存储方式：同一般线性表的顺序存储结构完全相同，**利用一组地址连续的存储单元依次存放自栈底到栈顶的数据元素**。栈底一般在低地址端。

- 附设**top指针**，指示栈顶元素在顺序栈中的位置。

- 另设**base指针**，指示栈底元素在顺序栈中的位置。

- 用stacksize表示栈可使用的最大容量。

但是，为了方便操作，通常top指示真正的**栈顶元素之上**的下标地址。

空栈：base == top是栈空标志

栈满：top - base == stacksize

- 栈满时的处理方法：

    1. 报错，返回操作系统

    2. 分配更大的空间，作为栈的存储空间，将原栈的内容移入新栈

使用数组作为顺序栈存储方式的特点：简单、方便、但易产生溢出（数组大小固定）

- 上溢(overflow)：栈已经满，又要压入元素

- 下溢(underflow)：栈已经空，还要弹出元素

注：上溢是一种错误，使问题的处理无法进行；而下溢一般认为是一种结束条件，即问题处理结束。

> 顺序栈的表示

```C++
    #define MAXSIZE 100
    struct SqStack{
        SElemType *base;    // 栈底指针
        SElemType *top;     // 栈顶指针
        int stacksize;      // 栈可用最大容量
    };
```

> 算法3.1 顺序栈的初始化

```C++
    // 构造一个空栈
    State InitStack(SqStack &S){
        S.base = new SElemType[MAXSIZE];
        if(!S.base) exit(OVERFLOW); // 存储分配失败
        S.top = S.base; // 栈顶指针等于栈底指针
        S.stacksize = MAXSIZE;
        return OK;
    }
```

> 补充算法1 判断顺序栈是否为空

```C++
    // 若栈为空，返回TRUE；否则返回FALSE
    State StackEmpty(SqStack &S){
        if(S.top == S.base)
            return TRUE;
        else
            return FALSE;
    }
```

> 补充算法2 求顺序栈的长度

```C++
    int StackLength(SqStack S)
    {
        return S.top - S.base;
    }
```

> 补充算法3 清空顺序栈

```C++
    Status ClearStack(SqStack &S){
        if(S.base) S.top = S.base;
        return OK;
    }
```

> 补充算法4 销毁顺序栈

```C++
    Status DestoryStack(SqStack &S){
        if(S.base){
            delete S.base;
            S.stacksize = 0;
            S.base = S.top = NULL;
        }
        return OK;
    }
```

> 算法3.2 顺序栈的入栈

- 步骤：

    1. 判断是否栈满，若满则出错

    2. 元素e压入栈顶

    3. 栈顶指针加1

```C++
    Status Push(SqStack &S, SElemType e){
        if(S.top - S.base == S.stacksize)   // 栈满
            return ERROR;
        *S.top = e;
        S.top++;
        // 等同于
        // *S.top++ = e;
        return OK;
    }
```

> 算法3.3 顺序栈的出栈

- 步骤：

    1. 判断是否栈空，若空则出错

    2. 获取栈顶元素e

    3. 栈顶指针减1

```C++
    Status Pop(SqStack &S, SElemType &e){
        if(S.top  == S.base) return ERROR;
        S.top--;
        e = *S.top;
        // 等同于
        e = *--S.top;
        return OK;
    }
```

### 3.3.3 链栈的表示和实现

链栈是运算受限的单链表，只能在链表头部进行操作。定义链栈的结构类型：

```C++
    struct StackNode{
        SElemType data;
        StackNode *next;
    };
    typedef StackNode *LinkStack;
```

- 链表的头指针就是栈顶

- 不需要头结点

- 基本不存在栈满的情况

- 空栈相当于，栈指针指向空

- 插入和删除仅在栈顶处执行

> 算法3.5 链栈的初始化

```C++
    void InitStack(LinkStack &S){
        // 构造一个空栈，栈顶指针置为空
        S = NULL;
        return OK;
    }
```

> 补充算法1 判断链栈是否位空

```C++
    Status StackEmpty(LinkList S){
        if(S == NULL) return TRUE;
        else return FALSE;
    }
```

> 算法3.6 链栈的入栈

```C++
    Status Push(LinkStack &S, SElemType e){
        p = new StackNode;  // 生成新结点p
        p->data = e;    // 将新结点数据域置为e
        p->next = S;    // 将新结点插入栈顶
        S = p;          // 修改栈顶指针
        return OK;
    }
```

> 算法3.7 链栈的出栈

```C++
    Status Pop(LinkStack &S, SElemType &e){
        if(S == NULL) return ERROR;
        e = S->data;
        p = S;
        S = S->next;
        delete p;
        return OK;
    }
```

> 算法3.8 取栈顶的元素

```C++
    SElemType GetTop(LinkStack S){
        if(S != NULL){
            return S->data;
        }
    }
```

## 3.4 栈与递归

- 递归的定义

  - 若一个对象部分地包含它自己，或用它自己给自己定义，则称这个对象是递归的；

  - 若一个过程直接地或间接地调用自己，则称这个过程是递归的过程。

- 常用到递归方法的三种情况：

  - 递归定义的数学函数

  - 具有递归特性的数据结构

    - 二叉树

    - 广义表

  - 可递归求解的问题

    - 迷宫问题

    - 汉诺塔问题

- 递归问题——用分治法求解

  - 分治法：对于一个较为复杂的问题，能够分解成几个相对简单的且解法相同或类似的子问题来求解

  - 必备的三个条件

    1. 能将一个问题转变成一个新问题，而新问题与原问题的解法相同或类同，不同的仅是处理的对象，且这些处理对象是变化有规律的

    2. 可以通过上述转换而使得问题简化

    3. 必须有一个明确的递归出口，或称递归边界

  - 分治法求解递归问题算法的一般形式

    ```C++
        void p(参数表){
            // 基本项
            if(递归结束条件) 可直接求解步骤; // 递归边界
            // 归纳项
            else p(较小的参数);
        }
    ```

- 递归的优缺点

  - 优点：结构清晰，程序易读

  - 缺点：每次调用要生成工作记录，保存状态信息，入栈；返回时要出栈，恢复状态信息。时间开销大。

- 实现递归转非递归

  - 方法1：尾递归、单向递归变为循环结构

  - 方法2：自用栈模拟系统的运行时栈

## 3.5 队列的表示和操作的实现

- 队列描述

  - **队列**(**Queue**)是仅在表尾进行插入操作，在表头进行删除操作的线性表。

  - 表尾即an端，称为队尾；表头即a1端，称为队头；

  - 它是一种先进先出(FIFO)的线性表

### 3.5.1 队列的抽象数据类型定义

### 3.5.2 队列的顺序表示和实现

队列的物理存储可以用顺序存储结构，也可用链式存储结构。相应地队列的存储方式也分为两种，即**顺序队列**和**链式队列**。

队列的顺序表示——用一维数组`base[MAXQSIZE]`

```C++
    #define MAXQSIZE 100 // 最大队列长度
    typedef struct{
        QElemType *base;    // 初始化的动态分配存储空间
        int front;  // 头指针，即队头下标
        int rear;   // 尾指针
    }SqQueue;
```

> 顺序队列存在的问题

顺序队列的真溢出问题：即front=0，rear=MAXQSIZE时，队列中存满，为真溢出；

而当入队、出队操作之后，随着front和rear移动，出现front!=0，rear=MAXQSIZE时，为假溢出。

> 顺序队列假上溢解决办法

- 解决假上溢的方法

    1. 将队中元素依次向队头方向移动。缺点：浪费时间。每移动一次，队中元素都要移动。

    2. 将队空间设想成一个循环的表，即分配给队列的m个存储单元可以循环使用，当rear为maxqsize时，若向量的开始端空着，又可从头使用空着的空间。当front为maxqsize时，也是一样。

- 引入循环队列——解决假上溢的问题

    `base[0]`接在`base[MAXQSIZE-1]`之后，若rear+1==M，则rear=0；

    实现方法：利用模运算(mod, %)

    插入元素：(尾指针后移一位)

    ```C++
        Q.base[Q.rear] = x;
        Q.rear = (Q.rear+1) % MAXQSIZE;
    ```

    删除元素：(头指针后移一位)

    ```C++
        x = Q.base[Q.front];
        Q.front = (Q.front + 1) % MAXQSIZE;
    ```

    针对循环队列，判断队空、对满时，front都与rear相等，因此可解决的方案有：

    1. 另外设一个标态以区别队空和队满

    2. 另设一个变量，记录元素个数

    3. 少用一个能素空间

- 循环队列解决队满时判断方法——少用一个元素空间

    队空时：front == rear

    队满时：(rear+1)% MAXQSIZE == front;

> 循环队列的类型定义

```C++
    #define MAXQSIZE 100 // 最大队列长度
    typedef struct{
        QElemType *base;    // 初始化的动态分配存储空间
        int front;  // 头指针，若队列不为空，指向队列头元素
        int rear;   // 尾指针，若队列不为空，指向队尾元素的下一个位置
    }SqQueue;
```

> 循环队列的操作——队列的初始化(算法3.11)

```C++
    Status InitQueue(SqQueue &Q){
        Q.base = new QElemType[MAXQSIZE];
        if(!Q.base) exit(OVERFLOW); // 存储分配失败
        Q.front = Q.rear = 0;
        return OK;
    }
```

> 循环队列的操作——求队列的长度(算法3.12)

```C++
    int QueueLength(SqQueue Q){
        return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
    }
```

> 循环队列的操作——循环队列入队(算法3.13)

```C++
    Status EnQueue(SqQueue &Q, QElemType e){
        if((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR; // 队满
        Q.base[Q.rear] = e; // 新元素加入队尾
        Q.rear = (Q.rear + 1) % MAXQSIZE;   // 队尾指针+1
        return OK;
    }
```

> 循环队列的操作——循环队列出队(算法3.14)

```C++
    Status DeQueue(SqQueue &Q, QElemType &e){
        if(Q.rear == Q.front) return ERROR; // 队空
        e = Q.base[Q.front];    // 保存队头元素
        Q.front = (Q.front + 1) % MAXQSIZE; // 队头指针+1
        return OK;
    }
```

> 循环队列的操作——取循环队列队头元素(算法3.15)

```C++
    QElemType GetHead(SqQueue Q){
        if(Q.rear != Q.front){ // 不为空
            return Q.base[Q.front]; // 返回队头指针元素的值，队头指针不变
        }
    }
```

### 3.5.3 链队——队列的链式表示和实现

若用户无法估计所用队列的长度，则宜采用链队列。

> 链式队列的类型定义

```C++
    #define MAXQSIZE 100 // 最大队列长度
    struct Qnode{
        QElemType data;
        Qnode *next;
    };
    typedef Qnode *QueuePtr;

    struct LinkQueue{
        QueuePtr front; // 队头指针
        QueuePtr rear;  // 队尾指针
    };
```

> 链队列的操作——链队列的初始化(算法3.16)

```C++
    Status InitQueue(LinkQueue &Q){
        Q.front = new QueuePtr();
        Q.rear = new QueuePtr();
        Q.front->next = NULL;
        return OK;
    }
```

> 链队列的操作——销毁链队列(补充)

```C++
    Status DestoryQueue(LinkQueue &Q){
        while(Q.front){
            p = Q.front->next;
            delete (Q.front);
            Q.front = p;
        }
        return OK;
    }
```

> 链队列的操作——将元素e入队(算法3.17)

```C++
    Status EnQueue(LinkQueue &Q, QElemType e){
        p = new QueuePtr;
        if(!p) exit(OVERFLOW);  // 存储分配失败
        p->data = e;
        p->next = NULL;
        Q.rear->next = p;
        Q.rear = p;
        return OK;
    }
```

> 链队列的操作——链队列的出队(算法3.18)

```C++
    Status DeQueue(LinkQueue &Q, QElemType &e){
        if(Q.front == Q.rear) return ERROR; // 队空
        p = Q.front->next;
        e = p->data;
        Q.front->next = p->next;
        if(Q.rear == p) Q.rear = Q.front;
        delete p;
        return OK;
    }
```

> 链队列的操作——求链队列的队头元素(算法3.19)

```C++
    Status GetHead(LinkQueue &Q, QElemType &e){
        if(Q.front == Q.rear) return ERROR;
        e = Q.front->next->data;
        return OK;
    }
```
