//
//  P02_1652677_吴桐欣.cpp
//

#include <iostream>
using namespace std;

struct man{
    int id;//序号
    man* next;//下一个人
};

int main(void) {
    //获取数据
    int n,m,s,k;
    while(true) {
        cout<<"总人数n：";
        cin>>n;
        if (n>0) {
            break;
        } else {
            if (cin.fail()) {
                cerr<<"输入了非法字符！"<<endl;
                cin.clear();
                string st;
                cin>>st;
            } else {
                cerr<<"请输入符合条件的操作数！"<<endl;
            }
        }
    }
    while(true) {
        cout<<"开始位置s：";
        cin>>s;
        if (s>0 && s<=n) {
            break;
        } else {
            if (cin.fail()) {
                cerr<<"输入了非法字符！"<<endl;
                cin.clear();
                string st;
                cin>>st;
            } else {
                cerr<<"请输入符合条件的操作数！"<<endl;
            }
        }
    }
    while(true) {
        cout<<"循环数m：";
        cin>>m;
        if (m>0) {
            break;
        } else {
            if (cin.fail()) {
                cerr<<"输入了非法字符！"<<endl;
                cin.clear();
                string st;
                cin>>st;
            } else {
                cerr<<"请输入符合条件的操作数！"<<endl;
            }
        }
    }
    while(true) {
        cout<<"剩余人数k：";
        cin>>k;
        if (k>0 && k<n) {
            break;
        } else {
            if (cin.fail()) {
                cerr<<"输入了非法字符！"<<endl;
                cin.clear();
                string st;
                cin>>st;
            } else {
                cerr<<"请输入符合条件的操作数！"<<endl;
            }
        }
    }
    
    //初始化三个指针，创建循环链表
    man* data=NULL;//序号为1的人
    man* cur=NULL;
    man* start = NULL;//循环开始位置
    for (int i=1; ; i++) {
        man* temp = new man;
        temp->id = i;
        if (i==s) {
            start = temp;
        }
        if (i==1) {
            data = temp;
            cur = temp;
        } else {
            cur->next = temp;
            cur = temp;
        }
        if (i==n) {
            cur->next = data;
            break;
        }
    }
    //开始游戏
    for (cur=start; ;cur=cur->next) {
        static int count=1;//记录循环数
        static int dead=0;//记录死者个数
        if (count==m-1) {//如果下一个人将要死
            dead++;
            man* toDie=cur->next;
            if (toDie == data) {
                //如果是序号为1的人死去，要将data指针指向下一个人
                data = toDie->next;
            }
            cout<<"第"<<dead<<"个死者的位置是："<<toDie->id<<endl;
            cur->next = toDie->next;
            delete toDie;//释放空间
            count=1;//计数从1开始
            if (dead==n-k) {
                //幸存者数符合要求，结束游戏
                break;
            }
        } else {
            count++;//循环数+1
        }
    }
    cout<<"最后剩下:"<<k<<"人"<<endl;
    cout<<"幸存者的位置为："<<endl;
    //输出幸存者
    cur = data;
    for (int i=0; i<k; i++) {
        cout<<cur->id<<" ";
        cur = cur->next;
    }
    cout<<endl;
    
    return 0;
}

