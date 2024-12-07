#ifndef CONSTVALUE_H
#define CONSTVALUE_H


#include <QDir>
#include <QApplication>

class ConstValue
{
public:
    enum SystemState{
        Start,
        Working,
        Close
    };

    enum EngineOptions
    {
        Editor,
        Player
    };

    enum EngineFPS
    {
        FPS_5=5,
        LowFPS=10,
        MidFPS=30,
        HighFPS=60
    };

    enum DataType{
        Int,Double,Float,String,UInt,Unknown
    };

    enum StateLabelState
    {
        Current,Normal
    };



public:
    ConstValue();
static QDir SourceDir() ;
private:

static QDir s_sourceDir;


};


class GlobalKeyValue{
public:
GlobalKeyValue()=default;
public:
static  bool keyPressed   ;
static  bool key_a        ;
static  bool key_b        ;
static  bool key_c        ;
static  bool key_d        ;
static  bool key_e        ;
static  bool key_f        ;
static  bool key_g        ;
static  bool key_h        ;
static  bool key_i        ;
static  bool key_j        ;
static  bool key_k        ;
static  bool key_l        ;
static  bool key_m        ;
static  bool key_n        ;
static  bool key_o        ;
static  bool key_p        ;
static  bool key_q        ;
static  bool key_r        ;
static  bool key_s        ;
static  bool key_t        ;
static  bool key_u        ;
static  bool key_v        ;
static  bool key_w        ;
static  bool key_x        ;
static  bool key_y        ;
static  bool key_z        ;
static  bool key_1        ;
static  bool key_2        ;
static  bool key_3        ;
static  bool key_4        ;
static  bool key_5        ;
static  bool key_6        ;
static  bool key_7        ;
static  bool key_8        ;
static  bool key_9        ;
static  bool key_0        ;

static  bool key_up       ;
static  bool key_down     ;
static  bool key_left     ;
static  bool key_right    ;

static QMap<QString,bool*> keyPressedDictionary;
static QMap<int,bool*>keyDictionaryByNum;
static QMap<int,bool*>keyDictionaryByChar;

bool getKeyPressedState(QString key)
{
    auto it=keyPressedDictionary.find(key);
    if(it!=keyPressedDictionary.end())
        return *it.value();
    else
        return false;
}

bool getNumKeyValue(int id)
{
    auto it=keyDictionaryByNum.find(id);
    if(it!=keyDictionaryByNum.end())
        return *it.value();
    else
        return false;
}
bool getCharKeyValue(int id)
{
    auto it=keyDictionaryByChar.find(id);
    if(it!=keyDictionaryByChar.end())
        return *it.value();
    else
        return false;
}

static void initKeyPressed(){
    keyPressed=false;
    key_w=false;
    key_a=false;
    key_s=false;
    key_d=false;
    key_r=false;
    key_e=false;
    key_q=false;
    key_up=false;
    key_down=false;
    key_left=false;
    key_right=false;
}

};





#endif // CONSTVALUE_H
