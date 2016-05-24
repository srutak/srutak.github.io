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
void xwindowsCallback (Widget w, XtPointer clientData, XtPointer callData);
void pythonCallback (Widget w, XtPointer clientData, XtPointer callData);
Widget shell, panel, topLabel, XwPy, startEnd, quitControl;
Widget quit, yes, no, start, end, xw, py, topLabel; 
Widget Dum1, Dum2; 
int xwFlag = 0;
int pyFlag = 0;
int startFlag = 0;
int endFlag = 0;
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
  char *msg="  Draw Randomly Colored Figures   ";
  XmString       xmstr;
  if (putenv ("XENVIRONMENT=drawRCC.color") < 0)
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
  startEnd = XtVaCreateManagedWidget ("startEnd", xmRowColumnWidgetClass,
			     panel, XmNnumColumns, 3,
			     XmNorientation, XmHORIZONTAL,
			     XmNtopAttachment, XmATTACH_WIDGET, XmNtopWidget, XwPy,
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
  yes = XtCreateManagedWidget  ("  Yes    ", xmPushButtonWidgetClass, quitControl, NULL, 0);
  quit = XtCreateManagedWidget ("  Quit  ", xmPushButtonWidgetClass, quitControl, NULL, 0);
  no = XtCreateManagedWidget   ("    No ", xmPushButtonWidgetClass, quitControl, NULL, 0);
  start = XtCreateManagedWidget(" End XWindows ", xmPushButtonWidgetClass, startEnd, NULL, 0);
  Dum1 = XtCreateManagedWidget ("               ", xmPushButtonWidgetClass, startEnd, NULL, 0);
  end = XtCreateManagedWidget  ("  End Python  ", xmPushButtonWidgetClass, startEnd, NULL, 0);
  xw = XtCreateManagedWidget   ("Start Xwindows", xmPushButtonWidgetClass, XwPy, NULL, 0);
  Dum2 = XtCreateManagedWidget ("               ", xmPushButtonWidgetClass, XwPy, NULL, 0);
  py = XtCreateManagedWidget   (" Start Python ", xmPushButtonWidgetClass, XwPy, NULL, 0);
  XtAddCallback (quit, XmNactivateCallback, quitCallback, NULL);
  XtAddCallback (yes, XmNactivateCallback, yesCallback, NULL);
  XtAddCallback (no, XmNactivateCallback, noCallback, NULL);
  XtAddCallback (start, XmNactivateCallback, startCallback, NULL);
  XtAddCallback (end, XmNactivateCallback, endCallback, NULL);
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
  XtSetValues (xw, greenwargs, 1);
  XtSetValues (py, greenwargs, 1);
  XtSetValues (start, redwargs, 1);
  XtSetValues (end, redwargs, 1);




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
  XtVaSetValues (xw, XmNsensitive, True, NULL);
       xwFlag = 0;
       XtSetValues (xw, greenwargs, 1);
       system("pkill -9 xwdraw");
       XtSetValues (start, redwargs, 1);
}
void endCallback (Widget w, XtPointer clientData, XtPointer callData)
{
  XtVaSetValues (end, XmNsensitive, False, NULL);
  XtVaSetValues (py, XmNsensitive, True, NULL);
	pyFlag = 0;
        XtSetValues (py, greenwargs, 1);
	system ("pkill -9 python");
        XtSetValues (end, redwargs, 1);
}
void xwindowsCallback (Widget w, XtPointer clientData, XtPointer callData)
{
  xwFlag=1;
  pyFlag=0;
  XtVaSetValues (xw, XmNsensitive, False, NULL);
  XtSetValues (xw, redwargs, 1);
  XtVaSetValues (start, XmNsensitive, True, NULL);
  system("./xwdraw 2 &");
  XtSetValues (start, greenwargs, 1);
}
void pythonCallback (Widget w, XtPointer clientData, XtPointer callData)
{
  pyFlag=1;
  xwFlag=0;
  XtVaSetValues (py, XmNsensitive, False, NULL);
  XtSetValues (py, redwargs, 1);
  XtVaSetValues (end, XmNsensitive, True, NULL);
  XtSetValues (end, greenwargs, 1);
  system("/usr/bin/python3 pydraw.pyo &");

}

