/* 
 * File:   isgaussian.h
 * Author: bruno
 *
 * Created on 3 juin 2013, 22:21
 */

#ifndef ISGAUSSIAN_H
#define	ISGAUSSIAN_H

#include "is.h"
#include <math.h>

namespace fuzzy {

    template <class T>
    class IsGaussian : public Is<T> {
    public:
        IsGaussian(const T& sigma, const T& center);
        T evaluate(const core::Expression<T>* o) const;
    private:
        T m_sigma, m_center;
    };
    
    IsGaussian<T>::IsGaussian(const T& sigma, const T& center) : m_sigma(sigma), m_center(center)
    {
    }
    
    T IsGaussian<T>::evaluate(const core::Expression<T>* o) const
    {
        T v = o->evaluate();
        
        return exp(-((v - m_center) * (v - m_center)) / (2 * m_sigma * m_sigma));
    }
    

}



#endif	/* ISGAUSSIAN_H */

