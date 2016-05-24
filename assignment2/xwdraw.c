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
  GC drawW;
  GC drawP;
  GC drawBR;
  GC drawPU;
  GC drawGR;
  GC drawO;

  Colormap cmap;
  XColor color, ignore;
  char *colornameK = "Black";
  char *colornameR = "Red";
  char *colornameB = "Blue";
  char *colornameG = "Green";
  char *colornameY = "Yellow";
  char *colornameW = "White";
  char *colornameP = "Pink";
  char *colornameBR = "Brown";
  char *colornamePU = "Purple";
  char *colornameGR = "Gray";
  char *colornameO = "Orange";
  
  int PtCount=0;
  int b1, X, Y, d, a, b, distance, len,  CircleRadious, centerx, centery, distance1;
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
  
  XAllocNamedColor(display, cmap, colornameW, &color, &ignore);
  fgcolor = color.pixel;
  gcval.foreground = fgcolor;
  gcval.background = bgcolor;
  gcval.line_width  = 4;
  drawW = XCreateGC(display,window,GCForeground|GCBackground|GCLineWidth,&gcval);

  XAllocNamedColor(display, cmap, colornameP, &color, &ignore);
  fgcolor = color.pixel;
  gcval.foreground = fgcolor;
  gcval.background = bgcolor;
  gcval.line_width  = 4;
  drawP = XCreateGC(display,window,GCForeground|GCBackground|GCLineWidth,&gcval);
  
  XAllocNamedColor(display, cmap, colornameBR, &color, &ignore);
  fgcolor = color.pixel;
  gcval.foreground = fgcolor;
  gcval.background = bgcolor;
  gcval.line_width  = 4;
  drawBR = XCreateGC(display,window,GCForeground|GCBackground|GCLineWidth,&gcval);
  
  XAllocNamedColor(display, cmap, colornamePU, &color, &ignore);
  fgcolor = color.pixel;
  gcval.foreground = fgcolor;
  gcval.background = bgcolor;
  gcval.line_width  = 4;
  drawPU = XCreateGC(display,window,GCForeground|GCBackground|GCLineWidth,&gcval);
  
  XAllocNamedColor(display, cmap, colornameGR, &color, &ignore);
  fgcolor = color.pixel;
  gcval.foreground = fgcolor;
  gcval.background = bgcolor;
  gcval.line_width  = 4;
  drawGR = XCreateGC(display,window,GCForeground|GCBackground|GCLineWidth,&gcval);
  
  XAllocNamedColor(display, cmap, colornameO, &color, &ignore);
  fgcolor = color.pixel;
  gcval.foreground = fgcolor;
  gcval.background = bgcolor;
  gcval.line_width  = 4;
  drawO = XCreateGC(display,window,GCForeground|GCBackground|GCLineWidth,&gcval);
  
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
	len=sqrt(2*distance*distance);
	a = len/2;
	b = sqrt((distance*distance)-(a*a));
      	XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);
        distance1=distance-4;
	b1 = b-4;
        randnum = (rand() % 10);

      switch ( randnum) {
      case 0: 
	 XFillRectangle (display , window , drawK, (pointx1-distance), (pointy1-distance), abs (2*distance), abs (2*distance));
         XFillRectangle (display , window , drawR, (pointx1-distance1), (pointy1-distance1), abs (2*distance1), abs (2*distance1));
        XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);

      	XFillArc (display,window, drawG, pointx1-distance1, pointy1-distance1,2*distance1, 2*distance1, 0, 360 * 64);        
         XFillRectangle (display , window , drawK, (pointx1-b), (pointy1-b), abs (2*b), abs (2*b));
         XFillRectangle (display , window , drawB, (pointx1-b1), (pointy1-b1), abs (2*b1), abs (2*b1));
        break;
      case 1:
         XFillRectangle (display , window , drawK, (pointx1-distance), (pointy1-distance), abs (2*distance), abs (2*distance));
        XFillRectangle (display , window , drawG, (pointx1-distance1), (pointy1-distance1), abs (2*distance1), abs (2*distance1)); 
        XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);
      	XFillArc (display,window, drawB, pointx1-distance1, pointy1-distance1,2*distance1, 2*distance1, 0, 360 * 64);  
         XFillRectangle (display , window , drawK, (pointx1-b), (pointy1-b), abs (2*b), abs (2*b));
         XFillRectangle (display , window , drawY, (pointx1-b1), (pointy1-b1), abs (2*b1), abs (2*b1));
      break;
      case 2: 
         XFillRectangle (display , window , drawK, (pointx1-distance), (pointy1-distance), abs (2*distance), abs (2*distance));
        XFillRectangle (display , window , drawB, (pointx1-distance1), (pointy1-distance1), abs (2*distance1), abs (2*distance1));
        XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);
      	XFillArc (display,window, drawY, pointx1-distance1, pointy1-distance1,2*distance1, 2*distance1, 0, 360 * 64);  
         XFillRectangle (display , window , drawK, (pointx1-b), (pointy1-b), abs (2*b), abs (2*b));
         XFillRectangle (display , window , drawW, (pointx1-b1), (pointy1-b1), abs (2*b1), abs (2*b1));
      break;
      case 3: 
         XFillRectangle (display , window , drawK, (pointx1-distance), (pointy1-distance), abs (2*distance), abs (2*distance));
        XFillRectangle (display , window , drawY, (pointx1-distance1), (pointy1-distance1), abs (2*distance1), abs (2*distance1));
        XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);
      	XFillArc (display,window, drawW, pointx1-distance1, pointy1-distance1,2*distance1, 2*distance1, 0, 360 * 64);
         XFillRectangle (display , window , drawK, (pointx1-b), (pointy1-b), abs (2*b), abs (2*b));
         XFillRectangle (display , window , drawP, (pointx1-b1), (pointy1-b1), abs (2*b1), abs (2*b1));
      break;
	  case 4: 
		XFillRectangle (display , window , drawK, (pointx1-distance), (pointy1-distance), abs (2*distance), abs (2*distance));
        XFillRectangle (display , window , drawW, (pointx1-distance1), (pointy1-distance1), abs (2*distance1), abs (2*distance1));
        XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);

      	XFillArc (display,window, drawP, pointx1-distance1, pointy1-distance1,2*distance1, 2*distance1, 0, 360 * 64);        
         XFillRectangle (display , window , drawK, (pointx1-b), (pointy1-b), abs (2*b), abs (2*b));
         XFillRectangle (display , window , drawBR, (pointx1-b1), (pointy1-b1), abs (2*b1), abs (2*b1));
        break;
      case 5: 
		XFillRectangle (display , window , drawK, (pointx1-distance), (pointy1-distance), abs (2*distance), abs (2*distance));
         XFillRectangle (display , window , drawP, (pointx1-distance1), (pointy1-distance1), abs (2*distance1), abs (2*distance1));
        XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);

      	XFillArc (display,window, drawBR, pointx1-distance1, pointy1-distance1,2*distance1, 2*distance1, 0, 360 * 64);        
         XFillRectangle (display , window , drawK, (pointx1-b), (pointy1-b), abs (2*b), abs (2*b));
         XFillRectangle (display , window , drawPU, (pointx1-b1), (pointy1-b1), abs (2*b1), abs (2*b1));
        break;
      case 6: 
		XFillRectangle (display , window , drawK, (pointx1-distance), (pointy1-distance), abs (2*distance), abs (2*distance));
         XFillRectangle (display , window , drawBR, (pointx1-distance1), (pointy1-distance1), abs (2*distance1), abs (2*distance1));
        XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);

      	XFillArc (display,window, drawPU, pointx1-distance1, pointy1-distance1,2*distance1, 2*distance1, 0, 360 * 64);        
         XFillRectangle (display , window , drawK, (pointx1-b), (pointy1-b), abs (2*b), abs (2*b));
         XFillRectangle (display , window , drawGR, (pointx1-b1), (pointy1-b1), abs (2*b1), abs (2*b1));
        break;
      case 7 :
		XFillRectangle (display , window , drawK, (pointx1-distance), (pointy1-distance), abs (2*distance), abs (2*distance));
         XFillRectangle (display , window , drawPU, (pointx1-distance1), (pointy1-distance1), abs (2*distance1), abs (2*distance1));
        XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);

      	XFillArc (display,window, drawGR, pointx1-distance1, pointy1-distance1,2*distance1, 2*distance1, 0, 360 * 64);        
         XFillRectangle (display , window , drawK, (pointx1-b), (pointy1-b), abs (2*b), abs (2*b));
         XFillRectangle (display , window , drawO, (pointx1-b1), (pointy1-b1), abs (2*b1), abs (2*b1));
        break;
      case 8: 
		XFillRectangle (display , window , drawK, (pointx1-distance), (pointy1-distance), abs (2*distance), abs (2*distance));
         XFillRectangle (display , window , drawGR, (pointx1-distance1), (pointy1-distance1), abs (2*distance1), abs (2*distance1));
        XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);

      	XFillArc (display,window, drawO, pointx1-distance1, pointy1-distance1,2*distance1, 2*distance1, 0, 360 * 64);        
         XFillRectangle (display , window , drawK, (pointx1-b), (pointy1-b), abs (2*b), abs (2*b));
         XFillRectangle (display , window , drawR, (pointx1-b1), (pointy1-b1), abs (2*b1), abs (2*b1));
        break;
      case 9: 
		XFillRectangle (display , window , drawK, (pointx1-distance), (pointy1-distance), abs (2*distance), abs (2*distance));
         XFillRectangle (display , window , drawO, (pointx1-distance1), (pointy1-distance1), abs (2*distance1), abs (2*distance1));
        XFillArc (display,window, drawK, pointx1-distance, pointy1-distance,2*distance, 2*distance, 0, 360 * 64);

      	XFillArc (display,window, drawR, pointx1-distance1, pointy1-distance1,2*distance1, 2*distance1, 0, 360 * 64);        
         XFillRectangle (display , window , drawK, (pointx1-b), (pointy1-b), abs (2*b), abs (2*b));
         XFillRectangle (display , window , drawGR, (pointx1-b1), (pointy1-b1), abs (2*b1), abs (2*b1));
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
