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
#include "unaryshadowexpression.h"
#include "binaryshadowExpression.h"
#include "and.h"
#include "or.h"
#include "then.h"
#include "agg.h"
#include "mamdanidefuzz.h"
#include "not.h"
#include "is.h"

namespace fuzzy {
    
    template <class T>
    class FuzzyExpressionFactory : core::ExpressionFactory<T> {
    public:
        FuzzyExpressionFactory<T>(Not<T>*, And<T>, Or<T>*, Then<T>*, Or<T>*, MamdaniDefuzz<T>*);
        virtual core::Expression<T>* NewAnd(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewOr(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewThen(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewAgg(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewDefuzz(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewNot(const core::Expression<T>* o);
        virtual core::Expression<T>* NewIs(const fuzzy::Is<T>* is, const core::Expression<T>* o);
        
        virtual void ChangeAnd(const And<T>* o);
        virtual void ChangeOr(const Or<T>* o);
        virtual void ChangeThen(const Then<T>* o);
        virtual void ChangeAgg(const Agg<T>* o);
        virtual void ChangeDefuzz(const MamdaniDefuzz<T>* o);
        virtual void ChangeNot(const Not<T>* o);
        virtual void ChangeIs(const Is<T>* o);
    private:
        core::BinaryShadowExpression<T> *m_and, *m_or, *m_then, *m_agg, *m_defuzz, *m_is;
        core::UnaryShadowExpression<T>* m_not;
       
    };
    
    template <class T>
    FuzzyExpressionFactory<T>::FuzzyExpressionFactory(Not<T>* n, And<T> a, Or<T>* o, Then<T>* t, Or<T>* o2, MamdaniDefuzz<T>* d) :
        m_not(n),
        m_and(a),
        m_or(o),
        m_then(t),
        m_defuzz(d)
    {    
    }
}

#endif	/* FUZZYEXPRESSIONFACTORY_H */

