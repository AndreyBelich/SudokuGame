#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include <QVector>
#include "cell.h"

class GameField : public QWidget
{
    Q_OBJECT
private:
    QVector< QVector<Cell*> > field;
public:
    static const int ROW_SIZE = 9;
    explicit GameField(QWidget *parent = 0);
    void setCellValue(int row,int column,int value);
    void setEnabledCell(int row, int column);
    void resetState();
    void resetField();
    void setDisabledField();
    int getCellValue(int row, int column)const;
protected:
    virtual void paintEvent(QPaintEvent *);
};

#endif // GAMEFIELD_H
