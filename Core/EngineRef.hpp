// SINGLETON_DEFINE
#ifndef SINGLETON_DEFINE
#define SINGLETON_DEFINE

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

#endif



//Engine build







