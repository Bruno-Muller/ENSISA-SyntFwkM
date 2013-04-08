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
#include "agg.h"

namespace fuzzy {
    
    template <class T>
    class FuzzyExpressionFactory : core::ExpressionFactory<T> {
    public:
        FuzzyExpressionFactory<T>(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, MamdaniDefuzz<T>*);
        virtual core::Expression<T>* NewAnd(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewOr(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewThen(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewAgg(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewDefuzz(const core::Expression<T>* l, const core::Expression<T>* r);
        virtual core::Expression<T>* NewNot(const core::Expression<T>* o);
        virtual core::Expression<T>* NewIs(const fuzzy::Is<T>* is, const core::Expression<T>* o);
        
        virtual void ChangeAnd(And<T>* o);
        virtual void ChangeOr(Or<T>* o);
        virtual void ChangeThen(Then<T>* o);
        virtual void ChangeAgg(Agg<T>* o);
        virtual void ChangeDefuzz(MamdaniDefuzz<T>* o);
        virtual void ChangeNot(Not<T>* o);
        virtual void ChangeIs(Is<T>* o);
    private:
        core::BinaryShadowExpression<T> *m_and, *m_or, *m_then, *m_agg, *m_defuzz, *m_is;
        core::UnaryShadowExpression<T> *m_not;
       
    };
    
    template <class T>
    FuzzyExpressionFactory<T>::FuzzyExpressionFactory(Not<T>* n, And<T>* a, Or<T>* o, Then<T>* t, Agg<T>* g, MamdaniDefuzz<T>* d) :
        m_not((core::UnaryShadowExpression<T>*) n),
        m_and((core::BinaryShadowExpression<T>*) a),
        m_or((core::BinaryShadowExpression<T>*) o),
        m_then( (core::BinaryShadowExpression<T>*) t),
        m_agg((core::BinaryShadowExpression<T>*) g),
        m_defuzz((core::BinaryShadowExpression<T>*) d)
    {    
    }
    
    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::NewAnd(const core::Expression<T>* l, const core::Expression<T>* r)
    {
    }
    
    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::NewOr(const core::Expression<T>* l, const core::Expression<T>* r)
    {
    }
    
    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::NewThen(const core::Expression<T>* l, const core::Expression<T>* r)
    {
    }
    
    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::NewAgg(const core::Expression<T>* l, const core::Expression<T>* r)
    {
    }
    
    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::NewDefuzz(const core::Expression<T>* l, const core::Expression<T>* r)
    {
    }
    
    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::NewNot(const core::Expression<T>* o)
    {
    }
    
    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::NewIs(const fuzzy::Is<T>* is, const core::Expression<T>* o)
    {
    }
    
    template <class T>
    void FuzzyExpressionFactory<T>::ChangeAnd(And<T>* o)
    {
        this->m_and = (core::BinaryShadowExpression<T>*) o;
    }
    
    template <class T>
    void FuzzyExpressionFactory<T>::ChangeOr(Or<T>* o)
    {
        this->m_or = (core::BinaryShadowExpression<T>*) o;
    }
    
    template <class T>
    void FuzzyExpressionFactory<T>::ChangeThen(Then<T>* o)
    {
        this->m_then = (core::BinaryShadowExpression<T>*) o;
    }
    
    template <class T>
    void FuzzyExpressionFactory<T>::ChangeAgg(Agg<T>* o)
    {
        this->m_agg = (core::BinaryShadowExpression<T>*) o;
    }
    
    template <class T>
    void FuzzyExpressionFactory<T>::ChangeDefuzz(MamdaniDefuzz<T>* o)
    {
        this->m_defuzz = (core::BinaryShadowExpression<T>*) o;
    }
    
    template <class T>
    void FuzzyExpressionFactory<T>::ChangeNot(Not<T>* o)
    {
        this->m_not = (core::UnaryShadowExpression<T>*) o;
    }
    
    template <class T>
    void FuzzyExpressionFactory<T>::ChangeIs(Is<T>* o)
    {
        this->m_is = (core::BinaryShadowExpression<T>*) o;
    }
}

#endif	/* FUZZYEXPRESSIONFACTORY_H */

