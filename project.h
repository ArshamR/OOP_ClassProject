#ifndef IROBOTSTHEBOMB
#define IROBOTSTHEBOMB
#include "H:\project\gcc\sdl\include\SDL.h"
#include "H:\project\gcc\img\include\SDL_image.h"

#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Classes.h"
using namespace std;

typedef unsigned short ushrt;
typedef SDL_Surface* pic;

extern pic screen;
extern pic bg;
extern pic buttons;
extern pic font;
extern pic login;
extern pic admin;
extern pic robotIM;
extern pic bLeft;
extern pic bRight;
extern pic nortonSeal;
extern pic check;
extern pic robotBG;
extern pic back;
extern pic name;
extern pic info;

//Returns pointer to image
pic load(string file);

//Applies surface to screen
void apply(pic from, ushrt x = 0, ushrt y = 0, SDL_Rect* clip = NULL, pic to = screen);

//Initializes SDL and sets caption
bool init(string cap, ushrt wi, ushrt hi, ushrt bpp);

//Draws text to screen
void printFont(string text, ushrt x=0, ushrt y=0);

//Creates a textbox and returns the input as a string
string textbox(string text, ushrt max=0, ushrt x=0, ushrt y=0);

//Checks for admin password
bool adminLogon();

//Lets a customer create a robot
bool makeRobot(Robot<string> &temp);

//View testimonials and robots of previous customers
void viewRobots(vector<PCustomer<string>*> &robots);

//View interested customers (admin only)
void viewCustomers(vector<ICustomer<string>*> &customers);

//View and drag around pamphlet
void viewPam();

//View information
bool viewInfo();

//Buy robot
void checkOut(vector<PCustomer<string>*> &robots, vector<ICustomer<string>*> &customers, Robot<string> &temp);

//Input testimonial (logged on users only)
void testimonial(vector<PCustomer<string>*> &robots);

//Mail pamphlet
void mail(vector<ICustomer<string>*> &customers, vector<PCustomer<string>*> &robots);

//opens and reads interested customer file into vector
void openFile(vector<ICustomer<string>*>& customers);

//opens and reads paying customer file into vector
void openFilePC(vector<PCustomer<string>*>& robots);

//Used in the sort function, passed as a comparing parameter to sort interested customers by name
struct MyFunctor
{
    bool operator()(ICustomer<string>* lhs,ICustomer<string>* rhs)const
    {
        return lhs->getName() < rhs->getName();
    }
};

//Used in the sort function, passed as a comparing parameter to sort paying customers by name
struct MyFunctor2
{
    bool operator()(PCustomer<string>* lhs,PCustomer<string>* rhs)const
    {
        return lhs->getName() < rhs->getName();
    }
};
//Opens interested customer file and writes to it
void writeToFileIC(vector<ICustomer<string>*> customers);

//Opens paying customer file and writes to it
void writeToFilePC(vector<PCustomer<string>*> robots);

#endif
