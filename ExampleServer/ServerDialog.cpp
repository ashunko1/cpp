#include "ServerDialog.h"

ServerDialog::ServerDialog( QWidget *parent ) :
    QDialog( parent ),
    _pBtnStartServer( new QPushButton ),
    _pBtnStopServer( new QPushButton ),
    _pLblStateServer( new QLabel )

{
    QGridLayout *_pGridLayout = new QGridLayout;

    setMinimumSize( 300, 200 );
    _pLblStateServer->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Fixed );

    _pGridLayout->addWidget( _pBtnStartServer,  0, 0 );
    _pGridLayout->addWidget( _pBtnStopServer,   0, 1 );
    _pGridLayout->addWidget( _pLblStateServer,  1, 0 );

    connect( _pBtnStartServer, SIGNAL( clicked() ), this, SLOT( onStartServer() ) );
    connect( _pBtnStopServer, SIGNAL( clicked() ), this, SLOT( onStopServer() ) );
    connect( this, SIGNAL( finished(int) ), this, SLOT( onStopServer() ) );

    _httpServer.init();

    _pLblStateServer->setText( "HTTP server initialization" );

    setLayout( _pGridLayout );
}

void ServerDialog::onStartServer()
{
    _httpServer.start();
   _pLblStateServer->setText( "HTTP server started" );
}

void ServerDialog::onStopServer()
{
    _httpServer.stop();
   _pLblStateServer->setText( "HTTP server stopped" );
}
