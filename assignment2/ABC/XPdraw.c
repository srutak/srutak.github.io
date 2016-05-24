#include <Xm/Xm.h>
#include <Xm/DrawingA.h>
#include <Xm/RowColumn.h>
#include <Xm/PushB.h>
#include <Xm/Form.h>
#include <Xm/Label.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void quitCallback (Widget w, XtPointer clientData, XtPointer callData);
void yesCallback (Widget w, XtPointer clientData, XtPointer callData);
void noCallback (Widget w, XtPointer clientData, XtPointer callData);

void startCallback (Widget w, XtPointer clientData, XtPointer callData);
void endCallback (Widget w, XtPointer clientData, XtPointer callData);

void circlesCallback (Widget w, XtPointer clientData, XtPointer callData);
void rectanglesCallback (Widget w, XtPointer clientData, XtPointer callData);
void trianglesCallback (Widget w, XtPointer clientData, XtPointer callData);

void xwindowsCallback (Widget w, XtPointer clientData, XtPointer callData);
void pythonCallback (Widget w, XtPointer clientData, XtPointer callData);


Widget shell, panel, topLabel, XwPy, drawShapes, startEnd, quitControl;

Widget quit, yes, no, start, end, cir, rec, tri, xw, py, topLabel; 
Widget Dum1, Dum2; 

int xwFlag = 0;
int pyFlag = 0;
int cirFlag = 0;
int recFlag = 0;
int triFlag = 0;
int startFlag = 0;
int endFlag = 0;

int sysFlag = 0;
int shapeFlag = 0;

Colormap cmap;
char *green="green";
char *red="red";
XColor color, ignore;
Arg redwargs[1];
Arg greenwargs[1];
Display *display;
int screen;


