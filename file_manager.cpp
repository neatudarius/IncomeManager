#include "file_manager.h"

FileManager::FileManager ( ) {
    QStringList pathsList = QStandardPaths::standardLocations ( QStandardPaths::AppDataLocation );
    applicationDataLocation = pathsList[ 0 ];

    databasePath = applicationDataLocation;
    databasePath . append ( "/Database" );

    createDirectory ( databasePath . toStdString ( ) );
}

FileManager::~FileManager ( ) {}

bool FileManager::createDirectory ( const std::string& dirName ) {
    QString path = dirName . c_str ( );

    QDir dir;
    if ( dir . mkpath ( path ) ) {
        return true;
    }

    return false;
}


bool FileManager::createFile ( const char* fileName ) {
    FILE* fd = fopen ( fileName , "r" );

    if ( fd ) {
        fclose ( fd );
        return true;
    }

    return false;
}


bool FileManager::createFile ( const std::string& fileName ) {
    return createFile ( fileName . c_str ( ) );
}
