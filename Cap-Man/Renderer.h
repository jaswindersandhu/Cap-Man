#pragma once
#include "Wrapper.h"

class Texture;
class Rect;
class Color;
class Window;
struct SDL_Renderer;

class Renderer 
    : public Wrapper<SDL_Renderer> {
public:
    Renderer();
    ~Renderer();

    bool initialize(const Window& window);
    void setDrawColor(const Color& color) const;
    void fillRect(const Rect& rect) const;
    void copyTexture(Texture& texture, const Rect& source, const Rect& dest) const;
    void clear() const;
    void present() const;

    const SDL_Renderer* data() const override { return mSdlRenderer; }
    SDL_Renderer* mutableData() override { return mSdlRenderer; }

private:
    SDL_Renderer* mSdlRenderer;
};

