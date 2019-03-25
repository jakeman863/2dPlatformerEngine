#include "GameObject.h"

GameObject::GameObject(windowInstance* thisWindow)
{
	windowRef = thisWindow;
	//addRectangle(640 / 2, 480 - 50, 640, 30, false);
	//myRect = addRectangle(100, 200, 50, 50, true);
}

GameObject::GameObject(windowInstance* thisWindow, int objectType, int r, int c)
{
	windowRef = thisWindow;

	// Just air
	if (objectType == 0)
	{

	}

	// Simple Ground Block
	if (objectType == 1)
	{
		addRectangle((c*50) + 25, r*50, 50, 50, false);
	}
	
	// Whatever else we decide to add
	if (objectType == 2)
	{

	}
}

GameObject::GameObject()
{
}


void GameObject::drawLine(SDL_Surface* dest, int x0, int y0, int x1, int y1)
{
	int tmp;
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
	float y = y0;
	float roundError = (float)abs(y1 - y0) / (x1 - x0);
	int ystep = (y1 > y0 ? 1 : -1);
	for (int i = x0; i < x1; i++)
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

void GameObject::rotateTranslate(b2Vec2& vector, const b2Vec2& center, float angle)
{
	b2Vec2 tmp;
	tmp.x = vector.x*cos(angle) - vector.y*sin(angle);
	tmp.y = vector.x*sin(angle) + vector.y*cos(angle);
	vector = tmp + center;
}


b2Body* GameObject::addRectangle(int x, int y, int w, int h, bool dyn = true)
{
	b2BodyDef bodydef;
	bodydef.position.Set(x * PixelsToMeters, y * PixelsToMeters);

	if (dyn == true)
	{
		bodydef.type = b2_dynamicBody;
	}

	b2Body* body = windowRef->world->CreateBody(&bodydef);
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


void GameObject::drawSquare(b2Vec2* points, b2Vec2 center, float angle)
{
	for (int i = 0; i < 4; i++)
	{
		drawLine(windowRef->screen, points[i].x*MetersToPixels, points[i].y*MetersToPixels, points[(i + 1) > 3 ? 0 : (i + 1)].x*MetersToPixels, points[(i + 1) > 3 ? 0 : (i + 1)].y*MetersToPixels);
	}
}


void GameObject::displayIt()
{
	SDL_FillRect(windowRef->screen, NULL, 0);
	b2Body* tmp = windowRef->world->GetBodyList();
	b2Vec2 points[4];
	while (tmp)
	{
		for (int i = 0; i < 4; i++)
		{
			points[i] = ((b2PolygonShape*)tmp->GetFixtureList()->GetShape())->GetVertex(i);
			rotateTranslate(points[i], tmp->GetWorldCenter(), tmp->GetAngle());
		}
		drawSquare(points, tmp->GetWorldCenter(), tmp->GetAngle());
		tmp = tmp->GetNext();
	}
}

void GameObject::putPixel(SDL_Surface* dest, int x, int y, int r, int g, int b)
{
	if (x >= 0 && x < dest->w && y >= 0 && y < dest->h)
	{
		((Uint32*)dest->pixels)[y*dest->pitch / 4 + x] = SDL_MapRGB(dest->format, r, g, b);
	}
}

void GameObject::swapValue(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}