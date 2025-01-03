#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <cell.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void getButtonClicked(QString str);
    void updateCounter();
    void restartScene();

private:
    Ui::MainWindow *ui;
    Cell* buttons[9][9];
    int counter;
    int flagsPlaced;
    bool gameStarted;
    QTimer *timer;
    void start_game();
    void set_style();
    void revealCell(int x, int y);
    void checkGameState();
};

#endif // MAINWINDOW_H
