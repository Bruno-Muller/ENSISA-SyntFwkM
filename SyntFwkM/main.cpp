/* 
 * File:   main.cpp
 * Author: bruno
 *
 * Created on 5 mars 2013, 17:38
 */

#include <iostream>

#define ASSERT_ON
#include "assertion.h"

#include "valuemodel.h"
#include "aggmax.h"
#include "aggplus.h"
#include "andmin.h"
#include "andmult.h"
#include "notminus1.h"
#include "ormax.h"
#include "orplus.h"
#include "thenmin.h"
#include "thenmult.h"
#include "istriangle.h"

#include "unaryexpressionmodel.h"
#include "binaryexpressionmodel.h"

#include "cogdefuzz.h"
#include "sugenodefuzz.h"
#include "sugenoconclusion.h"
#include "evaluator.h"

#include "fuzzyexpressionfactory.h"


void tests() {
    
    /* 
     *  Test ValueModel
     */
    core::ValueModel<float> *sutVm1 = new core::ValueModel<float>(0.5);
    ASSERT(sutVm1->evaluate() == 0.5);
    
    core::ValueModel<float> *sutVm2 = new core::ValueModel<float>(0.5);
    sutVm2->setValue(27);
    ASSERT(sutVm2->evaluate() == 27);
    
    /*
     *  Test operators
     */ 
    fuzzy::AggMax<float> sutAggMax;
    core::BinaryExpressionModel<float> sut1(&sutAggMax, sutVm1, sutVm2);
    ASSERT(sut1.evaluate() == 27);
    
    fuzzy::AggPlus<float> sutAggPlus;
    core::BinaryExpressionModel<float> sut2(&sutAggPlus, sutVm1, sutVm2);
    ASSERT(sut2.evaluate() == 27.5);
    
    fuzzy::AndMin<float> sutAndMin;
    core::BinaryExpressionModel<float> sut3(&sutAndMin, sutVm1, sutVm2);
    ASSERT(sut3.evaluate() == 0.5); 
    
    fuzzy::AndMult<float> sutAndMult;
    core::BinaryExpressionModel<float> sut4(&sutAndMult, sutVm1, sutVm2);
    ASSERT(sut4.evaluate() == 13.5);
    
    fuzzy::NotMinus1<float> sutNotMinus1;
    core::UnaryExpressionModel<float> sut5(&sutNotMinus1, sutVm1);
    ASSERT(sut5.evaluate() == 0.5);
    
    fuzzy::OrMax<float> sutOrMax;
    core::BinaryExpressionModel<float> sut6(&sutOrMax, sutVm1, sutVm2);
    ASSERT(sut6.evaluate() == 27);
    
    fuzzy::OrPlus<float> sutOrPlus;
    core::BinaryExpressionModel<float> sut7(&sutOrPlus, sutVm1, sutVm2);
    ASSERT(sut7.evaluate() == 27.5);
    
    fuzzy::ThenMin<float> sutThenMin;
    core::BinaryExpressionModel<float> sut8(&sutThenMin, sutVm1, sutVm2);
    ASSERT(sut8.evaluate() == 0.5);
    
    fuzzy::ThenMult<float> sutThenMult;
    core::BinaryExpressionModel<float> sut9(&sutThenMult, sutVm1, sutVm2);
    ASSERT(sut9.evaluate() == 13.5);
    
    /*
     *  Test triangle
     */
    fuzzy::IsTriangle<float> sutIsTriangle(2, 4, 6);
    core::UnaryExpressionModel<float> sut10(&sutIsTriangle, sutVm1);
    sutVm1->setValue(2);
    ASSERT(sut10.evaluate() == 0);
    sutVm1->setValue(3);
    ASSERT(sut10.evaluate() == 0.5);
    sutVm1->setValue(4);
    ASSERT(sut10.evaluate() == 1);
    sutVm1->setValue(5);
    ASSERT(sut10.evaluate() == 0.5);
    sutVm1->setValue(6);
    ASSERT(sut10.evaluate() == 0);    
        
}

