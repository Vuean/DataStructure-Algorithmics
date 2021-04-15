#include <iostream>
#include "AlgoDesignStack.h"
using namespace std;

void InOutStack(SqStack& S){
    int n = 0;
    cin >> n;   // ��������������������
    for(int i = 0; i < n; i++){
        int x;
        while(cin >> x){
            if(x != -1){
                if(S.top - S.base == S.stacksize){
                    cout << "ջ��" << endl;
                }else{
                    *S.top++ = x;
                }
            }else{
                if(S.top == S.base){
                    cout << "ջ��" << endl;
                }else{
                    cout << *S.top-- << endl;
                }
            }
        }
    }
}