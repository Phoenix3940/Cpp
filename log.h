#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <string>
#include <time.h>
#include "stdutil.h"

typedef unsigned char log_type;

/**
    Gibt den derzeitigen Zeitstempel in verschiedenen Formaten zurück.
    \param type Das Format des Zeistempels (0: Sctime()-Format  1: hh:mm:ss  2: Nur Datum)
*/
string getTimeStamp(log_type type){
    time_t clk = time(NULL);
    string timestamp = toString(ctime(&clk));
    timestamp = timestamp.substr(0, timestamp.find('\n'));
    switch (type){
        case 0:
            break;
        case 1:
            timestamp = timestamp.substr(8, timestamp.length());
            timestamp = timestamp.substr(timestamp.find(' ')+1, timestamp.length()-8);
            break;
        case 2:
            timestamp = timestamp.substr(4, timestamp.length()-18);
            break;
    }
    return "[" + timestamp + "]";
}

/**
    The Logging-interface 'logger'.
*/
typedef struct {
private:
    string s_prefix;
    string _std_color;
    string _err_color;
    string _warn_color;
    log_type type;
    bool b_init = false;
public:
    void init(log_type type_){
        if (!b_init){
            s_prefix = "LOGGER";
            _std_color = "0f";
            _err_color = "0c";
            _warn_color = "06";
            type = type_;
            b_init = true;
        }
    }
    void notInit(){
        system("COLOR 06");
        printf("[LOGGER][WARNING]:\nInitialization not run!\tContinuing with default options.\n");
        init(1);
    }


    void setPrefix(string prefix){
        s_prefix = prefix;
    }
    string getPrefix(){
        return s_prefix;
    }
    /**
        Setzt die standardmaessige Logging-Farbe
    */
    void setStd_color(string color){
        setStdColor(color);
    }
    /**
        Setzt die standardmaessige Fehler-Farbe
    */
    void setErr_color(string color){
        setErrColor(color);
    }
    void logInfo(string msg){
        if (b_init){
            system(("COLOR " + _std_color).c_str());
            printf("%s [INFO] [%s] %s", getTimeStamp(type).c_str(), s_prefix.c_str(), msg.c_str());
        } else {
            notInit();
        }
    }
    void logInfo(string msg, string title){
        if (b_init){
            system(("TITLE " + title).c_str());
            system(("COLOR " + _std_color).c_str());
            printf("%s [INFO] [%s] %s:\n%s", getTimeStamp(type).c_str(), s_prefix.c_str(), title.c_str(), msg.c_str());
        } else {
            notInit();
        }
    }
    void logWarning(string msg){
        if(b_init){
            system(("COLOR " + _warn_color).c_str());
            printf("%s [WARNING] [%s] %s", getTimeStamp(type).c_str(), s_prefix.c_str(), msg.c_str());
        } else {
            notInit();
        }
    }
    void logWarning(string msg, string title){
        if(b_init){
            system(("TITLE " + title).c_str());
            system(("COLOR " + _warn_color).c_str());
            printf("%s [WARNING] [%s] %s:\n%s", getTimeStamp(type).c_str(), s_prefix.c_str(), title.c_str(), msg.c_str());
        } else {
            notInit();
        }
    }
    void logError(string msg){
        if(b_init){
            system(("COLOR " + _err_color).c_str());
            printf("%s [ERROR] [%s] %s", getTimeStamp(type).c_str(), s_prefix.c_str(), msg.c_str());
        } else {
            notInit();
        }
    }
    void logError(string msg, string title){
        if(b_init){
            system(("TITLE " + title).c_str());
            system(("COLOR " + _err_color).c_str());
            printf("%s [ERROR] [%s] %s:\n%s", getTimeStamp(type).c_str(), s_prefix.c_str(), title.c_str(), msg.c_str());
        } else {
            notInit();
        }
    }
} logger;

#endif // LOG_H
