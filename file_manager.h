#pragma once
#include <string>
#include <QString>
#include <QDir>
#include <QStandardPaths>
#include "event.h"

class FileManager {
    public:
    bool createDirectory (const std::string& dirName);

    bool createFile (const std::string& fileName);

    bool createFile (const char* fileName);

    static FileManager* getInstance ();

    static void releaseInstance ();

    private:
    QString applicationDataLocation;
    QString databasePath;
    static FileManager* _INSTANCE;

    FileManager ();

    ~FileManager ();
};
