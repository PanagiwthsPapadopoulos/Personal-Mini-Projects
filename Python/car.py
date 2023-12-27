import turtle
import random
import time

wn = turtle.Screen()
wn.title("CAR")
wn.bgcolor("black")
wn.setup(width=800, height=600)
wn.tracer()




t = turtle.Turtle()
t.pensize(10)
t.speed(20)
t.shape("square")
t.shapesize(stretch_wid=3, stretch_len=7)
t.hideturtle()
t.color("white")
t.penup()
t.goto(-394,-290 )
t.left(90)
t.pendown()
t.forward(800)
t.penup()
t.goto(385, -290)
t.pendown()
t.forward(800)
t.penup()
t.goto(-134, -290)
for x in range(4):
        t.pendown()
        t.forward(110)
        t.penup()
        t.forward(50)    
t.penup()
t.goto(134, -290)
for x in range(4):
        t.pendown()
        t.forward(110)
        t.penup()
        t.forward(50)
t.color("deep pink")
t.penup()
t.goto(0, -210)
t.showturtle()
t.speed(0)
    
    
obst = turtle.Turtle()
obst.shape("square")
obst.color("brown") 
obst.penup()
obst.goto(random.randint(-370, 370), 310)
obst.speed(10)
obst.shapesize(stretch_wid=2, stretch_len=5
)
obst.dy = -3


obst1 = turtle.Turtle()
obst1.shape("square")
obst1.color("brown") 
obst1.penup()
obst1.dy = -3
obst1.goto(random.randint(-370, 370), 400)
obst1.speed(10)
obst1.shapesize(stretch_wid=2, stretch_len=5
)


obst2 = turtle.Turtle()
obst2.shape("square")
obst2.color("brown") 
obst2.penup()
obst2.goto(random.randint(-370, 370), 450)
obst2.speed(10)
obst2.shapesize(stretch_wid=2, stretch_len=5
)
obst2.dy = -3


obst3 = turtle.Turtle()
obst3.shape("square")
obst3.color("brown") 
obst3.penup()
obst3.goto(random.randint(-370, 370), 500)
obst3.speed(10)
obst3.shapesize(stretch_wid=2, stretch_len=5
)
obst3.dy = -3


obst4 = turtle.Turtle()
obst4.shape("square")
obst4.color("brown") 
obst4.penup()
obst4.goto(random.randint(-370, 370), 500)
obst4.speed(10)
obst4.shapesize(stretch_wid=2, stretch_len=5
)
obst4.dy = -3


obst5 = turtle.Turtle()
obst5.shape("square")
obst5.color("brown") 
obst5.penup()
obst5.goto(random.randint(-370, 370), 550)
obst5.speed(10)
obst5.shapesize(stretch_wid=2, stretch_len=5
)
obst5.dy = -3

score = 0
pen = turtle.Turtle()
pen.speed(0)
pen.color("white")
pen.penup()
pen.hideturtle()
pen.goto(0, 260)
pen.write(" SCORE: 0 ", align="center", font=("Courier", 24, "normal"))




def t_right():
    if(t.xcor() < 350):
        x = t.xcor()
        x += 20
        t.setx(x)

def t_left():
    if(t.xcor() > -362):
        x = t.xcor()
        x -= 20
        t.setx(x)






wn.listen()
wn.onkey(t_right, "d")
wn.onkey(t_left, "a")




