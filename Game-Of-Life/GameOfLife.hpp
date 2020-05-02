#include <iostream>
#include <string>
#include <array>
#include <thread>
#include <mutex>
#include <string>
#include <random>
#include <time.h>

/*THE PROGRAM GOES INTO AN INFINITE LOOP.  
    JUST CLICK CTRL+C TO STOP.
 This was intended and it's not an error*/
 
//CellStory is the map. All the cells state (alive/ dead) are stored here.

using vec2d = std::array<std::array<uint8_t, 60>, 80>;
vec2d CellStory = {0};