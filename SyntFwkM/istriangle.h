/* 
 * File:   istriangle.h
 * Author: bruno
 *
 * Created on 10 mars 2013, 02:09
 */

#ifndef ISTRIANGLE_H
#define	ISTRIANGLE_H

#include "expression.h"
#include "is.h"


namespace fuzzy {

    template <class T>
    class IsTriangle : Is<T> {
    public:
        IsTriangle(const T& min, const T& mid, const T& max);
        virtual T evaluate(const core::Expression<T>& o) const;
    private:
        T m_min, m_mid, m_max;

    };
    
    
    template <class T>
    IsTriangle<T>::IsTriangle(const T& min, const T& mid, const T& max) :
        m_min(min),
        m_mid(mid),
        m_max(max)
    {
    }

    template <class T>
    T IsTriangle<T>::evaluate(const core::Expression<T>& o) const {
        return o.evaluate(); // TODO
    }

}


#endif	/* ISTRIANGLE_H */

