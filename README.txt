Game features code from Allegro Vivace semi-official game creation tutorial (credit to liballeg team) because pure C libraries for gamedev
are mostly abandoned and this tutorial is still up to date, save for some mistakes in code, which I fixed - also I tidied the code up so
that the files are split up -relatively- nicely.
To compile the source code you must first download the Allegro5 library (via the repo or nuget in VS). For compiling with gcc the easiest
way is to either use linux and e.g. apt or -if you are using Windows- to use msys2.
Then to actually compile run:
with gcc:
gcc main.c -o game $(pkg-config allegro-5 allegro_font-5 allegro_image-5 --libs --cflags)
with cl (on VS) just compile the project.

To play the game: press arrow keys to move, X to shoot and ESC to quit the game.