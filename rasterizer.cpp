#include "rasterizer.hpp"

std::vector<Point> rasterize_line(Point p1, Point p2) {

    std::vector<Point> points;

    points.push_back(p1);
    points.push_back(p2);

    Point left_point;
    Point right_point;
    if (p1.x < p2.x) {
        left_point = p1;
        right_point = p2;
    } else {
        left_point = p2;
        right_point = p1;
    }

    if (p1.x == p2.x) { // Horizontal line
        for(int y = std::min(p1.y, p2.y); y < std::max(p1.y, p2.y); y++) {
            points.push_back(Point{p1.x, y});
        }
    } else {
        for (int x = left_point.x+1; x < right_point.x; x++) {
            int y = linear_interpolation(left_point, right_point, x);
            points.push_back(Point{x, y});
        }
    }

    return points;
}

std::vector<Point> rasterize_triangle(Point p1, Point p2, Point p3) {
    std::vector<Point> points;
    
    return points;
}

// Calculates the y coordinate for the given x of the line that goes through (x1, y1) and (x2, y2)
template<typename T> T linear_interpolation(Point p1, Point p2, T x) {
    int x1 = p1.x, x2 = p2.x;
    int y1 = p1.y, y2 = p2.y;
    return y1 + (y2 - y1) * (x - x1) / (x2 - x1);
}
