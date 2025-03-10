/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 01.03.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "study_in_pink2.h"
//#include "tc_bkel.h"

using namespace std;

//void tc_1117() {
//    cout << "----- Testcase 117 -----" << endl;
//    int num_walls = 8;
//    Position arr_walls[] = { Position(1, 1), Position(2, 1), Position(3, 1), Position(4, 1), Position(1, 3), Position(2, 3), Position(3, 3), Position(4, 3) };
//    int num_fake_walls = 2;
//    Position arr_fake_walls[] = { Position(1, 2), Position(4, 2) };
//
//    Map* map = new Map(5, 5, num_walls, arr_walls, num_fake_walls, arr_fake_walls);
//
//    Watson* watson = new Watson(1, "DR", Position(0, 2), map, 100, 500);
//    cout << watson->getNextPosition().str() << endl;
//
//    delete map;
//    delete watson;
//}


// TESTCASE BKEL
void g_satc_02() { // global
    cout << "----- Sample Testcase 02 -----" << endl;
    Configuration * config = new Configuration("sa_tc_02_config");
    cout << config->str() << endl;
    delete config;
}

void g_satc_16() { // global
    cout << "----- Sample Testcase 16 -----" << endl;
    StudyPinkProgram* study_pink_program = new StudyPinkProgram("sa_tc_16_config");
    study_pink_program->run(100);

    delete study_pink_program;
}

void g_satc_05() { // global
    cout << "----- Sample Testcase 05 -----" << endl;
    StudyPinkProgram* study_pink_program = new StudyPinkProgram("sa_tc_03_config");
    study_pink_program->run(100);

    delete study_pink_program;
}

void g_satc_06() { // global
    cout << "----- Sample Testcase 06 -----" << endl;
    StudyPinkProgram* study_pink_program = new StudyPinkProgram("sa_tc_06_config");
    study_pink_program->run(100);

    delete study_pink_program;
}

//void tc_1167() {
//    cout << "----- Testcase 167 -----" << endl;
//
//    ArrayMovingObject* arr_mv_objs = new ArrayMovingObject(5);
//    cout << arr_mv_objs->str() << endl;
//    delete arr_mv_objs;
//}

void g_satc_07() { // global
    cout << "----- Sample Testcase 07 -----" << endl;
    StudyPinkProgram* study_pink_program = new StudyPinkProgram("sa_tc_07_config");
    study_pink_program->run(100);

    delete study_pink_program;
}

void g_satc_08() { // global
    cout << "----- Sample Testcase 08 -----" << endl;
    StudyPinkProgram* study_pink_program = new StudyPinkProgram("sa_tc_08_config");
    study_pink_program->run(100);

    delete study_pink_program;
}

void g_satc_10() { // global
    cout << "----- Sample Testcase 10 -----" << endl;
    StudyPinkProgram* study_pink_program = new StudyPinkProgram("sa_tc_10_config");
    study_pink_program->run(100);

    delete study_pink_program;
}

void g_satc_15() { // global
    cout << "----- Sample Testcase 15 -----" << endl;
    StudyPinkProgram* study_pink_program = new StudyPinkProgram("sa_tc_15_config");
    study_pink_program->run(100);

    delete study_pink_program;
}

void g_satc_17() { // global
    cout << "----- Sample Testcase 17 -----" << endl;
    StudyPinkProgram* study_pink_program = new StudyPinkProgram("sa_tc_17_config");
    study_pink_program->run(100);

    delete study_pink_program;
}

void g_satc_18() { // global
    cout << "----- Sample Testcase 18 -----" << endl;
    StudyPinkProgram* study_pink_program = new StudyPinkProgram("sa_tc_18_config");
    study_pink_program->run(100);

    delete study_pink_program;
}


class TestStudyInPink {
public:
    TestStudyInPink() = default;

