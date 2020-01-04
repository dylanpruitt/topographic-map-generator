#ifndef WORLD_MAP_H
#define WORLD_MAP_H
#include <vector>

class world_map
{
    public:
        world_map (int map_size);
        virtual ~world_map();

        void generate ();

        void render ();
    private:
        int map_size = 30;

        std::vector <int> height_map;
};

#endif // WORLD_MAP_H
