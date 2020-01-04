#include <iostream>
#include "world_map.h"

int main()
{
    const int MAP_SIZE = 36;
    world_map new_world_map = world_map (MAP_SIZE);
    new_world_map.generate ();
    new_world_map.render ();
    return 0;
}
