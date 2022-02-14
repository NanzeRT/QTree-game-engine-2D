#include "App.h"

App::App() : App(Settings())
{
}

App::App(Settings settings_)
    : settings(settings_), game_engine(this)
{
    InitX();
}

void App::InitX()
{
    /* get the colors black and white (see section for details) */
    unsigned long black, white;

    /* use the information from the environment variable DISPLAY 
	   to create the X connection:
	*/
    dis = XOpenDisplay((char *)0);
    screen = DefaultScreen(dis);
    black = BlackPixel(dis, screen),     /* get color black */
        white = WhitePixel(dis, screen); /* get color white */

    /* once the display is initialized, create the window.
	   This window will be have be 200 pixels across and 300 down.
	   It will have the foreground white and background black
	*/
    win = XCreateSimpleWindow(dis, DefaultRootWindow(dis), 0, 0,
                              settings.window_size.first, settings.window_size.second, 5, white, black);

    /* here is where some properties of the window can be set.
	   The third and fourth items indicate the name which appears
	   at the top of the window and the name of the minimized window
	   respectively.
	*/
    XSetStandardProperties(dis, win, "My Window", "HI!", None, NULL, 0, NULL);

    /* this routine determines which types of input are allowed in
	   the input.  see the appropriate section for details...
	*/
    XSelectInput(dis, win, settings.input_mask);

    /* create the Graphics Context */
    gc = XCreateGC(dis, win, 0, 0);

    /* here is another routine to set the foreground and background
	   colors _currently_ in use in the window.
	*/
    XSetBackground(dis, gc, black);
    XSetForeground(dis, gc, white);

    /* clear the window and bring it on top of the other windows */
    XClearWindow(dis, win);
    XMapRaised(dis, win);
}

void App::StartLoop()
{
    while (1)
    {
        auto start = std::chrono::steady_clock::now();
        Loop();
        std::this_thread::sleep_for(std::chrono::microseconds(1000000 / settings.FPS) - (start - std::chrono::steady_clock::now()));
    }
}

XEvent event;   /* the XEvent declaration !!! */
KeySym key;     /* a dealie-bob to handle KeyPress Events */
char text[255]; /* a char buffer for KeyPress Events */

void App::Loop()
{
    HandleXEvents();
    game_engine.Update();
    Redraw();
}

void App::HandleXEvents()
{
    while (XPending(dis))
    {
        XNextEvent(dis, &event);

        switch (event.type)
        {
        case Expose:
            if (event.xexpose.count != 0)
                break;
            /* the window was exposed redraw it! */
            Redraw();
            break;
        case KeyPress:
            if (XLookupString(&event.xkey, text, 255, &key, 0) != 1)
                break;
            if (text[0] == 'q')
                Close();
            printf("You pressed the %c key!\n", text[0]);
            break;
        case ButtonPress:
            game_engine.OnMouseDown(event.xbutton.x, event.xbutton.y);
            break;
        case MotionNotify:
            game_engine.OnMouseDrag(event.xbutton.x, event.xbutton.y);
            break;
        case ButtonRelease:
            game_engine.OnMouseUp(event.xbutton.x, event.xbutton.y);
            break;
        }
    }
}

void App::Redraw()
{
    XClearWindow(dis, win);
    game_engine.DrawAll();
    XFlush(dis);
}

void App::Close()
{
    XFreeGC(dis, gc);
    XDestroyWindow(dis, win);
    XCloseDisplay(dis);
    exit(1);
}

void App::Draw(IDrawable *d)
{
    d->Draw(dis, win, gc);
}