void
main (int argc, char **argv)
{
  XtAppContext app;
  char *msg="    Motif      *       Xwindows      *      PythonTurtle ";
  XmString       xmstr;

  if (putenv ("XENVIRONMENT=XPdraw.color") < 0)
    printf ("can't set XENVIRONMENT\n");

  shell = XtAppInitialize (&app, "DrawShapes", NULL, 0, &argc, argv, NULL, NULL, 0);

  panel = XtCreateManagedWidget ("panel", xmFormWidgetClass, shell, NULL, 0);
  display = XtDisplay (shell);
  screen = DefaultScreen (display);
  cmap = DefaultColormap (display, screen);



  xmstr = XmStringCreate ( msg, XmFONTLIST_DEFAULT_TAG ); 
  topLabel = XtVaCreateManagedWidget ( "topLabel", xmLabelWidgetClass, panel, XmNlabelString, xmstr, 
			    XmNtopAttachment, XmATTACH_FORM, 
                            XmNrightAttachment, XmATTACH_FORM,
			    XmNleftAttachment, XmATTACH_FORM, 
                            XmNbottomAttachment, XmATTACH_NONE, 
                            NULL ); 

  XwPy = XtVaCreateManagedWidget ("XwPy", xmRowColumnWidgetClass,
			     panel, XmNnumColumns, 3,
			     XmNorientation, XmHORIZONTAL,
			     XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, topLabel,
			     XmNleftAttachment, XmATTACH_FORM, 
                             XmNrightAttachment, XmATTACH_FORM,
                             XmNbottomAttachment, XmATTACH_NONE, 
                             NULL );

  drawShapes = XtVaCreateManagedWidget ("drawShapes", xmRowColumnWidgetClass,
			     panel, XmNnumColumns, 3,
			     XmNorientation, XmHORIZONTAL,
			     XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, XwPy,
			     XmNleftAttachment, XmATTACH_FORM, 
                             XmNrightAttachment, XmATTACH_FORM,
                             XmNbottomAttachment, XmATTACH_NONE, 
                             NULL);

  startEnd = XtVaCreateManagedWidget ("startEnd", xmRowColumnWidgetClass,
			     panel, XmNnumColumns, 3,
			     XmNorientation, XmHORIZONTAL,
			     XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, drawShapes,
			     XmNleftAttachment, XmATTACH_FORM, 
                             XmNrightAttachment, XmATTACH_FORM,
                             XmNbottomAttachment, XmATTACH_NONE, 
                             NULL);

  quitControl = XtVaCreateManagedWidget ("quitControl", xmRowColumnWidgetClass,
			     panel, XmNnumColumns, 3,
			     XmNorientation, XmHORIZONTAL,
			     XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, startEnd,
			     XmNleftAttachment, XmATTACH_FORM, 
                             XmNrightAttachment, XmATTACH_FORM,
                             XmNbottomAttachment, XmATTACH_NONE, 
                             NULL);

  yes = XtCreateManagedWidget  ("       Yes         ", xmPushButtonWidgetClass, quitControl, NULL, 0);
  quit = XtCreateManagedWidget ("      Quit     ", xmPushButtonWidgetClass, quitControl, NULL, 0);
  no = XtCreateManagedWidget   ("       No      ", xmPushButtonWidgetClass, quitControl, NULL, 0);
  start = XtCreateManagedWidget("      Start    ", xmPushButtonWidgetClass, startEnd, NULL, 0);
  Dum1 = XtCreateManagedWidget ("                       ", xmPushButtonWidgetClass, startEnd, NULL, 0);
  end = XtCreateManagedWidget  ("      End      ", xmPushButtonWidgetClass, startEnd, NULL, 0);
  cir = XtCreateManagedWidget  ("     Circls    ", xmPushButtonWidgetClass, drawShapes, NULL, 0);
  rec = XtCreateManagedWidget  ("    Rectagles  ", xmPushButtonWidgetClass, drawShapes, NULL, 0);
  tri = XtCreateManagedWidget  ("    Triangles  ", xmPushButtonWidgetClass, drawShapes, NULL, 0);
  xw = XtCreateManagedWidget   ("    Xwindows   ", xmPushButtonWidgetClass, XwPy, NULL, 0);
  Dum2 = XtCreateManagedWidget ("               ", xmPushButtonWidgetClass, XwPy, NULL, 0);
  py = XtCreateManagedWidget   ("     Python    ", xmPushButtonWidgetClass, XwPy, NULL, 0);

  XtAddCallback (quit, XmNactivateCallback, quitCallback, NULL);
  XtAddCallback (yes, XmNactivateCallback, yesCallback, NULL);
  XtAddCallback (no, XmNactivateCallback, noCallback, NULL);
  XtAddCallback (start, XmNactivateCallback, startCallback, NULL);
  XtAddCallback (end, XmNactivateCallback, endCallback, NULL);
  XtAddCallback (cir, XmNactivateCallback, circlesCallback, NULL);
  XtAddCallback (rec, XmNactivateCallback, rectanglesCallback, NULL);
  XtAddCallback (tri, XmNactivateCallback, trianglesCallback, NULL);
  XtAddCallback (xw, XmNactivateCallback, xwindowsCallback, NULL);
  XtAddCallback (py, XmNactivateCallback, pythonCallback, NULL);

  XtRealizeWidget (shell);
  XtUnmapWidget(Dum1);
  XtUnmapWidget(Dum2);
  XtUnmapWidget(yes);
  XtUnmapWidget(no);
  initInterface();
  XtAppMainLoop (app);
}

void initInterface(){

  XAllocNamedColor (display, cmap, green, &color, &ignore);
  XtSetArg (greenwargs[0], XmNbackground, color.pixel);
  XAllocNamedColor (display, cmap, red, &color, &ignore);
  XtSetArg (redwargs[0], XmNbackground, color.pixel);

  XtVaSetValues (start, XmNsensitive, False, NULL);
  XtVaSetValues (end, XmNsensitive, False, NULL);
  XtVaSetValues (rec, XmNsensitive, False, NULL);
  XtVaSetValues (cir, XmNsensitive, False, NULL);
  XtVaSetValues (tri, XmNsensitive, False, NULL);
}

void quitCallback (Widget w, XtPointer clientData, XtPointer callData)
{

  XtVaSetValues (quit, XmNsensitive, False, NULL);
  XtMapWidget (no);
  XtMapWidget (yes);


}
void yesCallback (Widget w, XtPointer clientData, XtPointer callData)
{
	system ("pkill -9 python3");
	system ("pkill -9 xwdraw");
	exit(0);
} 
void noCallback (Widget w, XtPointer clientData, XtPointer callData)
{
  XtVaSetValues (quit, XmNsensitive, True, NULL);
  XtUnmapWidget(no);
  XtUnmapWidget(yes);
}
void startCallback (Widget w, XtPointer clientData, XtPointer callData)
{
  XtVaSetValues (start, XmNsensitive, False, NULL);
  XtVaSetValues (end, XmNsensitive, True, NULL);
  if (xwFlag == 1) {
        if (cirFlag == 1) system("./xwdraw 1 &");
        if (recFlag == 1) system("./xwdraw 2 &");
        if (triFlag == 1) system("./xwdraw 3 &");
  } 
  if (pyFlag == 1) {
        if (cirFlag == 1) system("/usr/bin/python3 pydraw.pyo '1' &");
        if (recFlag == 1) system("/usr/bin/python3 pydraw.pyo '2' &");
        if (triFlag == 1) system("/usr/bin/python3 pydraw.pyo '3' &");
  }
}

