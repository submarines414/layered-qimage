#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class editor; }
QT_END_NAMESPACE

/*!
 *  the editor class for combining two QImages into a single one.
 */
class editor : public QMainWindow
{
    Q_OBJECT

public:
    editor(QWidget *parent = nullptr);
    ~editor();

private:
    Ui::editor *ui;

protected:
    void keyPressEvent(QKeyEvent* event);
};
#endif // EDITOR_H
