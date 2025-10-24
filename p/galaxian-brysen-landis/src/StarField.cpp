#include "StarField.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

StarField::StarField(int width, int height, int numStars)
    : m_width(width)
    , m_height(height)
    , m_speedMultiplier(1.0f)
    , m_tintR(255)
    , m_tintG(255)
    , m_tintB(255)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    init(numStars);
}

void StarField::init(int numStars)
{
    m_stars.clear();
    m_stars.reserve(numStars);
    for (int i = 0; i < numStars; ++i)
    {
        Star s;
        // random x across screen
        s.x = static_cast<float>(std::rand() % m_width);
        // random y across screen (spawn anywhere)
        s.y = static_cast<float>(std::rand() % m_height);

        // dist determines parallax: 1 = near (bigger, faster), 3 = far (smaller, slower)
        s.dist = 1 + (std::rand() % 3); // values 1..3

        // radius influenced by depth (near -> larger)
        s.rad = (s.dist == 1) ? (1 + (std::rand() % 2)) : (s.dist == 2 ? 1 : 0);

        // base speed depending on depth
        float base = (s.dist == 1) ? 80.0f : (s.dist == 2 ? 45.0f : 20.0f);
        // add bit of random variation
        s.dy = base * (0.5f + static_cast<float>(std::rand()) / RAND_MAX * 1.0f);

        // star color slight variation (whitish to bluish)
        int tint = (std::rand() % 56) + 200; // 200..255
        s.r = static_cast<uint8_t>(std::min(255, tint + (std::rand() % 16 - 8)));
        s.g = static_cast<uint8_t>(std::min(255, tint + (std::rand() % 16 - 8)));
        s.b = static_cast<uint8_t>(std::min(255, tint + (std::rand() % 32 - 16)));

        m_stars.push_back(s);
    }
}

void StarField::respawnStar(Star & s, bool atTop)
{
    // place star just above top or just below screen depending on atTop flag
    s.x = static_cast<float>(std::rand() % m_width);
    if (atTop)
    {
        s.y = - (std::rand() % 20 + 1); // small negative offset so it scrolls into view
    }
    else
    {
        s.y = static_cast<float>(m_height + (std::rand() % 20 + 1));
    }

    s.dist = 1 + (std::rand() % 3);
    s.rad = (s.dist == 1) ? (1 + (std::rand() % 2)) : (s.dist == 2 ? 1 : 0);
    float base = (s.dist == 1) ? 80.0f : (s.dist == 2 ? 45.0f : 20.0f);
    s.dy = base * (0.5f + static_cast<float>(std::rand()) / RAND_MAX * 1.0f);
    int tint = (std::rand() % 56) + 200;
    s.r = static_cast<uint8_t>(std::min(255, tint + (std::rand() % 16 - 8)));
    s.g = static_cast<uint8_t>(std::min(255, tint + (std::rand() % 16 - 8)));
    s.b = static_cast<uint8_t>(std::min(255, tint + (std::rand() % 32 - 16)));
}

void StarField::update(float dtSeconds)
{
    // move stars downward; when passing bottom, respawn at top
    for (auto & s : m_stars)
    {
        s.y += s.dy * dtSeconds * m_speedMultiplier;
        if (s.y > m_height + 10)
        {
            respawnStar(s, true);
        }
    }
}

void StarField::render(Surface & surface)
{
    surface.lock();
    renderUnlocked(surface);
    surface.unlock();
}

void StarField::renderUnlocked(Surface & surface)
{
    // Draw each star. Smaller (far) stars as single pixel; larger stars as small circle.
    for (auto const & s : m_stars)
    {
        // apply global tint
        uint8_t rr = static_cast<uint8_t>((s.r * m_tintR) / 255);
        uint8_t gg = static_cast<uint8_t>((s.g * m_tintG) / 255);
        uint8_t bb = static_cast<uint8_t>((s.b * m_tintB) / 255);

        int ix = static_cast<int>(std::round(s.x));
        int iy = static_cast<int>(std::round(s.y));

        if (s.rad <= 0)
        {
            // single pixel
            if (ix >= 0 && ix < m_width && iy >= 0 && iy < m_height)
            {
                surface.put_pixel(ix, iy, rr, gg, bb);
            }
        }
        else
        {
            // small filled circle for larger stars
            if (iy + s.rad >= 0 && iy - s.rad < m_height)
            {
                surface.put_circle(ix, iy, s.rad, rr, gg, bb);
            }
        }
    }
}

void StarField::setSpeedMultiplier(float m)
{
    m_speedMultiplier = m;
}

void StarField::setColorTint(uint8_t r, uint8_t g, uint8_t b)
{
    m_tintR = r;
    m_tintG = g;
    m_tintB = b;
}
