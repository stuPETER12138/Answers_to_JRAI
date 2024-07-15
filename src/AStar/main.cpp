//
// Created by WuYan on 2024/7/12.
//

#include "iostream"
#include "A_star.h"

using namespace std;

bool InPath(const int &x, const int &y, const list<Point *> &path) {
    for (auto &p : path) {
        if (p->x == x && p->y == y) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> map = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0},
            {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    A_star a_star;
    a_star.set_astar(map);
    Point start(0, 0);
    Point end(16, 14);
    auto path = a_star.GetPath(start, end, false);
    for (int x = 0; x < map.vector::size(); ++x) {
        for (int y = 0; y < map[0].vector::size(); ++y) {
            if (InPath(x, y, path)) {
                if (map[x][y] != 0) {
                    cout << "e";
                } else {
                    cout << "*" << " ";
                }
            } else {
                cout << map[x][y] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
