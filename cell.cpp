#include "cell.h"
#include <stdio.h>

Cell::Cell()
{
    this->setFixedSize(QSize(37,37));
}

Cell::~Cell()
{

}


void Cell::mousePressEvent(QMouseEvent* e){
    if(e->button() == Qt::LeftButton){
        emit mouseButton("Left");
    }else if(e->button() == Qt::RightButton){
        emit mouseButton("Right");
    }
}

