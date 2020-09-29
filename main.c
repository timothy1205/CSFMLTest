#include <stdio.h>
#include <SFML/Graphics.h>

int main() {
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){1920, 1080}, "CSFMLTest",  sfFullscreen, NULL);
    sfView *view = sfRenderWindow_getDefaultView(window);

    sfView_setSize(view, (sfVector2f){1920.0f, 1080.0f});
    sfVector2u size = sfRenderWindow_getSize(window);
    sfView_setCenter(view, (sfVector2f){size.x/2, size.y/2});
    sfRenderWindow_setView(window, view);

    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, sfRed);
    sfCircleShape_setRadius(circle, 10.0f);
    sfCircleShape_setPosition(circle, (sfVector2f){0, 0});

    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){1920.0f/2, 50.0f});
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 1080.0f/2});

    while(sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            else if (event.type == sfEvtResized) {
                sfView_setSize(view, (sfVector2f){(float) event.size.width, (float) event.size.height});
                sfRenderWindow_setView(window, view);
            }
        }

        sfRenderWindow_clear(window, sfBlack);

        sfRenderWindow_drawCircleShape(window, circle, NULL);
        sfRenderWindow_drawRectangleShape(window, rect, NULL);
        sfCircleShape_move(circle, (sfVector2f){0.01f, 0.01f});

        sfRenderWindow_display(window);
    }
    return 0;
}