    static void testBasic()
    {
        // MapElement
        MapElement* testMapElement = new Path();
        cout << "Path getType: " << testMapElement->getType() << endl;
        delete testMapElement;
        testMapElement = new Wall();
        cout << "Wall getType: " << testMapElement->getType() << endl;
        delete testMapElement;
        testMapElement = new FakeWall(666);
        cout << "FakeWall getType: " << testMapElement->getType() << endl;
        delete testMapElement;
        // Map
        Position arrayWall[1] = { Position(0, 1) };
        Position arrayFakeWall[1] = { Position(0, 0) };
        Map* testMap = new Map(1, 3, 1, arrayWall, 1, arrayFakeWall);
        // isValid Watson
        MovingObject* dummyObj = new Watson(0, "", Position(0, 0), nullptr, 0, 0);
        cout << "Watson go in Path: " << testMap->isValid(Position(0, 2), dummyObj) << endl;
        cout << "Watson go in Wall: " << testMap->isValid(Position(0, 1), dummyObj) << endl;
        cout << "Watson go in FakeWall with EXP_" << dynamic_cast<Watson*>(dummyObj)->getExp() << " : " << testMap->isValid(Position(0, 0), dummyObj) << endl;
        dynamic_cast<Watson*>(dummyObj)->setExp(89);
        cout << "Watson go in FakeWall with EXP_" << dynamic_cast<Watson*>(dummyObj)->getExp() << " : " << testMap->isValid(Position(0, 0), dummyObj) << endl;
        dynamic_cast<Watson*>(dummyObj)->setExp(90);
        cout << "Watson go in FakeWall with EXP_" << dynamic_cast<Watson*>(dummyObj)->getExp() << " : " << testMap->isValid(Position(0, 0), dummyObj) << endl;
        delete dummyObj;
        // isValid Sherlock
        dummyObj = new Sherlock(0, "", Position(0, 0), nullptr, 0, 0);
        cout << "Sherlock go in Path: " << testMap->isValid(Position(0, 2), dummyObj) << endl;
        cout << "Sherlock go in Wall: " << testMap->isValid(Position(0, 1), dummyObj) << endl;
        cout << "Sherlock go in FakeWall: " << testMap->isValid(Position(0, 0), dummyObj) << endl;
        delete dummyObj;
        // isValid Criminal
        dummyObj = new Criminal(0, Position(0, 0), nullptr, nullptr, nullptr);
        cout << "Criminal go in Path: " << testMap->isValid(Position(0, 2), dummyObj) << endl;
        cout << "Criminal go in Wall: " << testMap->isValid(Position(0, 1), dummyObj) << endl;
        cout << "Criminal go in FakeWall: " << testMap->isValid(Position(0, 0), dummyObj) << endl;
        delete dummyObj;
        // isValid Robot
        dummyObj = new RobotC(0, Position(0, 0), nullptr, nullptr);
        cout << "Robot go in Path: " << testMap->isValid(Position(0, 2), dummyObj) << endl;
        cout << "Robot go in Wall: " << testMap->isValid(Position(0, 1), dummyObj) << endl;
        cout << "Robot go in FakeWall: " << testMap->isValid(Position(0, 0), dummyObj) << endl;
        // isValid outrange
        cout << "Outrange " << Position(-1, 0).str() << " : " << testMap->isValid(Position(-1, 0), dummyObj) << endl;
        cout << "Outrange " << Position(0, -1).str() << " : " << testMap->isValid(Position(0, -1), dummyObj) << endl;
        cout << "Outrange " << Position(1, 0).str() << " : " << testMap->isValid(Position(1, 0), dummyObj) << endl;
        cout << "Outrange " << Position(0, 3).str() << " : " << testMap->isValid(Position(0, 3), dummyObj) << endl;
        delete dummyObj;
        delete testMap;
        // Position
        cout << "Position: " << Position().str() << endl;
        cout << "Position (1,1): " << Position(1, 1).str() << endl;
        cout << "Position String (2,2): " << Position("(2,2)").str() << endl;
        cout << "Position getRow: " << Position().getRow() << endl;
        cout << "Position getCol: " << Position().getCol() << endl;
        Position testPos;
        testPos.setRow(1);
        testPos.setCol(1);
        cout << "Position setRow: " << testPos.getRow() << endl;
        cout << "Position setCol: " << testPos.getCol() << endl;
        cout << "Position (0,0) isEqual (0,0): " << Position(0, 0).isEqual(Position(0, 0)) << endl;
        cout << "Position (0,0) isEqual (0,1): " << Position(0, 0).isEqual(Position(0, 1)) << endl;
        cout << "Position (0,0) isEqual (0,0): " << Position(0, 0).isEqual(0, 0) << endl;
        cout << "Position (0,0) isEqual (0,1): " << Position(0, 0).isEqual(0, 1) << endl;
        // MovingObject
        Map dummyMap(10, 10, 0, nullptr, 0, nullptr);
        MovingObject* sherlock = new Sherlock(1, "URDL", Position(0, 0), &dummyMap, 0, 0);
        MovingObject* watson = new Watson(2, "URDL", Position(0, 0), &dummyMap, 0, 0);
        MovingObject* criminal = new Criminal(0, Position(0, 0), &dummyMap, dynamic_cast<Sherlock*>(sherlock), dynamic_cast<Watson*>(watson));
        MovingObject* robotC = new RobotC(3, Position(5, 5), &dummyMap, dynamic_cast<Criminal*>(criminal));
        MovingObject* robotS = new RobotS(4, Position(5, 5), &dummyMap, dynamic_cast<Criminal*>(criminal), dynamic_cast<Sherlock*>(sherlock));
        MovingObject* robotW = new RobotW(5, Position(5, 5), &dummyMap, dynamic_cast<Criminal*>(criminal), dynamic_cast<Watson*>(watson));
        MovingObject* robotSW = new RobotSW(6, Position(5, 5), &dummyMap, dynamic_cast<Criminal*>(criminal), dynamic_cast<Sherlock*>(sherlock), dynamic_cast<Watson*>(watson));
        // str
        cout << "Sherlock: " << sherlock->str() << endl;
        cout << "Watson: " << watson->str() << endl;
        cout << "Criminal: " << criminal->str() << endl;
        cout << "RobotC: " << robotC->str() << endl;
        cout << "RobotS: " << robotS->str() << endl;
        cout << "RobotW: " << robotW->str() << endl;
        cout << "RobotSW: " << robotSW->str() << endl;
        // getCurrentPosition
        cout << "Sherlock: " << sherlock->getCurrentPosition().str() << endl;
        cout << "Watson: " << watson->getCurrentPosition().str() << endl;
        cout << "Criminal: " << criminal->getCurrentPosition().str() << endl;
        cout << "RobotC: " << robotC->getCurrentPosition().str() << endl;
        cout << "RobotS: " << robotS->getCurrentPosition().str() << endl;
        cout << "RobotW: " << robotW->getCurrentPosition().str() << endl;
        cout << "RobotSW: " << robotSW->getCurrentPosition().str() << endl;
        // getNextPosition
        // move
        for (int imove = 0; imove < 10; imove++)
        {
            cout << "Sherlock getNextPosition: " << sherlock->getNextPosition().str() << endl;
            cout << "Watson getNextPosition: " << watson->getNextPosition().str() << endl;
            cout << "Criminal getNextPosition: " << criminal->getNextPosition().str() << endl;
            cout << "RobotC getNextPosition: " << robotC->getNextPosition().str() << endl;
            cout << "RobotS getNextPosition: " << robotS->getNextPosition().str() << endl;
            cout << "RobotW getNextPosition: " << robotW->getNextPosition().str() << endl;
            cout << "RobotSW getNextPosition: " << robotSW->getNextPosition().str() << endl;

            sherlock->move();
            watson->move();
            criminal->move();
            robotC->move();
            robotS->move();
            robotW->move();
            robotSW->move();

            cout << "Sherlock move: " << sherlock->str() << endl;
            cout << "Watson move: " << watson->str() << endl;
            cout << "Criminal move: " << criminal->str() << endl;
            cout << "RobotC move: " << robotC->str() << endl;
            cout << "RobotS move: " << robotS->str() << endl;
            cout << "RobotW move: " << robotW->str() << endl;
            cout << "RobotSW move: " << robotSW->str() << endl;

            cout << "RobotC distance Sherlock: " << dynamic_cast<RobotC*>(robotC)->getDistance(dynamic_cast<Sherlock*>(sherlock)) << endl;
            cout << "RobotC distance Watson: " << dynamic_cast<RobotC*>(robotC)->getDistance(dynamic_cast<Watson*>(watson)) << endl;
            cout << "RobotS distance: " << dynamic_cast<Robot*>(robotS)->getDistance() << endl;
            cout << "RobotW distance: " << dynamic_cast<Robot*>(robotW)->getDistance() << endl;
            cout << "RobotSW distance: " << dynamic_cast<Robot*>(robotSW)->getDistance() << endl;
        }
        // ArrayMovingObject
        // add
        // isFull
        // str
        ArrayMovingObject* testArray = new ArrayMovingObject(7);
        cout << "isFull: " << testArray->isFull() << endl;
        cout << "ArrayMovingObject str: " << testArray->str() << endl;
        cout << "ArrayMovingObject add: " << testArray->add(criminal) << endl;
        cout << "isFull: " << testArray->isFull() << endl;
        cout << "ArrayMovingObject str: " << testArray->str() << endl;
        cout << "ArrayMovingObject add: " << testArray->add(sherlock) << endl;
        cout << "isFull: " << testArray->isFull() << endl;
        cout << "ArrayMovingObject str: " << testArray->str() << endl;
        cout << "ArrayMovingObject add: " << testArray->add(watson) << endl;
        cout << "isFull: " << testArray->isFull() << endl;
        cout << "ArrayMovingObject str: " << testArray->str() << endl;
        cout << "ArrayMovingObject add: " << testArray->add(robotC) << endl;
        cout << "isFull: " << testArray->isFull() << endl;
        cout << "ArrayMovingObject str: " << testArray->str() << endl;
        cout << "ArrayMovingObject add: " << testArray->add(robotS) << endl;
        cout << "isFull: " << testArray->isFull() << endl;
        cout << "ArrayMovingObject str: " << testArray->str() << endl;
        cout << "ArrayMovingObject add: " << testArray->add(robotW) << endl;
        cout << "isFull: " << testArray->isFull() << endl;
        cout << "ArrayMovingObject str: " << testArray->str() << endl;
        cout << "ArrayMovingObject add: " << testArray->add(robotSW) << endl;
        cout << "isFull: " << testArray->isFull() << endl;
        cout << "ArrayMovingObject str: " << testArray->str() << endl;
        cout << "ArrayMovingObject add: " << testArray->add(criminal) << endl;
        cout << "isFull: " << testArray->isFull() << endl;
        cout << "ArrayMovingObject str: " << testArray->str() << endl;
        delete testArray;
        delete sherlock;
        delete watson;
        delete criminal;
    }

    

