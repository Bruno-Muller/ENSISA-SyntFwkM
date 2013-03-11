/* 
 * File:   main.cpp
 * Author: bruno
 *
 * Created on 5 mars 2013, 17:38
 */

#include <iostream>

#define ASSERT_ON
#include "assertion.h"

#include "expression.h"

#include "unaryexpression.h"
#include "unaryexpressionmodel.h"
#include "unaryshadowexpression.h"

#include "valuemodel.h"

#include "naryexpression.h"
#include "naryexpressionmodel.h"
#include "naryshadowexpression.h"

#include "not.h"
#include "notminus1.h"

#include "is.h"
#include "istriangle.h"

#include "expressionfactory.h"
#include "fuzzyexpressionfactory.h"

void tests() {
    //ASSERT(...);
}

int main(int argc, char** argv) {

    tests(); // lance les tests
    
    //Operators
    fuzzy::NotMinus1<int> opNot;
    //fuzzy::AndMin<int> opAnd;
    //fuzzy::OrMax<int> opOr;
    //fuzzy::ThenMin<int> opThen;
    //fuzzy::CogDefuzz<int> opDefuzz;
    
    //fuzzy expession factory
    //FuzzyExpressionFactory f(&opNot,&opAnd,&opOr,&opThen,&opOr,&opDefuzz);
    
    //membership function
    fuzzy::IsTriangle<int> poor(-5,0,5);
    fuzzy::IsTriangle<int> good(0,5,10);
    fuzzy::IsTriangle<int> excellent(5,10,15);
    fuzzy::IsTriangle<int> cheap(0,5,10);
    fuzzy::IsTriangle<int> average(10,15,20);
    fuzzy::IsTriangle<int> generous(20,25,30);
        
    //values
    core::ValueModel<int> service(0);
    core::ValueModel<int> food(0);
    core::ValueModel<int> tips(0);
    
    //Expression *r =
    //        f.NewAgg(
    //            f.NewAgg(
    //                    f.NewThen(
    //                            f.NewIs(&service, &poor),
    //                            f.NewIs(&tips,&cheap)
    //                    ),
    //                    f.NewThen(
    //                            f.NewIs(&service,&good),
    //                            f.NewIs(&tips,&average)
    //                    )
    //            ),
    //            f.NewThen(
    //                    f.NewIs(&service,&excellent),
    //                    f.NewIs(&tips,&generous)
    //            )
    //        );

    //defuzzification
    //Expression *system = f.NewDefuzz(&tips, r, 0, 25, 1);

    //apply input

    //float s;
    //while(true) {
    //    std::cout << "service : ";
    //    std::cin >> s; service.SetValue(s);
    //    std::cout << "tips -> " << system->Evaluate() << std::endl;
    //}
    
    return 0;
}

