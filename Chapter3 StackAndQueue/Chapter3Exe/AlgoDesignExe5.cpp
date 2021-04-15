#include <iostream>
using namespace std;

// 判断字符数组A中的输入输出序列是否是合法序列
bool Judge(char A[]){
    int index = 0, inum = 0, onum = 0;
    while(A[index] != '\0'){
        if(A[index] == 'I'){
            inum++;
        }else if(A[index] == 'O'){
            onum++;
        }
        if(onum > inum){
            cout << "非法序列" << endl;
            return false;
        }
        index++;
    }
    if(inum == onum){
        cout << "合法序列" << endl;
        return true;
    }else{
        cout << "非法序列" << endl;
        return false;
    }
}