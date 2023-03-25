#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Editor; }
QT_END_NAMESPACE

/*!
 *  the editor class for combining two QImages into a single one.
 */
class Editor : public QMainWindow
{
    Q_OBJECT

public:
    Editor(QWidget *parent = nullptr);
    ~Editor();

private:
    Ui::Editor *ui;
    QGraphicsScene* scene;

protected:
    void keyPressEvent(QKeyEvent* event);

public slots:
    void renderComposite();

};
#endif // EDITOR_H
