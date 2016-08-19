#pragma once
#include <string>
#include <QString>

struct Event;

class FileManager {
    public:
    FileManager ( );
    ~FileManager ( );
    bool createDirectory ( const std::string &dirName );
    bool createFile ( const std::string &fileName );
    bool createFile ( const char *fileName );

    private:
    QString applicationDataLocation;
    QString databasePath;
};
