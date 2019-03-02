//
//  01_1652677_吴桐欣.cpp
//

#include "P01_1652677_吴桐欣.h"

int main(void) {
    cout.setf(std::ios::left);
    class system* testSys = new class system;
    
    //建立系统
    cout<<"首先请建立考生信息系统！"<<endl;
    int n;
    while(true) {
        cout<<"请输入考生人数：";
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
    cout<<"请依次输入考生的考号，姓名，性别，年龄及报考类别："<<endl;
    for (int i=0; i<n; i++) {
        student* newStu = new student;
        cin>>*newStu;
        testSys->insertStu(i+1, newStu);
    }
    testSys->display();
    
    //执行操作
    int act;
    cout<<"操作数表(1-插入；2-删除；3-查找；4-修改；5-统计；0-取消)"<<endl;
    while(true) {
        cout<<"请选择您要进行的操作：";
        cin>>act;
        if (act>=0 && act<=5) {
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
    while(act != 0){
        switch (act) {
            case 1:
            {
                cout<<"请输入你要插入的考生的位置"<<endl;
                int pos;
                cin>>pos;
                while (pos<1) {
                    cerr<<"请输入符合条件的操作数！"<<endl;
                    cin>>pos;
                }
                student* newStu = new student;
                cout<<"请依次输入要插入的考生的考号，姓名，性别，年龄及报考类别："<<endl;
                cin>>*newStu;
                testSys->insertStu(pos, newStu);
                testSys->display();
                break;
            }
            case 2:
            {
                cout<<"请输入你要删除的考生的考号"<<endl;
                int ID;
                cin>>ID;
                student* find=testSys->searchStu(ID);
                if (find) {
                    testSys->deleteStu(find);
                } else {
                    cout<<"考生不存在！"<<endl;
                }
                
                break;
            }
            case 3:
            {
                cout<<"请输入你要查找的考生的考号"<<endl;
                int ID;
                cin>>ID;
                student* find=testSys->searchStu(ID);
                if (find) {
                    cout<<"以下是你所查找的考生信息："<<endl;
                    cout.width(10);
                    cout<<"考号";
                    cout.width(10);
                    cout<<"姓名";
                    cout.width(10);
                    cout<<"性别";
                    cout.width(10);
                    cout<<"年龄";
                    cout.width(10);
                    cout<<"报考类别"<<endl;
                    cout<<*find;
                } else {
                    cout<<"考生不存在！"<<endl;
                }
                break;
            }
            case 4:
            {
                cout<<"请输入你要修改的考生的考号"<<endl;
                int ID;
                cin>>ID;
                student* find=testSys->searchStu(ID);
                if (find) {
                    cout<<"可修改项目(1-考号，2-姓名，3-性别，4-年龄，5-报考类别)"<<endl;
                    int item;
                    while(true) {
                        cout<<"请选择要修改的项目：";
                        cin>>item;
                        if (item>0 && item<=5) {
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
                    testSys->reset(item, find);
                    cout<<"修改后的考生信息为："<<endl;
                    cout.width(10);
                    cout<<"考号";
                    cout.width(10);
                    cout<<"姓名";
                    cout.width(10);
                    cout<<"性别";
                    cout.width(10);
                    cout<<"年龄";
                    cout.width(10);
                    cout<<"报考类别"<<endl;
                    cout<<*find;
                } else {
                    cout<<"考生不存在！"<<endl;
                }

                break;
        }
            case 5:
            {
                testSys->display();
            }
            default:
                break;
        }
        cout<<endl<<"操作数表(1-插入；2-删除；3-查找；4-修改；5-统计；0-取消)"<<endl;
        while(true) {
            cout<<"请选择您要进行的操作：";
            cin>>act;
            if (act>=0 && act<=5) {
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
    }
    cout<<"考生信息系统最终为："<<endl;
    testSys->display();
    return 0;
}
