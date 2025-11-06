/*********************************************************************
File : World.h
Author: Brysen Landis
void init(char world[10][10]);
Set all elements in the array to ' ' and erects the walls.
void print(char world[10][10]);
Prints the 2-d array world. This includes a border of 'X' characters
and integers 0-9 marking the x-coordinates going left to right and
y-coordinates going top to bottom. Here is an example.
0123456789
XXXXXXXXXXXX
0 X X
1 X c G X
2 X P X
3 X P X
4 X XXXX X
5 X r X
6 X X X
7 X d X P X
8 X X X
9 X X X
XXXXXXXXXXXX
void set(char world[10][10], int x, int y, char c);
Sets world[x][y] to character c.
void clear(char world[10][10], int x, int y);
Sets world[x][y] to ' '.
bool is_unoccupied(char world[10][10], int x, int y);
Returns true exactly when world[x][y] is a space.
bool is_occupied(char world[10][10], int x, int y);
Returns true exactly when world[x][y] is not a space.
**********************************************************************/

#ifndef WORLD_H
#define WORLD_H

void init(char[10][10]);
void print(char[10][10]);


#endif
