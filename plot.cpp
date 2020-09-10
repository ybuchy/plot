#include <SDL2/SDL.h>
#include <vector>
#include "rasterizer.hpp"
#include <cstdio>

// To plot graphics like functions or shapes (triangles)
// Want function that returns vector of points (triangle interpolation)
// Want function that colors vector of points (giving color) returning vector of pixels

int WINDOW_W = 640;
int WINDOW_H = 480;

int main() {
    // Init SDL
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_W, WINDOW_H, 0, &window, &renderer);
    SDL_RenderClear(renderer);

    for (int y = 0; y < WINDOW_H; y++) {
        for (int x = 0; x < WINDOW_W; x++) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Test for: rasterize_line function
    std::vector<Point> test_points = rasterize_line(Point{3, 15}, Point{3, 123});

    for (Point point : test_points) {
        int x = point.x;
        int y = point.y;
        SDL_RenderDrawPoint(renderer, x, y);
    }

    test_points = rasterize_line(Point{3, 15}, Point{123, 15});

    for (Point point : test_points) {
        int x = point.x;
        int y = point.y;
        SDL_RenderDrawPoint(renderer, x, y);
    }

    test_points = rasterize_line(Point{100, 100}, Point{200, 250});

    for (Point point : test_points) {
        int x = point.x;
        int y = point.y;
        SDL_RenderDrawPoint(renderer, x, y);
    }

    // Test for: rasterize_triangle function
    test_points = rasterize_triangle(Point{523, 234}, Point{123, 100}, Point{350, 400});

    for (Point point : test_points) {
        int x = point.x;
        int y = point.y;
        SDL_RenderDrawPoint(renderer, x, y);
    }

    SDL_RenderPresent(renderer);

    SDL_Delay(2000);

    // Quit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
