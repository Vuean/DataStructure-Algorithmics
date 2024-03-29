# 第7章 查找

## 7.1 查找的基本概念

**查找表**是由同一类型的数据元素（或记录）构成的集合。由于“集合”中的数据元素之间存在着**松散的关系**，因此查找表是一种应用灵便的结构。

**查找**：根据给定的某个值，在查找表中确定一个其关键字等于给定值的数据元素或（记录）

- **关键字**：用来标识一个数据元素（或记录）的某个数据项的值

    - **主关键字**：可唯一地标识一个记录的关键字是主关键字；

    - **次关键字**：反之，用以识别若干记录的关键字是次关键字。

1. 查找的目的：

   - 查询某个“特定的"数据元素是否在查找表中；

   - 检索某个“特定的“数据元素的各种属性；

   - 在查找表中插入一个数据元素；

   - 删除查找表中的某个数据元素。

2. 查找的分类

    - **静态查找表**：仅作“查询”（检索）操作的查找表

    - **动态查找表**：作“插入”和“删除”操作的查找表

3. 如何评价查找算法

    - 查找算法的评价指标“：关键字的平均比较次数，也称为**平均查找长度**，（ASL, Average Search Length）。

    ![图1：平均查找长度定义](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E5%B9%B3%E5%9D%87%E6%9F%A5%E6%89%BE%E9%95%BF%E5%BA%A6%E5%AE%9A%E4%B9%89.png)

查找的方法取决于查找表的结构，即表中数据元素是依何种关系组织在一起的。

由于对查找表来说，在集合中查询或检索一个“特定的”数据元素时，若无规律可循，只能对集合中的元素一一加以辨认直至找到为止。而这样的“查询”或“检索”是任何计算机应用系统中使用频度都很高的操作，因此设法提高查找表的查找效率，是本章讨论问题的出发点。

为提高查找效率，一个办法就是在构造查找表时，在集合中的数据元素之间人为地加上某种确定的约束关系。

## 7.2 线性表的查找

### 7.2.1 顺序查找（线性查找）

应用范围：顺序表或线性链表表示的**静态查找表**；表内元素之间无序

```C++
    int Search_Seq(SSTable ST, KeyTable key)
    {
        // 若成功返回其位置信息，否则返回0
        for(i = ST.length; i >= 1; i--)
        {
            if(ST.R[i].key == key) return i;
        }
        return 0;
    }
```

改进：把待查关键字key存入表头（“哨兵”、”监视哨”），从后往前逐个比较，可免去查找过程中每一步都要检测是否查找完毕，加快速度。

```C++
    int Search_Seq(SSTable ST, KeyTable key)
    {
        ST.R[0].key = key;
        for(i = ST.length; ST.R[i].key != key; i--);
        return i;
    }
```

当ST.length较大时，此改进能使进行一次查找所需的平均时间几乎减少一半。

- 时间复杂度：O(n)，查找成功时的平均查找长度为：`ASL(n) = (1+2+...+n)/n = (n+1)/2`。

- 空间复杂度：一个辅助空间，O(1)。

讨论：

1. 记录的查找概率不相等时如何提高查找效率？

    查找表存储记录原则按查找概率高低存储：

    1. 查找概率越高，比较次数越少；

    2. 查找概率越低，比较次数较多。

2. 记录的查找概率无法测定时如何提高查找效率？

    方法——按查找概率**动态调整**记录顺序：
    1. 在每个记录中设一个访问频度域；
    
    2. 始终保持记录按非递增有序的次序排列；
    
    3. 每次查找后均将刚查到的记录直接移至表头。

优点：算法简单，逻辑次序无要求，且不同存储结构均适用。

缺点：ASL太长，时间效率太低

### 7.2.2 折半查找（二分或对分查找）

**折半查找**：每次将待查记录所在区间缩小一半。

- 折半查找算法：（非递归算法）

    - 设表长为n，low、high和mid分别指向待查元素所在区间的上界、下界和中点，key为给定的要查找的值；

    - 初始时，令low=1，high=n，mid=floar((low+high)/2)

    - 让k与mid指向的记录比较

        - 若key==R[mid].key，查找成功；
        - 若key<R[mid].key，high=mid-1；
        - 若key>R[mid].key，low=mid+1；

    - 重复上述操作，直至low>high时，查找失败

```C++
    int Search_Bin(SSTable ST, KeyTable key)
    {
        low = 1; high = ST.length;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(ST.R[mid].key == key) return mid;
            else if(key < ST.R[mid].key)
                high = mid-1;
            else
                low = mid + 1;
        }
        return 0;
    }
```

递归版：

