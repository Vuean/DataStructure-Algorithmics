#include <iostream>
using namespace std;

// �ж��ַ�����A�е�������������Ƿ��ǺϷ�����
bool Judge(char A[]){
    int index = 0, inum = 0, onum = 0;
    while(A[index] != '\0'){
        if(A[index] == 'I'){
            inum++;
        }else if(A[index] == 'O'){
            onum++;
        }
        if(onum > inum){
            cout << "�Ƿ�����" << endl;
            return false;
        }
        index++;
    }
    if(inum == onum){
        cout << "�Ϸ�����" << endl;
        return true;
    }else{
        cout << "�Ƿ�����" << endl;
        return false;
    }
}