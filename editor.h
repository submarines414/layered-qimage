#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class editor; }
QT_END_NAMESPACE

class editor : public QMainWindow
{
    Q_OBJECT

public:
    editor(QWidget *parent = nullptr);
    ~editor();

private:
    Ui::editor *ui;
};
#endif // EDITOR_H
