#ifndef CELL_H
#define CELL_H

#include <QPushButton>
#include <QAction>

class QMenu;

class Cell : public QPushButton
{
    Q_OBJECT
private:
    QMenu *menu;
public:
    explicit Cell(QWidget *parent = 0);
    void setCellStyle();
public slots:
    void actionChanged(QAction *action);
};

#endif // CELL_H
