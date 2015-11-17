#include <QtWidgets>
#include "cell.h"

Cell::Cell(QWidget *parent) : QPushButton(parent)
{
    setFixedSize(40,40);
    menu = new QMenu();
    for(int i = 0; i < 10; i++)
    {
        QAction *action = new QAction(QString::number(i),this);
        menu->addAction(action);
    }
    setMenu(menu);
    connect(menu,SIGNAL(triggered(QAction*)),this,SLOT(actionChanged(QAction*)));
    setCellStyle();
}

void Cell::actionChanged(QAction *action)
{
    QString text = action->text();
    if(text == "0")
    {
        setText("");
    }
    else
    {
        setText(text);
    }
}

void Cell::setCellStyle()
{
    setStyleSheet("Cell{background:#999999;color:#000000;};");
}
