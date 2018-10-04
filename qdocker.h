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

#ifndef QDOCKER_H
#define QDOCKER_H

#include <QWidget>

class QDocker
{
public:
    enum HorizontalPos {
      HorizontalRight,
      HorizontalCenter,
      HorizontalLeft,
    };

    enum VerticalPos {
      VerticalTop,
      VerticalCenter,
      VerticalBottom,
    };

    QDocker();
    QDocker(int distance);
    ~QDocker();

    int getDistance();
    void setDistance(int distance);

    // for dynamic allocated widgets

    void dockAbove(QWidget* qw, QWidget* anchor_widget,
                   HorizontalPos pos, int distance = 20);

    void dockBelow(QWidget* qw, QWidget* anchor_widget,
                   HorizontalPos pos, int distance = 20);

    void dockLeft(QWidget* qw, QWidget* anchor_widget,
                  VerticalPos pos, int distance = 20);

    void dockRight(QWidget* qw, QWidget* anchor_widget,
                   VerticalPos pos, int distance = 20);

    // for stack based widgets

     void dockAbove(QWidget& qw, QWidget& anchor_widget,
                   HorizontalPos pos, int distance = 20);

    void dockBelow(QWidget& qw, QWidget& anchor_widget,
                   HorizontalPos pos, int distance = 20);

    void dockLeft(QWidget& qw, QWidget& anchor_widget,
                  VerticalPos pos, int distance = 20);

    void dockRight(QWidget& qw, QWidget& anchor_widget,
                   VerticalPos pos, int distance = 20);

private:

    int m_distance = 0;

    // dynamic
    void resizeHorizontal(QWidget* qw, QWidget* qaw, HorizontalPos& pos);
    void resizeVertical(QWidget* qw, QWidget* qaw, VerticalPos& pos);

    //stack
    void resizeHorizontal(QWidget& qw, QWidget& qaw, HorizontalPos& pos);
    void resizeVertical(QWidget& qw, QWidget& qaw, VerticalPos& pos);

};

#endif // QDOCKER_H