```C++
    int Search_Bin(SSTable ST, KeyTable key, int low, int high)
    {
        if(low > high) return 0;
        mid = (low + high) / 2;
        if(key == ST.elem[mid].key) return mid;
        else if(key < ST.elem[mid].key)
            Search_Bin(ST,key, mid-1, high);
        else
            Search_Bin(ST,key, low, mid+1);
    }
```

假定每个元素的查找概率相等，查找成功时的平均查找长度（ASL），设表长n=2^h-1，则h=log2(n+1)，查找概率相等为：1/n，`ASL≈log2(n+1)-1    (n>50)`。

优点：效率比顺序查找高

缺点：只适用于**有序表**，且限于**顺序存储结构**（对线性链表无效）。

### 7.2.3 分块查找（索引顺序查找）

分块查找条件基础：

1. 将表分成几块，且表有序或者分块有序。若i < j，则第j块中所有记录的关键字均大于第i块中的最大关键字。

2. 建立”索引表“（每个结点含有最大关键字域和指向本块第一个结点的指针，且按关键字有序）。

查找过程：先确定待查记录所在块（顺序或折半查找），再在块内查找（顺序查找）。

查找效率：ASL = LB + LW；即对索引表查找的ASL加上对块内查找的ASL

![图2：分块查找效率](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E6%9F%A5%E6%89%BE%E6%95%88%E7%8E%87.png)

优点：插入和删除较容易，无需进行大量移动

缺点：要增加一个索引表的存储空间并对初始索引表进行排序运算

适用情况：如果线性表既要**快速查找**又经常**动态变化**，则可采用分块查找。

![图3：查找方法比较](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E6%9F%A5%E6%89%BE%E6%96%B9%E6%B3%95%E6%AF%94%E8%BE%83.png)

## 7.3 树表的查找

### 7.3.1 二叉排序树

**二叉排序树**（Binary Sort Tree）又称为二叉搜索树、二叉查找树。

1. 二叉排序树定义：

    二叉排序树或是空树，或是满足如下性质的二叉树：

    1. 若其左子树非空，则左子树上所有结点的值均小于根结点的值；

    2. 若其右子树非空，则右子树上所有结点的值均大于等于根结点的值；

    3. 其左右子树本身又各是一棵二叉排序树

2. 二叉排序树的性质：

    中序遍历非空的二叉排序树所得到的数据元素序列是一个按关键字排列的**递增有序**序列。

3. 二叉排序树的操作——查找

    - 若查找的关键字等于根节点，成功。

    - 否则：

        - 若小于根节点，查其左子树

        - 若大于根节点，查找右子树

    - 在左右子树上的操作类似

```C++
    // 二叉排序树的存储结构
struct ElemType
{
    KeyType key;    // 关键字项
    InfoType otherInfo; // 其他数据项
};

struct BSTNode
{
    ElemType data;      // 数据域
    struct BSTNode *lchild, *rchild;        // 左右孩子指针
};
typedef BSTNode* BSTree;

// 递归查找
BSTree SearchBST(BSTree T, KeyType key)
{
    if(!T || key == T->data.key) return T;
    else if(key < T->data.key)
        return SearchBST(T->lchild, key);
    else
        return SearchBST(T->rchild, key);
}
```

4. 二叉排序树的查找分析

    二叉排序树上查找某关键字等于给定值的结点过程，其实就是走了一条从根到该结点的路径。

    比较的关键字次数 = 此结点所在层次数；最多的比较次数 = 树的深度

    对于含有n个结点的二叉排序树的平均查找长度和树的形状有关。

        - 最好情况：与折半查找中的判定树相同，O(log2n)；

        - 最坏情况：退化为单支树（类似于线性列表），树深度为n，ASL = (n+1)/2，O(n)；

    为了提高形态不均衡的二叉排序树的查找效率，应当进行“平衡化”处理（即**平衡二叉树**），尽量使二叉树的形状均衡！

5. 二叉排序树的操作——插入

    - 若二叉排序树为空，则插入结点作为根结点插入到空树中

    - 否则，继续在其左、右子树上查找

        - 树中已有，不再插入

        - 树中没有

            - 查找直至某个叶子结点的左子树或右子树为空为止，则插入结点应为该叶子结点的左孩子或右孩子

    **插入的元素一定是叶子节点**。

6. 二叉排序树的操作——生成

    从空树出发，经过一系列的查找、插入操作之后，可生成一颗二叉排序树。

    一个无序序列可通过构造二叉排序树而变成一个有序序列。构造树的过程就是对无序序列进行排序的过程。

    插入的结点均为叶子结点，故无需移动其他结点。相当于在有序序列上插入记录而无需移动其他记录。但是，**关键字的输入顺序不同，建立的二叉排序树也不同**。

