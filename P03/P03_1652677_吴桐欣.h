//
//  P03_1652677_吴桐欣.h
//

#ifndef P03_1652677_吴桐欣_h
#define P03_1652677_吴桐欣_h
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define ctr(x,y,n) x*n+y
#define up(x,y,n) (x-1)*n+y
#define dw(x,y,n) (x+1)*n+y
#define le(x,y,n) x*n+y-1
#define ri(x,y,n) x*n+y+1
#define within(border,x) (x<border?1:0)&&(x>=0)

struct Point{
    int x;
    int y;
    //重载操作符
    Point& operator = (const Point& rhs){
        x = rhs.x;
        y = rhs.y;
        return *this;
    };
    bool operator != (const Point& rhs){
        if (x==rhs.x && y==rhs.y){return false;}
        else return true;
    };
    bool operator == (const Point& rhs){
        if (x==rhs.x && y==rhs.y){return true;}
        else return false;
    };
};

struct step{
    Point pos;//现在的位置
    vector<Point> choice;//可能的下一位置
    //重载操作符
    step& operator = (const step& rhs){
        pos = rhs.pos;
        choice = rhs.choice;
        return *this;
    };
};

class solut{
public:
    int* _track;//记录走过的地方
    char* _map;//迷宫地图
    stack<step> _cross;//经过的岔口
    stack<Point> _path;//走过的路径

    solut(int* track=NULL, char* map=NULL){_track=track;_map=map;};
    ~solut(){};
    bool findWay(step* cur, int col, int row);//寻找某一位置的下一可能位置
};

bool solut::findWay(step* cur, int col, int row){
    int x=cur->pos.x,y=cur->pos.y;
    //上侧
    if (_map[up(x, y, col)] == '0' && _track[up(x, y, col)] == 0 && within(row, x-1)) {
        cur->choice.push_back({x-1,y});
    } else if(_map[up(x, y, col)] == 'S'){
        cur->choice.clear();
        cur->choice.push_back({x-1,y});
        return true;
    }
    //下侧
    if (_map[dw(x, y, col)] == '0' && _track[dw(x, y, col)] == 0 && within(row, x+1)) {
        cur->choice.push_back({x+1,y});
    } else if(_map[dw(x, y, col)] == 'S'){
        cur->choice.clear();
        cur->choice.push_back({x+1,y});
        return true;
    }
    //左侧
    if (_map[le(x, y, col)] == '0' && _track[le(x, y, col)] == 0 && within(col, y-1)) {
        cur->choice.push_back({x,y-1});
    } else if(_map[le(x, y, col)] == 'S'){
        cur->choice.clear();
        cur->choice.push_back({x,y-1});
        return true;
    }
    //右侧
    if (_map[ri(x, y, col)] == '0' && _track[ri(x, y, col)] == 0 && within(col, y+1)) {
        cur->choice.push_back({x,y+1});
    } else if(_map[ri(x, y, col)] == 'S'){
        cur->choice.clear();
        cur->choice.push_back({x,y+1});
        return true;
    }
    return false;
}

ostream& operator << (ostream& os, Point& p){
    return os<<"("<<p.x<<","<<p.y<<")";
}
#endif /* P03_1652677_吴桐欣_h */
