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
    class NotMinus1 {
    public:
        virtual T evaluate(core::Expression) const;
    };
    
    template <class T>
    T NotMinus1::evaluate(core::Expression) const {
        return 0;
    }
    
}


#endif	/* NOTMINUS1_H */

