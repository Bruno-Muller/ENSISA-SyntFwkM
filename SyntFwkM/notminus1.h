/* 
 * File:   notminus1.h
 * Author: bruno
 *
 * Created on 9 mars 2013, 18:20
 */

#ifndef NOTMINUS1_H
#define	NOTMINUS1_H

#include "expression.h"
#include "not.h"

namespace fuzzy {

    template <class T>
    class NotMinus1 : Not<T> {
    public:
        virtual T evaluate(const core::Expression<T>& o) const;
    };
    
    template <class T>
    T NotMinus1<T>::evaluate(const core::Expression<T>& o) const {
        T t = o.evaluate();
        return ((~t) - 1 );
    }
    
}


#endif	/* NOTMINUS1_H */

