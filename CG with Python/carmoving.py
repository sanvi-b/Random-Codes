from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys
import math

WINDOW_SIZE = 500
GLOBAL_X = -400.0  
GLOBAL_Y = 0.0
MOVEMENT_SPEED = 4
direction = 'right'  
WHEEL_RADIUS = 35  
WHEEL_CIRCUMFERENCE = 2 * math.pi * WHEEL_RADIUS  
wheel_rotation_angle = 0  

def init():
    glClearColor(1.0, 1.0, 1.0, 1.0)  
    gluOrtho2D(-WINDOW_SIZE, WINDOW_SIZE, -WINDOW_SIZE, WINDOW_SIZE)  

    glDisable(GL_LIGHTING)
    glDisable(GL_LIGHT0)
    glDisable(GL_DEPTH_TEST)

def drawCircle(x, y, side, rotation_angle):
    if side == 0:
        x -= 50
        y -= 75  
    else:
        x += 50
        y -= 75  

    glColor3f(0.0, 0.0, 0.0)  
    glBegin(GL_TRIANGLE_FAN)
    glVertex2f(x, y)
    for i in range(0, 361, 1):
        glVertex2f(WHEEL_RADIUS * math.cos(math.radians(i)) + x, 
        WHEEL_RADIUS * math.sin(math.radians(i)) + y)
    glEnd()

    glPushMatrix()
    glTranslatef(x, y, 0)  
    glRotatef(rotation_angle, 0, 0, 1)  

    glColor3f(1.0, 0.0, 0.0)  
    glPointSize(3)
    glBegin(GL_POINTS)
    glVertex2f(WHEEL_RADIUS, 0)  
    glEnd()

    glColor3f(0.0, 0.0, 0.0)  
    num_spokes = 8
    for i in range(num_spokes):
        angle = i * (360 / num_spokes)
        glBegin(GL_LINES)
        glVertex2f(0, 0)  
        glVertex2f(WHEEL_RADIUS * math.cos(math.radians(angle)),
                    WHEEL_RADIUS * math.sin(math.radians(angle)))
    glEnd()

    glPopMatrix()  

def drawRectangle(x, y):
    glColor3f(0.0, 0.0, 1.0)  
    glBegin(GL_QUADS)
    glVertex2f(x - 120, y + 30)  
    glVertex2f(x + 120, y + 30) 
    glVertex2f(x + 120, y - 80) 
    glVertex2f(x - 120, y - 80) 
    glEnd()

def drawTrapezoid(x, y):
    glColor3f(1.0, 0.0, 0.0)  
    glBegin(GL_QUADS)
    glVertex2f(x - 120, y + 30)  
    glVertex2f(x + 120, y + 30)  
    glVertex2f(x + 60, y + 110)  
    glVertex2f(x - 60, y + 110) 
    glEnd()

def drawCar():
    global GLOBAL_X, GLOBAL_Y, wheel_rotation_angle

    if direction == 'up':
        angle = math.degrees(math.atan2(GLOBAL_Y, GLOBAL_X))  
    else:
        angle = 0  

    glClear(GL_COLOR_BUFFER_BIT)  

    glPushMatrix()  
    glTranslatef(GLOBAL_X, GLOBAL_Y, 0)  
    glRotatef(angle, 0, 0, 1)  

    drawRectangle(0, 0) 
    drawTrapezoid(0, 0)  
    drawCircle(0, 0, 0, wheel_rotation_angle)  
    drawCircle(0, 0, 1, wheel_rotation_angle)  

    glPopMatrix()  
    glutSwapBuffers()  

def animate(value):
    global GLOBAL_X, GLOBAL_Y, direction, wheel_rotation_angle
    
    if direction == 'right':
        if GLOBAL_X < 0:
            GLOBAL_X += MOVEMENT_SPEED  
        else:
            direction = 'up'  

    elif direction == 'up':
        if GLOBAL_X < WINDOW_SIZE and GLOBAL_Y < WINDOW_SIZE:
            GLOBAL_X += MOVEMENT_SPEED  
            GLOBAL_Y += MOVEMENT_SPEED  
        else:
            GLOBAL_X = min(GLOBAL_X, WINDOW_SIZE)
            GLOBAL_Y = min(GLOBAL_Y, WINDOW_SIZE)
    
    wheel_rotation_angle += (MOVEMENT_SPEED / WHEEL_CIRCUMFERENCE) * 360  
    if wheel_rotation_angle >= 360:
        wheel_rotation_angle -= 360  

    glutPostRedisplay()  
    glutTimerFunc(50, animate, 0)  

def keyboard(key, x, y):
    key = key.decode()
    if key == 'z': 
        glutLeaveMainLoop()  
    elif key == 'f': 
        glutFullScreen()  

def main():
    glutInit(sys.argv)
    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE)  
    glutInitWindowPosition(0, 0)  
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE) 
    glutCreateWindow("Car Animation")  
    glutDisplayFunc(drawCar) 
    glutKeyboardFunc(keyboard)  
    init()  
    glutTimerFunc(50, animate, 0)  
    glutMainLoop()  

main()