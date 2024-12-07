#pragma once

#include <QVariant>


template<typename LinkClass>
class Component
{
public:
    Component(LinkClass & linkClass):m_linkClass(linkClass),m_value(QVariant())
    {
    }

    inline LinkClass &linkClass()
    {
        return m_linkClass;
    }

    inline QVariant getValue()const
    {
        return m_value;
    }

    template<typename ValueClass>
    ValueClass getValue()
    {
        return m_value.value<ValueClass>();
    }

    inline void setValue(const QVariant & value){
        m_value=value;
    }

protected:
    QVariant m_value;
    LinkClass & m_linkClass;

private:

};
