/* 
 * File:   isbell.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 18 mars 2013, 09:06
 */

#ifndef ISBELL_H
#define	ISBELL_H

#include "expression.h"
#include "is.h"
#include <math.h>

namespace fuzzy
{
    template<class T>
    class IsBell : public fuzzy::Is<T>
    {
        public : 
            IsBell(const T& a,const T& b, const T& c);
            virtual T evaluate(const core::Expression<T>* o) const;
        private :
            T m_a, m_b, m_c;
    };
    
    template<class T>
    IsBell<T>::IsBell(const T& a, const T& b, const T& c): 
        m_a(a),
        m_b(b),
        m_c(c)
    {
    }
    
    template<class T>
    T IsBell<T>::evaluate(const core::Expression<T>* o) const
    {
        
        return 1/(1+(fabs((x-m_c)/m_a)^(2*m_b))
    }
}
     

#endif	/* ISBELL_H */

