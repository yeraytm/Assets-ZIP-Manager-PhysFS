#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"

#include "Font.h"
#include "Defs.h"
#include "Log.h"

Scene::Scene() : Module()
{
	name.Create("scene");

	font = nullptr;
}

// Destructor
Scene::~Scene()
{}

// Called before render is available
bool Scene::Awake(pugi::xml_node& config)
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene::Start()
{
	// TODO: Loading of the assets
	img = app->tex->Load("Textures/asteroid.png");

	app->audio->PlayMusic("Audio/Music/music_spy.ogg");
	sFx = app->audio->LoadFx("Audio/Fx/confirmation.wav");
	font = new Font("Fonts/showg.xml");

	return true;
}

// Called each loop iteration
bool Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool Scene::Update(float dt)
{
	// TODO: Displaying and playing the results
	if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		app->audio->PlayFx(sFx);
	}

	if (app->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN)
	{
		app->audio->StopMusic();
	}

	if (app->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		app->audio->PlayMusic("Audio/Music/music_spy.ogg");
	}

	app->render->DrawText(font, "Press SPACE to play a sound effect", 10, 50, 40, 5, { 255,255,255,255 });

	app->render->DrawTexture(img, 240, 0);

	return true;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	bool ret = true;

	if(app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}