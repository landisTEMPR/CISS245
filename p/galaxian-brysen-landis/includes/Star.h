#ifndef STARFIELD_H
#define STARFIELD_H

#include <vector>
#include <cstdint>
#include "Includes.h"   // your project's types: Surface, Color, etc.

struct Star
{
    float x;     // subpixel x
    float y;     // subpixel y
    float dy;    // speed in pixels/frame (or pixels/sec depending on update)
    int   rad;   // radius for drawing (0 -> single pixel)
    int   dist;  // depth layer (1 = near, larger = far)
    uint8_t r;   // color components
    uint8_t g;
    uint8_t b;
};

class StarField
{
public:
    // ctor: window width, height, and approximate number of stars
    StarField(int width, int height, int numStars = 200);

    // initialize or re-seed the stars (call if you resize, change density, or want reset)
    void init(int numStars);

    // update star positions. dtSeconds is seconds elapsed since last update (float).
    void update(float dtSeconds);

    // render to the surface (locks/unlocks internally)
    // If you prefer to draw within an already-locked surface, call renderUnlocked(surface).
    void render(Surface & surface);

    // render without locking (caller must lock/unlock around call)
    void renderUnlocked(Surface & surface);

    // configuration
    void setSpeedMultiplier(float m);
    void setColorTint(uint8_t r, uint8_t g, uint8_t b);

private:
    int m_width;
    int m_height;
    std::vector<Star> m_stars;
    float m_speedMultiplier;
    uint8_t m_tintR;
    uint8_t m_tintG;
    uint8_t m_tintB;

    // helper
    void respawnStar(Star & s, bool atTop = true);
};

#endif
