#include <SDL2/SDL.h>
#include <vector>
#include "rasterizer.hpp"
#include <algorithm>

// To plot graphics like functions or shapes (triangles)
// Want function that returns vector of points (triangle interpolation)
// Want function that colors vector of points (giving color) returning vector of pixels

const int WINDOW_W = 640;
const int WINDOW_H = 480;

int main() {
    // Init SDL
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_W, WINDOW_H, 0, &window, &renderer);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Test for: rasterize_line function
    auto add_point = [&](const Point &point){SDL_RenderDrawPoint(renderer, point.x, point.y);};
    auto add_line = [&](const std::pair<Point, Point> &line_points){
			std::vector<Point> test_points = rasterize_line(line_points.first, line_points.second);
			std::for_each(test_points.begin(), test_points.end(), add_point);
		    };
    add_line(std::make_pair(Point{3, 15}, Point{3, 123}));
    add_line(std::make_pair(Point{14, 112}, Point{12, 159}));
    add_line(std::make_pair(Point{95, 153}, Point{52, 211}));

    SDL_RenderPresent(renderer);

    SDL_Delay(2000);

    // Quit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
