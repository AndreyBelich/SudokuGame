#include <QtWidgets>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent) : QWidget(parent),gameMode(GameWidget::EASY)
{
    srand((unsigned)(time(0)));
    for(int i = 0; i < GameField::ROW_SIZE; i++)
    {
        QVector<int> temp(GameField::ROW_SIZE);
        numbers.push_back(temp);
    }
    gameField = new GameField();
    easyMode = new QRadioButton(tr("Легкий уровень"));
    easyMode->setChecked(true);
    middleMode = new QRadioButton(tr("Средний уровень"));
    hardMode = new QRadioButton(tr("Тяжелый уровень"));
    newGameButton = new QPushButton(tr("Новая игра"));
    resetButton = new QPushButton(tr("Сброс"));
    compareFieldsButton = new QPushButton(tr("Проверить решение"));

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(easyMode,0,0);
    gridLayout->addWidget(newGameButton,0,1);
    gridLayout->addWidget(middleMode,1,0);
    gridLayout->addWidget(resetButton,1,1);
    gridLayout->addWidget(hardMode,2,0);
    gridLayout->addWidget(compareFieldsButton,2,1);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(gameField);
    mainLayout->addLayout(gridLayout);
    setLayout(mainLayout);
    setWindowTitle(tr("Игра Судоку"));
    QPixmap applicationIcon(":/image/titleIcon");
    setWindowIcon(applicationIcon);
    makeBaseSudokuTable();
    shuffle();
    fillField();

    connect(newGameButton,SIGNAL(clicked(bool)),this,SLOT(newGame()));
    connect(resetButton,SIGNAL(clicked(bool)),this,SLOT(reset()));
    connect(compareFieldsButton,SIGNAL(clicked(bool)),this,SLOT(gameResult()));
}

void GameWidget::makeBaseSudokuTable()
{
    QVector<int> numberLine = {1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < GameField::ROW_SIZE; i++)
    {
        if(i > 0)
        {
            if(i % 3 == 0)
            {
                std::rotate(numberLine.begin(),numberLine.begin() + 4,numberLine.end());
            }
            else
            {
                std::rotate(numberLine.begin(),numberLine.begin() + 3,numberLine.end());
            }
        }
        for(int j = 0; j < numberLine.size(); j++)
        {
            numbers[i][j] = numberLine[j];
        }
    }
}

void GameWidget::fillField()
{
    gameField->resetState();
    int maxVisibleCells = 0;
    if(easyMode->isChecked())
    {
        gameMode = GameWidget::EASY;
        maxVisibleCells = GameWidget::EASY;
    }
    else if(middleMode->isChecked())
    {
        gameMode = GameWidget::MIDDLE;
        maxVisibleCells = GameWidget::MIDDLE;
    }
    else if(hardMode->isChecked())
    {
        gameMode = GameWidget::HARD;
        maxVisibleCells = GameWidget::HARD;
    }
    int tempArray[GameField::ROW_SIZE] = {0};
    int sumElementsOfArray = 0;
    while(true)
    {
        sumElementsOfArray = 0;
        for(int i = 0; i < GameField::ROW_SIZE; i++)
        {
            tempArray[i] = rand() % 6;
            sumElementsOfArray += tempArray[i];
        }
        if(sumElementsOfArray == maxVisibleCells)
        {
            break;
        }
    }
    QVector<int> numbArray = {0,1,2,3,4,5,6,7,8};
    for(int i = 0; i < GameField::ROW_SIZE; i++)
    {
        std::random_shuffle(numbArray.begin(),numbArray.end());
        for(int j = 0; j < tempArray[i]; j++)
        {
            gameField->setCellValue(i,numbArray[j],numbers[i][numbArray[j]]);
            gameField->setEnabledCell(i,numbArray[j]);
        }
    }
}

