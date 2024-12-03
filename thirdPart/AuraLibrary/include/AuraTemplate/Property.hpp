#pragma once

#define MakeProperty_H(Type,Name)\
public:\
Type get_##Name()const;\
void set_##Name(const Type value);\
private:    \
Type m_##Name;

#define MakeProperty_CPP(Class,Type,Name)\
Type Class::get_##Name()const{return m_##Name;}\
void Class::set_##Name(const Type value){m_##Name = value;}
