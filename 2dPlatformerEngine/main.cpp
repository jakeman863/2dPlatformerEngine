#include <iostream>
#include <SDL.h>

const int WIDTH = 640;
const int HEIGHT = 480;
const float MetersToPixels = 20;
const float PixelsToMeters = 1 / MetersToPixels;
b2World* world;
SDL_Surface* screen;
SDL_Window* window;
b2Body* myRect;

void putPixel(SDL_Surface* dest, int x, int y, int r, int g, int b)
{
	if (x >= 0 && x < dest->w && y >= 0 && y < dest->h)
	{
		((Uint32*)dest->pixels)[y*dest->pitch / 4 + x] = SDL_MapRGB(dest->format, r, g, b);
	}
}

void swapValue(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void drawLine(SDL_Surface* dest, int x0, int y0, int x1, int y1)
{
	//int tmp;
	bool step;

	step = abs(y1 - y0) > abs(x1 - x0);
	if (step)
	{
		swapValue(x0, y0);
		swapValue(x1, y1);
	}

	if (x0 > x1)
	{
		swapValue(x1, x0);
		swapValue(y1, y0);
	}
	float error = 0.0;
	int y = y0;
	float roundError = (float)abs(y1 - y0) / (x1 - x0);
	int ystep = (y1 > y0 ? 1 : -1);
	for (int i = x0;i < x1;i++)
	{

		if (step)
			putPixel(dest, y, i, 255, 255, 255);
		else
			putPixel(dest, i, y, 255, 255, 255);

		error += roundError;
		if (error >= 0.5)
		{
			y += ystep;
			error -= 1;
		}
	}
}

void rotateTranslate(b2Vec2& vector, const b2Vec2& center, float angle)
{
	b2Vec2 tmp;
	tmp.x = vector.x*cos(angle) - vector.y*sin(angle);
	tmp.y = vector.x*sin(angle) + vector.y*cos(angle);
	vector = tmp + center;
}


b2Body* addRectangle(int x, int y, int w, int h, bool dyn = true)
{
	b2BodyDef bodydef;
	bodydef.position.Set(x * PixelsToMeters, y * PixelsToMeters);

	if (dyn == true)
	{
		bodydef.type = b2_dynamicBody;
	}

	b2Body* body = world->CreateBody(&bodydef);
	b2PolygonShape shape;

	shape.SetAsBox(PixelsToMeters * w / 2, PixelsToMeters * h / 2);
	
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 1.0;
	
	//fixturedef.friction = 0.9;
	//fixturedef.restitution = .8;
	
	body->CreateFixture(&fixturedef);
	
	return body;
}


void drawSquare(b2Vec2* points, b2Vec2 center, float angle)
{
	for (int i = 0;i < 4;i++)
	{
		drawLine(screen, points[i].x*MetersToPixels, points[i].y*MetersToPixels, points[(i + 1) > 3 ? 0 : (i + 1)].x*MetersToPixels, points[(i + 1) > 3 ? 0 : (i + 1)].y*MetersToPixels);
	}
}

void init()
{
	world = new b2World(b2Vec2(0.0f,9.81f));
	addRectangle(WIDTH / 2, HEIGHT - 50, WIDTH, 30, false);
	myRect = addRectangle(100, 200, 50, 50, true);
}

void display()
{
	SDL_FillRect(screen, NULL, 0);
	b2Body* tmp = world->GetBodyList();
	b2Vec2 points[4];
	while (tmp)
	{
		for (int i = 0;i < 4;i++)
		{
			points[i] = ((b2PolygonShape*)tmp->GetFixtureList()->GetShape())->GetVertex(i);
			rotateTranslate(points[i], tmp->GetWorldCenter(), tmp->GetAngle());
		}
		drawSquare(points, tmp->GetWorldCenter(), tmp->GetAngle());
		tmp = tmp->GetNext();
	}
}

// Only a test function
void changeRenderer(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, rand() % 255, rand() % 255, rand() % 255, 255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{
<<<<<<< HEAD
	
=======

>>>>>>> parent of 222762a... Box2D
	SDL_Init(SDL_INIT_EVERYTHING);

	// Flags to change window properties (Adding more flags requires | between each flag)
	Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;

	// Creates a window (640 x 480) with the title "Game Window"
	SDL_Window *window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, flags);
	// Simple rendering for testing
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	bool quit = false;

	// Main Loop
	while (!quit)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) > 0)
		{
			switch (e.type)
			{
				case SDL_QUIT:
					quit = true;
					break;
				default:
					changeRenderer(renderer);
					break;
			}
			SDL_UpdateWindowSurface(window);
		}

		// Take Input Here

		// Update

		// Draw

		// Renderer Test function
		changeRenderer(renderer);
	}
	
	
	/*
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
	Uint32 start;
	SDL_Event event;
	screen = SDL_GetWindowSurface(window);
	bool running = true;
	init();
	while(running)
	{
			start=SDL_GetTicks();
			while(SDL_PollEvent(&event))
			{
					switch(event.type)
					{
							case SDL_QUIT:
									running=false;
									break;
							case SDL_KEYDOWN:
									switch(event.key.keysym.sym)
									{
											case SDLK_ESCAPE:
													running=false;
													break;
									}
									break;
							case SDL_MOUSEBUTTONDOWN:
									addRectangle(event.button.x,event.button.y,20,20,true);
									break;

					}
			}
			display();
			world->Step(1.0/30.0,8,3);      //update
			SDL_UpdateWindowSurface(window);
			if (1000.0 / 30 > SDL_GetTicks() - start)
			{
				SDL_Delay(1000.0 / 30 - (SDL_GetTicks() - start));
			}
	}

	SDL_Quit();
	*/

	return 0;
}