void GameWidget::swapRows()
{
    int firstRow = rand() % GameField::ROW_SIZE;
    int secondRow = 0;
    int coin = rand() % 2;
    switch(firstRow)
    {
    case 0:
        if(coin == 0)
        {
            secondRow = firstRow + 1;
        }
        else
        {
            secondRow = firstRow + 2;
        }
        break;
    case 1:
        if(coin == 0)
        {
            secondRow = firstRow - 1;
        }
        else
        {
            secondRow = firstRow + 1;
        }
        break;
    case 2:
        if(coin == 0)
        {
            secondRow = firstRow - 1;
        }
        else
        {
            secondRow = firstRow - 2;
        }
        break;
    case 3:
        if(coin == 0)
        {
            secondRow = firstRow + 1;
        }
        else
        {
            secondRow = firstRow + 2;
        }
        break;
    case 4:
        if(coin == 0)
        {
            secondRow = firstRow - 1;
        }
        else
        {
            secondRow = firstRow + 1;
        }
        break;
    case 5:
        if(coin == 0)
        {
            secondRow = firstRow - 1;
        }
        else
        {
            secondRow = firstRow - 2;
        }
        break;
    case 6:
        if(coin == 0)
        {
            secondRow = firstRow + 1;
        }
        else
        {
            secondRow = firstRow + 2;
        }
        break;
    case 7:
        if(coin == 0)
        {
            secondRow = firstRow - 1;
        }
        else
        {
            secondRow = firstRow + 1;
        }
        break;
    case 8:
        if(coin == 0)
        {
            secondRow = firstRow - 1;
        }
        else
        {
            secondRow = firstRow - 2;
        }
        break;
    default:
        break;
    }
    for(int i = 0; i < GameField::ROW_SIZE; i++)
    {
        int temp = numbers[firstRow][i];
        numbers[firstRow][i] = numbers[secondRow][i];
        numbers[secondRow][i] = temp;
    }
}

void GameWidget::swapColumns()
{
    int firstColumn = rand() % GameField::ROW_SIZE;
    int secondColumn = 0;
    int coin = rand() % 2;
    switch(firstColumn)
    {
    case 0:
        if(coin == 0)
        {
            secondColumn = firstColumn + 1;
        }
        else
        {
            secondColumn = firstColumn + 2;
        }
        break;
    case 1:
        if(coin == 0)
        {
            secondColumn = firstColumn - 1;
        }
        else
        {
            secondColumn = firstColumn + 1;
        }
        break;
    case 2:
        if(coin == 0)
        {
            secondColumn = firstColumn - 1;
        }
        else
        {
            secondColumn = firstColumn - 2;
        }
        break;
    case 3:
        if(coin == 0)
        {
            secondColumn = firstColumn + 1;
        }
        else
        {
            secondColumn = firstColumn + 2;
        }
        break;
    case 4:
        if(coin == 0)
        {
            secondColumn = firstColumn - 1;
        }
        else
        {
            secondColumn = firstColumn + 1;
        }
        break;
    case 5:
        if(coin == 0)
        {
            secondColumn = firstColumn - 1;
        }
        else
        {
            secondColumn = firstColumn - 2;
        }
        break;
    case 6:
        if(coin == 0)
        {
            secondColumn = firstColumn + 1;
        }
        else
        {
            secondColumn = firstColumn + 2;
        }
        break;
    case 7:
        if(coin == 0)
        {
            secondColumn = firstColumn - 1;
        }
        else
        {
            secondColumn = firstColumn + 1;
        }
        break;
    case 8:
        if(coin == 0)
        {
            secondColumn = firstColumn - 1;
        }
        else
        {
            secondColumn = firstColumn - 2;
        }
        break;
    }
    for(int i = 0; i < GameField::ROW_SIZE; i++)
    {
        int temp = numbers[i][firstColumn];
        numbers[i][firstColumn] = numbers[i][secondColumn];
        numbers[i][secondColumn] = temp;
    }
}

