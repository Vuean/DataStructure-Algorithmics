// 将字符串t插入字符串s的第pos个位置
#include <iostream>
using namespace std;

void insert(char* s, char* t, int pos){
    int i = 1, x = 0;
    char *p = s, *q = t;    // p和q、分别为字符串s和t的工作指针
    if(pos < 1){
        cout << "pos参数位置非法" << endl;
        return;
    }
    // 查找pos位置
    while(*p != '\0' && i < pos){
        p++;
        i++;
    }
    if(*p == '\0'){
        cout << "pos参数大于字符串s的长度" << endl;
        return;
    }else{
        // 查找字符串的尾
        while(*p != '\0'){
            // 查到尾时，i为字符'\0'的下标，p也指向'\0'
            p++;
            i++;
        }
        while(*q != '\0'){
            // 查找t的长度x，循环结束时，q指向'\0'
            q++;
            x++;
        }
        for(int j = i; j >= pos; j--){
            // 串s的pos后的子串右移，空出串t的位置。
            *(p+x) = *p;
            p--;
        }
        q--;    // 指针q回退到串t的最后一个字符
        for(int j = 1; j <= x; j++){
            // 将t串插入到s的pos位置上
            *p-- = *q--;
        }
    }
}