    static void satc_01() {
        cout << "----- Sample Testcase 01 -----" << endl;
        int num_walls = 3;
        Position arr_walls[] = {Position(1, 2), Position(2, 3), Position(3, 4)};
        int num_fake_walls = 1;
        Position arr_fake_walls[] = {Position(2, 0)};

        Map * map = new Map(10, 10, num_walls, arr_walls, num_fake_walls, arr_fake_walls);
        
        Sherlock * sherlock = new Sherlock(1, "RUU", Position(1, 3), map, 250, 450);
        cout << sherlock->str() << endl;

        Watson * watson = new Watson(2, "LU", Position(2, 1), map, 300, 350);
        cout << watson->str() << endl;

        Criminal * criminal = new Criminal(0, Position(7, 9), map, sherlock, watson);
        cout << criminal->str() << endl;

        cout << "* Sherlock makes a move" << endl;
        sherlock->move();
        cout << sherlock->str() << endl;

        cout << "* Watson makes a move" << endl;
        watson->move();
        cout << watson->str() << endl;

        cout << "* Criminal makes a move" << endl;
        criminal->move();
        cout << criminal->str() << endl;

        ArrayMovingObject * arr_mv_objs = new ArrayMovingObject(10);
        arr_mv_objs->add(criminal);
        arr_mv_objs->add(sherlock);
        arr_mv_objs->add(watson);
        cout << arr_mv_objs->str() << endl;

        delete arr_mv_objs;
        delete sherlock;
        delete watson;
        delete criminal;
        delete map;
    }

    static void satc_02() {
        g_satc_02();
    }

    static void satc_03() {
        // Sample test for RobotC
        cout << "----- Sample Testcase 03 -----" << endl;
        int num_walls = 3;
        Position arr_walls[] = {Position(1, 2), Position(2, 3), Position(3, 4)};
        int num_fake_walls = 1;
        Position arr_fake_walls[] = {Position(2, 0)};

        Map * map = new Map(10, 10, num_walls, arr_walls, num_fake_walls, arr_fake_walls);

        Sherlock * sherlock = new Sherlock(1, "RUU", Position(1, 3), map, 250, 450);
        Watson * watson = new Watson(2, "LU", Position(2, 1), map, 300, 350);
        Criminal * criminal = new Criminal(0, Position(7, 9), map, sherlock, watson);
        criminal->move();

        RobotC * robotC = new RobotC(3, Position(7,9), map, criminal);
        cout << "Current position of Criminal: " << criminal->str() << endl;
        cout << "Criminal makes a move" << endl;
        criminal->move();
        cout << "New position of Criminal: " << criminal->str() << endl;
        RobotS* robotS = new RobotS(4, Position(5, 9), map, criminal, sherlock);
        robotS->move();
        cout << "Current position of robotC: " << robotC->str() << endl;
        cout << "RobotC makes a move" << endl;
        robotC->move();
        cout << "New position of robotC: " << robotC->str() << endl;
        cout << robotC->getItem()->getType() << endl;
        ArrayMovingObject* arr_mv_objs = new ArrayMovingObject(10);
        arr_mv_objs->add(criminal);
        arr_mv_objs->add(sherlock);
        arr_mv_objs->add(watson);
        arr_mv_objs->add(robotC);
        arr_mv_objs->add(robotS);

        //delete robotS;
        delete sherlock;
        delete watson;
        delete criminal;
        delete map;
        delete robotC;
    }

    static void satc_04() {
        cout << "----- Sample Testcase 04 -----" << endl;
        int num_walls = 5;
        Position arr_walls[] = { Position(1, 2), Position(2, 3), Position(3, 4), Position(8,9), Position(6,9)};
        int num_fake_walls = 8;
        Position arr_fake_walls[] = { Position(2, 0), Position(0,3), Position(1,4), Position(1,2), Position(2,3), Position(2,2),Position(1,1), Position(3,1)};

        Map* map = new Map(10, 10, num_walls, arr_walls, num_fake_walls, arr_fake_walls);

        Sherlock* sherlock = new Sherlock(1, "RUU", Position(1, 3), map, 250, 450);
        cout << sherlock->str() << endl;

        Watson* watson = new Watson(2, "LU", Position(2, 1), map, 300, 900);
        cout << watson->str() << endl;

        Criminal* criminal = new Criminal(0, Position(7, 9), map, sherlock, watson);
        cout << criminal->str() << endl;

        cout << "* Sherlock makes a move" << endl;
        sherlock->move();
        cout << sherlock->str() << endl;

        cout << "* Watson makes a move" << endl;
        watson->move();
        cout << watson->str() << endl;

        cout << "* Criminal makes a move" << endl;
        criminal->move();
        cout << criminal->str() << endl;

        ArrayMovingObject* arr_mv_objs = new ArrayMovingObject(10);
        arr_mv_objs->add(criminal);
        arr_mv_objs->add(sherlock);
        arr_mv_objs->add(watson);
        cout << arr_mv_objs->str() << endl;

        delete arr_mv_objs;
        delete sherlock;
        delete watson;
        delete criminal;
        delete map;
    }

    static void satc_05() {
        g_satc_05();
    }

    static void satc_06() {
        g_satc_06();
    }

    static void satc_07() {
        g_satc_07();
    }
    
    static void satc_08() {
        g_satc_08();
    }

    static void satc_10() {
        g_satc_10();
    }

    static void satc_16() {
        g_satc_16();
    }
    
