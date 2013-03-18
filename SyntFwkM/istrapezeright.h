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
            IsTrapezeLeft(const T& min, const T& max);
            virtual T evaluate(const core::Expression<T>* o) const;
        private :
            T m_min, m_max;
    };
    
    template <class T>
    IsTrapezeLeft<T>::IsTrapezeLeft(const T& max, const T& min):
        m_max(max),
        m_min(min) 
    {       
    }
    
    template <T>
    T IsTrapezeLeft<T>::evaluate(const core::Expression<T>* o) const
    {
        return o->evaluate();
    }
}

#endif	/* ISTRAPEZERIGHT_H */

