/* 
 * File:   valuemodel.h
 * Author: bruno
 *
 * Created on 6 mars 2013, 08:58
 */

#ifndef VALUEMODEL_H
#define	VALUEMODEL_H

#include "expression.h"

namespace core {

    template <class T>
    class ValueModel : Expression<T> {
    public:
        ValueModel(const T& v);
        virtual T evaluate() const;
        virtual void setValue(const T& v);

    private:
        T m_value;
    };
    
    template <class T>
    ValueModel<T>::ValueModel(const T& v) :
    m_value(v)
    {
    }
    
    template <class T>
    T ValueModel<T>::evaluate() const {
        return m_value;
    }
    
    template <class T>
    void ValueModel<T>::setValue(const T& v) {
        m_value = v;
    }

}

#endif	/* VALUEMODEL_H */
