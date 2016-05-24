#include <X11/Xlib.h>
#include <X11/keysym.h>

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define RECT 1
#define CIRCLE 2
#define TRI 3
#define BUFFERSIZE 20


main(argc,argv)
int argc;
char **argv;
{
  Display *display;
  Window root, window;
  long fgcolor, bgcolor;
  int screen, pointx1, pointy1, pointx2, pointy2, pointx3, pointy3 ;
  long eventmask = ButtonPressMask |KeyPressMask;
  XEvent event;
  XGCValues gcval;
  GC drawK;
  GC drawR;
  GC drawB;
  GC drawG;
  GC drawY;

  Colormap cmap;
  XColor color, ignore;
  char *colornameK = "Black";
  char *colornameR = "Red";
  char *colornameB = "Blue";
  char *colornameG= "Green";
  char *colornameY= "Yellow";

  int PtCount=0;
  int X, Y, d, distance, len,  CircleRadious, centerx, centery;
  int DotRadious = 4;

char buffer[BUFFERSIZE];
int bufsize=BUFFERSIZE;
KeySym keysym;
long statinout;
int charcount;

int randnum;
rand(clock() + getpid());

  
  int Mode = atoi(argv[1]);
  if (!(display = XOpenDisplay(NULL))) {
    perror("XOpenDisplay");
    exit(1);
  }

  root = RootWindow(display,screen = DefaultScreen(display));
  fgcolor = BlackPixel(display,screen);
  bgcolor = WhitePixel(display,screen);

  window = XCreateSimpleWindow(display,root,0,0,600,500,2,fgcolor,bgcolor);

  cmap = DefaultColormap (display, screen);

  XAllocNamedColor(display, cmap, colornameK, &color, &ignore);
  fgcolor = color.pixel;
  gcval.foreground = fgcolor;
  gcval.background = bgcolor;
  gcval.line_width  = 4;
  drawK = XCreateGC(display,window,GCForeground|GCBackground|GCLineWidth,&gcval);


  XAllocNamedColor(display, cmap, colornameR, &color, &ignore);
  fgcolor = color.pixel;
  gcval.foreground = fgcolor;
  gcval.background = bgcolor;
  gcval.line_width  = 4;
  drawR = XCreateGC(display,window,GCForeground|GCBackground|GCLineWidth,&gcval);

  XAllocNamedColor(display, cmap, colornameG, &color, &ignore);
  fgcolor = color.pixel;
  gcval.foreground = fgcolor;
  gcval.background = bgcolor;
  gcval.line_width  = 4;
  drawG = XCreateGC(display,window,GCForeground|GCBackground|GCLineWidth,&gcval);


  XAllocNamedColor(display, cmap, colornameB, &color, &ignore);
  fgcolor = color.pixel;
  gcval.foreground = fgcolor;
  gcval.background = bgcolor;
  gcval.line_width  = 4;
  drawB = XCreateGC(display,window,GCForeground|GCBackground|GCLineWidth,&gcval);


  XAllocNamedColor(display, cmap, colornameY, &color, &ignore);
  fgcolor = color.pixel;
  gcval.foreground = fgcolor;
  gcval.background = bgcolor;
  gcval.line_width  = 4;
  drawY = XCreateGC(display,window,GCForeground|GCBackground|GCLineWidth,&gcval);

  XSelectInput(display,window,eventmask);
  XMapWindow(display,window);

  for (;;) {
      XWindowEvent(display,window,eventmask,&event);
      switch (event.type) {
        case ButtonPress:
      switch ( PtCount) {
      case 0: 
	PtCount=1;
        pointx1 = event.xbutton.x;
        pointy1 = event.xbutton.y;
        XDrawPoint (display,window,drawK, pointx1, pointy1);
	XFillArc (display , window , drawK, (pointx1 - DotRadious), (pointy1 - DotRadious), 
                (2 * DotRadious), (2 * DotRadious), 0, 360 * 64);

        break;
      case 1:
	PtCount=0;
        pointx2 = event.xbutton.x;
        pointy2 = event.xbutton.y;
	PtCount=0;
        X = pointx2 - pointx1;
        Y = pointy2 - pointy1;
        d = X * X + Y * Y;
        distance = sqrt (d);
        len=sqrt(distance);
      	XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);
        distance=distance-4;

        randnum = (rand() % 4);

      switch ( randnum) {
      case 0: 
      	XFillArc (display,window, drawR, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);
        break;
      case 1: 
      	XFillArc (display,window, drawG, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);
        break;
      case 2: 
      	XFillArc (display,window, drawB, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);
        break;
      case 3: 
      	XFillArc (display,window, drawY, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);
        break;
      }

	XFillArc (display , window , drawK, (pointx1 - DotRadious), (pointy1 - DotRadious), 
                (2 * DotRadious), (2 * DotRadious), 0, 360 * 64);
        break;
    } /* PtCount */
    break;
case KeyPress: 
      charcount = XLookupString(&event,buffer,bufsize, &keysym, &statinout);
      buffer[charcount]='\0';
      if (strcmp (buffer, "c") == 0 )  
        XClearWindow(display,window);
        break;
  } /*event*/
  }
}
