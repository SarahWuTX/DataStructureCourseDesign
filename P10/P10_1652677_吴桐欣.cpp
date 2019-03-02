//
//  P10_1652677_吴桐欣.cpp
//

#include "P10_1652677_吴桐欣.h"

int main(void) {
    cout<<"[排序算法比较]"<<endl;
    cout<<"1--冒泡排序"<<endl;
    cout<<"2--选择排序"<<endl;
    cout<<"3--直接插入排序"<<endl;
    cout<<"4--希尔排序"<<endl;
    cout<<"5--快速排序"<<endl;
    cout<<"6--堆排序"<<endl;
    cout<<"7--归并排序"<<endl;
    cout<<"8--基数排序"<<endl;
    cout<<"9--退出程序"<<endl<<endl;
    
    //获得随机数的个数
    int n;
    while(true) {
        cout<<"请输入要产生的随机数的个数：";
        cin>>n;
        if (n>0) {
            break;
        } else {
            if (cin.fail()) {
                cerr<<"输入了非法字符！"<<endl;
                cin.clear();
                string s;
                cin>>s;
            } else {
                cerr<<"请输入符合条件的操作数！"<<endl;
            }
        }
    }
    vector<int> numbs;
    //获得随机数，用vector存储所有随机数
    for (int i=0; i<n; i++) {numbs.push_back(rand());}
    
    int choice;
    //用户选择算法，确认用户输入符合要求
    while(true) {
        cout<<"请选择排序算法：";
        cin>>choice;
        if (choice>=1 && choice<=9) {
            break;
        } else {
            if (cin.fail()) {
                cerr<<"输入了非法字符！"<<endl;
                cin.clear();
                string s;
                cin>>s;
            } else {
                cerr<<"请输入符合条件的数字！"<<endl;
            }
        }
    }
    while (choice!=9) {
        switch (choice) {
            case 1:
                BubbleSort(numbs);
                break;
            case 2:
                SelectSort(numbs);
                break;
            case 3:
                InsertSort(numbs);
                break;
            case 4:
                ShellSort(numbs);
                break;
            case 5:
            {
                int count_comp=0;//记录比较次数
                int count_swap=0;//记录交换次数
                clock_t start=clock();
                QuickSort(numbs, 0, (int)(numbs.size()-1), count_comp, count_swap);
                clock_t end=clock();
                cout<<"快速排序所用时间："<<(float)(end-start)/CLOCKS_PER_SEC<<" 秒"<<endl;
                cout<<"快速排序比较次数："<<count_comp<<endl;
                cout<<"快速排序交换次数："<<count_swap<<endl<<endl;
            }
                break;
            case 6:
                HeapSort(numbs);
                break;
            case 7:
            {
                vector<int> copyList(numbs);
                int count_comp=0;//记录比较次数
                int count_swap=0;//记录交换次数
                clock_t start=clock();
                MergeSort(copyList, 0, (int)(numbs.size()-1), count_comp, count_swap);
                clock_t end=clock();
                cout<<"归并排序所用时间："<<(float)(end-start)/CLOCKS_PER_SEC<<" 秒"<<endl;
                cout<<"归并排序比较次数："<<count_comp<<endl;
                cout<<"归并排序交换次数："<<count_swap<<endl<<endl;
            }
                break;
            case 8:
                RadixSort(numbs);
                break;
            default:
                break;
        }
        
        
        while(true) {
            cout<<"请选择排序算法：";
            cin>>choice;
            if (choice>=1 && choice<=9) {
                break;
            } else {
                if (cin.fail()) {
                    cerr<<"输入了非法字符！"<<endl;
                    cin.clear();
                    string s;
                    cin>>s;
                } else {
                    cerr<<"请输入符合条件的数字！"<<endl;
                }
            }
        }
    }
    cout<<"退出程序"<<endl;
    return 0;
}

//for (int i=0; i<n; i++) {cout<<list[i]<<endl;}

