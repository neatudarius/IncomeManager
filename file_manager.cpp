#include "file_manager.h"
#include "income_manager.h"

FileManager* FileManager::_INSTANCE = NULL;

FileManager::FileManager () {
    QStringList pathsList = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
    applicationDataLocation = pathsList[ 0 ];

    databasePath = applicationDataLocation;
    databasePath.append("/Database");

    createDirectory(databasePath.toStdString());
}

FileManager::~FileManager () {}

FileManager* FileManager::getInstance ( ) {
    if ( _INSTANCE == NULL ) {
        _INSTANCE = new FileManager ( );
    }
    return _INSTANCE;
}

void FileManager::releaseInstance ( ) {
    if ( _INSTANCE != NULL ) {
        delete _INSTANCE;
        _INSTANCE = NULL;
    }
}

bool FileManager::createDirectory (const std::string& dirName) {
    QString path = dirName.c_str();

    QDir dir;
    if (dir.mkpath(path)) {
        return true;
    }

    return false;
}

bool FileManager::createFile (const char* fileName) {
    FILE* fd = fopen(fileName , "r");

    if (fd) {
        fclose(fd);
        return true;
    }

    return false;
}

bool FileManager::createFile ( const std::string& fileName ) {
    return createFile ( fileName.c_str ( ) );
}



bool FileManager::openFile ( const char* fileName ) {
    FILE* fd = fopen ( fileName, "r" );

    if ( fd ) {
        fclose ( fd );
        return true;
    }

    return false;
}


void FileManager::setCurrentFile (const QString& file) {
    currentFile = file;
    DbManager::getInstance ( )->reset ( );
}

void FileManager::save () {
    FILE *fd = fopen ( currentFile.toStdString ( ).c_str ( ), "wb" );

    QVector <Event> events = DbManager::getInstance()->getEvents ( );
    int eventsCount = events.size ( );

    fwrite ( &eventsCount, sizeof ( int ), 1, fd );
    for ( auto event : events ) {
        event.write ( fd );
    }
    
    fclose ( fd );
}

void FileManager::load () {
    FILE *fd = fopen ( currentFile.toStdString ( ).c_str ( ), "rb" );

    int eventsCount = 0;
    QVector <Event> events;

    fread ( &eventsCount, sizeof ( int ), 1, fd );
    for ( int i = 0; i < eventsCount; ++i ) {
        Event event;
        event.read ( fd );
        events.push_back ( event );
    }

    DbManager::getInstance()->load ( events );
    fclose ( fd );
}