    static void satc_09() {
        cout << "----- Sample Testcase 09 -----" << endl;
        int num_walls = 3;
        Position arr_walls[] = { Position(1, 2), Position(2, 3), Position(3, 4) };
        int num_fake_walls = 1;
        Position arr_fake_walls[] = { Position(2, 0) };

        Map* map = new Map(10, 10, num_walls, arr_walls, num_fake_walls, arr_fake_walls);

        Sherlock* sherlock = new Sherlock(1, "RUU", Position(1, 3), map, 100, 100);
        cout << sherlock->str() << endl;

        Watson* watson = new Watson(2, "LU", Position(2, 1), map, 300, 350);
        cout << watson->str() << endl;

        Criminal* criminal = new Criminal(0, Position(7, 9), map, sherlock, watson);
        cout << criminal->str() << endl;

        cout << "* Sherlock makes a move" << endl;
        sherlock->move();
        cout << sherlock->str() << endl;

        cout << "* Watson makes a move" << endl;
        watson->move();
        cout << watson->str() << endl;

        cout << "* Criminal makes a move" << endl;
        criminal->move();
        cout << criminal->str() << endl;

        ArrayMovingObject* arr_mv_objs = new ArrayMovingObject(10);
        cout << "-----------------------------------------------------" << endl;
        cout << arr_mv_objs->str() << endl;
        cout << "-----------------------------------------------------" << endl;

        arr_mv_objs->add(criminal);
        arr_mv_objs->add(sherlock);
        arr_mv_objs->add(watson);
        cout << arr_mv_objs->str() << endl;
        SherlockBag* sherlock_bag = new SherlockBag(sherlock);
        while (1) {
            MagicBook* magic_book = new MagicBook;
            if (!sherlock_bag->insert(magic_book)) break;
            PassingCard* passing_card = new PassingCard("all");
            if (!sherlock_bag->insert(passing_card)) break;
            FirstAid* first_aid = new FirstAid;
            if (!sherlock_bag->insert(first_aid)) break;
            EnergyDrink* energy_drink = new EnergyDrink;
            if (!sherlock_bag->insert(energy_drink)) break;
            ExcemptionCard* excemption_card = new ExcemptionCard;
            if (!sherlock_bag->insert(excemption_card)) break;
        }
        cout << sherlock_bag->str() << endl;
        cout << "HP: " << sherlock->getHp() << endl;
        cout << sherlock_bag->get(ENERGY_DRINK) <<endl;
        cout << "HP: " << sherlock->getHp() << endl;
        cout << sherlock_bag->str() << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << sherlock_bag->str() << endl;
        cout << sherlock_bag->get(MAGIC_BOOK) << endl;
        cout << sherlock_bag->str() << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << " test ham get khong doi so day ne" << endl << endl << endl;
        while (sherlock_bag->get() != NULL) {
            //cout << (sherlock_bag->get()->getType() != PASSING_CARD && sherlock_bag->get()->getType() != EXCEMPTION_CARD )<< endl;
            cout << "0--------------------0-----------------0-------------------0---------------------0----------------------0-------------------0" << endl;
            cout << sherlock_bag->str() << endl;
            cout << sherlock->getExp() << endl;
            cout << "HP: " << sherlock->getHp() << endl;
        }
        cout << "0--------------------0-----------------0-------------------0---------------------0----------------------0-------------------0" << endl;
        cout << sherlock_bag->str() << endl;
        cout << sherlock->getExp() << endl;
        cout << "HP: " << sherlock->getHp() << endl;
        sherlock_bag->get();
        cout << "0--------------------0-----------------0-------------------0---------------------0----------------------0-------------------0" << endl;
        cout << sherlock_bag->str() << endl;
        cout << sherlock->getExp() << endl;
        cout << "HP: " << sherlock->getHp() << endl;
        sherlock_bag->get(EXCEMPTION_CARD);
        cout << "0--------------------0-----------------0-------------------0---------------------0----------------------0-------------------0" << endl;
        cout << sherlock_bag->str() << endl;
        cout << sherlock->getExp() << endl;
        cout << "HP: " << sherlock->getHp() << endl;
        sherlock_bag->get(PASSING_CARD);
        cout << "0--------------------0-----------------0-------------------0---------------------0----------------------0-------------------0" << endl;
        cout << sherlock_bag->str() << endl;
        cout << sherlock->getExp() << endl;
        cout << "HP: " << sherlock->getHp() << endl;
        sherlock_bag->get(EXCEMPTION_CARD);
        cout << "0--------------------0-----------------0-------------------0---------------------0----------------------0-------------------0" << endl;
        cout << sherlock_bag->str() << endl;
        cout << sherlock->getExp() << endl;
        cout << "HP: " << sherlock->getHp() << endl;
        sherlock_bag->get(PASSING_CARD);
        cout << "0--------------------0-----------------0-------------------0---------------------0----------------------0-------------------0" << endl;
        cout << sherlock_bag->str() << endl;
        cout << sherlock->getExp() << endl;
        cout << "HP: " << sherlock->getHp() << endl;
        sherlock_bag->get(PASSING_CARD);
        cout << "0--------------------0-----------------0-------------------0---------------------0----------------------0-------------------0" << endl;
        cout << sherlock_bag->str() << endl;
        cout << sherlock->getExp() << endl;
        cout << "HP: " << sherlock->getHp() << endl;
        //while (sherlock_bag->get() != NULL || (sherlock_bag->get()->getType() != PASSING_CARD && sherlock_bag->get()->getType() != EXCEMPTION_CARD)) {
        //    //cout << (sherlock_bag->get()->getType() != PASSING_CARD && sherlock_bag->get()->getType() != EXCEMPTION_CARD )<< endl;
        //    cout << "0--------------------0-----------------0-------------------0---------------------0----------------------0-------------------0" << endl;
        //    cout << sherlock_bag->str() << endl;
        //    cout << sherlock->getExp() << endl;
        //}

        delete sherlock_bag;
        delete arr_mv_objs;
        delete sherlock;
        delete watson;
        delete criminal;
        delete map;
    }

    static void satc_11() {
        cout << "----- Sample Testcase 11 -----" << endl;
        int num_walls = 3;
        Position arr_walls[] = { Position(1, 2), Position(2, 3), Position(3, 4) };
        int num_fake_walls = 1;
        Position arr_fake_walls[] = { Position(2, 0) };

        Map* map = new Map(10, 10, num_walls, arr_walls, num_fake_walls, arr_fake_walls);

        Sherlock* sherlock = new Sherlock(1, "RUU", Position(1, 3), map, 250, 100);
        cout << sherlock->str() << endl;

        Watson* watson = new Watson(2, "LU", Position(2, 1), map, 300, 350);
        cout << watson->str() << endl;

        Criminal* criminal = new Criminal(0, Position(7, 9), map, sherlock, watson);
        cout << criminal->str() << endl;

        cout << "* Sherlock makes a move" << endl;
        sherlock->move();
        cout << sherlock->str() << endl;

        cout << "* Watson makes a move" << endl;
        watson->move();
        cout << watson->str() << endl;

        cout << "* Criminal makes a move" << endl;
        criminal->move();
        cout << criminal->str() << endl;

        ArrayMovingObject* arr_mv_objs = new ArrayMovingObject(10);
        arr_mv_objs->add(criminal);
        arr_mv_objs->add(sherlock);
        arr_mv_objs->add(watson);
        cout << arr_mv_objs->str() << endl;
        SherlockBag* sherlock_bag = new SherlockBag(sherlock);
        int sher = 2;
        while (sher--) {
            PassingCard* passing_card = new PassingCard("all");
            if (!sherlock_bag->insert(passing_card)) break;
            EnergyDrink* energy_drink = new EnergyDrink;
            if (!sherlock_bag->insert(energy_drink)) break;
            FirstAid* first_aid = new FirstAid;
            if (!sherlock_bag->insert(first_aid)) break;
            MagicBook* magic_book = new MagicBook;
            if (!sherlock_bag->insert(magic_book)) break;
        }
        WatsonBag* watson_bag = new WatsonBag(watson);
        int wat = 4;
        while (wat--) {
            MagicBook* magic_book = new MagicBook;
            if (!watson_bag->insert(magic_book)) break;
            EnergyDrink* energy_drink = new EnergyDrink;
            if (!watson_bag->insert(energy_drink)) break;
            ExcemptionCard* excemption_card = new ExcemptionCard;
            if (!watson_bag->insert(excemption_card)) break;
        }
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        cout << "_______________________________________________SHERLOCK_______________________________________________________" << endl;
        cout << sherlock_bag->str() << endl;
        cout << "_______________________________________________WATSON_______________________________________________________" << endl;
        cout << watson_bag->str() << endl;
        cout << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        cout << endl;
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++
        int sher_pass_card = 0;
        while (watson_bag->getSize()!=15) {
            if (watson_bag->insert(sherlock_bag->get(PASSING_CARD))) sher_pass_card++;
            else break;
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << endl;
            cout << "_______________________________________________SHERLOCK_______________________________________________________" << endl;
            cout << sherlock_bag->str() << endl;
            cout << "_______________________________________________WATSON_______________________________________________________" << endl;
            cout << watson_bag->str() << endl;
            cout << endl;
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << endl;
            cout << endl;
            cout << "sherlock pass card: " << sher_pass_card << endl;
        }
        while (sher_pass_card > 0) {
            if (sherlock_bag->insert(watson_bag->get(EXCEMPTION_CARD)) == 0) break;
            else sher_pass_card--;
        }
        cout << endl;
        cout << "sherlock pass card: " << sher_pass_card << endl;
        cout << endl;
        while (sher_pass_card > 0) {
            if (sherlock_bag->insert(watson_bag->get(PASSING_CARD)) == 0) break;
        }
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        cout << "_______________________________________________SHERLOCK_______________________________________________________" << endl;
        cout << sherlock_bag->str() << endl;
        cout << "_______________________________________________WATSON_______________________________________________________" << endl;
        cout << watson_bag->str() << endl;
        cout << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++



        delete sherlock_bag;
        delete watson_bag;
        delete arr_mv_objs;
        delete sherlock;
        delete watson;
        delete criminal;
        delete map;
    }

