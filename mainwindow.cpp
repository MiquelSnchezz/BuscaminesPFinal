#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <QTimer>
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    counter(0)
{
    ui->setupUi(this);

    set_style();

    ui->time_lcd->setDigitCount(3);
    ui->time_lcd->display(QString("%1").arg(0, 3, 10, QChar('0')));

    ui->score_lcd->setDigitCount(3);
    ui->score_lcd->display(QString("%1").arg(0, 3, 10, QChar('0')));


    QGridLayout* layoutWidget2 = new QGridLayout(ui->widget);
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            buttons[i][j] = new Cell;
            connect(buttons[i][j], SIGNAL(mouseButton(QString)),this, SLOT(getButtonClicked(QString)));
            layoutWidget2->addWidget(buttons[i][j], i, j);
        }
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateCounter);


    connect(ui->start_button, &QPushButton::clicked, this, &MainWindow::restartScene);
    ui->start_button->setToolTip("Reiniciar");

}

MainWindow::~MainWindow()
{
    delete ui;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            delete buttons[i][j];
        }
    }
}

void MainWindow::set_style(){

    QIcon icon(":/Icons/smile.png");
    ui->start_button->setIcon(icon);
    ui->start_button->setIconSize(QSize(20, 20));

    setStyleSheet("QMainWindow { background-color: rgb(51, 170, 43); }");

    ui->time_lcd->setStyleSheet("color: rgb(255, 255, 255);"
                                " qproperty-alignment: 'AlignCenter';"
                                "background-color: rgb(0, 118, 0);"
                                "border:none;"
                                "border-radius: 5px;");

    ui->score_lcd->setStyleSheet("color: rgb(255, 255, 255);"
                                 " qproperty-alignment: 'AlignCenter';"
                                 "background-color: rgb(0, 118, 0);"
                                 "border:none;"
                                 "border-radius: 5px;");
}

void MainWindow::start_game() {
    for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                buttons[i][j]->setNum(0);
                buttons[i][j]->setText("");
                buttons[i][j]->setState(false);
                buttons[i][j]->setBanner(false);
                buttons[i][j]->setEnabled(true);
                buttons[i][j]->setStyleSheet("");
            }
        }

    int numBombs = 0;
    while (numBombs < 10) {
        int i = QRandomGenerator::global()->bounded(9);
        int j = QRandomGenerator::global()->bounded(9);

        if (buttons[i][j]->getNum() == 0) {
            buttons[i][j]->setNum(-1); // Assignar una bomba.
            numBombs++;
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (buttons[i][j]->getNum() != -1) {
                int bombCount = 0;

                for (int x = -1; x <= 1; ++x) {
                    for (int z = -1; z <= 1; ++z) {
                        int nx = i + x;
                        int ny = j + z;

                        if (nx >= 0 && nx < 9 && ny >= 0 && ny < 9 && buttons[nx][ny]->getNum() == -1) {
                            bombCount++;
                        }
                    }
                }

                buttons[i][j]->setNum(bombCount); // Assignar el número de bombes adjacents.
            }
        }
    }
}


void MainWindow::getButtonClicked(QString str) {
    if (!gameStarted) { // Bloquejar clics abans que el joc comenci.
        QMessageBox::warning(this, "Warning", "The game has not started yet!");
        return;
    }

    Cell* cell = qobject_cast<Cell*>(sender());
    if (!cell || cell->getState()) return; // Ignorar si la cel·la ja està destapada.

    if (str == "Left") {
        cell->setState(true); // Marcar la cel·la com a destapada.

        if (cell->getNum() == -1) {
            // Mostrar la bomba i acabar el joc.
            cell->setText("💣");
            QMessageBox::critical(this, "Game Over", "You clicked on a bomb!");
            restartScene();
            return;
        }

        if (cell->getNum() > 0) {
            cell->setText(QString::number(cell->getNum()));
        } else {
            // Si és una cel·la buida, destapar recursivament les adjacents.
            revealCell(cell->getposX(), cell->getposY());
        }

        checkGameState(); // Comprovar si el jugador ha guanyat.
    } else if (str == "Right") {
        // Marcar/desmarcar la cel·la amb una bandera.
        if (!cell->getBanner() && flagsPlaced > 0) {
            // Col·locar una bandera si n'hi ha disponibles.
            cell->setBanner(true);
            cell->setText("🚩");
            flagsPlaced--;
        } else if (cell->getBanner()) {
            // Treure una bandera i tornar-la al comptador.
            cell->setBanner(false);
            cell->setText("");
            flagsPlaced++;
        }

        // Actualitzar el marcador de banderes al LCD.
        ui->score_lcd->display(QString("%1").arg(flagsPlaced, 3, 10, QChar('0')));
    }
}




void MainWindow::updateCounter(){
    counter++;

    if(counter == 1000){
        timer->stop();
        counter = 999;

        this->setStyleSheet("QMainWindow { background-color: rgb(60, 63, 255); }");

        ui->time_lcd->setStyleSheet("color: rgb(255, 255, 255);"
                                    " qproperty-alignment: 'AlignCenter';"
                                    "background-color: blue;"
                                    "border:none;"
                                    "border-radius: 5px;");

        ui->score_lcd->setStyleSheet("color: rgb(255, 255, 255);"
                                     " qproperty-alignment: 'AlignCenter';"
                                     "background-color: blue;"
                                     "border:none;"
                                     "border-radius: 5px;");

        QIcon icon(":/Icons/freezing-face.png");
        ui->start_button->setIcon(icon);
        ui->start_button->setIconSize(QSize(20, 20));

    }

    ui->time_lcd->display(QString("%1").arg(counter, 3, 10, QChar('0')));
}

void MainWindow::revealCell(int x, int y) {
    if (x < 0 || x >= 9 || y < 0 || y >= 9 || buttons[x][y]->getState() || buttons[x][y]->getNum() == -1) {
        return;
    }

    Cell* cell = buttons[x][y];
    cell->setState(true);
    cell->setStyleSheet("background-color: rgb(200, 200, 200);");

    if (cell->getNum() > 0) {
        cell->setText(QString::number(cell->getNum()));
    } else {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                revealCell(x + dx, y + dy);
            }
        }
    }
}



void MainWindow::checkGameState() {
    int revealedCells = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (buttons[i][j]->getState()) revealedCells++;
        }
    }
    if (revealedCells == 81 - 10) {
        QMessageBox::information(this, "Victory", "You won the game!");
        restartScene();
    }
}

void MainWindow::restartScene(){
    counter = 0;
    ui->time_lcd->display(QString("%1").arg(counter, 3, 10, QChar('0')));
    gameStarted = true;
    flagsPlaced = 10; // Reiniciar nombre de banderes.
    ui->score_lcd->display(QString("%1").arg(flagsPlaced, 3, 10, QChar('0')));
    timer->start(1000);
    start_game();
    set_style();

}