void endCallback (Widget w, XtPointer clientData, XtPointer callData)
{
  XtVaSetValues (end, XmNsensitive, False, NULL);
  XtVaSetValues (start, XmNsensitive, True, NULL);

	system ("pkill -9 xwdraw");
	system ("pkill -9 python3");

	recFlag = 0;
  	XtVaSetValues (rec, XmNsensitive, True, NULL);
  	XtSetValues (rec, redwargs, 1);
	cirFlag = 0;
  	XtVaSetValues (cir, XmNsensitive, True, NULL);
  	XtSetValues (cir, redwargs, 1);
	triFlag = 0;
  	XtVaSetValues (tri, XmNsensitive, True, NULL);
  	XtSetValues (tri, redwargs, 1);
}

void circlesCallback (Widget w, XtPointer clientData, XtPointer callData)
{
  cirFlag = 1;
  recFlag = 0;
  triFlag = 0;

  if (shapeFlag == 0){
	shapeFlag = 1;
  	XtVaSetValues (start, XmNsensitive, True, NULL);
  }

  XtVaSetValues (cir, XmNsensitive, False, NULL);
  XtSetValues (cir, greenwargs, 1);

  XtVaSetValues (rec, XmNsensitive, True, NULL);
  XtSetValues (rec, redwargs, 1);
  XtVaSetValues (tri, XmNsensitive, True, NULL);
  XtSetValues (tri, redwargs, 1);
}

void rectanglesCallback (Widget w, XtPointer clientData, XtPointer callData)
{
  recFlag = 1;
  cirFlag = 0;
  triFlag = 0;

  if (shapeFlag == 0){
	shapeFlag = 1;
  	XtVaSetValues (start, XmNsensitive, True, NULL);
  }

  XtVaSetValues (rec, XmNsensitive, False, NULL);
  XtSetValues (rec, greenwargs, 1);

  XtVaSetValues (cir, XmNsensitive, True, NULL);
  XtSetValues (cir, redwargs, 1);
  XtVaSetValues (tri, XmNsensitive, True, NULL);
  XtSetValues (tri, redwargs, 1);
}

void trianglesCallback (Widget w, XtPointer clientData, XtPointer callData)
{
  triFlag = 1;
  cirFlag = 0;
  recFlag = 0;
  
  if (shapeFlag == 0){
	shapeFlag = 1;
  	XtVaSetValues (start, XmNsensitive, True, NULL);
  }

  XtVaSetValues (tri, XmNsensitive, False, NULL);
  XtSetValues (tri, greenwargs, 1);

  XtVaSetValues (cir, XmNsensitive, True, NULL);
  XtSetValues (cir, redwargs, 1);
  XtVaSetValues (rec, XmNsensitive, True, NULL);
  XtSetValues (rec, redwargs, 1);
}
void xwindowsCallback (Widget w, XtPointer clientData, XtPointer callData)
{

  xwFlag=1;
  pyFlag=0;

  if (sysFlag == 0){
  	sysFlag=1;
  	XtVaSetValues (tri, XmNsensitive, True, NULL);
  	XtVaSetValues (cir, XmNsensitive, True, NULL);
  	XtVaSetValues (rec, XmNsensitive, True, NULL);
  }

  XtVaSetValues (xw, XmNsensitive, False, NULL);
  XtSetValues (xw, greenwargs, 1);
  XtVaSetValues (py, XmNsensitive, True, NULL);
  XtSetValues (py, redwargs, 1);
  
}
void pythonCallback (Widget w, XtPointer clientData, XtPointer callData)
{
  pyFlag=1;
  xwFlag=0;

  if (sysFlag == 0){
  	sysFlag=1;
  	XtVaSetValues (tri, XmNsensitive, True, NULL);
  	XtVaSetValues (cir, XmNsensitive, True, NULL);
  	XtVaSetValues (rec, XmNsensitive, True, NULL);
  }

  XtVaSetValues (py, XmNsensitive, False, NULL);
  XtSetValues (py, greenwargs, 1);
  XtVaSetValues (xw, XmNsensitive, True, NULL);
  XtSetValues (xw, redwargs, 1);
}
