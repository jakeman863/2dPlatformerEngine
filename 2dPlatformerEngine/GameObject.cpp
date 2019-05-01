/*****************************************************
* Program File Name: GameObject.h
* Name: Zackary Groppe, Jake Manning, Lee Barton, Sean Frick
* Date of Assignment: 4/30/17
* Purpose: Create basic game objects
*
* Input: Position, size, window, ID
*
* Output: Produce a game object
***************************************************************/

#include "GameObject.h"

/************************************************************************************************************
* sets the private variables to there default values
*
* parameters: there are no parameters in this constructor
*
* return: nothing is returned in this constructor
************************************************************************************************************/
GameObject::GameObject()
{
}

/************************************************************************************************************
* sets the private variables to there default values
*
* parameters: current window, ID, x, y, w, h, and dynamic quality
*
* return: nothing is returned in this constructor
************************************************************************************************************/
GameObject::GameObject(windowInstance* thisWindow, int oID, int x, int y, int w, int h, bool dyn, int numWide, int numHigh, string fileName)
{
	//Default operations
	windowRef = thisWindow;
	//addRectangle(x, y, w, h, dyn); //640 / 2, 8500, 64000, 30, false
	objectID = oID;
	xVal = x;
	yVal = y;
	wVal = w;
	hVal = h;
	isDynamic = dyn;
	nWideVal = numWide;
	nHighVal = numHigh;
	fName = fileName;
	//myRect = addRectangle(100, 200, 50, 50, true);
}

/************************************************************************************************************
* does current operations
*
* parameters: there are no parameters
*
* return: nothing is returned
************************************************************************************************************/
void GameObject::beginningOperation()
{
		objectAnim = new AnimationComponent(fName, nWideVal, nHighVal, xVal, yVal, wVal, hVal, windowRef->renderTarget);
		myRect = addRectangle(xVal, yVal, wVal, hVal, isDynamic);
}

/************************************************************************************************************
* draws surface line
*
* parameters: current surgace, and two coordinates
*
* return: nothing is returned
************************************************************************************************************/
void GameObject::drawLine(SDL_Surface* dest, int x0, int y0, int x1, int y1)
{
	int tmp;
	bool step;
	
	//Operations used to draw the line on the current surface
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
		{
			putPixel(dest, y, i, 255, 255, 255);
		}
		else
		{
			putPixel(dest, i, y, 255, 255, 255);
		}

		error += roundError;
		if (error >= 0.5)
		{
			y += ystep;
			error -= 1;
		}
	}
}

/************************************************************************************************************
* Allows for object rotation
*
* parameters: two vectors, and float angle
*
* return: nothing is returned
************************************************************************************************************/
void GameObject::rotateTranslate(b2Vec2& vector, const b2Vec2& center, float angle)
{
	b2Vec2 tmp;

	//THe following block conducts the 
	tmp.x = vector.x*cos(angle) - vector.y*sin(angle);
	tmp.y = vector.x*sin(angle) + vector.y*cos(angle);
	vector = tmp + center;
}

/************************************************************************************************************
* Adds surface rectangle
*
* parameters: x, y, w, h positions 
*
* return: Returns Box2D object
************************************************************************************************************/
b2Body* GameObject::addRectangle(int x, int y, int w, int h, bool dyn, b2Color color, uint16 categoryBits, uint16 maskBits, bool hitbox)
{
	dyn = true;
	b2BodyDef bodydef;
	bodydef.position.Set(x * PixelsToMeters, y * PixelsToMeters);
	m_color = color;

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
	if(hitbox)
		fixturedef.isSensor = true;
	fixturedef.filter.categoryBits = categoryBits;
	fixturedef.filter.maskBits = maskBits;

	body->CreateFixture(&fixturedef);

	b2BodyDef bodydef2;
	bodydef2.position.Set(x * PixelsToMeters, y * PixelsToMeters);
	m_color = color;

	if (dyn == true)
	{
		bodydef2.type = b2_dynamicBody;
	}

	b2PolygonShape shape2;

	shape2.SetAsBox(PixelsToMeters * w / 2, PixelsToMeters * h / 2);

	b2FixtureDef fixturedef2;
	fixturedef2.shape = &shape2;
	fixturedef2.density = 1.0;
	fixturedef2.isSensor = true;
	fixturedef2.filter.categoryBits = HITBOX;
	fixturedef2.filter.maskBits = ENEMY | PLAYER ;

	body->CreateFixture(&fixturedef2);
	body->SetUserData(this);
	return body;
}


