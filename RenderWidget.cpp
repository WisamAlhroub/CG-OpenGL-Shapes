//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Zein Salah, on 26.03.2021
//


#include "RenderWidget.h"
#include "Glut/glut.h"
#include <QPainter>

RenderWidget::RenderWidget(QWidget *parent) : QGLWidget(parent)
{

}


RenderWidget::~RenderWidget()
{

}


QSize RenderWidget::minimumSizeHint() const
{
    return QSize(100, 100);
}


QSize RenderWidget::sizeHint() const
{
    return QSize(600, 600);
}


void RenderWidget::initializeGL()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}


void RenderWidget::paintGL()
{
    glClearColor(0.937, 0.8901, 0.686, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    // drawing top right gradient triangle
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0); // red
        glVertex2f(380, 400);
        glColor3f(0.0, 1.0, 0.0); // green
        glVertex2f(480, 550);
        glColor3f(0.0, 0.0, 1.0); // blue
        glVertex2f(580, 400);
    glEnd();

    // drawing bottom right 5-points polygon
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 1.0);   // blue
        glVertex2f(350, 100);
        glVertex2f(500, 100);
        glVertex2f(550, 250);
        glVertex2f(425, 350);
        glVertex2f(300, 250);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(350, 150);
        glVertex2f(500, 150);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(420, 215);
        
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(350, 150);
        glVertex2f(420, 300);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(420, 215);

        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(500, 150);
        glVertex2f(420, 300);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(420, 215);
    glEnd();

    // drawing top left square
    glBegin(GL_QUADS);  
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(10, 300);
        glColor3f(0.2, 0.2, 0.2);
        glVertex2f(300, 300);   
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(300, 580);
        glColor3f(0.2, 0.2, 0.2);
        glVertex2f(10, 580);
    glEnd();

    // drawing yellow triangle
    glBegin(GL_TRIANGLES);
        glColor3f(0.996, 0.949, 0);
        glVertex2f(100, 200);
        glVertex2f(100, 350);
        glVertex2f(250, 200);
    glEnd();

    glFlush();
}


void RenderWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

//    glViewport(0, 0, width, height);
}


