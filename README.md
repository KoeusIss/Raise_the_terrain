```
-------------------------------------------------------------------------------
				Raise the Terrain
-------------------------------------------------------------------------------
```
## General
Raise the terrain is an optional project within Holberton School curriculum in
order to made the opporutnity to discover the amazing library SDL_2, it contain
two simple concept to build a 3D terrain and make it rotate by user input.
## Installation
In order to install Raise the terrain you should follow the below instructions:
1. Get the repository
You need to clone the repository and get the source code:
```
git clone https://github.com/KoeusIss/Raise_the_terrain.git
```
2. Install SDL_2 library
Download the installtion script from this link.
[Download SDL_2 Script from here](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/graphics_programming/install_SDL2.sh)
Make sure you follow this scripts:
```
cd ~/Downloads
chmod 755 install_SDL2.sh
sudo ./install_SDL2.sh
{...}
All set !
```
By seeing the all set flag the installation should be done.
3. Compiling
This tiny project using the library <math.h> make sure to put the right flags in comilation time for me i use the follow command using GCC compiler
```
gcc -pedantic -Wall -Werror -o terrain *.c `sdl2-config --cflags` `sdl2-config --libs` -lm
```
Enjoy!
## Usage:
To run this program prepare your attitudes file or try to use mine and type this command
```
./terrain file
```
Let me know if u encounter any issues
## Author
KoeusIss - Holberton School Student
