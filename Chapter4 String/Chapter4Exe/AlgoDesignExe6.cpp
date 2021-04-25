/*
本题属于排序问题，只是排出正负，不排出大小。可在数组首尾设两个指针
i和j，i自小至大搜索到负数停止，j自大至小搜索到正数停止。然后i和j所
指数据交换，继续以上过程，直到i=j为止。
*/

void Arrange(int A[], int n){
    int i = 0, j = n-1, x;
    while(i < j){
        while(i < j && A[i] > 0) i++;
        while(i < j && A[j] < 0) j--;
        if(i < j){
            x = A[i];
            A[i++] = A[j];
            A[j--] = x;
        }
    }
}