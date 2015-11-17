#ifndef GAMWWIDGET_H
#define GAMWWIDGET_H

#include <QWidget>
#include <QVector>
#include "gamefield.h"

class QPushButon;
class QRadioButton;

class GameWidget : public QWidget
{
    Q_OBJECT
private:
    enum {EASY = 35, MIDDLE = 30, HARD = 25};
    int gameMode;
    GameField *gameField;
    QVector< QVector<int> > numbers;
    QRadioButton *easyMode;
    QRadioButton *middleMode;
    QRadioButton *hardMode;
    QPushButton *newGameButton;
    QPushButton *resetButton;
    QPushButton *compareFieldsButton;
    void swapRows();
    void swapColumns();
    void swapRowRegion();
    void swapColumnRegion();
    void transposition();
public:
    explicit GameWidget(QWidget *parent = 0);
    void makeBaseSudokuTable();
    void fillField();
    void shuffle();
public slots:
    void newGame();
    void reset();
    void gameResult();
};

#endif // GAMWWIDGET_H
