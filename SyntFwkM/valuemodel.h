/* 
 * File:   valuemodel.h
 * Author: bruno
 *
 * Created on 6 mars 2013, 08:58
 */

#ifndef VALUEMODEL_H
#define	VALUEMODEL_H

namespace core {

    template <class T>
    class ValueModel : Expression {
    public:
        virtual T evaluate() const;
        virtual void setValue(T v) const;

    private:
        T m_value;
    };
    
    template <class T>
    T ValueModel::evaluate() const {
        return m_value;
    }
    
    template <class T>
    void ValueModel::setValue(T v) const {
        m_value = v;
    }

}

#endif	/* VALUEMODEL_H */
