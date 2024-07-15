//
// Created by WuYan on 2024/7/12.
//

#include "A_star.h"
#include "cmath"
#include "list"

using namespace std;

void A_star::set_astar(vector<vector<int>> &_map) {
    map = _map;
}
/*
 * 获取当前节点的 G 值
 * 根据两点间的距离计算移动成本，直线距离为 kCost_straight，对角线距离为kCost_diagonal
 */
double A_star::GetG(Point *temp_start, Point *point) {
    double nowG = (abs(point->x - temp_start->x) + abs(point->y - temp_start->y) == 1 ? kCost_straight : kCost_diagonal);
    double parentG = point->parent == nullptr ? 0.0 : point->parent->g;   // 初始节点的父节点为空
    return parentG + nowG;
}
/*
 * 获取当前节点的 H 值
 * 以欧几里得距离估计成本
 */
double A_star::GetH(Point *point, Point *end) {
    return sqrt((point->x - end->x) * (point->x - end->x) + (point->y - end->y) * (point->y - end->y)) * kCost_straight;
}
// 获取当前节点的 F 值（总成本）
double A_star::GetF(Point *point) {
    return point->g + point->h;
}
/*
 * 获取当前节点列表中 F 值最小的节点
 * 默认第一个节点为最小节点
 * 如果没有节点，则返回空指针
 */
Point *A_star::GetLeastFPoint() {
    if (!open_list.empty()) {
        auto it = open_list.front();
        for (auto &i : open_list) {
            if (i->f < it->f) {
                it = i;
            }
        }
        return it;
    }
    return nullptr;
}
// 获取最短路径
Point *A_star::FindPath(Point &start, Point &end, bool is_ignored_obstacle) {
    open_list.push_back(new Point(start.x, start.y));
    while (!open_list.empty()) {
        auto least_f_point = GetLeastFPoint();
        open_list.remove(least_f_point);
        close_list.push_back(least_f_point);
        auto nearest_points = GetNearestPoint(least_f_point, is_ignored_obstacle);
        for (auto &i : nearest_points) {
            if (!IsInList(open_list, i)) {
                i->parent = least_f_point;
                i->g = GetG(least_f_point, i);
                i->h = GetH(i, &end);
                i->f = GetF(i);
                open_list.push_back(i);
            } else {
                if (GetG(least_f_point, i) < i->g) {
                    i->parent = least_f_point;
                    i->g = GetG(least_f_point, i);
                    i->f = GetF(i);
                }
            }
            Point *result = IsInList(open_list, &end);
            if (result) {
                return result;
            }
        }
    }
    return nullptr;
}
// 获取最短路径
list<Point *> A_star::GetPath(Point &start, Point &end, bool is_ignored_obstacle) {
    Point *result = FindPath(start, end, is_ignored_obstacle);
    list<Point *> path;
    while (result != nullptr) {
        path.push_front(result);
        result = result->parent;
    }
    open_list.clear();
    close_list.clear();
    return path;
}
/*
 * 判断当前节点是否在列表中
 * 默认第一个节点为最小节点
 */
Point *A_star::IsInList(const list<Point *> &list, const Point *point) {
    for (auto &i : list) {
        if (i->x == point->x && i->y == point->y) {
            return i;
        }
    }
    return nullptr;
}
/*
 * 判断当前节点是否可到达
 * 1. 判断是否在边界内
 * 2. 判断是否为障碍物
 * 3. 判断是否在关闭列表中
 */
bool A_star::IsCanReach(const Point *point, const Point *target, bool is_ignored_obstacle) const {
    if (target->x < 0
    || target->x > map.size() -1
    || target->y < 0
    || target->y > map[0].size() -1
    || map[target->x][target->y] == 1
    || target->x == point->x && target->y == point->y
    || IsInList(close_list, target)) {
        return false;
    } else {
        if (abs(point->x - target->x) + abs(point->y - target->y) == 1){
            return true;    // 允许斜向移动
        } else {
            if (map[point->x][target->y] == 0 && map[target->x][point->y] == 0) {
                return true;    // 斜向移动时会被直角障碍绊住
            } else {
                return is_ignored_obstacle;
            }
        }
    }
}
// 获取当前节点的相邻节点
vector<Point *> A_star::GetNearestPoint(const Point *point, bool is_ignored_obstacle) const {
    vector<Point *> nearest_points;
    for (int x = point->x - 1; x <= point->x + 1; x++) {
        for (int y = point->y - 1; y <= point->y + 1; y++) {
            if (IsCanReach(point, new Point(x, y), is_ignored_obstacle)) {
                nearest_points.push_back(new Point(x, y));
            }
        }
    }
    return nearest_points;
}
