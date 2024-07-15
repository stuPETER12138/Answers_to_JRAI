//
// Created by WuYan on 2024/7/12.
//

#ifndef ASTAR_A_STAR_H
#define ASTAR_A_STAR_H

#include "list"
#include "vector"

using namespace std;

const double kCost_straight = 10;
const double kCost_diagonal = 14.14;

struct Point {
    int x, y;
    double f, g, h;
    Point *parent;   // 父节点， 用于回溯
    Point(int x, int y) {
        this->x = x;
        this->y = y;
        this->f = 0;
        this->g = 0;
        this->h = 0;
        this->parent = nullptr;
    }
};

class A_star {
public:
    void set_astar(vector<vector<int>> &_map);
    list<Point *> GetPath(Point &start, Point &end, bool is_ignored_obstacle);
private:
    Point *FindPath(Point &start, Point &end, bool is_ignored_obstacle);
    vector<Point *> GetNearestPoint(const Point *point, bool is_ignored_obstacle) const;    // 获取与定点相邻的可通行点
    bool IsCanReach(const Point *point, const Point *target, bool is_ignored_obstacle) const;    // 是否可以用于下一步判断
    static Point *IsInList(const list<Point *> &list, const Point *point) ;
    struct Point *GetLeastFPoint();
    // 获取 G, H, F
    static double GetG(Point *temp_start, Point *point);
    static double GetH(Point *point, Point *end);
    static double GetF(Point *point);
    vector<vector<int>> map;
    list<Point *> open_list;
    list<Point *> close_list;
};

#endif //ASTAR_A_STAR_H
