/*
 * screen_resolution.c: Program to obtain the X display resolution using X11
 *                      display library.
 *
 * Author: Rohan Bari
 * Date:   2021-09-21
 */

#include <stdio.h>
#include <X11/Xlib.h>

#define EXIT_SUCCESS 0

/*
 * User-defined resolution type.
 */
struct Resolution {
    int width;
    int height;
};

/*
 * Obtain the screen resolution.
 */
struct Resolution get_resolution(void) {
    struct Resolution res;

    // Prefers the current display.
    Display *display = XOpenDisplay(NULL);
    // Sets the current screen to the current display.
    Screen *screen = DefaultScreenOfDisplay(display);

    res.width = screen->width;
    res.height = screen->height;

    return res;
}

int main(void) {
    struct Resolution res = get_resolution();
    fprintf(stdout, "Screen resolution: %dx%d\n", res.width, res.height);

    return EXIT_SUCCESS;
}
