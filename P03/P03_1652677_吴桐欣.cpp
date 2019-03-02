//
//  P03_1652677_吴桐欣.cpp
//

#include "P03_1652677_吴桐欣.h"
using namespace std;

void displayMap(char* map, int m, int n);
void displayTrack(int** track, int m, int n);

int main(void) {
    int row=0,col=0;
    cout<<"输入迷宫地图的行数和列数：";
    cin>>row>>col;
    char map[row][col];//迷宫地图
    int track[row][col];//记录走过的地方
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            map[i][j]='#';
        }
    }
    
    displayMap(*map, row, col);
    int x,y;
    cout<<"请输入空位置的坐标“行 列”，一个坐标一行；若已输入完毕，行、列输入为-1"<<endl;
    while (true) {
        cin>>x>>y;
        map[x][y]='0';
        if (x==-1 && y==-1) {
            break;
        }
    }
    cout<<"请输入迷宫入口的坐标(行 列)：";
    cin>>x>>y;
    map[x][y]='S';
    Point start={x,y};
    cout<<"请输入迷宫出口的坐标(行 列)：";
    cin>>x>>y;
    map[x][y]='E';
    Point exitP={x,y};
    cout<<"迷宫地图："<<endl;
    displayMap(*map, row, col);
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            track[i][j]=0;
        }
    }
    cout<<endl;
    
    //寻找通路
    solut solut1(*track, *map);
    step* s = new step;
    s->pos = exitP;
    track[exitP.x][exitP.y] = 1;
    solut1._path.push(s->pos);
    //初始化s，从出口exitP找到入口
    
    while (!solut1.findWay(s, col, row)) {
        //若无路可走
        while (s->choice.size() == 0) {
            //返回上一岔口
            if (solut1._cross.empty()) {
                cout<<"无解！"<<endl;
                exit(0);
            } else {
                s->pos = solut1._cross.top().pos;
                s->choice = solut1._cross.top().choice;
            }
            //清除此段路径痕迹，包括path和track
            while (s->pos != solut1._path.top()) {
                track[solut1._path.top().x][solut1._path.top().y]=0;
                solut1._path.pop();
            }
            //删除这一选项
            s->choice.pop_back();
            solut1._cross.top().choice.pop_back();
            //若删除后只剩一条去路，不再是岔口
            if (s->choice.size()==1) {solut1._cross.pop();}
            //若删除后没有去路，则此路不通，继续循环返回上一岔口
        }
        //若此处为岔口
        if(s->choice.size() > 1){
            //标记岔口
            solut1._cross.push(*s);
        }
        //更新s，往下走
        s->pos = s->choice.back();
        s->choice.clear();
        //标记痕迹
        solut1._path.push(s->pos);
        track[s->pos.x][s->pos.y] = 1;
        
    }
    solut1._path.push(start);

    //输出结果
    cout<<"迷宫路径："<<endl;
    for (; ; ) {
        cout<<solut1._path.top()<<"->";
        solut1._path.pop();
        if (solut1._path.size()==1) {
            cout<<solut1._path.top()<<endl;
            solut1._path.pop();
            break;
        }
    }
    
}

void displayMap(char* map, int m, int n){
    cout<<" ";
    for (int j=0; j<n; j++) {
        cout.width(3);
        cout<<j;
    }
    cout<<endl;
    for (int i=0; i<m; i++) {
        cout<<i;
        for (int j=0; j<n; j++) {
            cout.width(3);
            cout<<map[i*n+j];
        }
        cout<<endl;
    }
}
