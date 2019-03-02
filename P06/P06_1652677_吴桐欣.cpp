//
//  P06_1652677_吴桐欣.cpp
//

#include "P06_1652677_吴桐欣.h"
using namespace std;

int main(void) {
    cout<<"[家谱管理系统]"<<endl<<"请选择要执行的操作："<<endl;
    cout<<"[S]——查看家谱"<<endl;
    cout<<"[A]——完善家谱"<<endl;
    cout<<"[B]——添加家庭成员"<<endl;
    cout<<"[C]——解散局部家庭"<<endl;
    cout<<"[D]——更改家庭成员姓名"<<endl;
    cout<<"[E]——退出程序"<<endl<<endl;
    
    
    cout<<"首先建立一个家谱 —— 请输入祖先姓名：";
    string anceName;
    cin>>anceName;
    tree family(anceName);
    string ins;
    while(true){
        cout<<endl<<"请选择要执行的操作：";
        cin>>ins;
        if (ins=="S") {
            family.display();
        }
        else if (ins=="A") {
            cout<<"请输入要建立家庭的人的姓名：";
            string parentName;
            cin>>parentName;
            cout<<"请输入"<<parentName<<"的儿女人数：";
            int n;
            cin>>n;
            cout<<"请依次输入"<<parentName<<"的儿女的姓名：";
            family.build(parentName, n);
        }
        else if (ins=="B") {
            string parentName, childName;
            cout<<"请输入要添加孩子的人的姓名：";
            cin>>parentName;
            cout<<"请输入添加的孩子的姓名：";
            cin>>childName;
            family.addChild(parentName, childName);
        }
        else if (ins=="C") {
            cout<<"请输入要解散家庭的人的姓名：";
            string parentName;
            cin>>parentName;
            family.dissolve(parentName);
        }
        else if (ins=="D") {
            cout<<"请输入要更改姓名的人目前的姓名：";
            string oldName;
            cin>>oldName;
            string newName;
            cout<<"请输入更改后的姓名：";
            cin>>newName;
            if(family.changeName(oldName, newName)){
                cout<<oldName<<"已更名为"<<newName<<endl;
            } else {
                cerr<<"操作失败!"<<endl;
            }
        }
        else if (ins=="E") {
            cout<<"退出家谱管理系统"<<endl;
            break;
        } else {
            cout<<"无效字符"<<endl;
        }
    }
    
    
    return 0;
}
