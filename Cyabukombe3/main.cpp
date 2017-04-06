/************************************************************************
***Name		 : Israel Cyabukombe
***Class	 : CSc 450
***ASSIGNMENT: 3
***DUE DATE	 : 10.3.2016
***INSTRUCTOR: KEN GAMRADT
************************************************************************
***DESCRIPTION:  This Assignment will create a game of a submarine/Spaceship
***************	 shooting at incoming comets/fish and it will display a blue 
***************  background and will use different fonts to show the number
***************  lives left and the number of comets destroyed at the end of
***************	 of the Game

###Directions: Use the "SPACE" Key to shoot 
			   Use the "ESC" Key to exit
			   Use the "ARROW" Keys to move the submarine
*************************************************************************/
#include "Globals.h"
#include "Bullet.h"
#include "Comet.h"
#include "GameObject.h"
#include "SpaceShip.h"

SpaceShip *ship = NULL;
std::list<GameObject*>objects;
std::list<GameObject*>::iterator iter1;
std::list<GameObject*>::iterator iter2;

//prototypes
void __cdecl takeLife();
void __cdecl scorePoint();
void changeState(State&currentState, const State newState);
int main(const int argc, const char * argv[]) {
	//==============================================
	//  SHELL VARIABLES
	//==============================================
	bool  done = false;
	bool  render = false;

	float gameTime = 0;
	int   frames = 0;
	int   gameFPS = 0;
	//  Match to KEYS
	bool keys[] = { false, false, false, false, false, false };

	//==============================================
	//  PROJECT VARIABLES
	//==============================================
	State gameState = INIT;
	ship = new SpaceShip;
	//==============================================
	//  ALLEGRO VARIABLES
	//==============================================
	ALLEGRO_DISPLAY     *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER       *timer = NULL;
	ALLEGRO_FONT        *font18 = NULL;
	ALLEGRO_FONT		*font16 = NULL; 
	ALLEGRO_FONT		*font20 = NULL;

	//==============================================
	//  ALLEGRO INIT FUNCTIONS
	//==============================================
	//  initialize Allegro
	if (!al_init()) {
		return -1;
	}
	//  create the display
	display = al_create_display(WIDTH, HEIGHT);
	//  verify the display object
	if (!display) {
		return -1;
	}

	//==============================================
	//  ADDON INSTALL
	//==============================================
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	//==============================================
	//  PROJECT INIT
	//==============================================
	font18 = al_load_font("Titillium-Bold.otf", 18, 0);
	font16 = al_load_font("Titillium-Black.otf", 18, 0);
	font20 = al_load_font("SHREK.ttf", 18, 0);
	ship->init();
	objects.push_back(ship);
	changeState(gameState, TITLE);
	srand(time(NULL));
	//==============================================
	//  TIMER INIT AND STARTUP
	//==============================================
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);
	gameTime = al_current_time();
	while (!done) {
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		//==============================================
		//  INPUT
		//==============================================
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				if (gameState == TITLE) {
					changeState(gameState, PLAYING);
				}
				else if (gameState == PLAYING) {
					Bullet *bullet = new Bullet(ship->getX() + BULLET_PLACEMENT, ship->getY(), &scorePoint);
					objects.push_back(bullet);
				}
				else if (gameState == OVER) {
					changeState(gameState, PLAYING);
				}
				break;
			}
		}
		else if (event.type == ALLEGRO_EVENT_KEY_UP) {
			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			}
		}
		//==============================================
		//  GAME UPDATE
		//==============================================
		else if (event.type == ALLEGRO_EVENT_TIMER) {
			render = true;
			if (gameState == PLAYING) {
				if (keys[UP])
				{
					ship->moveUp();
				}
				else if (keys[DOWN])
				{
					ship->moveDown();
				}
				else if (keys[LEFT])
				{
					ship->moveLeft();
				}
				else if (keys[RIGHT])
				{
					ship->moveRight();
				}

				//Handle comet creation
				if (rand() % COMET_CHANCE == 0) {

					Comet* comet = new Comet(WIDTH, COMET_RADIUS1 + rand() % (HEIGHT - (2 * COMET_RADIUS2)), &takeLife);
					objects.push_back(comet);
				}
				//handle object updates
				for (iter1 = objects.begin();iter1 != objects.end(); ++iter1) {
					(*iter1)->update();

				}
				//handle object collisions
    				for (iter1 = objects.begin(); iter1 != objects.end(); ++iter1) {
					if ((*iter1)->isCollidable()) {
						for (iter2 = iter1; iter2 != objects.end(); ++iter2) {
							if ((((*iter2)->isCollidable())) && ((*iter1)->getId() != (*iter2)->getId())) {
								if ((*iter1)->checkCollision((*iter2))) {
									(*iter1)->collided((*iter2)->getId());
									(*iter2)->collided((*iter1)->getId());
									int x1 = (*iter1)->getX();
									int y1 = (*iter1)->getY();
									int x2 = (*iter2)->getX();
									int y2 = (*iter2)->getY();
									al_draw_filled_circle(((x1 + x2)/2) , (y1 + y2)/2  , EXPLOSION_RADIUS, YELLOW);
								}
							}
						}
					}
				}
				// check for game over condition
				if (ship->getLives() <= 0) {
					changeState(gameState, OVER);
				}
			}
		//remove inactive objects
		for (iter1 = objects.begin(); iter1 != objects.end();) {
			if (!(*iter1)->getAlive()) {
				delete(*iter1);
				iter1 = objects.erase(iter1);
			}
			else {
				++iter1;
			}
			}
			//  UPDATE FPS =========================
			frames++;
			if (al_current_time() - gameTime >= 1) {
				gameTime = al_current_time();
				gameFPS = frames;
				frames = 0;
			}
			//======================================
		}

		//==============================================
		//  RENDER
		//==============================================
		if (render && al_is_event_queue_empty(event_queue)) {
			render = false;
			//  display FPS on screen
			al_draw_textf(font18, MAGENTA, 5, 5, 0, "FPS: %d", gameFPS);

			//  BEGIN PROJECT RENDER ===============
			//handle game state output
			if (gameState == TITLE) {
				al_draw_text(font20, BLACK, WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "WELCOME TO GAME 2!");
				al_draw_text(font20, BLACK, WIDTH / 2, HEIGHT - 25, ALLEGRO_ALIGN_CENTER, "Press SPACE to Play");
			}
			else if (gameState == PLAYING) {
				al_draw_textf(font16, BLACK, WIDTH / 2, 5, ALLEGRO_ALIGN_CENTER, "Player has %d lives left. Player has destroyed %d  objects", ship->getLives(), ship->getScore());
				for (iter1 = objects.begin(); iter1 != objects.end(); ++iter1) {
					(*iter1)->render();
				}
			}
			else if (gameState == OVER) {
				al_draw_text(font20, BLACK, WIDTH / 2, 5, ALLEGRO_ALIGN_CENTER, "Game Over");
				al_draw_textf(font20, BLACK, WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "Player has destroyed %d objects", ship->getScore());
				al_draw_text(font20, BLACK, WIDTH / 2, HEIGHT - 25, ALLEGRO_ALIGN_CENTRE, "Press SPACE to Play Again ::::: Press ESCAPE to Exit");
			}

			//  FLIP BUFFERS =======================
			al_flip_display();
			al_clear_to_color(CADETBLUE);
		}

	}     //end while

	//==============================================
	//  DESTROY PROJECT OBJECTS
	//==============================================
	for (iter1 = objects.begin(); iter1 != objects.end();) {
		(*iter1)->destroy();
		delete(*iter1);
		iter1 = objects.erase(iter1);
	}
	// SHELL OBJECTS ===============================
	al_destroy_font(font18);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);

	return 0;
}
/********************************************************************
*** FUNCTION :
*********************************************************************
*** DESCRIPTION :
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void __cdecl takeLife()
{
	ship->setLives(ship->getLives() - 1);
}
/********************************************************************
*** FUNCTION :
*********************************************************************
*** DESCRIPTION :
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void __cdecl scorePoint() {
	ship->setScore(ship->getScore() + 1);
}
/********************************************************************
*** FUNCTION :
*********************************************************************
*** DESCRIPTION :
*** OUTPUT ARGS :
*** IN/OUT ARGS :
*** RETURN : nothing
********************************************************************/
void changeState(State & currentState, const State newState)
{
	//handle current state
	if (currentState == INIT)
	{
	}
	else if (currentState == PLAYING)
	{
		for (iter1 = objects.begin();iter1 != objects.end(); ++iter1) {
			if (((*iter1)->getId() != PLAYER) && ((*iter1)->getId() != MISC)) {
				(*iter1)->setAlive(false);
			}
		}
	}
	else if (currentState == OVER) {

	}
	else if (currentState == EXIT) {

	}
	//change state
	currentState = newState;
	//handle new state
	if (currentState == INIT) {
	}
	if (currentState == TITLE) {
	}
	else if (currentState == PLAYING) {
		ship->init();
	}
	else if (currentState == OVER) {
	}
	else if (currentState == EXIT) {
	}
}