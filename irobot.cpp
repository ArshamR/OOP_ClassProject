#include "project.h"

//Checks for admin password
bool adminLogon()
{
	SDL_Event event;
	SDL_Rect cBack;
	string password;
	short x;
	short y;
	bool done = false;
	bool refresh = true;

	cBack.x = 0;
	cBack.y = cBack.h = 24;
	cBack.w = 48;

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				x = event.button.x;
				y = event.button.y;
				//Back button
				if (x >= 0 && x <= 48 &&
					y >= 0 && y <= 24)
				{
					return false;
				}
				//Password textbox
				else if (x >= 440 && x <= 610 &&
						y >= 375 && y <= 402)
				{
					done = true;
					password = textbox(password,10,443,376);
				}
			}
		}
		if (refresh)
		{
			refresh = !refresh;
			apply(bg);
			apply(back,0,0,&cBack);
			apply(login,272,160);
			SDL_Flip(screen);
		}
		SDL_Delay(30);
	}
	SDL_FreeSurface(font);
	font = load("assets/letters.png");
	apply(login,272,160);
	printFont(password == "CS1C" ? "CORRECT" : "WRONG",443,376);
	SDL_Flip(screen);
	SDL_Delay(400);
	return password == "CS1C";
}

//Lets a customer create a robot
bool makeRobot(Robot<string> &temp)
{
	SDL_Event event;
	SDL_Rect cPaint;
	SDL_Rect cMove;
	SDL_Rect cNorton;
	SDL_Rect cBack;
	ostringstream priceStream;
	unsigned char paint = 2;
	unsigned char move = 1;
	bool norton = true;
	bool done = false;
	bool refresh = true;
	unsigned int price;
	short x;
	short y;

	cPaint.x = cPaint.y = 0;
	cPaint.h = cPaint.w = 240;
	cMove.x = 0;
	cMove.y = 240;
	cMove.h = 186;
	cMove.w = 240;
	cNorton.x = 0;
	cNorton.y = 0;
	cNorton.h = cNorton.w = 48;
	cBack.x = 0;
	cBack.y = cBack.h = 24;
	cBack.w = 48;

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				x = event.button.x;
				y = event.button.y;
				//Back button
				if (x >= 0 && x <= 48 &&
					y >= 0 && y <= 24)
				{
					return false;
				}
				//Paint button right
				else if (x >= 904 && x <= 968 &&
						y >= 64 && y <= 128 && paint < 5)
				{
					paint++;
				}
				//Paint button left
				else if (x >= 536 && x <= 600 &&
						y >= 64 && y <= 128 && paint > 0)
				{
					paint--;
				}
				//Movement button right
				else if (x >= 904 && x <= 968 &&
						y >= 304 && y <= 368 && move < 5)
				{
					move++;
				}
				//Movement button left
				else if (x >= 536 && x <= 600 &&
						y >= 304 && y <= 368 && move > 0)
				{
					move--;
				}
				//Norton tickbox
				else if (x >= 840 && x <= 888 &&
						y >= 508 && y <= 556)
				{
					norton = !norton;
				}
				//Checkout
				else if (x >= 49 && x <= 368 &&
						y >= 526 && y <= 589)
				{
					temp.setColor(paint);
					temp.setMovement(move);
					temp.setNorton(norton);
					return true;
				}
				refresh = true;
			}
		}
		if (refresh)
		{
			refresh = false;
			apply(bg);
			apply(back,0,0,&cBack);
			apply(robotBG);
			//Base price
			price = 250000;
			priceStream << price;
			printFont(priceStream.str(),90,206);
			//Paint
			cPaint.x = paint*240;
			if (paint < 5) apply(bRight,904,64);
			if (paint > 0) apply(bLeft,536,64);
			priceStream.str("");
			priceStream.clear();
			priceStream << (paint >= 1 && paint <= 3 ? 5000 : paint > 3 ? 50000 : 0);
			price += paint >= 1 && paint <= 3 ? 5000 : paint > 3 ? 50000 : 0;
			printFont(priceStream.str(),90,273);
			apply(robotIM,632,64,&cPaint);
			//Movement type
			cMove.x = move*240;
			if (move < 5) apply(bRight,904,304);
			if (move > 0) apply(bLeft,536,304);
			priceStream.str("");
			priceStream.clear();
			priceStream << (move >= 1 && move <= 3 ? 50000 : move > 3 ? 100000 : 0);
			price += move >= 1 && move <= 3 ? 50000 : move > 3 ? 100000 : 0;
			printFont(priceStream.str(),90,341);
			apply(robotIM,632,304,&cMove);
			//Norton
			cNorton.x = norton*48;
			if (norton) apply(nortonSeal,632,500);
			price += norton*10000;
			priceStream.str("");
			priceStream.clear();
			priceStream << (norton ? 10000 : 0);
			printFont(priceStream.str(),90,409);
			apply(check,840,508,&cNorton);
			//Total
			priceStream.str("");
			priceStream.clear();
			priceStream << price;
			printFont(priceStream.str(),90,477);
			priceStream.str("");
			priceStream.clear();
			SDL_Flip(screen);
		}
		SDL_Delay(30);
	}
}

