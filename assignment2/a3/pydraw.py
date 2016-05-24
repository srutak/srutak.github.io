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
			radious = math.sqrt (d);
			self.T.goto(self.firstx, self.firsty-radious)
			self.T.down()
			self.T.circle(radious)
			self.T.up()


			c = random.randint(1, 4)
			if c == 1:
				self.T.color("red")
			if c == 2:
				self.T.color("green")
			if c == 3:
				self.T.color("blue")
			if c == 4:
				self.T.color("yellow")

			self.T.begin_fill()
			radious=radious-4
			self.T.goto(self.firstx, self.firsty-radious)
			self.T.down()
			self.T.circle(radious)
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

drawcir()