while True:
    wn.update()

    obst.sety(obst.ycor() + obst.dy)
    
    if obst.ycor() < -320:
        obst.hideturtle
        obst.shapesize(stretch_wid=2, stretch_len=5)
        obst.dy=-3
        obst.goto(random.randint(-370, 370), 200)
        obst.showturtle
        score += 10
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))


    if obst.distance(t)<110: 
        time.sleep(1)
        obst.hideturtle
        t.goto(0, -210)
        obst.goto(random.randint(-370, 370), 200)
        obst.showturtle
        score = 0
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))

    if obst.ycor()<150:
        obst.shapesize(stretch_wid=3, stretch_len=7)
        obst.dy = -8

    if obst.ycor()<50:
        obst.dy = -9




    
    obst1.sety(obst1.ycor() + obst1.dy)
    
    if obst1.ycor() < -320:
        obst1.hideturtle
        obst1.shapesize(stretch_wid=2, stretch_len=5
        )
        obst1.dy=-3
        obst1.goto(random.randint(-370, 370), 200)
        obst1.showturtle
        score += 10
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))

    if obst1.distance(t)<110: 
        time.sleep(1)
        obst1.hideturtle
        t.goto(0, -210)
        obst1.goto(random.randint(-370, 370), 200)
        obst1.showturtle
        score = 0
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))

    if obst1.ycor()<150:
        obst1.shapesize(stretch_wid=3, stretch_len=7)
        obst1.dy = -8

    if obst1.ycor()<50:
        obst1.dy = -9


    


    obst2.sety(obst2.ycor() + obst2.dy)
    
    if obst2.ycor() < -320:
        obst2.hideturtle
        obst2.shapesize(stretch_wid=2, stretch_len=5
        )
        obst2.dy=-3
        obst2.goto(random.randint(-370, 370), 200)
        obst2.showturtle
        score += 10
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))


    if obst2.distance(t)<110: 
        time.sleep(1)
        obst2.hideturtle
        t.goto(0, -210)
        obst2.goto(random.randint(-370, 370), 200)
        obst2.showturtle
        score = 0
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))


    if obst2.ycor()<150:
        obst2.shapesize(stretch_wid=3, stretch_len=7)
        obst2.dy = -8

    if obst2.ycor()<50:
        obst2.dy = -9






    obst3.sety(obst3.ycor() + obst3.dy)
    
    if obst3.ycor() < -320:
        obst3.hideturtle
        obst3.shapesize(stretch_wid=2, stretch_len=5
        )
        obst3.dy=-3
        obst3.goto(random.randint(-370, 370), 200)
        obst3.showturtle
        score += 10
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))


    if obst3.distance(t)<110: 
        time.sleep(1)
        obst3.hideturtle
        t.goto(0, -210)
        obst3.goto(random.randint(-370, 370), 200)
        obst3.showturtle
        score = 0
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))

    if obst3.ycor()<150:
        obst3.shapesize(stretch_wid=3, stretch_len=7)
        obst3.dy = -8

    if obst3.ycor()<50:
        obst3.dy = -9





    obst4.sety(obst4.ycor() + obst4.dy)
    
    if obst4.ycor() < -320:
        obst4.hideturtle
        obst4.shapesize(stretch_wid=2, stretch_len=5
        )
        obst4.dy=-3
        obst4.goto(random.randint(-370, 370), 200)
        obst4.showturtle
        score += 10
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))


    if obst4.distance(t)<110: 
        time.sleep(1)
        obst4.hideturtle
        t.goto(0, -210)
        obst4.goto(random.randint(-370, 370), 200)
        obst4.showturtle
        score = 0
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))

    if obst4.ycor()<150:
        obst4.shapesize(stretch_wid=3, stretch_len=7)
        obst4.dy = -8

    if obst4.ycor()<50:
        obst4.dy = -9




    
    
    obst5.sety(obst5.ycor() + obst5.dy)
    
    if obst5.ycor() < -320:
        obst5.hideturtle
        obst5.shapesize(stretch_wid=2, stretch_len=5
        )
        obst5.dy=-3
        obst5.goto(random.randint(-370, 370), 200)
        obst5.showturtle
        score += 10
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))


    if obst5.distance(t)<110: 
        time.sleep(1)
        obst5.hideturtle
        t.goto(0, -210)
        obst5.goto(random.randint(-370, 370), 200)
        obst5.showturtle
        score = 0
        pen.clear()
        pen.write(" SCORE: {} ".format(score), align="center", font=("Courier", 24, "normal"))

    if obst5.ycor()<150:
        obst5.shapesize(stretch_wid=3, stretch_len=7)
        obst5.dy = -8

    if obst5.ycor()<50:
        obst5.dy = -9