# Topographic Map Generator
This project uses a simple algorithim to generate an array of height values, which is then displayed in text format.

![Height map render](https://user-images.githubusercontent.com/8081069/71770350-92a14b80-2ef9-11ea-8378-9cdc163ddfd1.JPG)

***

# Generation Process
A max height value is given to the generator; in this project, it is set to 9.

The generator starts at height 0 and works its way up to 9, and for each height value:

The generator goes through every tile in the map (a vector of integers), and if the tile is that height value, there is a chance that the tile will be elevated.

```c++
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
```
After the map is updated, the generator looks at each tile again to smooth out the map.

```c++
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
```

This is what the process looks like for each step:

![Generation part 1](https://user-images.githubusercontent.com/8081069/71770389-02afd180-2efa-11ea-95a7-38cb12554db1.JPG)  
![Generation part 2](https://user-images.githubusercontent.com/8081069/71770391-080d1c00-2efa-11ea-8e0f-6176e041378e.JPG)  
![Generation part 3](https://user-images.githubusercontent.com/8081069/71770392-080d1c00-2efa-11ea-9369-37c21c928fb3.JPG)