    static void satc_12() {
        cout << "----- Sample Testcase 11 -----" << endl;
        int num_walls = 3;
        Position arr_walls[] = { Position(1, 2), Position(2, 3), Position(3, 4) };
        int num_fake_walls = 1;
        Position arr_fake_walls[] = { Position(2, 0) };

        Map* map = new Map(10, 10, num_walls, arr_walls, num_fake_walls, arr_fake_walls);

        Sherlock* sherlock = new Sherlock(1, "RUU", Position(1, 3), map, 250, 100);
        cout << sherlock->str() << endl;

        Watson* watson = new Watson(2, "LU", Position(2, 1), map, 300, 350);
        cout << watson->str() << endl;

        Criminal* criminal = new Criminal(0, Position(7, 9), map, sherlock, watson);
        cout << criminal->str() << endl;

        cout << "* Sherlock makes a move" << endl;
        sherlock->move();
        cout << sherlock->str() << endl;

        cout << "* Watson makes a move" << endl;
        watson->move();
        cout << watson->str() << endl;

        cout << "* Criminal makes a move" << endl;
        criminal->move();
        cout << criminal->str() << endl;

        ArrayMovingObject* arr_mv_objs = new ArrayMovingObject(10);
        arr_mv_objs->add(criminal);
        arr_mv_objs->add(sherlock);
        arr_mv_objs->add(watson);
        cout << arr_mv_objs->str() << endl;
        SherlockBag* sherlock_bag = new SherlockBag(sherlock);
        int sher = 1;
        while (sher--) {
            PassingCard* passing_card = new PassingCard("all");
            if (!sherlock_bag->insert(passing_card)) break;        
        }
        WatsonBag* watson_bag = new WatsonBag(watson);
        int wat = 1;
        while (wat--) {
            ExcemptionCard* excemption_card = new ExcemptionCard;
            if (!watson_bag->insert(excemption_card)) break;
        }
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        cout << "_______________________________________________SHERLOCK_______________________________________________________" << endl;
        cout << sherlock_bag->str() << endl;
        cout << "_______________________________________________WATSON_______________________________________________________" << endl;
        cout << watson_bag->str() << endl;
        cout << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        cout << endl;
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++
        int sher_pass_card = 0;
        while (watson_bag->getSize() != 15) {
            if (watson_bag->insert(sherlock_bag->get(PASSING_CARD))) sher_pass_card++;
            else break;
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << endl;
            cout << "_______________________________________________SHERLOCK_______________________________________________________" << endl;
            cout << sherlock_bag->str() << endl;
            cout << "_______________________________________________WATSON_______________________________________________________" << endl;
            cout << watson_bag->str() << endl;
            cout << endl;
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << endl;
            cout << endl;
            cout << "sherlock pass card: " << sher_pass_card << endl;
        }
        while (sher_pass_card > 0) {
            if (sherlock_bag->insert(watson_bag->get(EXCEMPTION_CARD)) == 0) break;
            else sher_pass_card--;
        }
        cout << endl;
        cout << "sherlock pass card: " << sher_pass_card << endl;
        cout << endl;
        while (sher_pass_card > 0) {
            if (sherlock_bag->insert(watson_bag->get(PASSING_CARD)) == 0) break;
        }
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        cout << "_______________________________________________SHERLOCK_______________________________________________________" << endl;
        cout << sherlock_bag->str() << endl;
        cout << "_______________________________________________WATSON_______________________________________________________" << endl;
        cout << watson_bag->str() << endl;
        cout << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++



        delete sherlock_bag;
        delete watson_bag;
        delete arr_mv_objs;
        delete sherlock;
        delete watson;
        delete criminal;
        delete map;
    }

    static void satc_13() {
        cout << "----- Sample Testcase 013 -----" << endl;
        int num_walls = 1;
        Position arr_walls[] = { Position(0, 18) };
        int num_fake_walls = 5;
        int num_steps = 40;
        Position arr_fake_walls[] =  { Position(1, 10), Position(0, 6), Position(6, 15), Position(8, 3), Position(0, 9) };

        Map* map = new Map(9, 28, num_walls, arr_walls, num_fake_walls, arr_fake_walls);

        Sherlock* sherlock = new Sherlock(1, "D", Position(6, 2), map, 500, 500);
        cout << sherlock->str() << endl;

        Watson* watson = new Watson(2, "UDDRDDR", Position(1, 22), map, 500, 500);
        cout << watson->str() << endl;

        Criminal* criminal = new Criminal(0, Position(0, 23), map, sherlock, watson);
        cout << criminal->str() << endl;

        cout << "* Sherlock makes a move" << endl;
        sherlock->move();
        cout << sherlock->str() << endl;

        cout << "* Watson makes a move" << endl;
        watson->move();
        cout << watson->str() << endl;

        cout << "* Criminal makes a move" << endl;
        criminal->move();
        cout << criminal->str() << endl;

        ArrayMovingObject* arr_mv_objs = new ArrayMovingObject(10);
        arr_mv_objs->add(criminal);
        arr_mv_objs->add(sherlock);
        arr_mv_objs->add(watson);
        cout << arr_mv_objs->str() << endl;

        cout << sherlock->str() << endl;
        cout << watson->str() << endl;
        cout << criminal->str() << endl;

        RobotC* robotC = nullptr;

        for (int i = 0; i < num_steps; i++)
        {
            Position temp_pos = criminal->getCurrentPosition();
            cout << "STEP" << i + 1 << ": * Moving objects make a move" << endl;

            criminal->move();
            sherlock->move();
            watson->move();
            if (robotC != nullptr)
                robotC->move();

            cout << arr_mv_objs->str() << endl;
            if (i == 3)
            {
                cout << "* Create new RobotC" << endl;
                robotC = new RobotC(3, temp_pos, map, criminal);
                cout << robotC->str() << endl;
                arr_mv_objs->add(robotC);
            }
        }

        delete sherlock;
        delete watson;
        delete criminal;
        delete arr_mv_objs;
        delete map;
    }

    static void satc_14() {
        cout << "----- Sample Testcase 14 -----" << endl;
        int num_walls = 1;
        Position arr_walls[] = { Position(0, 18) };
        int num_fake_walls = 5;
        int num_steps = 40;
        Position arr_fake_walls[] = { Position(1, 10), Position(0, 6), Position(6, 15), Position(8, 3), Position(0, 9) };

        Map* map = new Map(9, 28, num_walls, arr_walls, num_fake_walls, arr_fake_walls);

        Sherlock* sherlock = new Sherlock(1, "UDDRDDR", Position(6, 2), map, 500, 500);
        cout << sherlock->str() << endl;

        Watson* watson = new Watson(2, "D", Position(1, 22), map, 500, 500);
        cout << watson->str() << endl;

        Criminal* criminal = new Criminal(0, Position(0, 23), map, sherlock, watson);
        cout << criminal->str() << endl;

        ArrayMovingObject* arr_mv_objs = new ArrayMovingObject(10);
        arr_mv_objs->add(criminal);
        arr_mv_objs->add(sherlock);
        arr_mv_objs->add(watson);
        cout << arr_mv_objs->str() << endl;

        cout << sherlock->str() << endl;
        cout << watson->str() << endl;
        cout << criminal->str() << endl;

        RobotSW* robotSW = nullptr;

        for (int i = 0; i < num_steps; i++)
        {
            Position temp_pos = criminal->getCurrentPosition();
            cout << "STEP" << i + 1 << ": * Moving objects make a move" << endl;

            criminal->move();
            sherlock->move();
            watson->move();
            if (robotSW != nullptr)
                robotSW->move();

            cout << arr_mv_objs->str() << endl;
            if (i == 12)
            {
                cout << "* Create new RobotWS" << endl;
                robotSW = new RobotSW(6, temp_pos, map, criminal, sherlock, watson);
                cout << robotSW->str() << endl;
                arr_mv_objs->add(robotSW);
            }
        }

        delete sherlock;
        delete watson;
        delete criminal;
        delete arr_mv_objs;
        delete map;
    }
    static void satc_15() {
        g_satc_15();
    }
    static void satc_17() {
        g_satc_17();
    }
    static void satc_18() {
        g_satc_18();
    }

