# 第二章 线性表

## 2.1 线性表的定义和特点

**线性表是具有相同特性的数据元素的一个有限序列**。

> 线性表(Linear List)：

由n(n ≥ 0)个数据元素（结点）a1, a2, ... an组成的**有限序列**。

- 其中数据元素的个数n定义为表的**长度**

- 当n=0时称为**空表**

- 将非空的线性表(n>0)记作：(a1, az, ... an)

- 这里的数据元素ai(1≤i≤n)只是一个抽象的符号，其具体含义在不同的情况下可以不同。

> 线性表的逻辑特征

- 在非空的线性表，有且仅有一个开始结点a1，它没有直接前趋，而仅有一个直接后继a2；

- 有且仅有一个终端结点an，它没有直接后继，而仅有一个直接前趋an-1；

- 其余的内部结点ai(2≤i≤n-1)都有且仅有一个直接前趋ai-1和一个直接后继ai+1。

## 2.2 案例引入

> 顺序存储结构存在问题

- 存储空询分配不灵活

- 运算的空间复杂度高

> 总结

- 线性表中的数据元素的类型可以为**简单类型**，也可以为**复杂类型**

- 许多实际应用问题所涉的基本操作有很大相似性，不应为每个具体应用单独编写一个程序

- 从具体应用中抽象出共性的**逻辑结构和基本操作**（抽象数据类型），然后实现其**存储结构和基本操作**

## 2.3 线性表的定义

> 基本操作

- InitList(&L)

  - 操作结果：构造一个空的线性表L

- DestoryList(&L)

  - 初始条件：线性表L已存在

  - 操作结果：销毁线性表L

- ClearList(&L)

  - 初始条件：线性表L已存在

  - 操作结果：将线性表L重置为空表

- ListEmpty(L)

  - 初始条件：线性表L已存在

  - 操作结果：若线性表L空表则返回TURE；否则返回FALSE。

- ListLength(L)

  - 初始条件：线性表L已存在

  - 操作结果：返回线性表L中的数据元素个数。

- GetElem(L, i, &e)

  - 初始条件：线性表L已存在，1 <= i <= ListLength(L)

  - 操作结果：用e返回线性表L中第个数据元素的值。

- LocateElem(L, e, compare())

  - 初始条件：线性表L已存在，compare()是数据元素判定函数

  - 操作结果：返回L中第1个与e满足compare()的数据元素的位序。若这样的数据元素不存在则返回值为0。

- PriorElem(L, cur_e, &pre_e)

  - 初始条件：线性表L已存在

  - 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败；pre_e无意义。

- NextElem(L, cur_e, &next_e)

  - 初始条件：线性表L已存在

  - 操作结果：若cur_e是L的数据元素，且不是第最后个，则用next_e返回它的后继，否则操作失败，next_e无意义。

- ListInsert(&L, i, e)

  - 初始条件：线性表L已存在，1 <= i <= ListLength(L)+1

  - 操作结果：在L的第i个位置**之前**插入新的数据元素e，L的长度加一。

- ListDelete(&L, i, &e)

  - 初始条件：线性表L已存在，1 <= i <= ListLength(L)

  - 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减一。

- ListTraverse(&L, visited())   // 遍历

  - 初始条件：线性表L已存在

  - 操作结果：依次对线性表中每个元素调用visited()。

## 2.4 线性表的顺序表示和实现

### 2.4.1 线性表的顺序存储表示

线性表的顺序表示又称为**顺序存储结构**或**顺序映像**。

顺序存储定义：把**逻辑上相邻的数据元素**存储在**物理上相邻的存储单元**中的存储结构。

线形表顺序存储结构占用**一片续的存储空间**。知道某个元素的存储位置就可以计算其他元素的存储位置。

> 数组静态分配

```C++
  typedef struct{
    ElemType data[MaxSize];
    int length;
  } SqList; // 顺序表类型
```

数组存放的是第一个元素的地址，因此也可以写成以下动态分配形式，用指针代替第一个元素地址。

> 数组动态分配

```C++
  typedef struct{
    ElemType *data;
    int length;
  } SqList; // 顺序表类型
```

```C++
  SqList L;
  L.data = (ElemType*)malloc(sizeof(ElemType) * MaxSize);
```

在头文件stdlib.h中：

malloc(m)函数，开辟m字节长度的地址空间，并返回这段空间的首地址。

free(p)函数，释放指针p所指变量的存储空间，即彻底删除一个变量。