//View testimonials and robots of previous customers
void viewRobots(vector<PCustomer<string>*> &robots)
{
	SDL_Event event;
	SDL_Rect cBack;
	SDL_Rect cPaint;
	SDL_Rect cMove;
	SDL_Rect infoClear;
	ostringstream price;
	short numRobots = robots.size();
	unsigned char select = 0;
	short x;
	short y;
	bool done = false;
	bool refresh = true;

	cBack.x = 0;
	cBack.y = cBack.h = 24;
	cBack.w = 48;
	cPaint.x = cPaint.y = 0;
	cPaint.h = cPaint.w = 240;
	cMove.x = 0;
	cMove.y = 240;
	cMove.h = 186;
	cMove.w = 240;
	infoClear.x = infoClear.y = 48;
	infoClear.h = infoClear.w = 544;

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				x = event.button.x;
				y = event.button.y;
				//Back button
				if (x >= 0 && x <= 48 &&
					y >= 0 && y <= 24)
				{
					return;
				}
				//Tabs for customers
				else if (x >= 648 && x <= 976)
				{
					for (unsigned char i = 0; i < numRobots; i++)
					{
						if (y >= i*40+48 && y <= i*40+88) select = i;
					}
				}
				refresh = true;
			}
		}
		if (refresh)
		{
			refresh = false;
			apply(bg);
			apply(robotBG);
			apply(back,0,0,&cBack);
			//Draw customer tabs
			for (unsigned char i = 0; i < numRobots; i++)
			{
				apply(name,648,i*40+48);
				printFont(robots[i]->getName(),654,i*40+56);
			}
			//Selected customer info
			if (numRobots != 0)
			{
				printFont(robots[select]->getName(),105,72);
				printFont(robots[select]->getTestimonial(),64+(512-robots[select]->getTestimonial().length()*16)/2,48);
				printFont(robots[select]->getRobotName(),436,392);
				if (robots[select]->getNorton()) apply(nortonSeal,436,454);
				cPaint.x = robots[select]->getColor()*240;
				apply(robotIM,127,177,&cPaint);
				cMove.x = robots[select]->getMovement()*240;
				apply(robotIM,127,417,&cMove);
				price.str("");
				price.clear();
				price << robots[select]->getPrice();
				printFont(price.str(),452,427);
			}
			SDL_Flip(screen);
		}
		SDL_Delay(30);
	}
}

//View interested customers (admin only)
void viewCustomers(vector<ICustomer<string>*> &customers)
{
	SDL_Event event;
	SDL_Rect cBack;
	SDL_Rect cCheck;
	SDL_Rect infoClear;
	short numCustomers = customers.size();
	unsigned char select = 0;
	short x;
	short y;
	bool done = false;
	bool refresh = true;

	cBack.x = 0;
	cBack.y = cBack.h = 24;
	cBack.w = 48;
	cCheck.x = cCheck.y = 0;
	cCheck.h = cCheck.w = 48;
	infoClear.x = infoClear.y = 48;
	infoClear.h = infoClear.w = 544;

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				x = event.button.x;
				y = event.button.y;
				//Back button
				if (x >= 0 && x <= 48 &&
					y >= 0 && y <= 24)
				{
					return;
				}
				//Toggle Key/Nice to have on current customer
				else if (x >= 381 && x <= 429 &&
						y >= 464 && y <= 512)
				{
					customers[select]->setValue(!customers[select]->getValue());
				}
				//Customer tabs
				else if (x >= 648 && x <= 976)
				{
					for (unsigned char i = 0; i < numCustomers; i++)
					{
						if (y >= i*40+48 && y <= i*40+88) select = i;
					}
				}
				refresh = true;
			}
		}
		if (refresh)
		{
			refresh = false;
			apply(bg);
			apply(robotBG);
			apply(back,0,0,&cBack);
			cCheck.x = customers[select]->getValue()*48;
			apply(check,381,464,&cCheck);
			//Draw customer tabs
			for (unsigned char i = 0; i < numCustomers; i++)
			{
				apply(name,648,i*40+48);
				printFont(customers[i]->getName(),654,i*40+56);
			}
			//Selected customer info
			printFont(customers[select]->getName(),60,167);
			printFont(customers[select]->getInterest() == 0 ? "Never Call Again"
					: customers[select]->getInterest() == 1 ? "Not Interested"
					: customers[select]->getInterest() == 2 ? "Somewhat Interested"
					: "Very Interested",60,233);
			printFont(customers[select]->getAddress(),60,299);
			printFont(customers[select]->getCity(),60,326);
			printFont(customers[select]->getZip(),412,326);
			SDL_Flip(screen);
		}
		SDL_Delay(30);
	}
}

