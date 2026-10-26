import turtle
from random import randint

STEP = 10

pen = turtle.Turtle()
paper = turtle.Screen()
pen.speed(0)

def one_step():
    dir = randint(0,3)
    pen.setheading(dir*90)
    pen.forward(STEP)

for _ in range(1,1000):
    one_step()

paper.exitonclick()