### 2.4.2 顺序表基本操作的实现

> 线性表L的初始化

```C++
  Status InitList_Sq(SqList&L){// 构造一个空的顺序表L   
  L.elem=new ElemType[MAXSIZE]; // 为顺序表分配空间
  if(!L.elem) exit(OVERFLOW); // 存储分配失败
  L.length = 0; // 空表长度为0
  return OK；
```

> 销毁线性表L

```C++
  void DestoryList(SqList &L)
  {
    if(L.elem) delete L.elem; // 释放存储空间
  }
```

> 清空线性表L

```C++
  void ClearList(SqList &L){
    L.length = 0; // 将线性表的长度置为0
  }
```

> 求线性表的长度

```C++
  int GetLength(SqList &L){
    return L.length;
  }
```

> 判断线性表是否为空

```C++
  int IsEmpty(SqList &L){
    if(L.length == 0) return 0;
    return 1;
  }
```

> 顺序表的取值

```C++
  // 取物理位置第i个元素
  int GetElem(SqList L, int i, ElemType &e){
    if(i < 1 || i >= L.length) return ERROR;

    e = L.elem[i-1];
    return OK;
  }
```

> 顺序表按值查找(顺序查找)

- 在线性表L中查找与指定值e相同的数据元素的位置

- 从表的一端开始，逐个进行记录的关键字和给定值的比较。找到，返回该元素的位置序号，未找到，返回0。

平均查找长度ASL(Average Search Length):

- 为确定记录在表中的位置，需要与给定值进行比较的关键字的个数的期望值叫做查找算法的**平均查找长度**。

> 顺序表插入

插入不同位置的算法演示：插入位置在最后、插入位置在中间、插入位置在最前面

算法思想：

1. 判断插入位置i是否合理

2. 判断顺序表的存储空间是否已满，若已满返回ERROR

3. 将第n至第i位的元素一次向后移动一个位置，空出第i个位置

4. 将要插入的新元素e放入第i个位置

5. 表长加1，返回插入成功。

```C++
  ListInsert_Sq(SqList& L, int i, ElemType e)
  {
    if(i < 1 || i > L.length+1) return ERROR; // i值不合法
    if(L.length == MAXSIZE) return ERROR; // 当前存储已满
    for(j = L.length-1; j >= i; j--){
      L.elem[j+1] = L.elem[j];
    }
    L.elem[i-1] = e;
    L.length++;
    return OK;
  }
```

顺序表插入算法的平均时间复杂度为O(n)。

> 顺序表的删除算法

算法思想：

1. 判断删除位置i是否合法

2. 将欲删除的元素保留在e中

3. 将第i+1至第n位的元素依次向前移动一个位置

4. 表长减1，删除成功返回OK

```C++
  ListInsert_Sq(SqList& L, int i, ElemType &e)
  {
    if(i < 1 || i > L.length+1) return ERROR; // i值不合法
    e = L.elem[i];
    for(j = i; j <= L.length-1; j++){
      L.elem[j-1] = L.elem[j];
    }
    L.length--;
    return OK;
  }
```

顺序表删除算法的平均时间复杂度为O(n)。

### 2.4.3 顺序表小结

1. 利用数据元素的存储位置表示线性表中相邻数据元素之间的前后关系，即线性表的逻辑结构与存储结构一致

2. 在访问线性表时，可以快速地计算出任何一个数据元素的存储地址。因此可以粗略地认为，访问每个元素所花时间相等

   - 这种存取元素的方法被称为随机存取法

> 顺序表的操作算法分析

- 时间复杂度

  - 查找、插入、删除算法的平均时间复杂度为O(n)

- 空间复杂度

  - 顺序表操作算法的空间复杂度S(n) = O(1)，没有占用辅助空间

> 顺序表的优缺点

1. 优点

   - 存储密度大（结点本身所占存储量/结点结构所占存储量）
  
   - 可以随机存取表中任一元素

2. 缺点

   - 在插入、删除某一元素时，需要移动大量元素

   - 浪费存储空间

   - 属于静态存储形式，数据元素的个数不能自由扩充

## 2.5 线性表的链式表示和实现

- 链式存储结构

  - 节点在存储器中的位置是任意的，即逻辑上相邻的数据在物理上不一定相邻

- 线性表的链式表示又称为非顺序映像或链式映像。

- 用一组**物理位置任意的存储单元**来存放线性表的数据元素。

