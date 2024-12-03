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
#define Q_SINGLETON_H(Class)            \
private:                                \
    static Class* m_instance;           \
public:                                 \
    static Class* getInstance();

//cpp中
#define Q_SINGLETON_CPP(Class)              \
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
