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
