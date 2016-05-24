import random
import math
import re
import turtle
from turtle import Turtle, mainloop
import sys

from cImage import *
import sys

class KeysMouseEvents:
	def __init__(self):
		super().__init__()
		global arg
		turtle.setup(width=600,height=400,startx=300,starty=200)
		self.T=Turtle()
		self.screen=self.T.getscreen()
		self.T.pensize(4)
		self.T.color("blue")
		if arg == '1':
			self.screen.onclick(self.drawcir)
		if arg == '2':
			self.screen.onclick(self.drawrec)
		if arg == '3':
			self.screen.onclick(self.drawtri)


		self.screen.listen()
		self.count=0
		self.first=(0,0)
		self.T.hideturtle()
		self.T.up()
		
	def drawcir(self,x,y):
		self.count = (self.count + 1) 
		if self.count == 1:
			self.firstx=x
			self.firsty=y
			self.T.goto(x,y)
			self.T.down()
			self.T.dot()
			self.T.up()
			return
		if self.count == 2:
			self.secondx=x
			self.secondy=y
			X = self.secondx - self.firstx
			Y = self.secondy - self.firsty
			d = X * X + Y * Y
			radious = math.sqrt (d);
			self.T.goto(self.firstx, self.firsty-radious)
			self.T.down()
			self.T.circle(radious)
			self.T.up()
			self.count=0

	def drawrec(self,x,y):
		self.count = (self.count + 1) 
		if self.count == 1:
			self.firstx=x
			self.firsty=y
			self.T.goto(x,y)
			self.T.down()
			self.T.dot()
			self.T.up()
			return
		if self.count == 2:
			self.secondx=x
			self.secondy=y
			self.T.goto(x,y)
			self.T.down()
			self.T.dot()
			self.T.up()
			self.count=0
			if ((self.secondx > self.firstx) and (self.secondy < self.firsty)):
				upperleft = (self.firstx, self.firsty)
			if ((self.secondx < self.firstx) and (self.secondy > self.firsty)):
				upperleft = (self.secondx, self.secondy)
			if ((self.secondx < self.firstx) and (self.secondy < self.firsty)):
				upperleft = (self.secondx, self.firsty)
			if ((self.secondx > self.firstx) and (self.secondy > self.firsty)):
				upperleft = (self.firstx, self.secondy)
			"""
			elif (self.secondy < self.firsty):
				upperleft = (self.firstx, self.secondy)
			elif (self.secondx < self.firstx):
				upperleft = (self.secondx, self.firsty)
			else: 
				upperleft = (self.firstx, self.firsty)
			"""
			width=abs (self.secondx - self.firstx)
			height=abs (self.secondy - self.firsty)
                        
			self.T.goto(upperleft)
			self.T.down()
			self.T.forward(width)
			self.T.right(90)
			self.T.forward(height)
			self.T.right(90)
			self.T.forward(width)
			self.T.right(90)
			self.T.forward(height)
			self.T.right(90)
			self.T.up()

	def drawtri(self,x,y):
		if self.count == 0:
			self.first=(x,y)
		if self.count < 3:
			self.T.goto(x,y)
			self.T.down()
			self.T.dot()
			self.count = (self.count + 1) 
		if self.count == 3:
			self.T.goto(self.first)
			self.T.up()
			self.count=0

	def main(self):
		mainloop()
	
def drawcir():
	draw=KeysMouseEvents() 
	draw.main()

def drawrec():
	draw=KeysMouseEvents() 
	draw.main()

def drawtri():
	draw=KeysMouseEvents() 
	draw.main()

if __name__ == '__main__':
        arg=sys.argv[1]
        drawcir()
        drawrec()
        drawtri()