    static void satc_19() {
        cout << "----- Sample Testcase 11 -----" << endl;
        int num_walls = 3;
        Position arr_walls[] = { Position(1, 2), Position(2, 3), Position(3, 4) };
        int num_fake_walls = 1;
        Position arr_fake_walls[] = { Position(2, 0) };
        Map* map = new Map(10, 10, num_walls, arr_walls, num_fake_walls, arr_fake_walls);
        Sherlock* sherlock = new Sherlock(1, "RUU", Position(1, 3), map, 100, 100);
        Watson* watson = new Watson(2, "LU", Position(2, 1), map, 300, 350);
        Criminal* criminal = new Criminal(0, Position(7, 9), map, sherlock, watson);
        ArrayMovingObject* arr_mv_objs = new ArrayMovingObject(10);
        arr_mv_objs->add(criminal);
        arr_mv_objs->add(sherlock);
        arr_mv_objs->add(watson);

        SherlockBag* sherlock_bag = new SherlockBag(sherlock);
        cout << sherlock_bag->passingSearch() << endl;
        int sher = 2;
        while (sher--) {
            /*MagicBook* magic_book = new MagicBook;
            if (!sherlock_bag->insert(magic_book)) break;*/
            PassingCard* passing_card = new PassingCard("all");
            if (!sherlock_bag->insert(passing_card)) break;
            cout << sherlock_bag->passingSearch() << endl;
            FirstAid* first_aid = new FirstAid;
            if (!sherlock_bag->insert(first_aid)) break;
            EnergyDrink* energy_drink = new EnergyDrink;
            if (!sherlock_bag->insert(energy_drink)) break;
            /*ExcemptionCard* excemption_card = new ExcemptionCard;
            if (!sherlock_bag->insert(excemption_card)) break;*/
        }
        WatsonBag* watson_bag = new WatsonBag(watson);
        cout << watson_bag->excemptionSearch() << endl;
        int wat = 3;
        while (wat--) {
            MagicBook* magic_book = new MagicBook;
            if (!watson_bag->insert(magic_book)) break;
            /*PassingCard* passing_card = new PassingCard("all");
            if (!watson_bag->insert(passing_card)) break;*/
            /*FirstAid* first_aid = new FirstAid;
            if (!watson_bag->insert(first_aid)) break;
            EnergyDrink* energy_drink = new EnergyDrink;
            if (!watson_bag->insert(energy_drink)) break;*/
            ExcemptionCard* excemption_card = new ExcemptionCard;
            if (!watson_bag->insert(excemption_card)) break;
            cout << watson_bag->excemptionSearch() << endl;
        }

        if (sherlock_bag->passingSearch() && watson_bag->excemptionSearch()) {
            while (watson_bag->getSize() < 15) {
                cout << endl;
                cout << "++++++++++++++++++++++++++++++++++++++++++++===============================" << endl;
                cout << sherlock_bag->str() << endl;
                cout << watson_bag->str() << endl;
                cout << "++++++++++++++++++++++++++++++++++++++++++++===============================" << endl;
                cout << endl;
                if (watson_bag->insert(sherlock_bag->get(PASSING_CARD))) {}
                else break;
            }
            while (sherlock_bag->getSize() < 13) {
                cout << endl;
                cout << "++++++++++++++++++++++++++++++++++++++++++++================================" << endl;
                cout << sherlock_bag->str() << endl;
                cout << watson_bag->str() << endl;
                cout << "++++++++++++++++++++++++++++++++++++++++++++================================" << endl;
                cout << endl;
                if (sherlock_bag->insert(watson_bag->get(EXCEMPTION_CARD))) {}
                else break;
            }
        }
        cout << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++===============================" << endl;
        cout << sherlock_bag->str() << endl;
        cout << watson_bag->str() << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++===============================" << endl;
        cout << endl;
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++
        cout << endl;
        cout << "++++++++++++++++++++++++++++++++==========================================================================++++++++++++" << endl;
        cout << sherlock_bag->str() << endl;
        cout << watson_bag->str() << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++
        watson_bag->get();
        watson_bag->get();
        watson_bag->get();
        watson_bag->get();
        watson_bag->get();
        watson_bag->get();
        watson_bag->get();
        watson_bag->get();
        watson_bag->get();
        watson_bag->get();
        watson_bag->get();
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++
        cout << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << sherlock_bag->str() << endl;
        cout << watson_bag->str() << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++
        int sher_pass_card = 6;
        while (sher_pass_card--) {
            cout << endl;
            cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << sherlock_bag->str() << endl;
            BaseItem* found_item2 = NULL;
            int item_value = sherlock_bag->search();
            if (item_value == 0) found_item2 = sherlock_bag->get(MAGIC_BOOK);
            else if (item_value == 1) found_item2 = sherlock_bag->get(ENERGY_DRINK);
            else if (item_value == 2) found_item2 = sherlock_bag->get(FIRST_AID);
            if (found_item2 != NULL) {
                cout << found_item2->getType() << endl;
            }
            cout << endl;
            //cout << watson_bag->str() << endl;
            cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << endl;
            cout << "sherlock pass card: " << sher_pass_card << endl;
        }
        while (sher_pass_card > 0) {
            if (sherlock_bag->insert(watson_bag->get(EXCEMPTION_CARD)) == 0) break;
            else sher_pass_card--;
        }
        cout << "sherlock pass card: " << sher_pass_card << endl;
        while (sher_pass_card > 0) {
            if (sherlock_bag->insert(watson_bag->get(PASSING_CARD)) == 0) break;
        }
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++
        cout << sherlock_bag->str() << endl;
        cout << watson_bag->str() << endl;
        //DEBUG++++++++++++++++++++++++++++++++++++++++++++



        delete sherlock_bag;
        delete watson_bag;
        delete arr_mv_objs;
        delete sherlock;
        delete watson;
        delete criminal;
        delete map;
    }
    /*static void tc_1167() {
        ::tc_1167();
    }*/
    //static void tc_1207() {
    //    cout << "----- Testcase 207 -----" << endl;
    //    int num_walls = 3;
    //    Position arr_walls[] = { Position(2, 3), Position(3, 3), Position(4, 3) };
    //    int num_fake_walls = 1;
    //    Position arr_fake_walls[] = { Position(2, 0) };

    //    Map* map = new Map(10, 10, num_walls, arr_walls, num_fake_walls, arr_fake_walls);

    //    Sherlock* sherlock = new Sherlock(1, "RUU", Position(3, 4), map, 250, 450);
    //    Watson* watson = new Watson(2, "LU", Position(2, 1), map, 300, 350);
    //    Criminal* criminal = new Criminal(0, Position(7, 9), map, sherlock, watson);
    //    RobotS* robotS = new RobotS(3, Position(3, 2), map, criminal, sherlock);
    //    int distance_old = robotS->getDistance();


    //    Position new_position = robotS->getNextPosition();  // 2,2
    //    RobotS* robotS_new = new RobotS(4, new_position, map, criminal, sherlock);
    //    int distance_new = robotS->getDistance();

    //    cout << robotS->pos.str() << endl;
    //    cout << "Current: " << robotS->pos.getRow() << " " << robotS->pos.getCol() << endl;
    //    cout << "Next position: " << robotS_new->pos.getRow() << " " << robotS_new->pos.getCol() << endl;

