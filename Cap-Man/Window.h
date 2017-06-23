#pragma once
#include "Wrapper.h"

struct SDL_Window;

class Window 
		: public Wrapper<SDL_Window> {
	friend class Renderer;
public:
	Window();
	~Window();

	bool initialize(int width, int height);
	// TODO: Consider this with respect to Map scaling
	// NB: This doesn't affect mSdlWindow. Is used instead for updates after an SDL_Event window resize
	void setDimens(int w, int h) { mWidth = w; mHeight = h; }

	const SDL_Window* data() const override { return mSdlWindow; }
	SDL_Window* mutableData() override { return mSdlWindow; }

private:
	SDL_Window* mSdlWindow;
	int mWidth;
	int mHeight;
};

