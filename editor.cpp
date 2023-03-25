#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Editor)
{
    ui->setupUi(this);

    // load images
    QPixmap first(":/graphics/images/duck_body.png");
    QPixmap second(":/graphics/images/duck_appendages.png");

    // scale them to the size of the labels
    QPixmap firstScaled = first.scaled(ui->image_1->size());
    QPixmap secondScaled = second.scaled(ui->image_1->size());

    // set the labels to display the resized graphics
    ui->image_1->setPixmap(firstScaled);
    ui->image_2->setPixmap(secondScaled);

    // add the two images to a graphics scene
    // note: the x/y values for position are relative to the view
    scene = new QGraphicsScene(QRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height()));
    scene->addPixmap(firstScaled);
    scene->addPixmap(secondScaled);

    // set a graphics view within the UI to render the scene
    ui->graphicsView->setScene(scene);

    // set the signal for the render pushbutton to render the scene to a single layer image
    connect(ui->combine_button, &QPushButton::clicked, this, &Editor::renderComposite);


}

Editor::~Editor()
{
    delete ui;
    delete scene;
}

void Editor::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
        QApplication::quit();
}

void Editor::renderComposite()
{
    qDebug() << "render triggered";
    QPixmap image = ui->graphicsView->grab(ui->graphicsView->sceneRect().toRect());
    ui->post_render->setPixmap(image);
    // bonus: you can save the image >:)
    //image.save("lolitsaduck.png");
}
