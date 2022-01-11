# FDF
fdf is a 3D wireframe viewer / editor program that displays a 3D representation of height map files.

# tools
  * C language  :
    - primitive functions only (write, read, malloc, free, open, close, [ if, else if, else ], [ while, break]).
  * minilibx    :
    - a micro framework that provides : window creation, coloring a pixel on a window, event management, runing loop.
  * makefile    :
    - compiles the program's source code.

# features
it comes with these features :
- allowed colors in file -> colors specified in "height map files" are allowed
- rotations                 -> all axis (x, y, z)
- translations              -> two axis (x, y)
- scaling                   -> (entire object) or (z only)
- color gradient
- fill areas
- color editing             -> colors palette (generated) | resizable brush tool | fill with color

# run
  - $> clone repo
  - $> make
  - $> ./fdf [file.fdf] -> "file.fdf" contains height values

# controls
  - rotation        -> press (left_k , right_k, up_k, down_k, 1, 0) keys to rotate (y+, y-, x+, x-, z+, z-).
  - translate       -> press (a, d, w, s) keys to move (left, right, up, down).
  - scale           -> press (z) key to switch between (scale all and scale z only) mode then (+ or scroll up, - or scroll down) to zoom (in, out).
  - color gradient  -> press (c) to activate/deactivate the "gradient rainbow colors"
  - fill areas      -> press (f) to fill/erase the empty areas 
  - color editing   -> click on brush 'the first rect' then select color form palette, choose your brush size (+ or scroll up, - or scroll down)
