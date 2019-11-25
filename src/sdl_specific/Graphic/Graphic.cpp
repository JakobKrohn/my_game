#include "Graphic.hpp"

#include "Output.hpp"
#include "Settings.hpp"

void Graphic::addObject(IDrawable* object, std::string imagePath) {
	objects_.push_back(object);
	object->getDrawable();
	auto silent = imagePath;
}

bool Graphic::begin(int x, int y) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << SDL_GetError() << "\n";
		return false;
	}

	window_ = SDL_CreateWindow("Window", x, y, 
		WINDOW_WIDTH, 
		WINDOW_HEIGHT, 
		SDL_WINDOW_SHOWN);
		
	if (window_ == nullptr) {
		std::cout << SDL_GetError() << "\n";
		return false;
	}

		// TODO: WHY IS THIS GENERATING LINKER ERROR?
	if ((IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)) {
		print(IMG_GetError());
		return false;
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
	if (renderer_ == nullptr) {
		std::cout << SDL_GetError() << "\n";
	}

	SDL_SetRenderDrawColor( renderer_, 0x00, 0x00, 0x00, 0x00 ); 
	SDL_RenderClear(renderer_);
	SDL_SetRenderDrawColor( renderer_, 0x00, 0xFF, 0x00, 0xFF ); 
	auto pos = objects_.front()->getDrawable();
	SDL_Rect rect = {pos->x, pos->y, pos->width, pos->height};

	SDL_RenderFillRect(renderer_, &rect);
	SDL_RenderPresent(renderer_);

	return true;
}

void Graphic::update() {
	// SDL_SetRenderDrawColor( renderer_, 0x00, 0x00, 0x00, 0x00 ); 
	// SDL_RenderClear(renderer_);
	// SDL_SetRenderDrawColor( renderer_, 0x00, 0xFF, 0x00, 0xFF ); 
	// SDL_Rect rect = {a++, b++, 50, 50};
	// SDL_RenderFillRect(renderer_, &rect);
	// SDL_RenderPresent(renderer_);
}

// http://lazyfoo.net/tutorials/SDL/07_texture_loading_and_rendering/index.php
SDL_Texture * Graphic::loadTexture(std::string path) {
	// SDL_Texture * texture = nullptr;
	auto silent = path;
	return nullptr;
}