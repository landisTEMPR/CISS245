#include <iostream>
#include "Includes.h"
#include "Menu.h"
#include "StarField.h"

void menu()
{
    const int W = 1920;
    const int H = 1080;

    Surface s(W, H);

    // Fonts
    Font fontTitle("fonts/FreeMonoBold.ttf", 150);
    Font fontSub("fonts/FreeMonoBold.ttf", 50);
    Font fontItem("fonts/FreeMonoBold.ttf", 75);

    // Colors
    Color titleColor = { 0, 0, 255 };
    Color subColor = { 255, 255, 255 };
    Color itemColor = { 0, 200, 225 };
    Color itemHoverColor = { 255, 230, 100 };     // hover text
    Color buttonBgColor = { 20, 60, 120 };        // normal button background
    Color buttonBgHoverColor = { 50, 100, 180 };  // hover background

    // Create title/subtitle text images
    Image t0(fontTitle.render("GALAXIAN", titleColor));
    Image t1(fontSub.render("BY BRYSEN LANDIS", subColor));

    // Render two variants (normal & hover) for each button label
    Image t2_normal(fontItem.render("PLAY", itemColor));
    Image t2_hover(fontItem.render("PLAY", itemHoverColor));

    Image t3_normal(fontItem.render("HELP", itemColor));
    Image t3_hover(fontItem.render("HELP", itemHoverColor));

    Image t4_normal(fontItem.render("QUIT", itemColor));
    Image t4_hover(fontItem.render("QUIT", itemHoverColor));

    // Rects (we will recompute x/y to center later)
    Rect r0 = t0.getRect();
    Rect r1 = t1.getRect();
    Rect r2 = t2_normal.getRect();
    Rect r3 = t3_normal.getRect();
    Rect r4 = t4_normal.getRect();

    // Layout parameters and padding
    const int centerX = W / 2;
    const int centerY = H / 2;

    const int PAD_X = 12;                     // horizontal padding inside button
    const int PAD_Y = 8;                      // vertical padding inside button

    const int TITLE_TO_SUBTITLE = 10;         // gap between title and subtitle
    const int SUBTITLE_TO_BUTTON = 20;        // gap between subtitle and first button
    const int BUTTON_SPACING = 18;            // vertical spacing between buttons

    // Compute heights for stacking
    int titleH = r0.h;
    int subH = r1.h;
    int btnH0 = r2.h;
    int btnH1 = r3.h;
    int btnH2 = r4.h;

    int totalHeight = titleH
                    + TITLE_TO_SUBTITLE
                    + subH
                    + SUBTITLE_TO_BUTTON
                    + btnH0
                    + BUTTON_SPACING
                    + btnH1
                    + BUTTON_SPACING
                    + btnH2;

    // Start Y for the stacked block (vertically centered)
    int startY = centerY - (totalHeight / 2);

    // Place title
    r0.x = centerX - (r0.w / 2);
    r0.y = startY;
    startY += r0.h;
    startY += TITLE_TO_SUBTITLE;

    // Place subtitle
    r1.x = centerX - (r1.w / 2);
    r1.y = startY;
    startY += r1.h;
    startY += SUBTITLE_TO_BUTTON;

    // Place buttons stacked, centered
    r2.x = centerX - (r2.w / 2);
    r2.y = startY;
    startY += r2.h;
    startY += BUTTON_SPACING;

    r3.x = centerX - (r3.w / 2);
    r3.y = startY;
    startY += r3.h;
    startY += BUTTON_SPACING;

    r4.x = centerX - (r4.w / 2);
    r4.y = startY;

    // Compute padded backgrounds for each button
    int bx2 = r2.x - PAD_X;
    int by2 = r2.y - PAD_Y;
    int bw2 = r2.w + 2 * PAD_X;
    int bh2 = r2.h + 2 * PAD_Y;

    int bx3 = r3.x - PAD_X;
    int by3 = r3.y - PAD_Y;
    int bw3 = r3.w + 2 * PAD_X;
    int bh3 = r3.h + 2 * PAD_Y;

    int bx4 = r4.x - PAD_X;
    int by4 = r4.y - PAD_Y;
    int bw4 = r4.w + 2 * PAD_X;
    int bh4 = r4.h + 2 * PAD_Y;

    // Background star field
    StarField stars(W, H, 500);    // tweak density
    stars.setSpeedMultiplier(1.0f);
    stars.setColorTint(255, 252, 220);

    Event event;
    bool quit = false;

    // For stable movement compute dt
    uint32_t lastTicks = getTicks();

    // Hover state variables
    bool hover2 = false;
    bool hover3 = false;
    bool hover4 = false;

    // Main loop
    while (!quit)
    {
        // Poll all events
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
            }
            else if (event.type() == MOUSEMOTION)
            {
                // update mouse position from helper functions (keeps code consistent across platforms)
                int mx = mouse_x();
                int my = mouse_y();

                hover2 = (mx >= bx2 && mx < bx2 + bw2 && my >= by2 && my < by2 + bh2);
                hover3 = (mx >= bx3 && mx < bx3 + bw3 && my >= by3 && my < by3 + bh3);
                hover4 = (mx >= bx4 && mx < bx4 + bw4 && my >= by4 && my < by4 + bh4);
            }
            else if (event.type() == MOUSEBUTTONUP)
            {
                int mx = mouse_x();
                int my = mouse_y();

                // Prefer hit-testing against padded background (more forgiving click zone)
                if (mx >= bx2 && mx < bx2 + bw2 && my >= by2 && my < by2 + bh2)
                {
                    std::cout << "PLAY clicked\n";
                }
                else if (mx >= bx3 && mx < bx3 + bw3 && my >= by3 && my < by3 + bh3)
                {
                    std::cout << "HELP clicked\n";
                }
                else if (mx >= bx4 && mx < bx4 + bw4 && my >= by4 && my < by4 + bh4)
                {
                    std::cout << "QUIT clicked\n";
                    quit = true;
                }
            }
        } // end event.poll loop

        // compute dt in seconds (clamped)
        uint32_t now = getTicks();
        float dt = static_cast<float>(now - lastTicks) / 1000.0f;
        if (dt > 0.05f) dt = 0.05f;
        lastTicks = now;

        // update star positions
        stars.update(dt);

        // draw frame: starfield first, then menu (so menu is on top)
        s.lock();
        s.fill(BLACK);                  // clear background
        stars.renderUnlocked(s);        // draw stars while still locked

        // draw title / subtitle
        s.put_image(t0, r0);
        s.put_image(t1, r1);

        // draw buttons: pick bg color and text image based on hover state
        if (hover2)
        {
            s.put_rect(bx2, by2, bw2, bh2, buttonBgHoverColor.r, buttonBgHoverColor.g, buttonBgHoverColor.b);
            s.put_image(t2_hover, r2);
        }
        else
        {
            s.put_rect(bx2, by2, bw2, bh2, buttonBgColor.r, buttonBgColor.g, buttonBgColor.b);
            s.put_image(t2_normal, r2);
        }

        if (hover3)
        {
            s.put_rect(bx3, by3, bw3, bh3, buttonBgHoverColor.r, buttonBgHoverColor.g, buttonBgHoverColor.b);
            s.put_image(t3_hover, r3);
        }
        else
        {
            s.put_rect(bx3, by3, bw3, bh3, buttonBgColor.r, buttonBgColor.g, buttonBgColor.b);
            s.put_image(t3_normal, r3);
        }

        if (hover4)
        {
            s.put_rect(bx4, by4, bw4, bh4, buttonBgHoverColor.r, buttonBgHoverColor.g, buttonBgHoverColor.b);
            s.put_image(t4_hover, r4);
        }
        else
        {
            s.put_rect(bx4, by4, bw4, bh4, buttonBgColor.r, buttonBgColor.g, buttonBgColor.b);
            s.put_image(t4_normal, r4);
        }

        s.unlock();
        s.flip();

        delay(16); // ~60 FPS
    } // end main loop

    return;
}

void click_menu()
{
    
    
    return;
}
