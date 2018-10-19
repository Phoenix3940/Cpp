#ifndef STDUTIL_H
#define STDUTIL_H

#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <sstream>

/**Hilfsmethode fuer 'getSize()'*/
#define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))


/**Bestimmt die Laenge des Arrays 'type'*/
#define getSize(type) (my_sizeof(type)/my_sizeof(type[0]))
using namespace std;

/**
    Bestimmt die Laenge des Arrays 'type'
*/
template <typename T>
int sizeOf(T type[]){
    return getSize(type);
}

/**
    Die Standardconsolenfarbe (!CMD-Format!)
*/
static string std_color = "0f";
/**
    Die Fehlerconsolenfarbe (!CMD-Format!)
*/
static string err_color = "0c";

/**
    Gibt die cmd-hilfe fuer den color befehl aus.
*/
void getColorHelp(){
    system("CLS");
    system("COLOR ?");
    printf("\n\n\n");
    system("PAUSE");
    system("CLS");
}
/**
    Um Variablen in strings zu konvertieren.
    (Benoetigt <string>, <sstream>)
    \brief toString
    \param T Variable
    \return Die Variable als string
*/
template <typename T>
  std::string toString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

/**
    Wartet bis der gegebene Character eingegeben wurde.
    \brief waitForKey
    \param keyToWaitFor Character, auf den gewartet werden soll
*/
bool waitForKey(char keyToWaitFor) {
    while (true) {
        if(getch()==keyToWaitFor)
            break;
    }
    return true;
}

/**
    Wartet bis der gegebene Character eingegeben wurde.
    \brief waitForKey
    \param keyToWaitFor Character, auf den gewartet werden soll
    \param millis       Die Anzahl der Millisekunden, die gewartet werden soll
*/
bool waitForKeyContinue(char keyToWaitFor, int millis) {
    for (int z = 0; z < (int)(millis/10); z++){
        Sleep(1);
        if (GetAsyncKeyState((int)keyToWaitFor)){
            getch();
            return true;
        }
    }
    return false;
}
/**
    Setzt die Standardmaessige Farbe.
*/
void setStdColor(string color){
    if(sizeOf(color.c_str())!=2){
        system(("COLOR " + err_color).c_str());
        system("TITLE ERROR!");
        printf("\nIllegalArgument: At: stdutil.h:69\nMaximumArraySize=2\tColorFormat=CMDFormat - See \"cmd.exe c color -?\"\n");
        system("PAUSE");
        exit(1);
    } else{
        system(("COLOR " + color).c_str());
        std_color = toString(color);
    }
}
/**
    Stetzt die Standardmaessige Fehlerfarbe.
*/
void setErrColor(string color){
    if(sizeOf(color.c_str())!=4){
        system(("COLOR " + err_color).c_str());
        system("TITLE ERROR!");
        printf("\nIllegalArgument: At: stdutil.h:83\nMaximumArraySize=2\tColorFormat=CMDFormat - See \"cmd.exe c color -?\"\n");
        system("PAUSE");
        exit(1);
    } else{
//        system(("COLOR " + toString(color)).c_str());
        err_color = toString(color);
    }
}
/**
    (Benoetigt <windows.h>)
    \brief Bildschirmblinken:

    \param blink_farbe  Farbe in der es blinken soll
    \param std_farbe    Standardfarbe
    \param count_       Wie oft geblinkt werden soll
    \param millis       Verzoegerung
*/
void blink(string std_farbe, string blink_farbe, short count_, int millis){

    for (int i = 0; i < count_; i++){
        system(("COLOR " + blink_farbe).c_str());
        Sleep(millis);
        system(("COLOR " + std_farbe).c_str());
        Sleep(millis);
    }
}
/**
    (Benoetigt <windows.h>)
    \brief Bildschirmblinken:

    \param blink_farbe  Farbe in der es blinken soll
    \param std_farbe    Standardfarbe
    \param count_       Wie oft geblinkt werden soll
    \param stop_key     Die Taste die das Blinken abbricht
    \param millis       Verzoegerung
*/
void blink(string std_farbe, string blink_farbe, short count_, int millis, char stop_key){
    for (int i = 0; i < count_; i++){
        system(("COLOR " + blink_farbe).c_str());
        waitForKeyContinue(stop_key, millis);
        system(("COLOR " + std_farbe).c_str());
        waitForKeyContinue(stop_key, millis);
    }
}

void wait(){
    system("PAUSE>nul");
}

/**
    Gibt eine Zufallszahl zwischen $min_ und $max_ zurueck
    \param min_ Minimaler Wert der Zahl (inklusive)
    \param max_ Maximaler Wert der Zahl (inklusive)
    \return Zufallszahl zwischen $mi_ und $max_
*/
int getRand(int min_, int max_){
    srand(time(NULL));
    return ((int)((rand() % (max_ + 1 - min_)) + min_));
}
/**
    Gibt eine Zufallszahl zwischen $min_ und $max_ zurueck
    \param min_ Minimaler Wert der Zahl (inklusive)
    \param max_ Maximaler Wert der Zahl (inklusive)
    \param seed Der Seed für den Zufallsgenerator
    \return Zufallszahl zwischen $mi_ und $max_
*/
int getRand(int min_, int max_,unsigned int seed){
    srand(seed);
    return ((int)((rand() % (max_ + 1 - min_)) + min_));
}

/**
    Gibt eine Zufallszahl zwischen $min_ und $max_ zurueck
    \param min_ Minimaler Wert der Zahl (inklusive)
    \param max_ Maximaler Wert der Zahl (inklusive)
    \param seed Der Seed für den Zufallsgenerator
    \return Zufallszahl zwischen $mi_ und $max_
*/
int getRand(int min_, int max_,time_t seed){
    srand(time(&seed));
    return ((int)((rand() % (max_ + 1 - min_)) + min_));
}

void cls(){
    system("CLS");
}
void color(string color){
    system(("COLOR " + color).c_str());
}
void title(string title){
    system(("TITLE " + title).c_str());
}

void end_prog(){
    printf("\nExiting Program. . .\n");
    wait();
    exit(1);
}

#endif //STDUTIL_H
