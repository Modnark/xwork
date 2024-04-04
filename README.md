# XWORK
Made this on my own time as a hobby project. It's a fairly basic low-level game framework which makes use of SDL2. It is incomplete, only works for Linux (windows port soon) and at this point considered Alpha software. I wouldn't recommend using it in its current state. Feel free to make suggestions and / or contributions.

# Compiling
**Compiling for Linux**

Compiling on linux is fairly straightforward, you will need the following libraries installed: SDL2, SDL2_image, SDL2_ttf, SDL2_mixer. All of which can likely be found in your distrobution's package repositories.

```bash
mkdir build
cd build
cmake ..
make
```
# Using in a project
(UPDATE: 4/4/24) The breakout example will not work with the current API any longer and needs to be updated.

Using this in a project is just as simple as any other library, all you need to do is include all of the .h header files, and libxwork.a, for an example check out my [Breakout Game](https://github.com/Modnark/x-work_breakout).

# TODO
* Finish GUI elements
  * Proper Button scaling
  * GUI frame objects
  * Text input (maybe if I'm not lazy)
* Tie up loose ends, (eg. half-baked error handling, implement values / functions that serve no purpose)
* Camera / Scrolling
* Improve collision detection (can get wacky and imprecise at lower framerates)
* Layering system for rendering order
