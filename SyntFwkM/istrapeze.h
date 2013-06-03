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
            IsTrapeze(const T& min, const T& midMin, const T& midMax, const T& max);
            virtual T evaluate(const core::Expression<T>* o) const;
        private :
            T m_min, m_midMin, m_midMax, m_max;
    };
    
    template <class T>
    IsTrapeze<T>::IsTrapeze(const T& min, const T& midMin, const T& midMax, const T& max):
        m_min(min),
        m_midMin(midMin),
        m_midMax(midMax),
        m_max(max)
    {
    }
    
    template <T>
    T IsTrapeze<T>::evaluate(const core::Expression<T>* o) const
    {
        T v = o->evaluate();
        
        if (v <= m_min || v >= m_max)
            return 0;
        
        if (v >= m_midMin && v <= m_midMax)
            return 1;
        
        if (v > m_midMax)
            return (m_midMax - m_max) / (v - m_max);
        
        if (v <= m_midMin)
            return (m_midMin - m_min) / (v - m_min);

    }
}

#endif	/* ISTRAPEZE_H */

