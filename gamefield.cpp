#include <QtWidgets>
#include "gamefield.h"

GameField::GameField(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    for(int i = 0; i < GameField::ROW_SIZE; i++)
    {
        QVector<Cell*> temp;
        QHBoxLayout *hLayout = new QHBoxLayout();
        for(int j = 0; j < GameField::ROW_SIZE; j++)
        {
            Cell *cell = new Cell();
            hLayout->addWidget(cell);
            temp.push_back(cell);
        }
        field.push_back(temp);
        mainLayout->addLayout(hLayout);
    }
    setLayout(mainLayout);
    setFixedSize(400,400);
}

void GameField::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QColor(255,0,0),4,Qt::SolidLine));
    painter.drawLine(QPoint(138,11),QPoint(138,392));
    painter.drawLine(QPoint(266,11),QPoint(266,392));
    painter.drawLine(QPoint(11,138),QPoint(392,138));
    painter.drawLine(QPoint(11,266),QPoint(392,266));
}


void GameField::setCellValue(int row,int column,int value)
{
    field[row][column]->setText(QString::number(value));
}

void GameField::setEnabledCell(int row, int column)
{
    field[row][column]->setEnabled(false);
}

void GameField::resetState()
{
    for(int i = 0; i < GameField::ROW_SIZE; i++)
    {
        for(int j = 0; j < GameField::ROW_SIZE; j++)
        {
            field[i][j]->setEnabled(true);
            field[i][j]->setText("");
        }
    }
}

void GameField::resetField()
{
    for(int i = 0; i < GameField::ROW_SIZE; i++)
    {
        for(int j = 0; j < GameField::ROW_SIZE; j++)
        {
            if(field[i][j]->isEnabled())
            {
                field[i][j]->setText("");
            }
        }
    }
}

int GameField::getCellValue(int row, int column)const
{
    return field[row][column]->text().toInt();
}

void GameField::setDisabledField()
{
    for(int i = 0; i < GameField::ROW_SIZE; i++)
    {
        for(int j = 0; j < GameField::ROW_SIZE; j++)
        {
            field[i][j]->setEnabled(false);
        }
    }
}
