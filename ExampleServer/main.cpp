#include <QApplication>
#include "ServerDialog.h"

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );

    ServerDialog dlg;
    dlg.exec();

    return app.exec();
}