//View and drag around pamphlet
void viewPam()
{
	SDL_Event event;
	SDL_Rect cBack;
	short x;
	short y;
	short xPam = 460;
	short yPam = 32;
	short xMousePam;
	short yMousePam;
	bool mouse = false;
	bool done = false;
	bool refresh = false;

	cBack.x = 0;
	cBack.y = cBack.h = 24;
	cBack.w = 48;

	SDL_FillRect(screen, NULL, 0xFF000000);
	apply(info,xPam,yPam);
	apply(back,0,0,&cBack);
	printFont("Click and drag with mouse",32,64);
	SDL_Flip(screen);

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{	
				x = event.button.x;
				y = event.button.y;
				//Back button
				if (x >= 0 && x <= 48 &&
					y >= 0 && y <= 24)
				{
					done = true;
				}
				//Start drag
				else if (x >= xPam && x <= xPam + 1278 &&
						y >= yPam && y <= yPam + 1936)
				{
					mouse = true;
					xMousePam = x - xPam;
					yMousePam = y - yPam;
				}
				refresh = true;
			}
			//Mouse button being released
			else if (event.type == SDL_MOUSEBUTTONUP)
			{
				//End drag
				mouse = false;
			}
			//Mouse being dragged around
			else if (mouse && event.type == SDL_MOUSEMOTION)
			{
				//Move pamphlet along with mouse
				xPam = event.motion.x - xMousePam;
				yPam = event.motion.y - yMousePam;
				refresh = true;
			}
		}
		if (refresh)
		{
			refresh = false;
			SDL_FillRect(screen, NULL, 0xFF000000);
			apply(info,xPam,yPam);
			apply(back,0,0,&cBack);
			SDL_Flip(screen);
		}
		SDL_Delay(17);
	}
}

//View information
bool viewInfo()
{
	SDL_Event event;
	SDL_Rect tab;
	SDL_Rect cBack;
	SDL_Rect cInfo;
	short x;
	short y;
	unsigned char tabNum;
	bool done = false;
	bool refresh = true;

	tab.x = 735;
	tab.y = 36;
	tab.h = 72;
	tab.w = 256;
	cBack.x = 0;
	cBack.y = cBack.h = 24;
	cBack.w = 48;
	cInfo.x = 0;
	cInfo.y = 200;
	cInfo.h = 512;
	cInfo.w = 639;

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				x = event.button.x;
				y = event.button.y;
				//Back button
				if (x >= 0 && x <= 48 &&
					y >= 0 && y <= 24)
				{
					done = true;
				}
				//Info tabs
				else if (x >= 739 && x <= 986 &&
						y >= 36 && y <= 487)
				{
					for (tabNum = 0; tabNum < 6; tabNum++)
					{
						if (y >= tabNum * 76 + 36 && y <= tabNum * 76 + 106)
						{
							tab.y = tabNum * 76 + 36;
							cInfo.x = tabNum % 2 == 0 ? 0 : 639;
							cInfo.y = tabNum / 2 == 0 ? 200
									: tabNum / 2 == 1 ? 712 : 1224;
							break;
						}
					}
				}
				//Print button
				else if (x >= 739 && x <= 852 &&
						y >= 521 && y <= 576)
				{
					viewPam();
				}
				//Mail button
				else if (x >= 857 && x <= 970 &&
						y >= 521 && y <= 576)
				{
					return true;
				}
				refresh = true;
			}
		}
		if (refresh)
		{
			refresh = false;
			apply(bg);
			apply(robotBG);
			apply(back,0,0,&cBack);
			apply(info,35,35,&cInfo);
			SDL_FillRect(screen,&tab,0xFF494949);
			//Slight adjustment for tab clipping
			if (tab.y == 36)
			{
				tab.y -= 4;
				SDL_FillRect(screen,&tab,0xFF494949);
				tab.y += 4;
			}
			else if (tab.y == 416)
			{
				tab.y += 4;
				SDL_FillRect(screen,&tab,0xFF494949);
				tab.y -= 4;
			}
			SDL_Flip(screen);
		}
		SDL_Delay(30);
	}
	return false;
}