单链表由头指针惟一确定，因此单链表可以用头指针的名字来命名。

各结点由两个域组成：

- 数据域：存储元素数值数据

- 指针域：存储直接后继结点的存储位置

> 链式存储有关的术语

1. 结点：数据元素的存储映像。由数据域和指针域两部分组成

2. 链表：n个结点由**指针链**链接而成的一个链表

3. 链表类型

    单链表：结点只有你一个指针域的链表；

    双链表：结点有两个指针域的链表；

    循环链表：首尾相接的链表；

4. 头指针、头节点和首元结点：

    头指针：是指向链表中第一个结点的指针

    首元结点：是指链表中存储第一个数据元素a1的结点

    头结点：是在链表的首元结点之前附设的一个结点，一个附加结点。

> 讨论1：如何表示空表

- 若无头结点时，头指针为空时表示空表

- 有头结点时，当头结点的指针域位空时表示空表

> 讨论2：在链表中设置头结点有什么好处？

1. 便于首元结点的处理

    首元结点的地址保存在头结点的指针域中，所以在链表的第一个位置上的操作和其他位置一致，无需进行特殊处理

2. 便于空表和非空表的统一处理

    无论链表是否为空，头指针都是指向头结点的非空指针，因此空表和非空表的处理也就统一了

> 讨论3：头结点的数据域内装的是什么？

头结点的数据域可以位空，也可以存放线性表长度等附加信息，但此结点不能计入链表长度值。

> 链表的特点：

1. 结点在存储器中的位置是任意的，即逻辑上相邻的数据元素在物理上不一定相邻

2. 访问时只能通过头指针进入链表，并通过每个结点的指针域依次向后顺序扫描其余结点，所以寻找第一个结点和最后一个结点所花费的时间不相同

3. 链表是顺序存取的，顺序表是随机存取的

### 2.5.1 单链表的定义和表示

> 带头结点的单链表

单链表是由**表头**唯一确定，因此单链表可以用头指针的名字来命名若头指针名是L，则把链表称为表L

```C++
  typedef struct Lnode{ // 声明结点的类型和指向结点的指针类型
    ElemTyoe data;  // 结点的数据域
    Lnode *next;    // 结点的指针域
  } Lnode, *LinkList; // LinkList为指向结构体Lnode的指针类型
```

定义链表L：LinkList L;

定义结点指针p：LNode *p;

### 2.5.2 单链表基本操作的实现

> 算法2.6——单链表的初始化(带头结点的单链表)

单链表的初始化即构造一个空表。

算法步骤：

  1. 生成新结点作为头结点，用头指针L指向头结点

  2. 将头结点的指针域置空

算法描述：

```C++
  Status InitList_L(LinkList &L){
    L = new LNode;
    L->next = NULL;
    return OK;
  }
```

> 补充算法1：判断链表是否为空

空表：链表中无元素，称为空链表(头指针和头结点仍然在)

算法描述：

```C++
  int ListEmpty(LinkList L){ // 若L为空表，则返回1，否则返回0
    if(L->next)
      return 1;
    else
      return 0;
  }
```

> 补充算法2：单链表的销毁：链表销毁后不存在

算法思路：从头指针开始，依次释放所有结点

算法描述：

```C++
  Status DestoryList_L(LinkList &L){// 销毁单链表L
    Lnode *p;
    while(L){ // 直至L为空
      p = L;
      L = L->next;
      delete p;
    }
    return OK;
  }
```

> 补充算法3：清空链表

链表仍存在，但链表中无元素，成为空链表(头指针和头结点仍然在)

算法思路：依次释放所有结点，并将头结点指针域设置为空

算法描述：

```C++
  status ClearList(LinkList &L){  // 将L重置为空表
    Lnode *p, *ql
    p = L->next;
    while(p){
      q = p->next;
      delete p;
      p = q;
    }
    L->next = NULL; // 头结点指针域为空
    return OK;
  }
```

> 补充算法3：求单链表的表长

算法思路：从首元结点开始，依次计数所有结点

算法描述：

```C++
  int ListLength_L(LinkList L){ // 返回L中数据元素个数
    LinkList p;
    p = L->next;
    int i = 0;
    while(p){ // 遍历单链表，统计结点数
      i++;
      p = p->next;
    }
    return i;
  }
```

> 算法2.7——取址(取单链表中第i个元素的内容)

算法思路：从链表的头指针出发，顺着链域next逐个结点往下搜索，直至搜索到第i个结点为止。因此，**链表不是随机存取结构**。

