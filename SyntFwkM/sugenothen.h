/* 
 * File:   sugenothen.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 17:11
 */

#ifndef SUGENOTHEN_H
#define	SUGENOTHEN_H

#include "binaryexpression.h"
#include "then.h"

namespace fuzzy
{
    template <class T>
    class ThenMult : public Then<T>
    {
        public:
            virtual ~ThenMult() {};
            virtual T evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
            virtual T premiseValue();
        private:
            const T premiseValue; 
                
    };
    
    template <class T>
    T ThenMult<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
    {
        //TODO
    }
    
    template <class T>
    T ThenMult<T>::premiseValue
    {
        //TODO
    }
}


#endif	/* SUGENOTHEN_H */

