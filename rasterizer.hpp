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

std::vector<Point> rasterize_line(const Point p1, const Point p2);
std::vector<Point> rasterize_triangle(const Point p1, const Point p2, const Point p3);
template<typename T> T linear_interpolation(const Point p1, const Point p2, const Type x);