算法步骤：

1. 从第一个结点(L->next)顺链扫描，用指针p指向当前扫描到的结点，p初值p = L->next;

2. j做计数器，累计当前扫描过的结点数，j初值为1；

3. 当p指向扫描到的下一个结点时，计数器j加1；

4. 当j==i时，p所指的结点就是要找的第i个结点。

算法描述：

```C++
  Status GetElem_L(LinkList L, int i, ElemType &e){
    // 获取线性表L中的某个数据元素的内容，通过变量e返回
    p = L->next; j = 1;
    while(p && j < i){
      p = p->next;
      ++j;
    }
    if(!p || j > i) return ERROR; // 第i个元素不存在
    e = p->data;
    return OK;
  }
```

查找：

- 按值查找：根据指定数据获取该数据所在的位置（该数据的地址）；

- 按值查找：根据指定数据获取该数据所在位置序号（是第几个元素）

> 算法2.8——按值查找：根据指定数据获取该数据所在的位置（地址）

算法步骤：

1. 从第一个结点起，依次和e相比较

2. 如果找到一个其值与e相等的数据元素，则返回其在链表中的“位置”或地址；

3. 如果查遍整个链表都没有找到其值和e相等的元素，则返回0或NULL。

算法描述：

```C++
  Lnode* LocateElem_L(LinkList L, ElemType e){
    // 在线性表L中查找值e的数据元素
    // 找到，则返回L中值为e的数据元素的地址，查找失败返回NULL
    p = L->next;
    while(p && p->data != e){
      p = p->next;
    }
    return p;
  }
```

> 算法2.8 变化——按值查找：根据指定数据获取该数据所在的位置序号

算法描述：

```C++
  int LocateElem_L(LinkList L, ElemType e){
    // 返回L中值为e的数据元素的位置序号，查找失败返回0
    p = L->next; j = 1;
    while(p && p->data != e){
      p = p->next;
      j++;
    }
    if(p) return j;
    else return 0;
  }
```

> 算法2.9 插入——在第i个结点前插入值为e的新结点

算法步骤：

1. 首先找到ai-1的存储位置p

2. 生成一个数据域为e的新结点s。

3. 插入新结点：
  
    1. 新结点的指针域指向结点ai

    2. 结点ai-1的指针域指向新结点

算法描述：

```C++
  Status ListInsert_L(LinkList &L, int i, ElemType e){
    p = L; j = 0;
    // 寻找第i-1个结点，p指向i-1结点
    while(p && j < i - 1){
      p = p->next;
      ++j;
    }
    // /i大于表长+1或者小于1，插入位置非法
    if(!p || j > i - 1) return ERROR; 
    // 生成新结点s，将结点s的数据域置为e
    s = new LNode;
    s->data = e;
    // 将结点s插入L中
    s->next = p->next;
    p->next = s;
  }
```

> 算法2.10 删除——删除第i个结点

算法步骤：

1. 首先找到ai-1的存储位置p，保存要删除的ai的值

2. 令p->next指向ai+1

3. 释放结点ai的空间

算法描述：

```C++
  // 将线性表L中第i个数据元素删除
  Status ListDelete_L(LinkList &L, int i, ElemType&e){
  p = L; j = 0; 
  while(p->next && j < i-1){
    p = p->next;
    ++j;
  }
  // 寻找第i个结点，并令p指向其前驱
  if(!(p->next) || j > i-1) return ERROR；//删除位置不合理
  q = p->next;  // 临时保存被删结点的地址以备释放
  p->next = q->next; // 改变删除结点前驱结点的指针域
  e = q->data;  // 保存删除结点的数据域
  delete q;     // 释放删除结点的空间
  return OK;
} // ListDelete_L
```

> 算法2.11 建立单链表——头插法

头插法：元素插入在链表头部，也叫前插法

算法步骤：

1. 从一个空表开始，重复读入数据；

2. 生成新结点，将读入数据存放到新结点的数据域中

3. **从最后一个结点开始**，依次将各结点插入到链表的前端

算法描述：

```C++
  void CreateList_H(LinkList &L, int n){
    L = new LNode;
    L->next = NULL; // 先建立一个带头结点的单链表
    for(int i = n; i > 0; --i){
      p = new LNode;  // 生成新结点p
      cin >> p->data; // 输入元素值
      p->next = L->next;  // 插入到表头
      L->next = p;
    }
  }
```

> 算法2.11 建立单链表——尾插法

