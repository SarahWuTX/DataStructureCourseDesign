//
//  01_1652677_吴桐欣.h
//

#ifndef P01_1652677_吴桐欣_h
#define P01_1652677_吴桐欣_h

#include <iostream>
using namespace std;

class student {
    friend class system; //声明友元类
private:
    int _id;
    string _name;
    string _gender;
    int _age;
    string _type;
    student* _last;
    student* _next;
public:
    student(student* last=NULL, student* next=NULL){_last=last, _next=next;};
    student(const int& ID, const string& name, const string& gender, const int& age, const string& type, student* last=NULL, student* next=NULL) {
        _id=ID;
        _name=name;
        _gender=gender;
        _age=age;
        _type=type;
        _last=last;
        _next=next;
    }//两个构造函数
    friend istream& operator>>(istream& is, student& rhs);//重载输入符号
    friend ostream& operator<<(ostream& os, const student& rhs);//重载输出符号
};


class system {
private:
    student* _data;
public:
    //构造函数
    system(){_data = new student;}
    //析构函数
    ~system(){
        student* toDelete=NULL;
        while(toDelete!=NULL){
            toDelete = _data->_next;
            _data->_next = toDelete->_next;
            delete toDelete;
            
        }
    }
    void insertStu(int pos, student* newStu);//插入考生
    void deleteStu(student* stu);//删除考生
    student* searchStu(int ID);//根据考号查找考生
    student* findPos(int pos);//根据位置查找将插入的考生的位置
    void reset(int item, student* stu);//修改信息
    void display();//输出所有信息，即统计
};


istream& operator>>(istream& is, student& rhs){
    int ID, age;
    string name, gender, type;
    is >> ID >> name >> gender >> age >> type;
    rhs._id = ID;
    rhs._name = name;
    rhs._gender = gender;
    rhs._age = age;
    rhs._type = type;
    return is;
};

ostream& operator<<(ostream& os, const student& rhs){
    cout.width(10);
    os<<rhs._id;
    cout.width(10);
    os<<rhs._name;
    cout.width(10);
    os<<rhs._gender;
    cout.width(10);
    os<< rhs._age;
    cout.width(10);
    os<<rhs._type<<endl;
    return os;
};

void system::reset(int item, student* stu){
    switch (item) {
        case 1:
        {
            int ID;
            cout<<"请输入新的考号：";
            cin>>ID;
            stu->_id = ID;
            break;
        }
        case 2:
        {
            string name;
            cout<<"请输入新的姓名：";
            cin>>name;
            stu->_name = name;
            break;
        }
        case 3:
        {
            string gender;
            cout<<"请输入新的性别：";
            cin>>gender;
            stu->_gender = gender;
            break;
        }
        case 4:
        {
            int age;
            cout<<"请输入新的年龄：";
            cin>>age;
            stu->_age = age;
            break;
        }
        case 5:
        {
            string type;
            cout<<"请输入新的报考类别：";
            cin>>type;
            stu->_type = type;
            break;
        }
        default:
            break;
    }
    
}


void system::insertStu(int pos, student* newStu){
    student* pre = findPos(pos-1);
    if (pre) {
        newStu->_next = pre->_next;
        pre->_next = newStu;
        newStu->_last=pre;
        if (newStu->_next) {
            newStu->_next->_last=newStu;
        }
    } else {
        cout<<"该数字超过当前考生人数，无法完成操作"<<endl;
    }
}

void system::deleteStu(student* stu){
    cout<<"你删除的考生的信息是："<<endl;
    cout<<*stu;
    stu->_next->_last = stu->_last;
    stu->_last->_next = stu->_next;
    delete stu;
}

student* system::searchStu(int ID){
    student* current = _data;
    while(current) {
        if (current->_id == ID) {
            return current;
            break;
        }
        current = current->_next;
    }
    return NULL;
}

student* system::findPos(int pos){
    student* cur = _data;
    for (int i=0; i<pos; i++) {
        if (cur->_next) {
            cur = cur->_next;
        } else {
            return NULL;
        }
    }
    return cur;
}

void system::display(){
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
    student* current = _data->_next;
    while (current) {
        cout<<*current;
        current = current->_next;
    }
}

#endif /* P01_1652677_吴桐欣_h */