7. 二叉排序树的操作——删除

    从二叉排序树中删除一个结点，不能把以该结点为根的子树者都删除，只能删掉该结点，并且**还应保证删除后所得的二叉树仍然满足二叉排序树的性质不变**。

    由于中序遍历二叉排序树可以得到一个递增有序的序列。那么，在二叉排序树中删去一个结点相当于删去有序序列中的一个结点。

        - 将因删除结点而断开的二叉链表重新链接起来

        - 防止重新链接后树的高度增加

    1. 如果删除的结点是叶子结点：直接删除该结点。

    2. 被删除的结点只有左子树或者只有右子树，用其左子树或者右子树替换它（结点替换）。

    3. 本删除的结点既有左子树，也有右子树：可以用其中序的前驱结点替换，然后删除该前驱结点（前驱结点是左子树中最大的结点）；也可以用中序的后继结点，然后删除该后继结点（后继是右子树中最小的结点）。

### 7.3.2 平衡二叉树

1. 平衡二叉树的定义

    **平衡二叉树**（balanced binary tree），又称为AVL树（Adelson-Velskii and Landis）。

    一棵平衡二叉树或者是空树，或者是具有以下性质的**二叉排序树**：

    - 左子树与右子树的高度之差的绝对值小于等于1；

    - 左子树和右子树也是**平衡二叉排序树**。

    左子树与右子树的高度差又称为结点的平衡因子（BF），`平衡因子=结点左子树的高度-结点右子树的高度`。根据平衡二叉树的定义，平衡二又树上所有结点的平衡因子只能是-1、0，或1。

对于一棵有n个结点的AVL树，其高度保持在O(log2n)数量级，ASL也保持在O(log2n)量级。

2.  失衡二叉排序树的分析与调整

    当我们在一个平衡二叉排序树上插入一个结点时，有可能导致**失衡**，即出现平衡因子绝对值大于1的结点。

    如果在一个AVL树中插入一个新结点后造成失衡，则必须**重新调整树的结构**，使之回复平衡。

平衡调整的四种类型：LL型、LR型、RL型和RR型

![图4：平衡调整的四种类型示意图](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E5%B9%B3%E8%A1%A1%E8%B0%83%E6%95%B4%E7%9A%84%E5%9B%9B%E7%A7%8D%E7%B1%BB%E5%9E%8B.png)

![图5：平衡调整的四种类型调整后示意图](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E5%B9%B3%E8%A1%A1%E8%B0%83%E6%95%B4%E7%9A%84%E5%9B%9B%E7%A7%8D%E7%B1%BB%E5%9E%8B_%E8%B0%83%E6%95%B4%E5%90%8E.png)

平衡调整的原则：1）降低高度；2）保持二叉排序树性质

1. LL型调整

    ![图6：LL型调整前-后对比示意图](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/LL%E5%9E%8B%E8%B0%83%E6%95%B4%E5%89%8D-%E5%90%8E%E5%AF%B9%E6%AF%94.png)

    - B结点带左子树一起上升

    - A结点成为B的右孩子

    - 原来B结点的右子树作为A的左子树

    ![图7：LL型调整示例](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E5%9B%BE7%EF%BC%9ALL%E5%9E%8B%E8%B0%83%E6%95%B4%E7%A4%BA%E4%BE%8B.png)

2. RR型调整

    ![图8：RR型调整前-后对比示意图](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E5%9B%BE8%EF%BC%9ARR%E5%9E%8B%E8%B0%83%E6%95%B4%E5%89%8D-%E5%90%8E%E5%AF%B9%E6%AF%94%E7%A4%BA%E6%84%8F%E5%9B%BE.png)

    - B结点带右节点一起上升

    - A结点成为B结点的左孩子

    - 原来B结点的左子树作为A的右子树

    ![图9：RR型调整示例](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E5%9B%BE9%EF%BC%9ARR%E5%9E%8B%E8%B0%83%E6%95%B4%E7%A4%BA%E4%BE%8B.png)

3. LR型调整

    ![图10：LR型调整前-后对比示意图](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E5%9B%BE10%EF%BC%9ALR%E5%9E%8B%E8%B0%83%E6%95%B4%E5%89%8D-%E5%90%8E%E5%AF%B9%E6%AF%94%E7%A4%BA%E6%84%8F%E5%9B%BE.png)

    - C结点穿过A、B结点上升

    - B结点成为C的左孩子，A结点成为C的右孩子

    - 原来C结点的左子树作为B的右子树，原来C结点的右子树作为A的左子树

    ![图11：LR型调整示例](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E5%9B%BE11%EF%BC%9ALR%E5%9E%8B%E8%B0%83%E6%95%B4%E7%A4%BA%E4%BE%8B.png)