尾查法：元素插入在链表尾部，也叫后插法

算法步骤：

1. 从一个空表开始，将新结点逐个插入到链表的尾部，尾指针r指向链表的尾结点。

2. 初始时，r同L均指向头结点。每读入一个数据元素则申请一个新结点，将新结点插入到尾结点后，r指向新结点。

算法描述：

```C++
  // 正位序输入n个元素的值，建立带表头结点的单链表L
  void CreateList_R(LinkList& L, int n){
    L = new LNode;
    L->next = NULL;
    r = L;  // 尾指针r指向头结点
    for(int i = 0; i < n; ++i){
      p = new LNode;  // 生成新结点，输入元素值
      cin >> p->data;
      p->next = NULL;
      r->next = p;
      r = p;
    }
  } // CreateList_R
```

### 2.5.3 单链表的查找、插入、删除算法时间效率分析

1. 因线性链表只能顺序存取，即在查找时要从头指针找起，查找的时间复杂度为O(n)

2. 插入和删除：

    因线性链表不需要移动元素，只要修改指针，一般情况下时间复杂度为O(1)。

    但是，如果要在单链表中进行前插或删除操作，由于要从头查找前驱结点，所耗时间复杂度为O(n)

3. 头插法的时间复杂度是O(n)

4. 尾插法的时间复杂度是O(n)

### 2.5.4 循环链表

循环链表：是一种头尾相接的链表（即：表中最后一个结点的指针域指向头结点，整个链表形成一个环）。

优点：**从表中任一结点出发均可找到表中其他结点**。

循环链表的空表表示：头指针的指针域指向自己。

> 注意：

由于循环链表中没有NULL指针，故涉及遍历操作时，其终止条件就不再像非循环链表那样判断p或p->next是否为空，而是判断它们**是否等于头指针**。

> 头指针表示单循环链表

找a1的时间复杂度：O(1)

找an的时间复杂度：O(n)

但考虑到表的操作常常是在表的首尾位置上进行，因此更过的是考虑用**尾指针表示单循环链表**

> 尾指针表示单循环链表

设尾指针为R：

找a1的时间复杂度：O(1)，a1的存储位置是：R->next->next

找an的时间复杂度：O(1)，an的存储位置是：R

> 带尾指针循环链表的合并（将Tb合并在Ta之后）

操作步骤：

1. p存表头结点：p = Ta->next;

2. Tb表头连接到Ta表尾:Ta->next = Tb->next->next;

3. 释放Tb表头结点:delete Tb->next;

4. 修改指针:Tb->next = p;

算法描述：

```C++
  LinkList Connect(LinkList Ta, LinkList Tb){
    // 假设Ta、Tb都是非空的单循环链表
    p = Ta->next;     // 1. p存表头结点
    Ta->next = Tb->next->next;  // Tb表头连接到Ta表尾
    delete Tb->next;         // 释放Tb表头结点
    Tb->next = p;           // 修改指针
    return Tb;
  }
```

时间复杂度为O(1)

### 2.5.5 双向链表

双向链表：在单链表的每个结点里再增加一个指向其直接前驱的指针域prior，这样链表中就形成了有两个方向不同的链，故称为双向链表。

双向链表结构定义：

```C++
  typedef struct DuLNode{
    Elemtype data;
    struct DuLNode *prior, *next;
  }DuLNode, *DuLinkList;
```

双向循环链表:

和单链的循环表类似，双向链表也可以有循环表

- 让头结点的前驱指针指向链表的最后一个结点

- 让最后一个结点的后继指针指向头结点。

在双向链表中有些操作（如：ListLength、GetElem等），因仅涉及一个方向的指针，故它们的算法与线性链表的相同。但在插入、删除时，则需同时修改两个方向上的指针，两者的操作的时间复杂度均为O(n)。

> 算法2.13 双向链表的插入

```C++
  void ListInsert_DuL(DuLinkList &L, int i, ElemType e){
    // 在带头结点的双向循环链表L中第i个位置之前插入元素e
    if(!(p = GetElemP_DuL(L, i))) return ERROR;
    s = new DuLNode;
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
  }
```

> 算法2.14 双向链表的删除

```C++
  void ListDelete_DuL(DuLinkList& L, int i, ElemType &e){
    // 删除带头结点的双向循环链表L的第i个元素，并用e返回。
    if(!(p = GetElemP_DuL(L, i))) return ERROR;
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
    return OK;
  }
```

