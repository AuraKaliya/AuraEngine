#pragma once

#define REGISTFUNCTIONFORCHECK(Function)                               \
template <typename T, typename U, typename... Args>                    \
struct Class_##Function {                                              \
        template <typename V, U(V::*)(Args...) = &V::Function>       \
        static constexpr bool check(V*) { return true; };              \
        static constexpr bool check(...) { return false; };            \
        static constexpr bool res = check(static_cast<T*>(0));         \
};                                                                  

#define CHECKCLASSFUNCTION(ObjClass, Function, RetClass, ...)                      \
     []()-> bool {                                                                 \
        using Class_Function = Class_##Function<ObjClass,RetClass, ##__VA_ARGS__>; \
        return Class_Function::res;                                                \
    }()