//Buy robot
void checkOut(vector<PCustomer<string>*> &robots, vector<ICustomer<string>*> &customers, Robot<string> &temp)
{
	SDL_Event event;
	SDL_Rect cBack;
	PCustomer<string>* newRobot = NULL;
	short x;
	short y;
	short customer = -1;
	short i;
	bool done = false;
	bool refresh = true;
	string name;
	string robotName;
	string address;
	string city;
	string zip;
	string password;
	ostringstream price;
	
	cBack.x = 0;
	cBack.y = cBack.h = 24;
	cBack.w = 48;

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				x = event.button.x;
				y = event.button.y;
				//Back button
				if (x >= 0 && x <= 48 &&
					y >= 0 && y <= 24)
				{
					done = true;	
				}
				//Name textbox
				else if (x >= 330 && x <= 661 &&
						y >= 168 && y <= 195)
				{
					name = textbox(name,20,330,168);
					if (name != "" && int(name[0]) > 90)
					{
						name[0] = (name[0] - 32);
					}
					//Search previous customer list for name
					for (i = robots.size()-1; i >= 0; i--)
					{
						//Kick user out if name is found
						if (name == robots[i]->getName())
						{
							cBack.x = 198;
							cBack.y = 89;
							cBack.h = 465;
							cBack.w = 627;
							SDL_FillRect(screen,&cBack,0xFF494949);
							printFont("You already have one",352,308);
							SDL_Flip(screen);
							SDL_Delay(2000);
							return;	
						}
					}

					//Search customer list for name
					customer = -1;
					for (i = customers.size()-1; i >= 0; i--)
					{
						//If found, get information and prepare to delete entry
						if (name == customers[i]->getName())
						{
							customer = i;
							address = address == "" ?  customers[i]->getAddress() : address;
							city = city == "" ? customers[i]->getCity() : city;
							zip = zip == "" ? customers[i]->getZip() : zip;
						}
					}
					
				}
				//Robot Name textbox
				else if (x >= 330 && x <= 661 &&
						y >= 215 && y <= 242)
				{
					robotName = textbox(robotName,20,330,215);
				}
				//Address textbox
				else if (x >= 330 && x <= 792 &&
						y >= 262 && y <= 289)
				{
					address = textbox(address,28,330,262);
				}
				//City textbox
				else if (x >= 330 && x <= 661 &&
						y >= 309 && y <= 336)
				{
					city = textbox(city,20,330,309);
				}
				//Zipcode textbox
				else if (x >= 330 && x <= 499 &&
						y >= 356 && y <= 383)
				{
					zip = textbox(zip,10,330,356);
				}
				//Password textbox
				else if (x >= 330 && x <= 499 &&
						y >= 403 && y <= 430)
				{
					password = textbox(password,10,330,403);
				}
				//Finalize button
				else if (x >= 671 && x <= 799 &&
						y >= 450 && y <= 481)
				{
					//Make sure all fields are full
					if (name != "" && robotName != "" && address != "" &&
						city != "" && zip != "" && password != "")
					{
						//Remove customer from interested customer list and put them in previous customers list
						if (customer != -1)
						{
							delete customers[customer];
							customers.erase(customers.begin() + customer);
						}
						newRobot = new PCustomer<string>;
						newRobot->setName(name);
						newRobot->setRobotName(robotName);
						newRobot->setNorton(temp.getNorton());
						newRobot->setColor(temp.getColor());
						newRobot->setMovement(temp.getMovement());
						newRobot->setPassword(password);
						newRobot->setTestimonial("TESTIMONIAL UNAVAILABLE");
						robots.push_back(newRobot);
						sort(robots.begin(), robots.end(), MyFunctor2());
						done = true;	
					}
				}
				refresh = true;
			}
		}
		if (refresh)
		{
			refresh = false;
			apply(bg);
			apply(robotBG);
			apply(back,0,0,&cBack);
			printFont(name,330,168);
			printFont(robotName,330,215);
			printFont(address,330,262);
			printFont(city,330,309);
			printFont(zip,330,356);
			printFont(password,330,403);
			//Tell user if fields are empty
			if (x >= 671 && x <= 799 &&
				y >= 450 && y <= 481)
			{
				if (name == "") printFont("Enter Name",330,168);
				if (robotName == "") printFont("Enter Robot Name",330,215);
				if (address == "") printFont("Enter Address",330,262);
				if (city == "") printFont("Enter City",330,309);
				if (zip == "") printFont("Enter Zip",330,356);
				if (password == "") printFont("Enter Pass",330,403);
			}
			price.str("");
			price.clear();
			price << temp.getPrice();
			printFont(price.str(),348,450);
			SDL_Flip(screen);
		}
		SDL_Delay(30);
	}
}

