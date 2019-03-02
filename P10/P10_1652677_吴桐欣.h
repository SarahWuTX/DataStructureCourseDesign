//
//  P10_1652677_吴桐欣.h
//

#ifndef P10_1652677_____h
#define P10_1652677_____h
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void SWAP(int& a, int& b);//交换函数
void BubbleSort(vector<int> list);//冒泡排序函数
void SelectSort(vector<int> list);//选择排序函数
void InsertSort(vector<int> list);//直接插入排序函数
void ShellSort(vector<int> list);//希尔排序函数
void QuickSort(vector<int> list, const int left, const int right, int& count_comp, int& count_swap);
//快速排序函数
int& median3(vector<int>& list, const int left, const int right, int& count_comp, int& count_swap);
//快速排序-三者取中函数
int Partition(vector<int>& list, const int left, const int right, int& count_comp, int& count_swap);
//快速排序-一趟划分函数

void siftDown(vector<int>& heap, int s, int m);//堆排序-从s到m自顶向下调整最大堆
void HeapSort(vector<int> list);//堆排序函数

void Merge(vector<int>& list, const int left, const int mid, const int right, int& count_comp, int& count_swap);//归并排序-合并
void MergeSort(vector<int>& list, int left, int right, int& count_comp, int& count_swap);//归并排序函数

void RadixSort(vector<int> list);//基数排序函数

//交换函数
void SWAP(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}

//冒泡排序
void BubbleSort(vector<int> list){
    long n=list.size();//元素个数
    int count_comp=0;//记录比较次数
    int count_swap=0;//记录交换次数
    
    clock_t start=clock();
    
    for (int i=0; i<n-1; i++) {
        bool exchange=false;//是否产生交换
        for (long j=n-1; j>0; j--) {
            count_comp++;
            if (list[j-1]>list[j]) {
                //发现逆序，进行交换
                SWAP(list[j], list[j-1]);
                count_swap++;
                exchange = true;
            }
        }
        if (!exchange) {
            //本轮不产生交换，排序完毕
            break;
        }
    }
    clock_t end=clock();
    cout<<"冒泡排序所用时间："<<(float)(end-start)/CLOCKS_PER_SEC<<" 秒"<<endl;
    cout<<"冒泡排序比较次数："<<count_comp<<endl;
    cout<<"冒泡排序交换次数："<<count_swap<<endl<<endl;
}

//选择排序
void SelectSort(vector<int> list){
    long n=list.size();//元素个数
    int count_comp=0;//记录比较次数
    int count_swap=0;//记录交换次数
    
    clock_t start=clock();
    for (int i=0; i<n; i++) {
        int min_i=i;//最小元素的序号
        for (int j=i+1; j<n; j++) {
            count_comp++;
            if (list[min_i]>list[j]) {min_i = j;}
        }
        //交换
        SWAP(list[i], list[min_i]);
        count_swap++;
    }
    clock_t end=clock();
    cout<<"选择排序所用时间："<<(float)(end-start)/CLOCKS_PER_SEC<<" 秒"<<endl;
    cout<<"选择排序比较次数："<<count_comp<<endl;
    cout<<"选择排序交换次数："<<count_swap<<endl<<endl;
}

//直接插入排序
void InsertSort(vector<int> list){
    long n=list.size();//元素个数
    int count_comp=0;//记录比较次数
    int count_swap=0;//记录交换次数
    int temp;//暂存要插入的元素
    
    clock_t start=clock();
    for (int i=1; i<n; i++) {
        //获取要插入的元素
        temp=list[i];
        //从后向前一个个比较
        for (int j=i-1; j>=0; j--) {
            count_comp++;
            if (list[j]>temp) {
                //将前一个元素后移
                list[j+1]=list[j];
            } else {
                //若前面数小于temp，则找到要插入的位置
                list[j+1]=temp;
                break;
            }
        }
    }
    count_swap=count_comp;//每次比较都会修改数据，因此交换次数与比较次数相等
    clock_t end=clock();
    cout<<"直接插入排序所用时间："<<(float)(end-start)/CLOCKS_PER_SEC<<" 秒"<<endl;
    cout<<"直接插入排序比较次数："<<count_comp<<endl;
    cout<<"直接插入排序交换次数："<<count_swap<<endl<<endl;
}

//希尔排序
void ShellSort(vector<int> list){
    int count_comp=0;//记录比较次数
    int count_swap=0;//记录交换次数
    long n=list.size();//元素个数
    int gap=(int)n;//增量
    
    clock_t start=clock();
    do{
        gap = gap/3+1;//计算增量
        for (int i=gap; i<n; i+=gap) {
            count_comp++;
            //若在子序列中发现逆序
            if (list[i-gap]>list[i]) {
                int temp=list[i];
                //用直接插入法，从后向前比较
                for (int j=i-gap; ; j-=gap) {
                    count_comp++;
                    if (list[j]<=temp) {
                        //小于等于temp，找到temp插入位置
                        list[j+gap]=temp;
                        count_swap++;
                        break;
                    } else {
                        //若比temp大，则后移一位
                        list[j+gap]=list[j];
                        count_swap++;
                    }
                }
            }
        }
    } while (gap>1);
    clock_t end=clock();
    cout<<"希尔排序所用时间："<<(float)(end-start)/CLOCKS_PER_SEC<<" 秒"<<endl;
    cout<<"希尔排序比较次数："<<count_comp<<endl;
    cout<<"希尔排序交换次数："<<count_swap<<endl<<endl;
}

