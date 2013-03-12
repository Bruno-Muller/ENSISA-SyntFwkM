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
#include "is.h"
#include "unaryshadowexpression.h"

namespace fuzzy {
    
    template <class T>
    class FuzzyExpressionFactory : core::ExpressionFactory {
    public:
        virtual core::Expression<T>* NewAnd(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewOr(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewThen(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewAgg(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewDefuzz(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewNot(const core::Expression<T>* o);
        virtual core::Expression<T>* NewIs(const core::Is<T>* is, const core::Expression<T>* o);
        
        //virtual void ChangeAnd(const And<T>* o);
        //virtual void ChangeOr(const Or<T>* o);
        //virtual void ChangeThen(const Then<T>* o);
        //virtual void ChangeAgg(const Agg<T>* o);
        //virtual void ChangeDefuzz(const Defuzz<T>* o);
        //virtual void ChangeNot(const Not<T>* o);
        //virtual void ChangeIs(const Is<T>* o);
    private:
        //
       
    };
}

#endif	/* FUZZYEXPRESSIONFACTORY_H */

