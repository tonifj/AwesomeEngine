#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "SDL.h"
#include "ModuleRenderExercise.h"



//#include "glew-2.1.0/include/GL/glew.h"
//#pragma comment (lib, "glew-2.1.0/lib/Release/Win32/glew32.lib")

ModuleRender::ModuleRender()
{


}

// Destructor
ModuleRender::~ModuleRender()
{

}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	SDL_GLContext glcontext = SDL_GL_CreateContext(App->window->window);

	//glClearColor(0.225f, 0, 0.225f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(App->window->window);

	GLenum err = glewInit();// ... check for errors
	LOG("Using Glew %s", glewGetString(GLEW_VERSION));

	LOG("Vendor: %s", glGetString(GL_VENDOR)); 
	LOG("Renderer: %s", glGetString(GL_RENDERER)); 
	LOG("OpenGL version supported %s", glGetString(GL_VERSION)); 
	LOG("GLSL: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
	glClearDepth(1.0f); 
	glClearColor(0.f, 0.f, 0.f, 1.f); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	glEnable(GL_DEPTH_TEST); 
	glFrontFace(GL_CCW); 
	glEnable(GL_CULL_FACE); 
	glEnable(GL_TEXTURE_2D); 

	return true;
}

update_status ModuleRender::PreUpdate()
{
	//glViewport(0, 0, 1024, 768);
	glClearColor(0.225f, 0, 0.225f, 1);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	return UPDATE_CONTINUE;
}

// Called every draw update
update_status ModuleRender::Update()
{



	return UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{

	SDL_GL_SwapWindow(App->window->window);

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy window

	return true;
}

void ModuleRender::WindowResized(unsigned width, unsigned height)
{
}