4. RL型调整

    ![图12：RL型调整前示意图](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E5%9B%BE12%EF%BC%9ARL%E5%9E%8B%E8%B0%83%E6%95%B4%E5%89%8D%E7%8A%B6%E6%80%81.png)

    ![图13：RL型调整示例](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E5%9B%BE13%EF%BC%9ARL%E5%9E%8B%E8%B0%83%E6%95%B4%E7%A4%BA%E4%BE%8B.png)

## 7.4 哈希表的查找（散列表的查找）

### 7.4.1 散列表的基本概念

基本思想：**记录的存储位置与关键字之间的存在对应关系**，对应关系常成为hash函数。

**优点：查找效率高；缺点：空间效率低！**

**散列方法（杂凑法）**：选取某个函数，依该函数按关键字**计算元素的存储位置**，并按此存放。查找时，**由同一个函数对给定值k计算地址**，将k与地址单元中元素关键码进行对比，确定查找是否成功。

**散列函数（杂凑函数）**：散列方法中适用的**转换函数**。

**冲突**：不同的关键码映射到同一个散列地址，则称为冲突。

### 7.4.2 散列函数的构造方法

在散列查找方法中，冲突是不可避免的，只能尽可能避免。使用散列表要解决的两个主要为题包括：

1. 构造好的散列函数

    - 所选函数尽可能简单，以便提高转换速度；

    - 所选函数对关键码计算出的地址，应在散列地址集中致均匀分布，以减少空间浪费。

2. 制定一个好的解决冲突的方案

    - 查找时，如果从散列函数计算出的地址中查不到关键码，则应当依据解决冲突的规则，有规律地查询其它相关单元。

构造散列函数考虑的因素：执行速度、关键字的长度、散列表的大小、关键字的分布情况、查找频率。

根据元素集合的特性构造，**要求一**：n个数据原仅占用n个地址，虽然散列查找是以空间换时间，但仍希望散列的**地址空间尽量小**。**要求二**：无论用什么方法存储，目的都是尽量**均匀**地存放元素，以避免冲突。

常见构造方法包括有：直接定址法、数字分析法、平方取中法、折叠法、**除留余数法**、随机数法。

**直接定址法**：以关键码key的某个线性函数值为散列地址，不会产生冲突。但是要占用连续地址空间，空间效率低。

**除留余数法**：`Hash(key) = key mod p(其中p是一个整数)`，常见p值取小于表长的质数。

### 7.4.3 处理冲突的方法

1. 开放地址法（开地址法）

    当有冲突时就去寻找**下一个**空的散列地址，只要散列表足够大，空的散列地址总能找到，并将数据元素存入。常见方法包括：**线性探测法**、**二次探测法**、**伪随机探测法**。`Hi = (Hash(key) + di) mod m, m是散列表长度, di是增量序列`

    线性探测法：`di为1, 2, ..., m-1线性序列`，一旦冲突，就找下一个地址，直到找到空地址存入。

    二次探测法：`di为1^2, -1^2, 2^2, -2^2， ..., q^2二次序列`。

    伪随机探测法：`di为伪随机数序列`。

2. 链地址法（拉链法）

    将相同散列地址的记录链成一个单链表，**m个散列地址就设m个单链表**，然后用一个数组将m个单链表的表头指针存储起来，形成一个动态的结构。

    链地址法建立散列表步骤：

    1. 取数据元素的关键字key，计算其散列函数值（地址）。若该地址对应的链表为空，则将该元素插入此链表；否则执行步骤2解决冲突。

    2. 根据选择的冲突处理方法，计算关键字key的下一个存储地址。若该地址对应的链表为不为空，则利用链表的前插法或后插法将该元素插入此链表。

    连地址法的优点：非同义词**不会冲突**，无聚集现象；链表上结点空间动态申请，更适合于表长不确定的情况；

3. 再散列法（双散列函数法）

4. 建立一个公共溢出区

### 7.4.4 散列表的查找及性能分析

![图14：散列表查找流程图](https://github.com/Vuean/DataStructure-Algorithmics/blob/main/Chapter7%20Search/%E5%9B%BE14%EF%BC%9A%E6%95%A3%E5%88%97%E8%A1%A8%E6%9F%A5%E6%89%BE%E6%B5%81%E7%A8%8B%E5%9B%BE.png, '散列表查找流程图')

散列表的查找效率，如果使用平均查找长度ASL来衡量，则ASL取决于：散列函数、处理冲突的方法、散列表的**装填因子**α（`α=表中填入的记录数/哈希表的长度`）。

其中，α越大，表中记录的数据越多，说明表装填的越满，发生冲突的可能性越大，查找时比较次数就越多。

ASL与装填因子α有关，既不是严格的O(1)，也不是O(n)。

`ASL≈1+α/2(拉链法);ASL≈1/2*(1+(1/(1-α)))(线性探测法);ASL≈-(1/α)*ln(1-α)(随机探测法)`。