> 单链表、循环链表和双向链表的时间效率比较

![单链表、循环链表和双向链表的时间效率比较](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter2%20LinearList/%E5%8D%95%E9%93%BE%E8%A1%A8%E3%80%81%E5%BE%AA%E7%8E%AF%E9%93%BE%E8%A1%A8%E5%92%8C%E5%8F%8C%E5%90%91%E9%93%BE%E8%A1%A8%E7%9A%84%E6%97%B6%E9%97%B4%E6%95%88%E7%8E%87%E6%AF%94%E8%BE%83.png "单链表、循环链表和双向链表的时间效率比较")

## 2.6 顺序表和链式表的比较

> 链式存储结构的优点：

- 结点空间可以动态申请和释放；

- 数据元素的逻辑次序靠结点的指针来指示，插入和删除时不需要移动数据元素。

> 链式存储结构的缺点

- 存储密度小：每个结点的指针域需额外占用存储空间。当每个结点的数据域所占字节不多时，指针域所占存储空间的比重显得很大。

- 链式存储结构是非随机存取结构。对任一结点的操作都需要从头指针依指针链查找到该结点，这增加了算法的复杂度。

> 顺序表和链式表的比较

![]( "顺序表和链式表的比较")

## 2.7 线性表的应用

主要介绍线性表的合并和有序表的合并。

> 线性表的合并

- 问题描述：

  假设利用两个线性表La和Lb分别表示两个集合A和B，现要求合一个新的集合A = A∪B

- 算法步骤：

  依次取出Lb中的每个元素，执行以下操作：

    1. 在La中查找该元素

    2. 如果找不到，则将其插入La的最后

- 算法描述：

```C++
  void union(List &La, List Lb){
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    for(int i = 1; i < Lb_len; i++){
      GetElem(Lb, i, e);
      if(!LocateElem(La, e)){
        ListInsert(&La, ++La_len, e);
      }
    }
  }
```

上述算法时间复杂度为O(La_len*Lb_len)。

> 有序表的合并

- 问题描述：

  已知线性表La和Lb的数据元素按值非递减有序排列，现要求将La和Lb归并为一个新的线性表Lc，且Lc中的数据元素仍按值非递减有序排列。

- 算法步骤：

  1. 创建一个空表Lc

  2. 依次从La或Lb中“摘取”元素值较小的结点插入到Lc表的最后，直至其中一个表变空为止

  3. 继续将La或Lb其中一个表的剩余结点插入在Lc表的最后

> 算法2.16 有序表合并——用顺序表实现

- 用顺序表实现

```C++
  void MergeList_sq(SqList LA, SqList LB, SqList& LC){
    // 指针pa和pb的初值分别指向两个表的第一个元素
    pa = LA.elem;
    pb = LB.elem;

    // 新表长度为待合并两表的长度和
    LC.length = LA.length + LB.length;
    // 为新表分配空间
    LC.elem = new ElemType[LC.length];
    pc = LC.elem;

    // 找到LA和LB的最后一个元素
    pa_last = LA.elem + LA.length - 1;
    pb_last = LB.elem + LB.length - 1;

    // 两个表都非空
    while(pa <= pa_last && pb <= pb_last){
      if(*pa <= *pb){
        *pc++ = *pa++;
      }else{
        *pc++ = *pb++;
      }
    }

    // LB已到达表尾，将LA中剩余元素加入LC
    while(pa <= pa_last) *pc++ = *pa++;

    // LA已到达表尾，将LB中剩余元素加入LC
    while(pb <= pb_last) *pc++ = *pb++;
  }
```

时间复杂度为：O(ListLength(LA)+ListLength(LB))

空间复杂度为：O(ListLength(LA)+ListLength(LB))

> 算法2.17 有序表合并——用链表实现

```C++
  void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc){
    pa = La->next;
    pb = Lb->next;
    // pc指针指向头结点
    pc = Lc = La; // 用La的头结点作为Lc的头结点
    while(pa && pb){
      if(pa->data <= pb->data){
        pc->next = pa;
        pc = pa;
        pa = pa->next;
      }else{
        pc->next = pb;
        pc = pb;
        pb = pb->next;
      }
    }
    pc->next = pa ? pa : pb;  // 插入剩余段
    delete Lb;  // 删除Lb的头结点
  }
```

时间复杂度为：O(ListLength(La)+ListLength(Lb))

空间复杂度为：O(1)

## 2.8 案例分析与实现
