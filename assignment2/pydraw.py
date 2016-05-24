import random
import math
import re
import turtle
from turtle import Turtle, mainloop
import sys

from cImage import *

class KeysMouseEvents:
	def __init__(self):
		super().__init__()
		self.reinit()

	def reinit(self):
		self.T=Turtle()
		self.screen=self.T.getscreen()
		self.screen.onclick(self.drawcir)
		self.screen.onkey(self.clear,"c")
		self.T.pensize(5)
		self.screen.listen()
		self.count=0
		self.firstx=0
		self.firsty=0
		self.secondx=0
		self.secondy=0
		self.T.hideturtle()
		self.T.up()

	def clear(self):
		self.T.screen.clear()
		self.reinit()

	def drawcir(self,x,y):
		self.count = (self.count + 1) 
		if self.count == 1:
			self.T.color("black")
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
			
			self.T.color("black")
			
			radius = math.sqrt (d);
			len = math.sqrt (2*radius*radius)
			a = len/2
			b = math.sqrt((radius*radius)-(a*a))
			self.T.goto(self.firstx-radius, self.firsty+radius)
			self.T.down()
			width = 2*radius
			height = 2*radius
			self.T.speed(0)
			self.T.forward(width)
			self.T.right(90)
			self.T.forward(height)
			self.T.right(90)
			self.T.forward(width)
			self.T.right(90)
			self.T.forward(height)
			self.T.right(90)
			self.T.up()

			x = random.randint(1, 7)
			c = x
			if c == 1:
				self.T.color("red")
			if c == 2:
				self.T.color("green")
			if c == 3:
				self.T.color("blue")
			if c == 4:
				self.T.color("yellow")
			if c == 5:
				self.T.color("white")
			if c == 6:
				self.T.color("pink")
			if c == 7:
				self.T.color("brown")
			if c == 8:
				self.T.color("purple")
			if c == 9:
				self.T.color("gray")
			if c == 10:
				self.T.color("orange")
			self.T.begin_fill()
			radius1=radius-4
			self.T.goto(self.firstx-radius1, self.firsty+radius1)
			self.T.down()
			width = 2*radius1
			height = 2*radius1
			self.T.speed(0)
			self.T.forward(width)
			self.T.right(90)
			self.T.forward(height)
			self.T.right(90)
			self.T.forward(width)
			self.T.right(90)
			self.T.forward(height)
			self.T.right(90)
			self.T.up()
			self.T.end_fill()
			self.T.up()
			self.T.color("black")
			self.T.goto(self.firstx, self.firsty-radius)
			self.T.down()
			self.T.circle(radius)
			self.T.up()

			c = x+1
			if c == 1:
				self.T.color("red")
			if c == 2:
				self.T.color("green")
			if c == 3:
				self.T.color("blue")
			if c == 4:
				self.T.color("yellow")
			if c == 5:
				self.T.color("white")
			if c == 6:
				self.T.color("pink")
			if c == 7:
				self.T.color("brown")
			if c == 8:
				self.T.color("purple")
			if c == 9:
				self.T.color("gray")
			if c == 10:
				self.T.color("orange")

			self.T.begin_fill()
			radius=radius-4
			self.T.goto(self.firstx, self.firsty-radius)
			self.T.speed(0)
			self.T.down()
			self.T.circle(radius)
			self.T.end_fill()
			self.T.up()
			self.T.color("black")
			self.T.goto(self.firstx-b, self.firsty+b)
			self.T.down()
			width = 2*b
			height = 2*b
			self.T.forward(width)
			self.T.right(90)
			self.T.forward(height)
			self.T.right(90)
			self.T.forward(width)
			self.T.right(90)
			self.T.forward(height)
			self.T.right(90)
			self.T.up()
			c = x+2
			if c == 1:
				self.T.color("red")
			if c == 2:
				self.T.color("green")
			if c == 3:
				self.T.color("blue")
			if c == 4:
				self.T.color("yellow")
			if c == 5:
				self.T.color("white")
			if c == 6:
				self.T.color("pink")
			if c == 7:
				self.T.color("brown")
			if c == 8:
				self.T.color("purple")
			if c == 9:
				self.T.color("gray")
			if c == 10:
				self.T.color("orange")
			self.T.begin_fill()
			b1=b-4
			self.T.goto(self.firstx-b1, self.firsty+b1)
			self.T.down()
			width = 2*b1
			height = 2*b1
			self.T.speed(0)
			self.T.forward(width)
			self.T.right(90)
			self.T.forward(height)
			self.T.right(90)
			self.T.forward(width)
			self.T.right(90)
			self.T.forward(height)
			self.T.right(90)
			self.T.up()
			self.T.end_fill()
			self.T.up()
			self.T.color("black")
			self.T.goto(self.firstx,self.firsty)
			self.T.down()
			self.T.dot()
			self.T.up()

			self.count=0
	def main(self):
		mainloop()
	
def drawcir():
	draw=KeysMouseEvents() 
	draw.main()
if __name__ == '__main__':

	drawcir()