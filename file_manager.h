#pragma once
#include <string>
#include <QString>
#include <QDir>
#include <QStandardPaths>
#include "event.h"

class FileManager {
    public:
        FileManager ( );
        ~FileManager ( );
        bool createDirectory ( const std::string& dirName );
        bool createFile ( const std::string& fileName );
        bool createFile ( const char* fileName );

    private:
        QString applicationDataLocation;
        QString databasePath;
};
