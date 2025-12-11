/*********************************************************************
File : Robot.h
Author: Brysen Landis
void init(Robot &, char name, int x, int y, int energylevel);
Sets the name, x, y, and energylevel to the arguments passed into the
function.
void print(const Robot & robot);
Prints the instance variables of the robot. If the name, x, y,
energylevel of robot is 'c', 10, 20, 30, then the output is
<Robot: name=c, x=10, y=20, energylevel=30>
A newline is printed at the end.
void move_north(Robot & robot);
Decrement the y value of robot and decrements the energylevel by 1.
void move_south(Robot & robot);
Increments the y value of robot and decrements the energylevel by 1.
void move_east(Robot & robot);
Increments the x value of robot and decrements the energylevel by 1.
void move_west(Robot & robot);
Decrements the x value of robot and decrements the energylevel by 1.
void inc_energylevel(Robot & robot, int d);
Increments the energylevel of robot by d.
void dec_energylevel(Robot & robot, int d);
Decrements the energylevel of robot by d.
*********************************************************************/

#ifndef ROBOT_H
#define ROBOT_H

struct Robot
{
    char name;
    int x, y;
    int energylevel;
};

void init(Robot &, char name, int x, int y, int energylevel);
void print(const Robot & robot);
void move_north(Robot & robot);
void move_south(Robot & robot);
void move_east(Robot & robot);
void move_west(Robot & robot);
void inc_energylevel(Robot & robot, int d);
void dec_energylevel(Robot & robot, int d);
std::ostream & operator<<(std::ostream &, const Robot &);

#endif
