#include <iostream>
#include "AlgoDesignStack.h"
using namespace std;

void InOutStack(SqStack& S){
    int n = 0;
    cin >> n;   // 输入待输入的整数的数量
    for(int i = 0; i < n; i++){
        int x;
        while(cin >> x){
            if(x != -1){
                if(S.top - S.base == S.stacksize){
                    cout << "栈满" << endl;
                }else{
                    *S.top++ = x;
                }
            }else{
                if(S.top == S.base){
                    cout << "栈空" << endl;
                }else{
                    cout << *S.top-- << endl;
                }
            }
        }
    }
}