#include "project.h"

pic screen = NULL;
pic bg = NULL;
pic buttons = NULL;
pic font = NULL;
pic login = NULL;
pic admin = NULL;
pic robotIM = NULL;
pic bLeft = NULL;
pic bRight = NULL;
pic nortonSeal = NULL;
pic check = NULL;
pic robotBG = NULL;
pic back = NULL;
pic name = NULL;
pic info = NULL;

int main(int argc, char* args[])
{
	if (!init("iRobotstheBomb",1024,640,32)) return 1;
	SDL_Event event;
	SDL_Rect cBack;

	Robot<string> temp;

	vector<ICustomer<string>*> customers;
	
	bg = load("assets/background.png");
	apply(bg);

	openFile(customers);

	//Sorts the customer vector by customer name
	sort(customers.begin(), customers.end(), MyFunctor());

	vector<PCustomer<string>*> robots;

	openFilePC(robots);

	//Sorts the robots vector by customer name
	sort(robots.begin(), robots.end(), MyFunctor2());


	bool quit = false;
	bool refresh = true;
	short xMouse;
	short yMouse;

	//Load assets
	//bg = load("assets/background.png");
	buttons = load("assets/buttons.png");
	font = load("assets/letters.png");
	admin = load("assets/admin.png");
	robotIM= load("assets/robot.png");
	bRight = load("assets/rightbutton.png");
	bLeft = load("assets/leftbutton.png");
	nortonSeal = load("assets/norton.png");
	check = load("assets/check.png");
	back = load("assets/back.png");
	name = load("assets/name.png");
	
	//Set up clipping mask for quit button
	cBack.x = cBack.y = 0;
	cBack.h = 24;
	cBack.w = 48;

	//Input loop
	while (!quit)
	{
		//Handle input
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				xMouse = event.button.x;
				yMouse = event.button.y;
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					//Quit button
					if (xMouse >= 0 && xMouse <= 48 &&
						yMouse >= 0 && yMouse <= 24)
					{
						quit = true;
					}
					//Admin button
					else if (xMouse >= 48 && xMouse <= 96 &&
						yMouse >= 0 && yMouse <= 24)
					{
						login = load("assets/adminLogin.png");
						SDL_FreeSurface(font);
						font = load("assets/password.png");
						if (adminLogon())
						{
							SDL_FreeSurface(robotBG);
							robotBG = load("assets/adminBG.png");
							viewCustomers(customers);
						}
						SDL_FreeSurface(login);
						SDL_FreeSurface(font);
						font = load("assets/letters.png");
					}
					//Create/Buy robot
					else if (xMouse >= 48 && xMouse <= 495 &&
						yMouse >= 356 && yMouse <= 438)
					{
						SDL_FreeSurface(robotBG);
						robotBG = load("assets/robotBG.png");
						if (makeRobot(temp) != 0)
						{
							SDL_FreeSurface(robotBG);
							robotBG = load("assets/order.png");
							checkOut(robots,customers,temp);
						}
					}
					//View testimonials
					else if (xMouse >= 528 && xMouse <= 975 &&
						yMouse >= 356 && yMouse <= 438)
					{
						SDL_FreeSurface(robotBG);
						robotBG = load("assets/testimBG.png");
						viewRobots(robots);
					}
					//View info/Mail pamphlet
					else if (xMouse >= 48 && xMouse <= 495 &&
						yMouse >= 471 && yMouse <= 553)
					{
						SDL_FreeSurface(robotBG);
						robotBG = load("assets/infoBG.png");
						info = load("assets/info.png");
						if (viewInfo())
						{
							SDL_FreeSurface(robotBG);
							robotBG = load("assets/mail.png");
							mail(customers,robots);
						}
						SDL_FreeSurface(info);
					}
					//Returning Customers
					else if (xMouse >= 528 && xMouse <= 975 &&
						yMouse >= 471 && yMouse <= 553)
					{
						login = load("assets/login.png");
						testimonial(robots);
						SDL_FreeSurface(login);
					}
				}
				refresh = true;
			}
			else if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		//Redraw screen if something changes
		if (refresh)
		{
			refresh = false;
			apply(bg);
			apply(buttons);
			apply(back,0,0,&cBack);
			cBack.y = 48;
			apply(back,48,0,&cBack);
			cBack.y = 0;
			SDL_Flip(screen);
		}
		SDL_Delay(30);
	}
	writeToFileIC(customers);
	writeToFilePC(robots);
	//Free memory
	for (xMouse = robots.size()-1; xMouse >= 0; xMouse--)
	{
		delete robots[xMouse];
	}

	for (xMouse = customers.size()-1; xMouse >= 0; xMouse--)
	{
		delete customers[xMouse];
	}

	SDL_FreeSurface(bg);
	SDL_FreeSurface(buttons);
	SDL_FreeSurface(font);
	SDL_FreeSurface(admin);
	SDL_FreeSurface(robotIM);
	SDL_FreeSurface(bLeft);
	SDL_FreeSurface(bRight);
	SDL_FreeSurface(nortonSeal);
	SDL_FreeSurface(check);
	SDL_FreeSurface(robotBG);
	SDL_FreeSurface(back);
	SDL_FreeSurface(name);
	SDL_Quit();

	return 0;
}

template <class Type>
Type OutputName (Client<Type>& name)
{
	return name.Output();
}

