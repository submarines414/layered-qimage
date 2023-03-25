#include "editor.h"
#include "ui_editor.h"

editor::editor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::editor)
{
    ui->setupUi(this);
    QPixmap first(":/graphics/images/duck_body.png");
    QPixmap second(":/graphics/images/duck_appendages.png");
    QPixmap firstScaled = first.scaled(ui->image_1->size());
    QPixmap secondScaled = second.scaled(ui->image_2->size());
    ui->image_1->setPixmap(firstScaled);
    ui->image_2->setPixmap(secondScaled);
}

editor::~editor()
{
    delete ui;
}

void editor::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
        QApplication::quit();
}

