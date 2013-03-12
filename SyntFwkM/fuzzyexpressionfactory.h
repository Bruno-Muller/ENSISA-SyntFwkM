/* 
 * File:   fuzzyexpressionfactory.h
 * Author: bruno
 *
 * Created on 10 mars 2013, 04:28
 */

#ifndef FUZZYEXPRESSIONFACTORY_H
#define	FUZZYEXPRESSIONFACTORY_H

#include "expression.h"
#include "expressionfactory.h"

namespace fuzzy {
    
    template <class T>
    class FuzzyExpressionFactory : core::ExpressionFactory {
    public:
        virtual core::Expression<T>* NewAnd(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewOr(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewThen(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewAgg(const core::Expression<T>* l, const core::Expression<T>* r);
    private:
       
    };
}

#endif	/* FUZZYEXPRESSIONFACTORY_H */

