# QDocker
[![AppVeyor Status](https://ci.appveyor.com/api/projects/status/github/leethomason/tinyxml2?branch=master&svg=true)](https://ci.appveyor.com/project/Shadowsith/qdocker)

<img src="./img/qdocker.png"></img>

---

QDocker is a small qt library to dock a widget object to another 'anchor' widget object.

* Uses only QWidget class
* Available for all classes which inherits form QWidget
* Can be used for dynamic allocated and stack objects

## Features

Docking all UI elements which are inheriting form QWidget to each other:
* Above
* Below
* Left
* Right

Align the widgets in connection with docking to the following positions:

On docking below/above
* Horizontal:
    * Left
    * Right
    * Center

On docking left/right
* Vertical:
    * Top
    * Bottom
    * Center

Check if the widgets have the same horizontal or vertical state

## Installation

Add qdocker.h and qdocker.cpp to your project and <code>#include "qdocker.h"</code><br>
I also recommend to add the project's license to your source code to  avoid copyright problems. 

## Usage
```
QDocker qd; // create default QDocker object with docking distance of 20 
QDocker qd(40); // QDocker object has default distance of 40
qd.getDistance(); // get the current distance
qd.setDistance(); // set another default distance

qd.dockBelow(widget1, widget2, qd.AlignLeft); // docks widget1 left-aligned below widget2  
qd.dockAbove(widget1, widget2, qd.AlignRight); // docks widget1 right-aligned above widget2  

qd.dockLeft(widget1, widget2, qd.AlignTop); // docks widget1 left from widget2 (top edge)
qd.dockRight(widget1, widget2, qd.AlignBottom, 30); // docks widget1 right from widget2 (lower edge) with distance 30

// check if the widgets start at the same horizontal X-Position (left aligned)
bool status = qd.isDocked(widget1, widget2, qd.AlignLeft); 
```

## Example
```cpp
#include "testwindow.h"
#include "ui_testwindow.h"
#include "qdocker.h"
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QTextEdit>
#include <QCheckBox>

TestWindow::TestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    this->resize(400,400);
    QDocker qd; // QDocker with standard distance of 20

    QLineEdit* le1 = new QLineEdit(ui->centralWidget);
    le1->move(20,30);
    le1->resize(150, 20);

    QLabel* desc = new QLabel(ui->centralWidget);
    desc->resize(200,20);
    desc->setText("UI setup with QDocker:");
    qd.dockAbove(desc, le1, qd.AlignLeft, 10);

    QLineEdit* le2 = new QLineEdit(ui->centralWidget);
    le2->resize(100, 20);
    qd.dockBelow(le2, le1, qd.AlignLeft);

    QLineEdit* le3 = new QLineEdit(ui->centralWidget);
    le3->resize(150,20);
    qd.dockRight(le3, le1, qd.AlignTop);

    QTextEdit* te = new QTextEdit(ui->centralWidget);
    te->resize(200, 200);
    qd.setDistance(40);
    qd.dockBelow(te, le2, qd.AlignLeft);

    QLabel *lbl = new QLabel(ui->centralWidget);
    lbl->resize(100, 20);
    lbl->setText("Example:");
    lbl->setAlignment(Qt::AlignRight);
    qd.setDistance(20);
    qd.dockRight(lbl, te, qd.AlignTop);

    QLineEdit* le4 = new QLineEdit(ui->centralWidget);
    le4->resize(100, 20);
    qd.dockBelow(le4, lbl, qd.AlignRight);

    QCheckBox* cb = new QCheckBox(ui->centralWidget);
    cb->setText("Checkbox:");
    cb->resize(100,20);
    qd.dockRight(cb, te, qd.AlignVCenter);
}
```

## Issues
* If a new instance of a widget object has not get a value for width/height QDocker has
  strange behaviors

## Why I have not used Qt::AlignmentFlag
* to much values that I have not used
* HorizontalPos and VerticalPos in QDocker class capsules it better for the situtation
* incorrect input can be checked by IDE linters
* to keep the Qt coding standards as good as possible the alignment flags have the same
  name as in Qt::AlignmentFlag

## License
LGPL

For commecial use and incompatible open-source licenses I recommend to use the
library only with dynamic linking. 
