#pragma once

#define Q_IMPL_H(Class)                 \
public:                                 \
~Class();                               \
private:                                \
class Class##Private;                   \
friend class Class##Private;            \
QScopedPointer<Class##Private>m_d;      \

//==================================
#define Q_IMPL_CPP_STRAT(Class)        \
class Class::Class##Private\
{\
    friend class Class;        \
public:\
Class##Private(Class* q):m_q(q){};\
Class* m_q;\

#define Q_IMPL_CPP_END(Class)    \
};

#define Q_IMPL_CPP_INIT(Class) \
m_d(new Class##Private(this))  \

#define Q_IMPL_CPP_DESTRUCTOR_DEFAULT(Class)   \
Class::~Class()=default;                \

