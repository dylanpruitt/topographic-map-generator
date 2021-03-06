#include <iostream>
#include <random>
#include <time.h>
#include "textGraphics.h"
#include "world_map.h"

world_map::world_map (int map_size)
{
    this->map_size = map_size;
}

world_map::~world_map()
{
    //dtor
}

void world_map::generate () {
    srand (time (NULL));
    create_blank_height_map ();

    int MAX_HEIGHT = 9;

    for (int i = 0; i < MAX_HEIGHT; i++) {
        update_map_at_height (i);
        smooth_map_at_height (i + 1);
    }
}

void world_map::create_blank_height_map () {
    for (int i = 0; i < map_size * map_size; i++) {
        height_map.push_back (0);
    }
}

void world_map::update_map_at_height (int height) {
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            int height_update_chance = base_chance * ((double) get_number_of_surrounding_tiles_at_height(i, j, height) / 9);
            int random = rand () % 100 + 1;
            int index = i + j * map_size;

            if (random <= height_update_chance && height_map [index] == height) {
                height_map [index] = height + 1;
            }
        }
    }
}

void world_map::smooth_map_at_height (int height) {
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            int index = i + j * map_size;
            if (height_map [index] == height - 1 && get_number_of_surrounding_tiles_at_height (i, j, height) >= 6) {
                height_map [index] = height;
            }

            if (height_map [index] == height && get_number_of_surrounding_tiles_at_height (i, j, height) < 2) {
                height_map [index] = height - 1;
            }
        }
    }
}

int world_map::get_number_of_surrounding_tiles_at_height (int x, int y, int height) {
    int number_of_tiles = 0;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if ((i + x) >= 0 && (j + y) >= 0 && (i + x) < map_size && (j + y) < map_size) {
                int index = i + x + (j + y) * map_size;
                if (height_map [index] == height) {
                    number_of_tiles++;
                }
            } else {
                number_of_tiles++;
            }
        }
    }

    return number_of_tiles;
}

void world_map::render () {
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            int index = i + j * map_size;

            if (height_map [index] < 4) {
                textGraphics::changeTextColor (textGraphics::height_colors::GRAY, textGraphics::height_colors::BLACK);
            } else if (height_map [index] < 8) {
                textGraphics::changeTextColor (textGraphics::height_colors::WHITE, textGraphics::height_colors::GRAY);
            } else {
                textGraphics::changeTextColor (textGraphics::height_colors::BRIGHT_WHITE, textGraphics::height_colors::WHITE);
            }

            std::cout << height_characters [height_map [index] % 4];
        }
        textGraphics::changeTextColor (textGraphics::height_colors::BRIGHT_WHITE, textGraphics::height_colors::BLACK);
        std::cout << "\n";
    }
}
