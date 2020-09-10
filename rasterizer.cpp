#include "rasterizer.hpp"

// Returns the points of the line that goes through the points p1 and p2
// The Points are calculated using linear interpolation
std::vector<Point> rasterize_line(const Point p1, const Point p2) {

    std::vector<Point> points{p1, p2};

    Point left_point;
    Point right_point;
    if (p1.x < p2.x) {
        left_point = p1;
        right_point = p2;
    } else {
        left_point = p2;
        right_point = p1;
    }

    if (left_point.x == right_point.x) { // Horizontal line
        for(int y = std::min(p1.y, p2.y); y < std::max(p1.y, p2.y); ++y) {
            points.push_back(Point{p1.x, y});
        }
    } else {
        for (int x = left_point.x+1; x < right_point.x; ++x) {
            points.push_back(Point{x, linear_interpolation(left_point, right_point, x});
        }
    }

    return points;
}

std::vector<Point> rasterize_triangle(const Point p1, const Point p2, const Point p3) {
    std::vector<Point> points;
    
    return points;
}

// Calculates the y coordinate for the given x of the line that goes through (x1, y1) and (x2, y2)
template<typename Type> Type linear_interpolation(const Point p1, const Point p2, const Type x) {
    return p1.y + (p2.y - p1.y) * (x - p1.x) / (p2.x - p1.x);
}