void GameWidget::swapRowRegion()
{
    int region = rand() % 3;
    int coin = rand() % 2;
    int firstRegionPosition = 0;
    int secondRegionPosition = 0;
    switch(region)
    {
    case 0:
        if(coin == 0)
        {
            firstRegionPosition = 0;
            secondRegionPosition = 3;
        }
        else
        {
            firstRegionPosition = 0;
            secondRegionPosition = 6;
        }
        break;
    case 1:
        if(coin == 0)
        {
            firstRegionPosition = 3;
            secondRegionPosition = 0;
        }
        else
        {
            firstRegionPosition = 3;
            secondRegionPosition = 6;
        }
        break;
    case 2:
        if(coin == 0)
        {
            firstRegionPosition = 6;
            secondRegionPosition = 0;
        }
        else
        {
            firstRegionPosition = 6;
            secondRegionPosition = 3;
        }
        break;
    default:
        break;
    }
    int rowInRegion = GameField::ROW_SIZE / 3;
    for(int i = 0; i < rowInRegion; i++)
    {
        for(int j = 0; j < GameField::ROW_SIZE; j++)
        {
            int temp = numbers[firstRegionPosition + i][j];
            numbers[firstRegionPosition + i][j] = numbers[secondRegionPosition + i][j];
            numbers[secondRegionPosition + i][j] = temp;
        }
    }
}

void GameWidget::swapColumnRegion()
{
    int region = rand() % 3;
    int coin = rand() % 2;
    int firstRegionPosition = 0;
    int secondRegionPosition = 0;
    switch(region)
    {
    case 0:
        if(coin == 0)
        {
            firstRegionPosition = 0;
            secondRegionPosition = 3;
        }
        else
        {
            firstRegionPosition = 0;
            secondRegionPosition = 6;
        }
        break;
    case 1:
        if(coin == 0)
        {
            firstRegionPosition = 3;
            secondRegionPosition = 0;
        }
        else
        {
            firstRegionPosition = 3;
            secondRegionPosition = 6;
        }
        break;
    case 2:
        if(coin == 0)
        {
            firstRegionPosition = 6;
            secondRegionPosition = 0;
        }
        else
        {
            firstRegionPosition = 6;
            secondRegionPosition = 3;
        }
        break;
    default:
        break;
    }
    int columnInRegion = GameField::ROW_SIZE / 3;
    for(int i = 0; i < columnInRegion; i++)
    {
        for(int j = 0; j < GameField::ROW_SIZE; j++)
        {
            int temp = numbers[j][firstRegionPosition + i];
            numbers[j][firstRegionPosition + i] = numbers[j][secondRegionPosition + i];
            numbers[j][secondRegionPosition + i] = temp;
        }
    }
}

void GameWidget::transposition()
{
    QVector< QVector<int> > tempVector;
    for(int i = 0; i < GameField::ROW_SIZE; i++)
    {
        QVector<int> temp;
        for(int j = 0; j < GameField::ROW_SIZE; j++)
        {
            temp.push_back(numbers[j][i]);
        }
        tempVector.push_back(temp);
    }
    numbers = tempVector;
}

void GameWidget::shuffle()
{
    int N = 100 + rand() % 1000;
    int dice = 0;
    for(int i = 0; i < N; i++)
    {
        dice = rand() % 5;
        switch(dice)
        {
        case 0:
            swapRows();
            break;
        case 1:
            swapColumns();
            break;
        case 2:
            swapRowRegion();
            break;
        case 3:
            swapColumnRegion();
            break;
        case 4:
            transposition();
            break;
        default:
            break;
        }
    }
}

void GameWidget::newGame()
{
    shuffle();
    fillField();
}

void GameWidget::reset()
{
    gameField->resetField();
}

void GameWidget::gameResult()
{
    gameField->setDisabledField();
    bool flag = true;
    for(int i = 0; i < GameField::ROW_SIZE; i++)
    {
        for(int j = 0; j < GameField::ROW_SIZE; j++)
        {
            if(gameField->getCellValue(i,j) != numbers[i][j])
            {
                flag = false;
                break;
            }
        }
        if(!flag)
        {
            break;
        }
    }
    if(flag)
    {
        QMessageBox::information(0,tr("Поздравление"),tr("Поздравляем, Вы победили!"));
    }
    else
    {
        QMessageBox::information(0,tr("Сообщение"),tr("К сожалению Вы проиграли. Попробуйте сыграть еще раз."));
    }
}
