//
//  P04_1652677_吴桐欣.h
//

#ifndef P04_1652677_吴桐欣_h
#define P04_1652677_吴桐欣_h
#include <iostream>
#include <vector>
using namespace std;

struct Point{
    int x;//行
    int y;//列
};

struct List{
    int n;//棋盘大小
    vector<bool> row;//行
    vector<bool> col;//列
    vector<bool> mainDiag;//主对角线（左上-右下）
    vector<bool> minorDiag;//副对角线（右上-左下）
    
    bool onList(Point p)const;//检查某一位置是否可放皇后
    
    void initialize();//初始化4个数组
    
    void addPoint(Point p);//新增一个皇后时，更新数组
    
    void deletePoint(Point p);//回溯时移走一个皇后时，更新数组
};

bool List::onList(Point p)const{
    if (row[p.x] == true
        && col[p.y] == true
        && mainDiag[p.x-p.y+n-1] == true
        && minorDiag[p.x+p.y] == true) {
        //当且仅当p位置在4个数组中对应元素值均为true时，p位置才可放置皇后
        return true;
    } else {
        return false;
    }
}

void List::initialize(){
    for (int i=0; i<n; i++) {
        row.push_back(true);
        col.push_back(true);
    }
    for (int i=0; i<(2*n-1); i++) {
        mainDiag.push_back(true);
        minorDiag.push_back(true);
    }
}

void List::addPoint(Point p){
    row[p.x] = false;
    col[p.y] = false;
    mainDiag[p.x-p.y+n-1] = false;
    minorDiag[p.x+p.y] = false;
}

void List::deletePoint(Point p){
    row[p.x] = true;
    col[p.y] = true;
    mainDiag[p.x-p.y+n-1] = true;
    minorDiag[p.x+p.y] = true;
}
#endif /* P04_1652677_吴桐欣_h */
