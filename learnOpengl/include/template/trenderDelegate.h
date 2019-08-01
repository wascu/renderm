//
// Created by wasku on 19-8-1.
//

#ifndef LEARNOPENGL_TRENDERDELEGATE_H
#define LEARNOPENGL_TRENDERDELEGATE_H

#include "../std_afx.h"

NAMESPACE_GL_BEGIN

template <class R, typename... Args>
class  TDelegate
{
public:
    TDelegate( R  (*f)(Args...) ):m_f(f) {}

    R operator()(Args&&... args)
    {
        return (*m_f)(std::forward<Args>(args) ...);
    }

private:
    R  (*m_f)(Args...);
};

template <class T, class R, typename... Args>
TDelegate<T, R, Args...> createRenDelegate(T* t, R (T::*f)(Args...))
{
    return TDelegate<T, R, Args...>(t, f);
}

template <class R, typename... Args>
TDelegate< R, Args...> createRenDelegate( R (*f)(Args...))
{
    return TDelegate<R, Args...>( f);
}

NAMESPACE_END

#endif //LEARNOPENGL_TRENDERDELEGATE_H
