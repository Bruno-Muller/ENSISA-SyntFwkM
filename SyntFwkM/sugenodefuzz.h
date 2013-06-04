/* 
 * File:   sugenodeffuz.h
 * Author: bruno
 *
 * Created on 3 juin 2013, 20:14
 */

#ifndef SUGENODEFUZZ_H
#define	SUGENODEFUZZ_H

#include <vector>

#include "expression.h"
#include "binaryexpressionmodel.h"
#include "binaryshadowexpression.h"
#include "naryexpression.h"
#include "sugenothen.h"

namespace fuzzy {

    template<class T>
    class SugenoDefuzz : public core::NaryExpression<T> {
        public:
            virtual T evaluate(std::vector<const core::Expression<T>*> *operands) const;
    };
    
    template<class T>
    T SugenoDefuzz<T>::evaluate(std::vector<const core::Expression<T>*> *operands) const {
        typename std::vector<const core::Expression<T>*>::const_iterator iterator = operands->begin();
        T numerator = 0;
        T denominator = 0;
        
        // numérateur : calcule la somme  
        for(iterator = operands->begin(); iterator != operands->end(); iterator++) {
            numerator += (*iterator)->evaluate();
            iterator++;
        }
        
        for(iterator = operands->begin(); iterator != operands->end(); iterator++) {
            core::BinaryExpressionModel<T> *model = (core::BinaryExpressionModel<T>*) (*iterator);
            core::BinaryShadowExpression<T> *shadow = (core::BinaryShadowExpression<T>*) model->getOperator();
            Then<T> *then = (Then<T>*) shadow->getTarget();
            SugenoThen<T> *sugeno = (SugenoThen<T>*) then;
            
            denominator += sugeno->premiseValue();
        }
        
        if (denominator != 0)
            return numerator/denominator;
        else
            return 0;
        
    }
    
}


#endif	/* SUGENODEFUZZ_H */

