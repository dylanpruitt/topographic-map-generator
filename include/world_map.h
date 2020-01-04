#ifndef WORLD_MAP_H
#define WORLD_MAP_H
#include <vector>

class world_map
{
    public:
        world_map (int map_size);
        virtual ~world_map ();

        void generate ();

        void render ();
    private:
        int map_size = 25;

        int base_chance = 95;

        char height_characters [4] = {' ', char (176), char (177), char (178)};

        std::vector <int> height_map;

        void create_blank_height_map ();

        void update_map_at_height (int height);

        void smooth_map_at_height (int height);

        int get_number_of_surrounding_tiles_at_height (int x, int y, int height);
};

#endif // WORLD_MAP_H
