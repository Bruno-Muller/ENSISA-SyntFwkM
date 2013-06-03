/* 
 * File:   istrapezeright.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 18 mars 2013, 08:57
 */

#ifndef ISTRAPEZERIGHT_H
#define	ISTRAPEZERIGHT_H

#include "expression.h"
#include "is.h"

namespace fuzzy
{
    template <class T>
    class IsTrapezeLeft : public fuzzy::Is<T>
    {
        public :
            IsTrapezeLeft(const T& min, const T& midMin, const T& max);
            virtual T evaluate(const core::Expression<T>* o) const;
        private :
            T m_min, m_midMin, m_max;
    };
    
    template <class T>
    IsTrapezeLeft<T>::IsTrapezeLeft(const T& max, const T& midMin, const T& min):
        m_max(max),
        m_midMin(midMin),
        m_min(min) 
    {       
    }
    
    template <T>
    T IsTrapezeLeft<T>::evaluate(const core::Expression<T>* o) const
    {
        T v = o->evaluate();
        
        if (v <= m_min || v >= m_max)
            return 0;
        
        if (v >= m_midMin)
            return 1;
        
        if (v <= m_midMin)
            return (m_midMin - m_min) / (v - m_min);
    }
}

#endif	/* ISTRAPEZERIGHT_H */

