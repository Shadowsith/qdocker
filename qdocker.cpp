/*
Project:        QDocker 
Description:    A Qt library to dock easily a qt widget to another 
Author:         Philip Mayer (Shadowsith) <philip.mayer@shadowsith.de>
Copyright:      2018 Philip Mayer
License:        LGPLv3+

This file is part of QDocker.

QDocker is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

QDocker is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with QDocker.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "qdocker.h"
#include <QWidget>

QDocker::QDocker() {
    m_distance = 20;
}

QDocker::QDocker(int distance) {
    m_distance = distance;
}

QDocker::~QDocker() {}

// private

void QDocker::resizeHorizontal(QWidget* qw, QWidget* qaw, HorizontalPos& pos) {
    switch (pos) {
        case HorizontalLeft: break;

        case HorizontalRight: {
            qw->move(qaw->x()+qaw->width()-qw->width(), qw->y());
        } break;

        case HorizontalCenter: {
            qw->move(qaw->x()+qaw->width()/2-qw->width()/2, qw->y());
        } break;
    }
}

void QDocker::resizeHorizontal(QWidget& qw, QWidget& qaw, HorizontalPos& pos) {
    switch (pos) {
        case HorizontalLeft: break;

        case HorizontalRight: {
            qw.move(qaw.x()+qaw.width()-qw.width(), qw.y());
        } break;

        case HorizontalCenter: {
            qw.move(qaw.x()+qaw.width()/2-qw.width()/2, qw.y());
        } break;
    }
}

void QDocker::resizeVertical(QWidget* qw, QWidget* qaw, VerticalPos& pos) {
    switch (pos) {
        case VerticalTop: break;

        case VerticalBottom: {
            qw->move(qw->x(), qaw->y()+qaw->height()-qw->height());
        } break;

        case VerticalCenter: {
            qw->move(qw->x(), qaw->y()+qaw->height()/2-qw->height()/2);
        } break;
    }
}

void QDocker::resizeVertical(QWidget& qw, QWidget& qaw, VerticalPos& pos) {
    switch (pos) {
        case VerticalTop: break;

        case VerticalBottom: {
            qw.move(qw.x(), qaw.y()+qaw.height()-qw.height());
        } break;

        case VerticalCenter: {
            qw.move(qw.x(), qaw.y()-qaw.height()/2-qw.height()/2);
        } break;
    }
}

// public

int QDocker::getDistance() {
    return m_distance;
}

void QDocker::setDistance(int distance) {
    m_distance = distance;
}

// for dynamic allocated widgets

void QDocker::dockAbove(QWidget* qw, QWidget* qaw,
                   HorizontalPos pos, int distance)
{
    if(distance == 0) distance = m_distance;
    qw->move(qaw->x(), qaw->y()-qaw->height()-distance);
    resizeHorizontal(qw, qaw, pos);

}

void QDocker::dockBelow(QWidget* qw, QWidget* qaw,
                        HorizontalPos pos, int distance)
{
    if(distance == 0) distance = m_distance;
    qw->move(qaw->x(), qaw->y()+qaw->height()+distance);
    resizeHorizontal(qw, qaw, pos);
}

void QDocker::dockLeft(QWidget* qw, QWidget* qaw,
                  VerticalPos pos, int distance)
{
    if(distance == 0) distance = m_distance;
    qw->move(qaw->x()-qw->width()-distance, qaw->y());
    resizeVertical(qw, qaw, pos);
}

void QDocker::dockRight(QWidget* qw, QWidget* qaw,
                  VerticalPos pos, int distance)
{
    if(distance == 0) distance = m_distance;
    qw->move(qaw->x()+qaw->width()+distance, qaw->y());
    resizeVertical(qw, qaw, pos);
}

bool QDocker::isDocked(QWidget* qw, QWidget* qaw, HorizontalPos pos) {
    switch(pos) {
        case HorizontalLeft: {
            return qw->x() == qaw->x();
        }
        case HorizontalCenter: {
            return qw->x() == qaw->x()+qaw->width()/2-qw->width()/2;
        }
        case HorizontalRight: {
            return qw->x() == (qaw->x()+qaw->width());
        }
    } return 0;
}

bool QDocker::isDocked(QWidget* qw, QWidget* qaw, VerticalPos pos) {
     switch(pos) {
        case VerticalTop: {
            return qw->y() == qaw->y();
        }
        case VerticalCenter: {
            return qw->y() == (qaw->y()+qaw->height()/2-qw->height()/2);
        }
        case VerticalBottom: {
            return qw->y() == (qaw->y()+qaw->height()-qw->height());
        }
    } return 0;
}

// for stack based widgets

void QDocker::dockAbove(QWidget& qw, QWidget& qaw,
                   HorizontalPos pos, int distance)
{
    if(distance == 0) distance = m_distance;
    qw.move(qaw.x(), qaw.y()-qaw.height()-distance);
    resizeHorizontal(qw, qaw, pos);
}

void QDocker::dockBelow(QWidget& qw, QWidget& qaw,
                        HorizontalPos pos, int distance)
{
    if(distance == 0) distance = m_distance;
    qw.move(qaw.x(), qaw.y()+qaw.height()+distance);
    resizeHorizontal(qw, qaw, pos);
}

void QDocker::dockLeft(QWidget& qw, QWidget& qaw,
                  VerticalPos pos, int distance)
{
    if(distance == 0) distance = m_distance;
    qw.move(qaw.x()-qw.width()-distance, qaw.y());
    resizeVertical(qw, qaw, pos);
}

void QDocker::dockRight(QWidget& qw, QWidget& qaw,
                  VerticalPos pos, int distance)
{
    if(distance == 0) distance = m_distance;
    qw.move(qaw.x()+qaw.width()+distance, qaw.y());
    resizeVertical(qw, qaw, pos);
}

bool QDocker::isDocked(QWidget& qw, QWidget& qaw, HorizontalPos pos) {
    switch(pos) {
        case HorizontalLeft: {
            return qw.x() == qaw.x();
        }
        case HorizontalCenter: {
            return qw.x() == qaw.x()+qaw.width()/2-qw.width()/2;
        }
        case HorizontalRight: {
            return qw.x() == (qaw.x()+qaw.width());
        }
    } return 0;
}

bool QDocker::isDocked(QWidget& qw, QWidget& qaw, VerticalPos pos) {
     switch(pos) {
        case VerticalTop: {
            return qw.y() == qaw.y();
        }
        case VerticalCenter: {
            return qw.y() == (qaw.y()+qaw.height()/2-qw.height()/2);
        }
        case VerticalBottom: {
            return qw.y() == (qaw.y()+qaw.height()-qw.height());
        }
    } return 0;
}