//Input testimonial (logged on users only)
void testimonial(vector<PCustomer<string>*> &robots)
{
	SDL_Event event;
	SDL_Rect cBack;
	string name;
	string password;
	string testimonial;
	short x,y;
	short i;
	bool logged = false;
	bool found = true;
	bool done = false;
	bool refresh = true;

	cBack.x = 0;
	cBack.y = cBack.h = 24;
	cBack.w = 48;

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				x = event.button.x;
				y = event.button.y;
				//Back button
				if (x >= 0 && x <= 48 &&
					y >= 0 && y <= 24)
				{
					done = true;
				}
				//If user is not logged on
				if (!logged)
				{
					//Name textbox
					if (x >= 386 && x <= 717 &&
						y >= 326 && y <= 353)
					{
						name = textbox(name,20,386,326);
						found = false;
						//Search for name in previous customers
						for (i = robots.size() - 1; i >= 0 && !found; i--)
						{
							found = robots[i]->getName() == name;
						}
						i++;
						name = found ? name : "";
					}
					//Password textbox
					else if (x >= 440 && x <= 610 &&
							y >= 375 && y <= 402)
					{
						SDL_FreeSurface(font);
						font = load("assets/password.png");
						password = textbox(password,10,440,375);
						SDL_FreeSurface(font);
						font = load("assets/letters.png");
					}
					//Login button
					else if (x >= 445 && x <= 578 &&
							y >= 411 && y <= 447)
					{
						//If user exists and fields are not blank
						if (found && name != "" & password != "")
						{
							//Check password
							if (password == robots[i]->getPassword())
							{
								//If correct user is logged in
								logged = true;
								SDL_FreeSurface(login);
								login = load("assets/testimonial.png");
							}
							else
							{
								printFont("Wrong",616,375);
								password = "";
								SDL_Flip(screen);
								SDL_Delay(1000);
							}
						}
					}
				}
				//If user is logged in
				else
				{
					//Testimonial textbox
					if (x >= 246 && x <= 767 &&
						y >= 497 && y <= 524)
					{
						testimonial = textbox(testimonial,32,246,497);
					}
				}
				refresh = true;
			}
		}
		if (refresh)
		{
			refresh = false;
			apply(bg);
			apply(login);
			apply(back,0,0,&cBack);
			//Not logged on assets
			if (!logged)
			{
				printFont(found ? name : "Not Found",386,326);
				SDL_FreeSurface(font);
				font = load("assets/password.png");
				printFont(password,440,375);
				SDL_FreeSurface(font);
				font = load("assets/letters.png");
				if (x >= 445 && x <= 578 &&
					y >= 411 && y <= 447)
				{
					printFont(password == "" ? "Enter Pass" : password,440,375);
				}
			}
			//Logged on assets
			else
			{
				if (testimonial != "")
				{
					robots[i]->setTestimonial(testimonial);
					printFont("Thank you!",246,497);
					SDL_Flip(screen);
					SDL_Delay(1000);
					done = true;
				}
			}
			SDL_Flip(screen);
		}
		SDL_Delay(30);
	}
}

