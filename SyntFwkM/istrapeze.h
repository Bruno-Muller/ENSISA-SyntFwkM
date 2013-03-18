/* 
 * File:   istrapeze.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 18 mars 2013, 08:29
 */

#ifndef ISTRAPEZE_H
#define	ISTRAPEZE_H

#include "expression.h"
#include "is.h"

namespace fuzzy
{
    template <class T>
    class IsTrapeze : public fuzzy::Is<T>
    {
        public :
            IsTrapeze(const T& min, const T& mid, const T& max, const T& lenght);
            virtual T evaluate(const core::Expression<T>* o) const;
        private :
            T m_min, m_mid, m_max, m_lenght;
    };
    
    template <class T>
    IsTrapeze<T>::IsTrapeze(const T& min, const T& mid, const T& max, const T& lenght)
    {
        m_min(min);
        m_mid(mid);
        m_max(max);
        m_lenght(lenght);
    }
    
    template <T>
    T IsTrapeze<T>::evaluate(const core::Expression<T>* o) const
    {
        return o->evaluate();
    }
}

#endif	/* ISTRAPEZE_H */