//快速排序-三者取中
int& median3(vector<int>& list, const int left, const int right, int& count_comp, int& count_swap){
    int mid=(left+right)/2;
    int k=left;
    if (list[mid]<list[k]) {k=mid;}
    if (list[right]<list[k]) {k=right;}//left,mid,right三者选最小
    if (k!=left) {
        SWAP(list[k], list[left]);
        
    }//把最小值移到left位置
    if (mid!=right && list[mid]<list[right]) {
        SWAP(list[right], list[mid]);
    }//把中间值，即基准，移到right位置
    return list[right];
}
//快速排序-一趟划分
int Partition(vector<int>& list, const int left, const int right, int& count_comp, int& count_swap){
    int i=left;
    int j=right-1;
    if (left<right) {
        int pivot=median3(list, left, right, count_comp, count_swap);
        for (; ; ) {
            while (i<j && list[i]<pivot) {i++;count_comp++;}
            while (i<j && list[j]>pivot) {j--;count_comp++;}
            if (i<j) {
                SWAP(list[i], list[j]);//交换list[i],list[j]的值
                count_swap++;
                i++;
                j--;
            } else {
                break;
            }
        }
        if (list[i]>pivot) {
            list[right]=list[i];
            list[i]=pivot;
            count_swap++;
            count_comp++;
        }
    }
    return i;
}
//快速排序
void QuickSort(vector<int> list, const int left, const int right, int& count_comp, int& count_swap){
    if (left==right) {}
    else if (left==right-1) {
        count_comp++;
        if (list[left]>list[right]) {
            SWAP(list[left], list[right]);
            count_swap++;
        }
    }
    else {
        int pivotpos=Partition(list, left, right, count_comp, count_swap);//划分
        QuickSort(list, left, pivotpos-1, count_comp, count_swap);
        QuickSort(list, pivotpos+1, right, count_comp, count_swap);
    }
}

//堆排序-从s到m自顶向下调整
void siftDown(vector<int>& heap, int s, int m, int& count_comp, int& count_swap){
    int i=s;
    int j=2*i+1;//j是i的左子女
    int temp=heap[i];
    while (j<=m) {
        count_comp++;
        if (j<m && heap[j]<heap[j+1]) {j++;}//j指向两子女中最大者
        count_comp++;
        if (temp>=heap[j]){
            break;
        } else {
            count_swap++;
            heap[i]=heap[j];
            i=j;
            j=2*i+1;//i降到子女的位置
        }
        
    }
    heap[i]=temp;
    count_swap++;
}
//堆排序
void HeapSort(vector<int> list){
    int count_comp=0;//记录比较次数
    int count_swap=0;//记录交换次数
    int n=(int)list.size();//元素个数
    
    clock_t start=clock();
    for (int i=(n-2)/2; i>=0; i--) {
        siftDown(list, i, n-1, count_comp, count_swap);
    }
    for (int i=n-1; i>=0; i--) {
        SWAP(list[0], list[i]);
        count_swap++;
        siftDown(list, 0, i-1, count_comp, count_swap);
    }
    clock_t end=clock();
    cout<<"堆排序所用时间："<<(float)(end-start)/CLOCKS_PER_SEC<<" 秒"<<endl;
    cout<<"堆排序比较次数："<<count_comp<<endl;
    cout<<"堆排序交换次数："<<count_swap<<endl<<endl;
}

//归并排序-合并
void Merge(vector<int>& list, const int left, const int mid, const int right, int& count_comp, int& count_swap){
    vector<int> tempList(list);
    int s1=left,s2=mid+1,t=left;//s1，s2是检测指针，t是存放指针
    while(s1<=mid && s2<=right){
        count_comp++;
        count_swap++;
        if (tempList[s1]<=tempList[s2]) {
            list[t++]=tempList[s1++];
        } else {
            list[t++]=tempList[s2++];
        }
    }
    while (s1<=mid) {
        list[t++]=tempList[s1++];
        count_swap++;
    }
    while (s2<=right) {
        list[t++]=tempList[s2++];
        count_swap++;
    }
}
//归并排序函数
void MergeSort(vector<int>& list, int left, int right, int& count_comp, int& count_swap){
    if (left>=right) {
        return;
    }
    int mid=(left+right)/2;
    MergeSort(list, left, mid, count_comp, count_swap);//左子序列排序
    MergeSort(list, mid+1, right, count_comp, count_swap);//右子序列排序
    Merge(list, left, mid, right, count_comp, count_swap);//合并左右子序列
}

//基数排序
void RadixSort(vector<int> list){
    int n=(int)list.size();//元素个数
    int count_comp=0;//记录比较次数
    int count_swap=0;//记录交换次数
    vector<int> tempList(list);
    
    clock_t start=clock();
    for (long place=1; ; place*=10) {
        int k=0;//存放指针
        bool change=false;
        for (int radix=0;; radix++) {
            for (int i=0; i<tempList.size();i++) {
                count_comp++;
                if ((tempList[i]%(10*place))/place == radix) {
                    if (list[k]!=tempList[i]) {
                        list[k]=tempList[i];//放入结果列中
                        count_swap++;
                        change=true;
                    }
                    k++;//存放指针移至下一个位置
                    if (i!=tempList.size()-1) {
                        //将此数移到列尾
                        int temp_i=i;
                        while(temp_i!=tempList.size()-1){
                            tempList[temp_i]=tempList[temp_i+1];
                            temp_i++;
                        }
                        i--;//要使下一步从i位置开始
                    }
                    tempList.pop_back();
                }
            }
            if (radix>9 || k>=n) {
                break;
            }
        }
        if (change==false) {
            break;
        }
        tempList=list;
    }
    clock_t end=clock();
    cout<<"基数排序所用时间："<<(float)(end-start)/CLOCKS_PER_SEC<<" 秒"<<endl;
    cout<<"基数排序比较次数："<<count_comp<<endl;
    cout<<"基数排序交换次数："<<count_swap<<endl<<endl;
}

#endif /* P10_1652677_____h */
