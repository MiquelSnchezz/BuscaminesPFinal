#ifndef CELL_H
#define CELL_H
#include <QPushButton>
#include <QMouseEvent>
#include <QWidget>

class Cell : public QPushButton
{
    Q_OBJECT

public:
    Cell();
    ~Cell();

    QString getText()const{return text;}
    void setText(const QString& text){this->text = text; QPushButton::setText(text);}

    int getNum()const{return num;}
    void setNum(int num){this->num = num;}

    int getposX()const{return posX;}
    void setposX(int posX){this->posX = posX;}

    int getposY()const{return posY;}
    void setposY(int posY){this->posY = posY;}

    bool getState()const{return state;}
    void setState(bool state){this->state = state;}

    bool getBanner()const{return banner;}
    void setBanner(bool banner){this->banner = banner;}


public slots:
    void mousePressEvent(QMouseEvent*);

signals:
    //void mouseButton(QString tecla);
    void mouseButton(QString tecla);

private:
    QString text;
    int num;
    int posX, posY;
    bool state;
    bool banner;

};

#endif // CELL_H