//Mail pamphlet
void mail(vector<ICustomer<string>*> &customers, vector<PCustomer<string>*> &robots)
{
	SDL_Event event;
	SDL_Rect cBack;

	ICustomer<string>* newCustomer = NULL;
	short x;
	short y;
	short i;
	bool done = false;
	bool refresh = true;
	string name;
	string address;
	string city;
	string zip;
	unsigned char interest = 3;
	
	cBack.x = 0;
	cBack.y = cBack.h = 24;
	cBack.w = 48;

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				x = event.button.x;
				y = event.button.y;
				//Back button
				if (x >= 0 && x <= 48 &&
					y >= 0 && y <= 24)
				{
					done = true;	
				}
				//Name textbox
				else if (x >= 330 && x <= 661 &&
						y >= 168 && y <= 195)
				{
					name = textbox(name,20,330,168);
					if (name != "" && int(name[0]) > 90)
					{
						name[0] = (name[0] - 32);
					}
					//Search for name in interested customers
					for (i = customers.size()-1; i >= 0; i--)
					{
						//Kick user out if found
						if (name == customers[i]->getName())
						{
							cBack.x = 198;
							cBack.y = 89;
							cBack.h = 465;
							cBack.w = 627;
							SDL_FillRect(screen,&cBack,0xFF494949);
							printFont("We sent you one already",352,308);
							SDL_Flip(screen);
							SDL_Delay(2000);
							return;
						}
					}
					//Search for name in previous customers
					for (i = robots.size()-1; i >= 0; i--)
					{
						//Kick user out if found
						if (name == robots[i]->getName())
						{
							cBack.x = 198;
							cBack.y = 89;
							cBack.h = 465;
							cBack.w = 627;
							SDL_FillRect(screen,&cBack,0xFF494949);
							printFont("You already have a robot",352,308);
							SDL_Flip(screen);
							SDL_Delay(2000);
							return;	
						}
					}
				}
				//Address textbox
				else if (x >= 330 && x <= 661 &&
						y >= 215 && y <= 242)
				{
					address = textbox(address,28,330,215);
				}
				//City textbox
				else if (x >= 330 && x <= 792 &&
						y >= 262 && y <= 289)
				{
					city = textbox(city,20,330,262);
				}
				//Zipcode textbox
				else if (x >= 330 && x <= 661 &&
						y >= 309 && y <= 336)
				{
					zip = textbox(zip,10,330,309);
				}
				//Interest left button
				else if (x >= 296 && x <= 360 &&
						y >= 396 && y <= 460 &&
						interest > 0)
				{
					interest--;
				}
				//Interest right button
				else if (x >= 664 && x <= 728 &&
						y >= 396 && y <= 460 &&
						interest < 3)
				{
					interest++;
				}
				//Finalize button
				else if (x >= 448 && x <= 576 &&
						y >= 503 && y <= 534)
				{
					//If fields are full
					if (name != "" && address != "" && city != "" &&
						zip != "")
					{
						//Add customer to interested customer list
						newCustomer = new ICustomer<string>;
						newCustomer->setName(name);
						newCustomer->setAddress(address);
						newCustomer->setCity(city);
						newCustomer->setZip(zip);
						newCustomer->setInterest(interest);
						customers.push_back(newCustomer);
						sort(customers.begin(), customers.end(), MyFunctor());
						done = true;	
					}
				}
				refresh = true;
			}
		}
		if (refresh)
		{
			refresh = false;
			apply(bg);
			apply(robotBG);
			apply(back,0,0,&cBack);
			printFont(name,330,168);
			printFont(address,330,215);
			printFont(city,330,262);
			printFont(zip,330,309);
			printFont(interest == 0 ? " Never Call Again  "
					: interest == 1 ? "  Not Interested   "
					: interest == 2 ? "Somewhat Interested"
					: "  Very Interested  ",360,396);
			if (interest > 0)
			{
				apply(bLeft,296,396);
			}
			if (interest < 3)
			{
				apply(bRight,664,396);
			}
			if (x >= 448 && x <= 576 &&
				y >= 503 && y <= 534)
			{
				if (name == "") printFont("Enter Name",330,168);
				if (address == "") printFont("Enter Address",330,215);
				if (city == "") printFont("Enter City",330,262);
				if (zip == "") printFont("Enter Zip",330,309);
			}
			SDL_Flip(screen);
		}
		SDL_Delay(30);
	}
}
