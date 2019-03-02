//
//  P06_1652677_吴桐欣.h
//

#ifndef P06_1652677_吴桐欣_h
#define P06_1652677_吴桐欣_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class member{
    friend class tree;
private:
    string _name;//名字
    member* _parent;//父代
    vector<member*> _child;//子代
    member(){};
    member(string name, member* parent=NULL):_name(name),_parent(parent){};
    member* search(string name);
};

class tree {
private:
    member* _ancestor;//祖先，家谱树的根节点
public:
    tree(string name) {
        _ancestor = new member(name);
        _ancestor->_name=name;
        cout<<"此家谱的祖先是："<<_ancestor->_name<<endl;
    };
    bool changeName(string oldName, string newName);//更改姓名
    void dissolve(string parentName);//解散家庭
    void addChild(string parentName, string childName);//搜索父代名字，添加后代
    bool addChild(member* parent, string childName);//利用父代指针，添加后代
    void build(string name, int nChild);//建立家庭，即添加多个后代
    member* search(string name){return _ancestor->search(name);}//搜索函数
    void showChildList(member* parent);//输出子代
    void display();//展示家谱
};

member* member:: search(string name){
    //是否就是此节点
    if (this->_name == name) {
        return this;
    } else {
        //是否有子节点
        if (this->_child.empty()) {
        } else {
            for (auto& p:_child) {
                member* cur=p->search(name);
                if (cur) {return cur;}
            }
        }
        return NULL;
    }
}


bool tree:: changeName(string oldName, string newName){
    member* person = _ancestor->search(oldName);
    if (!person) {
        cout<<"未找到成员"<<endl;
        return false;
    }
    person->_name = newName;
    if (person->_name==newName) {
        return true;
    } else {
        return false;
    }
}

void tree:: dissolve(string parentName){
    member* parent=_ancestor->search(parentName);
    if (!parent) {
        cout<<"未找到成员"<<endl;
        return;
    }
    cout<<"[操作前]"<<endl;
    showChildList(parent);
    for (auto& p:parent->_child){
        delete p;
        parent->_child.pop_back();
    }
    cout<<"[操作后]"<<endl;
    showChildList(parent);
}

void tree:: addChild(string parentName, string childName){
    member* parent=_ancestor->search(parentName);
    if (!parent) {
        cout<<"未找到成员"<<endl;
        return;
    }
    if(addChild(parent, childName)){
        showChildList(parent);
    } else {
        cerr<<"操作失败！"<<endl;
    }
}

bool tree:: addChild(member* parent, string childName){
    member* child = new member(childName);
    child->_parent = parent;
    parent->_child.push_back(child);
    //检查是否添加成功
    if (parent->_child.back()->_name == childName) {
        return true;
    } else {
        return false;
    }
}

void tree:: build(string parentName, int nChild){
    member* parent=_ancestor->search(parentName);
    if (!parent) {
        cout<<"未找到成员"<<endl;
        return;
    }
    string childName;
    for (int i=0; i<nChild; i++) {
        cin>>childName;
        addChild(parent, childName);
    }
    showChildList(parent);
}

void tree:: showChildList(member* parent){
    if (parent->_child.empty()) {
        cout<<parent->_name<<"没有后代";
    } else {
        cout<<parent->_name<<"的第一代后代是:";
        for (auto& p:parent->_child) {
            cout<<p->_name<<" ";
        }
    }
    cout<<endl;
}

void tree:: display(){
    vector<member*> haveChild;
    if (!_ancestor->_child.empty()) {
        haveChild.push_back(_ancestor);
    } else {
        cout<<"祖先"<<_ancestor->_name<<"没有后代"<<endl;    }
    member* cur;
    while (!haveChild.empty()) {
        cur=haveChild.back();
        showChildList(cur);
        haveChild.pop_back();
        for (auto& p:cur->_child) {
            if (!p->_child.empty()) {
                haveChild.push_back(p);
            }
        }
    }
}
#endif /* P06_1652677_吴桐欣_h */
