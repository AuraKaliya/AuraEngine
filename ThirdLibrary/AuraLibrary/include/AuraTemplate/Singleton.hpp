#pragma once

#include <QMutex>

template <typename T>
class Singleton
{
public:
    static T* getInstance();

private:
    Q_DISABLE_COPY(Singleton)
};

template <typename T>
T* Singleton<T>::getInstance()
{
    static QMutex mutex;
    QMutexLocker locker(&mutex);
    static T* instance = nullptr;
    if (instance == nullptr)
    {
        instance = new T();
    }
    return instance;
}

#define Q_SINGLETON_TEMPLATE(Class)             \
private:                                        \
    friend class Singleton<Class>;              \
public:                                         \
    static Class* getInstance()                 \
    {                                           \
        return Singleton<Class>::getInstance(); \
    }

//类声明中
#define SINGLETON_H(Class)            \
private:                                \
    static Class* m_instance;           \
public:                                 \
    static Class* getInstance();

#define SINGLETON_H_CONSTRUCTOR(Class)      \
private:                                    \
    Class();                                \
    Class(const Class&)=delete;             \
    Class& operator=(const Class&)=delete;  \

#define SINGLETON_CPP_CONSTRUCTOR_DEFAULT(Class)    \
Class::Class(){}    \


//cpp中
#define SINGLETON_CPP(Class)              \
    Class* Class::m_instance = nullptr;     \
    Class* Class::getInstance()             \
    {                                       \
        static QMutex mutex;                \
        QMutexLocker locker(&mutex);        \
        if (m_instance == nullptr)          \
        {                                   \
            m_instance = new Class();       \
        }                                   \
        return m_instance;                  \
    }




#define QOBJ_SINGLETON_H(Class) \
private:\
static Class* m_instance;\
public:\
static Class* getInstance(QObject*  parent = nullptr);\

#define QOBJ_SINGLETON_H_CONSTRUCTOR(Class)\
private:\
explicit Class(QObject* parent = nullptr);\
Class(const Class& ) =delete;\
Class& operator = (const Class& ) = delete; \

#define QOBJ_SINGLETON_CPP_CONSTRUCTOR_DEFAULT(Class)\
Class::Class(QObject*parent):QObject{parent}{}\

#define QOBJ_SINGLETON_CPP(Class)\
Class* Class::m_instance = nullptr;\
Class* Class::getInstance(QObject* parent)\
{                                       \
        static QMutex mutex;                \
        QMutexLocker locker(&mutex);        \
        if (m_instance == nullptr)          \
    {                                   \
            m_instance = new Class(parent);       \
    }                                   \
        return m_instance;                  \
}






