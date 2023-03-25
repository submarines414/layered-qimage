#include "editor.h"

#include <QApplication>

/*!
 * \brief main an entrypoint to the image combiner POC -- assigned Charles Knudson
 * \param argc
 * \param argv
 * \return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    editor w;
    w.show();
    return a.exec();
}