void test_mamdani() {
    
    int min = 5;
    int max = 25;
    int step = 1;
    
    // operateurs
    fuzzy::NotMinus1<float> sutNotMinus1;
    fuzzy::AndMin<float> sutAndMin;
    fuzzy::OrMax<float> sutOrMax;
    fuzzy::ThenMin<float> sutThenMin;
    fuzzy::AggMax<float> sutAggMax;
    fuzzy::IsTriangle<float> sutIsTriangle(1, 5, 10);
    
    // defuzz
    fuzzy::CogDefuzz<float> cogDefuzz(min, max, step);
    fuzzy::SugenoDefuzz<float> sugenoDeffuz;
    std::vector<float> coef;
    coef.push_back(1);
    coef.push_back(1);
    fuzzy::SugenoConclusion<float> sugenoConclusion(&coef);
    
    // Crée la factory
    fuzzy::FuzzyExpressionFactory<float> factory(&sutNotMinus1, &sutAndMin, &sutOrMax, &sutThenMin, &sutAggMax, &sutIsTriangle, &cogDefuzz, &sugenoDeffuz, &sugenoConclusion);
    
    // Qualité du service
    fuzzy::IsTriangle<float> poor(-5, 0, 5);
    fuzzy::IsTriangle<float> good(0, 5, 10);
    fuzzy::IsTriangle<float> excellent(5, 10, 15);
    
    // Pourboire
    fuzzy::IsTriangle<float> cheap(0, 5, 10);
    fuzzy::IsTriangle<float> average(10, 15, 20);
    fuzzy::IsTriangle<float> generous(20, 25, 30);
    
    // Valeurs
    core::ValueModel<float> service(0);
    core::ValueModel<float> tips(0);
    
    // Expression
    core::Expression<float> *expr1 =
        factory.newAgg(
                factory.newAgg(
                        factory.newThen(
                                factory.newIs(&poor, &service),
                                factory.newIs(&cheap ,&tips)
                        ),
                        factory.newThen(
                                factory.newIs(&good, &service),
                                factory.newIs(&average, &tips)
                        )
                ),
                factory.newThen(
                        factory.newIs(&excellent, &service),
                        factory.newIs(&generous, &tips)
                )
        );
    
    
    /*
     *  Test mamdani
     */ 
    core::Expression<float> *system = factory.newMamdani(expr1, &tips);
    
	float s;
        std::cout << "Test : mamdani (-1 to continue)" << std::endl;
	while(s!=-1)
	{
		std::cout << "service : ";std::cin >> s;
		service.setValue(s);
		std::cout << "tips -> " << system->evaluate() << std::endl << "shape :" << std::endl;
                //core::Evaluator<float>::Shape ss = core::Evaluator<float>::buildShape(5, 25, 1, expr1, &service);
                //core::Evaluator<float>::printShape(ss, std::cout);
	}
}

void test_sugeno() {
    
    int min = 5;
    int max = 25;
    int step = 1;
    
    
    // opeateur
    fuzzy::NotMinus1<float> opNot;
    fuzzy::AndMin<float> opAnd;
    fuzzy::OrMax<float> opOr;
    fuzzy::SugenoThen<float> opThen;
    fuzzy::AggMax<float> opAgg;
    fuzzy::IsTriangle<float> opIs(1, 5, 10);
    
    // defuzz
    fuzzy::CogDefuzz<float> opMamdani(min, max, step);
    fuzzy::SugenoDefuzz<float> opSugeno;
    std::vector<float> coef;
    coef.push_back(1);
    coef.push_back(1);
    fuzzy::SugenoConclusion<float> opConclusion(&coef);
    
    // factory
    fuzzy::FuzzyExpressionFactory<float> factory(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opIs, &opMamdani, &opSugeno, &opConclusion);
    
    // qualité
    fuzzy::IsTriangle<float> poor(-5,0,5);
    fuzzy::IsTriangle<float> good(0,5,10);
    fuzzy::IsTriangle<float> excellent(5,10,15);
    fuzzy::IsTriangle<float> rancid(-5,0,5);
    fuzzy::IsTriangle<float> delicious(5,10,15);
    
    core::ValueModel<float> service(0);
    core::ValueModel<float> food(0);
    
    // sugeno conclusion
    std::vector<const core::Expression<float>*> SCservicefood;
    SCservicefood.push_back(&service);
    SCservicefood.push_back(&food);

    std::vector<const core::Expression<float>*> SCservice;
    SCservice.push_back(&service);
    
    // regles
    std::vector<const core::Expression<float>*> rules;
    rules.push_back(
        factory.newThen(
                factory.newOr(
                        factory.newIs(&poor, &service),
                        factory.newIs(&rancid, &food)
		),
		factory.newConclusion(&SCservicefood)
	)
    );

    rules.push_back(
        factory.newThen(
                factory.newIs(&good, &service),
                factory.newConclusion(&SCservice)
	)
    );
    
    rules.push_back(
        factory.newThen(
                factory.newOr(
                        factory.newIs(&excellent, &service),
                        factory.newIs(&delicious, &food)
		),
		factory.newConclusion(&SCservicefood)
	)
    );
    

    // defuzzification
    core::Expression<float> *system = factory.newSugeno(&rules);

    /*
     *  Test sugeno
     */
    float s;
        std::cout << "Test : sugeno (-1 to continue)" << std::endl;
	while(s!=-1)
	{
		std::cout << "service : ";std::cin >> s;
		service.setValue(s);
		std::cout << "food : ";std::cin >> s;
		food.setValue(s);
		std::cout << "tips -> " << system->evaluate() << std::endl;
	}
    
    
}

int main(int argc, char** argv) {

    tests(); // lance les tests
    test_mamdani();
    //test_sugeno();
    
    return 0;
}

