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

    bool openFile (const char* fileName);

    void reset ();

    bool setCurrentFile (const QString& file);
    void save ( );
    void load ( );

    bool fileSet ();

    QString getCurrentFile ();

    static FileManager* getInstance ();

    static void releaseInstance ();

    private:
    QString applicationDataLocation;
    QString databasePath;
    QString currentFile;

    static FileManager* _INSTANCE;

    FileManager ();

    ~FileManager ();
};