b2Body* GameObject::addRectangle(int x, int y, int w, int h, bool dyn = true)
{
	b2BodyDef bodydef;
	
	//Default bodydef position
	bodydef.position.Set(x * PixelsToMeters, y * PixelsToMeters);

	if (dyn == true)
	{
		bodydef.type = b2_dynamicBody;
	}

	//Body creation
	b2Body* body = windowRef->world->CreateBody(&bodydef);
	b2PolygonShape shape;

	//Create shape
	shape.SetAsBox(PixelsToMeters * w / 2, PixelsToMeters * h / 2);

	//Default object qualities
	b2FixtureDef fixturedef;
	fixturedef.shape = &shape;
	fixturedef.density = 1.0;

	body->CreateFixture(&fixturedef);

	SDL_Rect renderRect;
	renderRect.x = x - w / 2;
	renderRect.y = y - h / 2;
	renderRect.w = w;
	renderRect.h = h;

	//Set render stuff
	SDL_SetRenderDrawColor(windowRef->renderTarget, 255, 255, 255, 255);
	SDL_RenderFillRect(windowRef->renderTarget, &renderRect);
	SDL_RenderPresent(windowRef->renderTarget);

	return body;
}

/************************************************************************************************************
* Creates a square
*
* parameters: shape points and center, and angle
*
* return: nothing is returned in this constructor
************************************************************************************************************/
void GameObject::drawSquare(b2Vec2* points, b2Vec2 center, float angle)
{
	//For loop creating each line for the square
	for (int i = 0; i < 4; i++)
	{
		drawLine(windowRef->screen, points[i].x*MetersToPixels, points[i].y*MetersToPixels, points[(i + 1) > 3 ? 0 : (i + 1)].x*MetersToPixels, points[(i + 1) > 3 ? 0 : (i + 1)].y*MetersToPixels);
	}
}

/************************************************************************************************************
* Creates a square
*
* parameters: shape points and center, and angle
*
* return: nothing is returned in this constructor
************************************************************************************************************/
void GameObject::drawSquare2(b2Vec2* points, b2Vec2 center, float angle)
{
	//For loop creating each line for the square
	for (int i = 0; i < 4; i++)
	{
		SDL_SetRenderDrawColor(windowRef->renderTarget, 255, 0, 0, 255);
		SDL_RenderDrawLine(windowRef->renderTarget, points[i].x*MetersToPixels, points[i].y*MetersToPixels, points[(i + 1) > 3 ? 0 : (i + 1)].x*MetersToPixels, points[(i + 1) > 3 ? 0 : (i + 1)].y*MetersToPixels);
	}
}

/************************************************************************************************************
* displays the current object
*
* parameters: there are no parameters in this constructor
*
* return: nothing is returned
************************************************************************************************************/
void GameObject::displayIt()
{
	SDL_FillRect(windowRef->screen, NULL, 100);
	b2Body* tmp = windowRef->world->GetBodyList();
	b2Vec2 points[4];
	
	//Loop going through and filling the current object
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


/************************************************************************************************************
* sets the private variables to there default values
*
* parameters: there are no parameters
*
* return: nothing is returned
************************************************************************************************************/
void GameObject::displayIt2()
{
	SDL_RenderDrawRect(windowRef->renderTarget, NULL);
	b2Body* tmp = windowRef->world->GetBodyList();
	b2Vec2 points[4];
	
	//Loop to display the object
	while (tmp)
	{
		for (int i = 0; i < 4; i++)
		{
			points[i] = ((b2PolygonShape*)tmp->GetFixtureList()->GetShape())->GetVertex(i);
			rotateTranslate(points[i], tmp->GetWorldCenter(), tmp->GetAngle());
		}
		drawSquare2(points, tmp->GetWorldCenter(), tmp->GetAngle());
		tmp = tmp->GetNext();
	}
}

/************************************************************************************************************
* Puts pixels in certain positions
*
* parameters: current surface, x, y, r, g, and b values
*
* return: nothing is returned
************************************************************************************************************/
void GameObject::putPixel(SDL_Surface* dest, int x, int y, int r, int g, int b)
{
	if (x >= 0 && x < dest->w && y >= 0 && y < dest->h)
	{
		((Uint32*)dest->pixels)[y*dest->pitch / 4 + x] = SDL_MapRGB(dest->format, r, g, b);
	}
}

/************************************************************************************************************
* Swaps values
*
* parameters: values to be swapped
*
* return: nothing is returned
************************************************************************************************************/
void GameObject::swapValue(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/************************************************************************************************************
* Updates player animation
*
* parameters: current player position
*
* return: nothing is returned
************************************************************************************************************/
void GameObject::updateAnimation(b2Vec2 currentPlayerPosition)
{
	objectAnim->increaseFrameTime();
	objectAnim->checkFrameTime(currentPlayerPosition, wVal, hVal);
}