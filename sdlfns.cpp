#include "project.h"

//Returns pointer to image
pic load(string file)
{
	pic image = NULL;
	image = IMG_Load(file.c_str());
	if (image != NULL) image = SDL_DisplayFormatAlpha(image);
	return image;
}

//Applies surface to screen
void apply(pic from, ushrt x, ushrt y, SDL_Rect* clip, pic to)
{
	SDL_Rect coord;
	coord.x = x;
	coord.y = y;
	SDL_BlitSurface(from,clip,to,&coord);
}

//Initializes SDL and sets caption
bool init(string cap, ushrt wi, ushrt hi, ushrt bpp)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) return false;
	screen = SDL_SetVideoMode(wi,hi,bpp,SDL_SWSURFACE);
	if (screen == NULL) return false;
	SDL_WM_SetCaption( cap.c_str(), NULL );
	return true;
}

//Draws text to screen
void printFont(string text, ushrt x, ushrt y)
{
	SDL_Rect clip;
	clip.h = 27;
	clip.w = 16;
	clip.y = 0;
	ushrt length = text.length();
	for (ushrt i = 0; i < length; i++)
	{
		clip.x = 16*(int(text[i])-48);
		apply(font,x,y,&clip);
		x += 16;
	}
}

//Creates a textbox and returns the input as a string
string textbox(string text, ushrt max, ushrt x, ushrt y)
{
	SDL_Event event;
	SDL_Rect box;
	SDL_Rect cursor;
	string backup = text;
	ushrt length = text.length();
	char input;
	bool done = false;
	bool refresh = true;
	bool lshift = false;
	bool rshift = false;

	box.x = x;
	box.y = y;
	box.h = 27;
	box.w = max*16;
	cursor.x = length*16+2+x;
	cursor.y = y+1;
	cursor.h = 25;
	cursor.w = 3;
	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				input = event.key.keysym.sym > 122 ? 0 : event.key.keysym.sym;
				if (input == SDLK_RETURN) done = true;
				else if (input == SDLK_BACKSPACE && length != 0) text.erase(--length,1);
				else if (input == SDLK_ESCAPE)
				{
					done = true;
					text = backup;
				}
				else if (event.key.keysym.sym == SDLK_LSHIFT) lshift = true;
				else if (event.key.keysym.sym == SDLK_RSHIFT) rshift = true;
				else if ((int(input) >= 48 && int(input) <= 57 ||
						  int(input) >= 97 && int(input) <= 122 || int(input) == 32) &&
						  length != max)
				{
					text += char(input - (int(input) >= 97 ? lshift || rshift ? 32 : 0 : 0));
					length++;
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_LSHIFT) lshift = false;
				if (event.key.keysym.sym == SDLK_RSHIFT) rshift = false;
			}
			refresh = true;
		}
		if (refresh)
		{
			refresh = false;
			cursor.x = length*16+2+x;
			SDL_FillRect(screen,&box,0xFF000000);
			if (length != max) SDL_FillRect(screen,&cursor,0xFFFFFFFF);
			printFont(text,x,y);
			SDL_Flip(screen);
		}
		SDL_Delay(30);
	}
	return text;
}
