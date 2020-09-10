#include <vector>

struct Point {
    int x;
    int y;
};

struct RGB_Color {
    int red;
    int green;
    int blue;
};

struct Pixel {
    Point location;
    RGB_Color color;
};

std::vector<Point> rasterize_line(Point p1, Point p2);
std::vector<Point> rasterize_triangle(Point p1, Point p2, Point p3);
template<typename T> T linear_interpolation(Point p1, Point p2, T x);