    //    cout << distance_old <<"    "<< distance_new << endl;
    //    if (distance_old - distance_new >= 0) cout << "Can get close";
    //    else cout << "Can not get close";
    //    robotS->move();

    //    delete robotS;
    //    delete robotS_new;
    //    delete sherlock;
    //    delete watson;
    //    delete criminal;
    //    delete map;
    //}
    /*static void tc_1117() {
        ::tc_1117();
    }*/
};

int main(int argc, const char * argv[]) {
    // TestStudyInPink::test();
    // TestStudyInPink::tc_1117();
    // TestStudyInPink::satc_01();
    // TestStudyInPink::satc_02();
    // TestStudyInPink::satc_03();
    // TestStudyInPink::satc_04();
    // TestStudyInPink::satc_05();
    // TestStudyInPink::satc_06();
    // TestStudyInPink::satc_07();
    // TestStudyInPink::satc_08();
    // TestStudyInPink::satc_09();
    // TestStudyInPink::satc_10();
    // TestStudyInPink::satc_11();
    // TestStudyInPink::satc_12();
    // TestStudyInPink::satc_13();
    // TestStudyInPink::satc_14();
    // TestStudyInPink::satc_15();
    // TestStudyInPink::satc_16();
    // TestStudyInPink::satc_17();
    TestStudyInPink::satc_18();
    // TestStudyInPink::satc_19();
    // TestStudyInPink::testBasic();
    // /////////////////////////////////////////////////////////
    //TestStudyInPink::tc_1001();
    //TestStudyInPink::tc_1004();
    //TestStudyInPink::tc_1009();
    //TestStudyInPink::tc_1014();
    //TestStudyInPink::tc_1015();
    //TestStudyInPink::tc_1016();
    //TestStudyInPink::tc_1017();
    //TestStudyInPink::tc_1043();
    //TestStudyInPink::tc_1057();
    //TestStudyInPink::tc_1062();
    //TestStudyInPink::tc_1063();
    //TestStudyInPink::tc_1066();
    //TestStudyInPink::tc_1067();
    //TestStudyInPink::tc_1070();
    //TestStudyInPink::tc_1094();
    //TestStudyInPink::tc_1099();
    //TestStudyInPink::tc_1109();
    //TestStudyInPink::tc_1114();
    //TestStudyInPink::tc_1120();
    //TestStudyInPink::tc_1132();
    //TestStudyInPink::tc_1138();
    //TestStudyInPink::tc_1143();
    //TestStudyInPink::tc_1153();
    //TestStudyInPink::tc_1159();
    //TestStudyInPink::tc_1167();
    //TestStudyInPink::tc_1171();
    //TestStudyInPink::tc_1181();
    //TestStudyInPink::tc_1185();
    //TestStudyInPink::tc_1199();
    //TestStudyInPink::tc_1211();
    //TestStudyInPink::tc_1223();
    //TestStudyInPink::tc_1235();
    //TestStudyInPink::tc_1247();
    //TestStudyInPink::tc_1278();
    //TestStudyInPink::tc_1297();
    //TestStudyInPink::tc_1323();
    //TestStudyInPink::tc_1286();
    //TestStudyInPink::tc_1194();
    //TestStudyInPink::tc_1253();
    //TestStudyInPink::tc_1354();
    /*for (int i = 280; i < 382; i++) {
        TestStudyInPink::test(i);
        cout << endl;
    }*/
    /*TestStudyInPink::tc_1101();
    TestStudyInPink::tc_1102();
    TestStudyInPink::tc_1103();
    TestStudyInPink::tc_1104();
    TestStudyInPink::tc_1105();
    TestStudyInPink::tc_1106();
    TestStudyInPink::tc_1107();
    TestStudyInPink::tc_1108();
    TestStudyInPink::tc_1109();
    TestStudyInPink::tc_1110();
    TestStudyInPink::tc_1111();
    TestStudyInPink::tc_1112();
    TestStudyInPink::tc_1113();
    TestStudyInPink::tc_1114();
    TestStudyInPink::tc_1115();
    TestStudyInPink::tc_1116();
    TestStudyInPink::tc_1117();
    TestStudyInPink::tc_1118();
    TestStudyInPink::tc_1119();
    TestStudyInPink::tc_1120();
    TestStudyInPink::tc_1121();
    TestStudyInPink::tc_1122();
    TestStudyInPink::tc_1123();
    TestStudyInPink::tc_1124();
    TestStudyInPink::tc_1125();
    TestStudyInPink::tc_1126();
    TestStudyInPink::tc_1127();
    TestStudyInPink::tc_1128();
    TestStudyInPink::tc_1129();
    TestStudyInPink::tc_1130();
    TestStudyInPink::tc_1131();
    TestStudyInPink::tc_1132();
    TestStudyInPink::tc_1133();
    TestStudyInPink::tc_1134();
    TestStudyInPink::tc_1135();
    TestStudyInPink::tc_1136();
    TestStudyInPink::tc_1137();
    TestStudyInPink::tc_1138();
    TestStudyInPink::tc_1139();
    TestStudyInPink::tc_1140();
    TestStudyInPink::tc_1141();
    TestStudyInPink::tc_1142();
    TestStudyInPink::tc_1143();
    TestStudyInPink::tc_1144();
    TestStudyInPink::tc_1145();
    TestStudyInPink::tc_1146();
    TestStudyInPink::tc_1147();
    TestStudyInPink::tc_1148();
    TestStudyInPink::tc_1149();
    TestStudyInPink::tc_1150();
    TestStudyInPink::tc_1151();
    TestStudyInPink::tc_1152();
    TestStudyInPink::tc_1153();
    TestStudyInPink::tc_1154();
    TestStudyInPink::tc_1155();
    TestStudyInPink::tc_1156();
    TestStudyInPink::tc_1157();
    TestStudyInPink::tc_1158();
    TestStudyInPink::tc_1159();
    TestStudyInPink::tc_1160();
    TestStudyInPink::tc_1161();
    TestStudyInPink::tc_1162();
    TestStudyInPink::tc_1163();
    TestStudyInPink::tc_1164();
    TestStudyInPink::tc_1165();
    TestStudyInPink::tc_1166();
    TestStudyInPink::tc_1167();
    TestStudyInPink::tc_1168();
    TestStudyInPink::tc_1169();
    TestStudyInPink::tc_1170();
    TestStudyInPink::tc_1171();
    TestStudyInPink::tc_1172();
    TestStudyInPink::tc_1173();
    TestStudyInPink::tc_1174();
    TestStudyInPink::tc_1175();
    TestStudyInPink::tc_1176();
    TestStudyInPink::tc_1177();
    TestStudyInPink::tc_1178();
    TestStudyInPink::tc_1179();
    TestStudyInPink::tc_1180();
    TestStudyInPink::tc_1181();
    TestStudyInPink::tc_1182();
    TestStudyInPink::tc_1183();
    TestStudyInPink::tc_1184();
    TestStudyInPink::tc_1185();
    TestStudyInPink::tc_1186();
    TestStudyInPink::tc_1187();
    TestStudyInPink::tc_1188();
    TestStudyInPink::tc_1189();
    TestStudyInPink::tc_1190();
    TestStudyInPink::tc_1191();
    TestStudyInPink::tc_1192();
    TestStudyInPink::tc_1193();
    TestStudyInPink::tc_1194();
    TestStudyInPink::tc_1195();
    TestStudyInPink::tc_1196();
    TestStudyInPink::tc_1197();
    TestStudyInPink::tc_1198();
    TestStudyInPink::tc_1199();
    TestStudyInPink::tc_1200();
    TestStudyInPink::tc_1201();
    TestStudyInPink::tc_1202();
    TestStudyInPink::tc_1203();
    TestStudyInPink::tc_1204();
    TestStudyInPink::tc_1205();
    TestStudyInPink::tc_1206();
    TestStudyInPink::tc_1207();
    TestStudyInPink::tc_1208();
    TestStudyInPink::tc_1209();
    TestStudyInPink::tc_1210();
    TestStudyInPink::tc_1211();
    TestStudyInPink::tc_1212();
    TestStudyInPink::tc_1213();
    TestStudyInPink::tc_1214();
    TestStudyInPink::tc_1215();
    TestStudyInPink::tc_1216();
    TestStudyInPink::tc_1217();
    TestStudyInPink::tc_1218();
    TestStudyInPink::tc_1219();
    TestStudyInPink::tc_1220();
    TestStudyInPink::tc_1221();
    TestStudyInPink::tc_1222();
    TestStudyInPink::tc_1223();
    TestStudyInPink::tc_1224();
    TestStudyInPink::tc_1225();
    TestStudyInPink::tc_1226();
    TestStudyInPink::tc_1227();
    TestStudyInPink::tc_1228();
    TestStudyInPink::tc_1229();
    TestStudyInPink::tc_1230();
    TestStudyInPink::tc_1231();
    TestStudyInPink::tc_1232();
    TestStudyInPink::tc_1233();
    TestStudyInPink::tc_1234();
    TestStudyInPink::tc_1235();
    TestStudyInPink::tc_1236();
    TestStudyInPink::tc_1237();
    TestStudyInPink::tc_1238();
    TestStudyInPink::tc_1239();
    TestStudyInPink::tc_1240();
    TestStudyInPink::tc_1241();
    TestStudyInPink::tc_1242();
    TestStudyInPink::tc_1243();
    TestStudyInPink::tc_1244();
    TestStudyInPink::tc_1245();
    TestStudyInPink::tc_1246();
    TestStudyInPink::tc_1247();
    TestStudyInPink::tc_1248();
    TestStudyInPink::tc_1249();
    TestStudyInPink::tc_1250();
    TestStudyInPink::tc_1251();
    TestStudyInPink::tc_1252();
    TestStudyInPink::tc_1253();
    TestStudyInPink::tc_1254();
    TestStudyInPink::tc_1255();
    TestStudyInPink::tc_1256();
    TestStudyInPink::tc_1257();
    TestStudyInPink::tc_1258();
    TestStudyInPink::tc_1259();
    TestStudyInPink::tc_1260();
    TestStudyInPink::tc_1261();
    TestStudyInPink::tc_1262();
    TestStudyInPink::tc_1263();
    TestStudyInPink::tc_1264();
    TestStudyInPink::tc_1265();
    TestStudyInPink::tc_1266();
    TestStudyInPink::tc_1267();
    TestStudyInPink::tc_1268();
    TestStudyInPink::tc_1269();
    TestStudyInPink::tc_1270();
    TestStudyInPink::tc_1271();
    TestStudyInPink::tc_1272();
    TestStudyInPink::tc_1273();
    TestStudyInPink::tc_1274();
    TestStudyInPink::tc_1275();
    TestStudyInPink::tc_1276();
    TestStudyInPink::tc_1277();
    TestStudyInPink::tc_1278();
    TestStudyInPink::tc_1279();
    TestStudyInPink::tc_1280();
    TestStudyInPink::tc_1281();
    TestStudyInPink::tc_1282();
    TestStudyInPink::tc_1283();
    TestStudyInPink::tc_1284();
    TestStudyInPink::tc_1285();
    TestStudyInPink::tc_1286();
    TestStudyInPink::tc_1287();
    TestStudyInPink::tc_1288();
    TestStudyInPink::tc_1289();
    TestStudyInPink::tc_1290();
    TestStudyInPink::tc_1291();
    TestStudyInPink::tc_1292();
    TestStudyInPink::tc_1293();
    TestStudyInPink::tc_1294();
    TestStudyInPink::tc_1295();
    TestStudyInPink::tc_1296();
    TestStudyInPink::tc_1297();
    TestStudyInPink::tc_1298();
    TestStudyInPink::tc_1299();
    TestStudyInPink::tc_1300();
    TestStudyInPink::tc_1301();
    TestStudyInPink::tc_1302();
    TestStudyInPink::tc_1303();
    TestStudyInPink::tc_1304();
    TestStudyInPink::tc_1305();
    TestStudyInPink::tc_1306();
    TestStudyInPink::tc_1307();
    TestStudyInPink::tc_1308();
    TestStudyInPink::tc_1309();
    TestStudyInPink::tc_1310();
    TestStudyInPink::tc_1311();
    TestStudyInPink::tc_1312();
    TestStudyInPink::tc_1313();
    TestStudyInPink::tc_1314();
    TestStudyInPink::tc_1315();
    TestStudyInPink::tc_1316();
    TestStudyInPink::tc_1317();
    TestStudyInPink::tc_1318();
    TestStudyInPink::tc_1319();
    TestStudyInPink::tc_1320();
    TestStudyInPink::tc_1321();
    TestStudyInPink::tc_1322();
    TestStudyInPink::tc_1323();
    TestStudyInPink::tc_1324();
    TestStudyInPink::tc_1325();
    TestStudyInPink::tc_1326();
    TestStudyInPink::tc_1327();
    TestStudyInPink::tc_1328();
    TestStudyInPink::tc_1329();
    TestStudyInPink::tc_1330();
    TestStudyInPink::tc_1331();
    TestStudyInPink::tc_1332();
    TestStudyInPink::tc_1333();
    TestStudyInPink::tc_1334();
    TestStudyInPink::tc_1335();
    TestStudyInPink::tc_1336();
    TestStudyInPink::tc_1337();
    TestStudyInPink::tc_1338();
    TestStudyInPink::tc_1339();
    TestStudyInPink::tc_1340();
    TestStudyInPink::tc_1341();
    TestStudyInPink::tc_1342();
    TestStudyInPink::tc_1343();
    TestStudyInPink::tc_1344();
    TestStudyInPink::tc_1345();
    TestStudyInPink::tc_1346();
    TestStudyInPink::tc_1347();
    TestStudyInPink::tc_1348();
    TestStudyInPink::tc_1349();
    TestStudyInPink::tc_1350();
    TestStudyInPink::tc_1351();
    TestStudyInPink::tc_1352();
    TestStudyInPink::tc_1353();
    TestStudyInPink::tc_1354();
    TestStudyInPink::tc_1355();
    TestStudyInPink::tc_1356();
    TestStudyInPink::tc_1357();
    TestStudyInPink::tc_1358();
    TestStudyInPink::tc_1359();
    TestStudyInPink::tc_1360();
    TestStudyInPink::tc_1361();
    TestStudyInPink::tc_1362();
    TestStudyInPink::tc_1363();
    TestStudyInPink::tc_1364();
    TestStudyInPink::tc_1365();
    TestStudyInPink::tc_1366();
    TestStudyInPink::tc_1367();
    TestStudyInPink::tc_1368();
    TestStudyInPink::tc_1369();
    TestStudyInPink::tc_1370();
    TestStudyInPink::tc_1371();
    TestStudyInPink::tc_1372();
    TestStudyInPink::tc_1373();
    TestStudyInPink::tc_1374();
    TestStudyInPink::tc_1375();
    TestStudyInPink::tc_1376();
    TestStudyInPink::tc_1377();
    TestStudyInPink::tc_1378();
    TestStudyInPink::tc_1379();
    TestStudyInPink::tc_1380();
    TestStudyInPink::tc_1381();*/
    return 0;
}
