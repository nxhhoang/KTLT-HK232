/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_2_H_
#define _H_STUDY_IN_PINK_2_H_

#include "main.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Forward declaration
class MovingObject;
class Position;
class Configuration;
class Map;

class MapElement;
class Wall;
class Path;
class FakeWall;

class Character;
class Criminal;
class Sherlock;
class Watson;
class Robot;
class RobotS;
class RobotW;
class RobotSW;
class RobotC;

class ArrayMovingObject;
class StudyPinkProgram;

class BaseItem;
class FirstAid;
class EnergyDrink;
class MagicBook;
class PassingCard;
class ExcemptionCard;

class BaseBag;
class SherlockBag;
class WatsonBag;

class TestStudyInPink;

enum ItemType { MAGIC_BOOK, ENERGY_DRINK, FIRST_AID, EXCEMPTION_CARD, PASSING_CARD };
enum ElementType { PATH, WALL, FAKE_WALL };
enum RobotType { C=0, S, W, SW };

int Manhattan(MovingObject* mv_obj1, MovingObject* mv_obj2);
int Manhattan(const MovingObject* mv_obj1, MovingObject* mv_obj2);
int Suitable(int x, int low, int high);

class MapElement {
    friend class TestStudyInPink;
protected:
    ElementType type;
public:
    MapElement(ElementType in_type);
    virtual ~MapElement();  
    virtual ElementType getType() const;
};

class Path : public MapElement {
    friend class TestStudyInPink;
public:
    Path();
    ElementType getType() const;
};

class Wall : public MapElement {
    friend class TestStudyInPink;
public:
    Wall();
    ElementType getType() const;
};

class FakeWall : public MapElement {
    friend class TestStudyInPink;
private:
    int req_exp;
public:
    FakeWall();
    FakeWall(int in_req_exp);
    ElementType getType() const;
    int getReqExp() const ;
};



class Map {
    friend class TestStudyInPink;
private:
    int num_rows, num_cols;
    MapElement*** map;             
public:
    Map(int num_rows, int num_cols, int num_walls, Position* array_walls, int num_fake_walls, Position* array_fake_walls);
    ~Map();
    bool isValid(const Position& pos, MovingObject* mv_obj) const;
    bool isValidPosition(int row, int col, MovingObject* mv_obj) const;
};



class Position {
    friend class TestStudyInPink;
private:
    int r, c;
public:
    static const Position npos;

    Position(int r = 0, int c = 0);

    Position(const string& str_pos);

    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);

    string str() const;

    bool isEqual(int in_r, int in_c) const;
    bool isEqual(const std::string& str_pos) const;
    bool isEqual(Position pos) const;
};

class MovingObject {
    friend class TestStudyInPink;
protected:
    int index;
    Position pos;
    Map * map;
    string name;

public:
    virtual ~MovingObject();
    MovingObject(int index, const Position pos, Map* map, const string& name = "");
    virtual Position getNextPosition() = 0;
    Position getCurrentPosition() const;
    virtual void move() = 0;
    virtual string str() const = 0;
    string getName() const;
    int getIndex() const;
};


class Character : public MovingObject {
    friend class TestStudyInPink;
protected:
    string moving_rule;
    int hp;
    int exp;
public:
    Character(int index, const string& moving_rule, const Position& init_pos, Map* map, const string& name = "");
    virtual Position getNextPosition() = 0;
    virtual void move() = 0;
    virtual string str() const = 0;
    virtual int getExp() const;
    virtual void setExp(int exp);
    virtual int getHp() const;
    virtual void setHp(int hp);
    ~Character();
};


class Sherlock : public Character {
    friend class TestStudyInPink;
private:
    // TODO
    int dem = 0;

public:
    Sherlock(int index, const string& moving_rule, const Position& init_pos, Map* map, int init_hp, int init_exp) ;
    Position getNextPosition();
    void move();
    string str() const;
    // ...
    void setCurrentPosition(Position diff_pos);
    int getExp() const;
    void setExp(int exp);
    int getHp() const;
    void setHp(int hp);
    ~Sherlock();
};


class Watson : public Character {
    friend class TestStudyInPink;
private:
    // TODO
    int demm = 0;

public:
    Watson(int index, const string & moving_rule, const Position & init_pos, Map * map, int init_hp, int init_exp);
    Position getNextPosition();
    void move();
    string str() const;
    // ...
    void setCurrentPosition(Position diff_pos);
    int getExp() const;
    void setExp(int exp);
    int getHp() const;
    void setHp(int hp);
    ~Watson();
};

class Criminal : public Character {
    friend class TestStudyInPink;
private:
    // TODO
    Sherlock* sherlock;
    Watson* watson;

public:
    //This is used to determine the old direction 
    static char direction;
    static int robot_create;
    static bool create_permit;
    //This is used to determine the old direction 
    Criminal(int index, const Position & init_pos, Map * map, Sherlock * sherlock, Watson * watson) ;
    Position getNextPosition();
    void move();
    string str() const;
    int getSherlockDistance() const;
    int getWatsonDistance() const;
    int getExp() const;
    void setExp(int exp);
    int getHp() const;
    void setHp(int hp);
    ~Criminal();
};

class ArrayMovingObject {
    friend class TestStudyInPink;
private:
    // TODO
    int capacity;
    MovingObject** arr_mv_objs;
    int count = 0;

public:
    ArrayMovingObject(int capacity);

    ~ArrayMovingObject() ;
    bool isFull() const;
    bool add(MovingObject* mv_obj);
    MovingObject* get(int index) const;
    int size() const; // return current number of elements in the array
    string str() const; 
};

class Configuration {
    friend class StudyPinkProgram;
    friend class TestStudyInPink;

private:
    int map_num_rows, map_num_cols;
    int max_num_moving_objects;
    int num_walls;
    Position* arr_walls;
    int num_fake_walls;
    Position* arr_fake_walls;
    //Sherlock//
    string sherlock_moving_rule;
    Position sherlock_init_pos;
    int sherlock_init_hp;
    int sherlock_init_exp;
    ///Watson//
    string watson_moving_rule;
    Position watson_init_pos;
    int watson_init_hp;
    int watson_init_exp;
    //Criminal//
    Position criminal_init_pos;
    int num_steps;

public:
    Configuration(const string & filepath);
    ~Configuration();
    string str() const;
};

// Robot, BaseItem, BaseBag,...
class Robot : public MovingObject {
    friend class TestStudyInPink;
protected:
    RobotType robot_type;
    Criminal* criminal;
    BaseItem* item;
    int s;

public:
    Robot(int index, const Position& init_pos, Map* map, Criminal* criminal);//
    virtual void move() = 0;
    RobotType getType() const;
    virtual Position getNextPosition() = 0;
    BaseItem* getItem() const;
    virtual int getDistance() const = 0;
    virtual string str() const; 
    virtual ~Robot();
};

/// /////////////////////////////////RobotC/////////////////////////
class RobotC : public Robot {
    friend class TestStudyInPink;
public:
    RobotC(int index, const Position& init_pos, Map* map, Criminal* criminal);//
    Position getNextPosition();
    void move();
    int getDistance() const;
    int getDistance(Sherlock* sherlock) const;//
    int getDistance(Watson* watson) const;//
    string str() const;//
    ~RobotC();
};

/// /////////////////////////////////RobotS/////////////////////////
class RobotS : public Robot {
    friend class TestStudyInPink;
private:
    Sherlock* sherlock;
    int dist; /////////////////////
public:
    RobotS(int index, const Position& init_pos, Map* map, Criminal* criminal, Sherlock* sherlock); //
    Position getNextPosition();//
    int getDistance() const;//
    void move();//
    string str() const;//
    ~RobotS();
};


/// /////////////////////////////////RobotW/////////////////////////
class RobotW : public Robot {
    friend class TestStudyInPink;
private:
    Watson* watson;
public:
    RobotW(int index, const Position& init_pos, Map* map, Criminal* criminal, Watson* watson);//
    Position getNextPosition();//
    int getDistance() const;//
    void move();//
    string str() const;//
    ~RobotW();
};

/// /////////////////////////////////RobotSW/////////////////////////
class RobotSW : public Robot {
    friend class TestStudyInPink;
private:
    Watson* watson;
    Sherlock* sherlock;
public:
    RobotSW(int index, const Position& init_pos, Map* map, Criminal* criminal, Sherlock* sherlock, Watson* watson);//
    Position getNextPosition();//
    int getDistance() const;//
    void move();//
    string str() const;//
    ~RobotSW();
};

class BaseItem {
    friend class TestStudyInPink;
protected:
    ItemType item_type;
    Character* obj;
    Robot* robot;
public:
    BaseItem(ItemType item_type);
    ItemType getType() const;
    virtual bool canUse(Character* obj, Robot* robot) = 0;
    virtual void use(Character* obj, Robot* robot) = 0;
    virtual string str() const = 0;
    virtual ~BaseItem();
};


class MagicBook : public BaseItem {
    friend class TestStudyInPink;
public:
    MagicBook();
    bool canUse(Character* obj, Robot* robot);
    void use(Character* obj, Robot* robot);
    string str() const;
    ~MagicBook();
};


class EnergyDrink : public BaseItem {
    friend class TestStudyInPink;
public:
    EnergyDrink();
    bool canUse(Character* obj, Robot* robot);
    void use(Character* obj, Robot* robot);
    string str() const;
    ~EnergyDrink();
};


class FirstAid : public BaseItem {
    friend class TestStudyInPink;
public:
    FirstAid();
    bool canUse(Character* obj, Robot* robot);
    void use(Character* obj, Robot* robot);
    string str() const;
    ~FirstAid();
};


class ExcemptionCard : public BaseItem {
    friend class TestStudyInPink;
public:
    ExcemptionCard();
    bool canUse(Character* obj, Robot* robot);
    void use(Character* obj, Robot* robot);
    string str() const;
    ~ExcemptionCard();
};


class PassingCard : public BaseItem {
    friend class TestStudyInPink;
private:
    string challenge = "";
public:
    PassingCard(string challenge);
    bool canUse(Character* obj, Robot* robot);
    void use(Character* obj, Robot* robot);
    string str() const;
    ~PassingCard();
};

struct Node {
    friend class TestStudyInPink;
    BaseItem* item;
    Node* next;
    Node(BaseItem* item, Node* next);
    Node();
    ~Node();
};

typedef struct Node Node;

class BaseBag {
    friend class TestStudyInPink;
protected:
    Node* head;
    int count = 0;
    int capacity;
    Character* obj;

public:
    BaseBag(Character* obj);
    virtual bool insert(BaseItem* item); // return true if insert successfully
    virtual BaseItem* get(); // return the item as described above , if not found, return NULL //Lấy một đồ vật bất kì gần nhất từ danh sách
    virtual BaseItem* get(ItemType itemType); // return the item as described above, if not found, return NULL //chon đồ vật đã biết tên
    virtual string str() const;
    int getSize() const;
    virtual ~BaseBag();
    virtual int search() const;
};



class SherlockBag : public BaseBag {
    friend class TestStudyInPink;
private:
    Sherlock* sherlock;
public:
    SherlockBag(Sherlock* sherlock);
    bool insert(BaseItem* item); // return true if insert successfully
    BaseItem* get(); // return the item as described above , if not found, return NULL //Lấy một đồ vật bất kì gần nhất từ danh sách
    BaseItem* get(ItemType itemType); // return the item as described above, if not found, return NULL //chon đồ vật đã biết tên
    string str() const;
    int search() const;
    ~SherlockBag();
    bool passingSearch() const;
};

class WatsonBag : public BaseBag {
    friend class TestStudyInPink;
private:
    Watson* watson;
public:
    WatsonBag(Watson* watson);
    bool insert(BaseItem* item); // return true if insert successfully
    BaseItem* get(); // return the item as described above , if not found, return NULL //Lấy một đồ vật bất kì gần nhất từ danh sách
    BaseItem* get(ItemType itemType); // return the item as described above, if not found, return NULL //chon đồ vật đã biết tên
    string str() const;
    int search() const;
    ~WatsonBag();
    bool excemptionSearch() const;
};



class StudyPinkProgram {
    friend class TestStudyInPink;
private:
    // Sample attributes
    Configuration * config;
    
    Sherlock * sherlock;
    Watson * watson;
    Criminal * criminal;
    
    Map * map;
    ArrayMovingObject * arr_mv_objs;
    SherlockBag* sherlock_bag;
    WatsonBag* watson_bag;

    bool flag_break;

public:
    StudyPinkProgram(const string& config_file_path) {
        config = new Configuration(config_file_path);

        map = new Map(config->map_num_rows, config->map_num_cols, config->num_walls, config->arr_walls, config->num_fake_walls, config->arr_fake_walls);
        
        sherlock = new Sherlock(1, config->sherlock_moving_rule, config->sherlock_init_pos, map, config->sherlock_init_hp, config->sherlock_init_exp);
        watson = new Watson(2, config->watson_moving_rule, config->watson_init_pos, map, config->watson_init_hp, config->watson_init_exp);
        criminal = new Criminal(0, config->criminal_init_pos, map, sherlock, watson);
        
        arr_mv_objs = new ArrayMovingObject(config->max_num_moving_objects);
        arr_mv_objs->add(criminal);
        arr_mv_objs->add(sherlock);
        arr_mv_objs->add(watson);
        sherlock_bag = new SherlockBag(sherlock);
        watson_bag = new WatsonBag(watson);
        flag_break = 0;
    }

    bool isStop() const {
        if (sherlock->getHp() == 1 || watson->getHp() == 1) return 1;
        if (sherlock->getCurrentPosition().isEqual(criminal->getCurrentPosition())) return 1;
        if (watson->getCurrentPosition().isEqual(criminal->getCurrentPosition())) return 1;
        return 0;
    }

    void printResult() const {
        if (sherlock->getCurrentPosition().isEqual(criminal->getCurrentPosition())) {
            cout << "Sherlock caught the criminal" << endl;
        }
        else if (watson->getCurrentPosition().isEqual(criminal->getCurrentPosition())) {
            cout << "Watson caught the criminal" << endl;
        }
        else {
            cout << "The criminal escaped" << endl;
        }
    }

    void printStep(int si) const {
        cout << "Step: " << setw(4) << setfill('0') << si
            << "--"
            << sherlock->str() << "--|--" << watson->str() << "--|--" << criminal->str() << endl;
    }

    void run(bool verbose) {
        // Note: This is a sample code. You can change the implementation as you like.
        // TODO
        for (int istep = 0; istep < config->num_steps; ++istep) {
            if (isStop()) {
                if (verbose) printStep(istep);
                break;
            }
            for (int i = 0; i < arr_mv_objs->size(); ++i) {
                arr_mv_objs->get(i)->move();
                if (i == 0 && Criminal::robot_create % 3 == 0) Criminal::create_permit = 1;
                if (i < 3) {
                    if (isStop()) {
                        if (verbose) printStep(istep);
                        this->flag_break = 1;
                        break;
                    }
                    if (sherlock->getCurrentPosition().isEqual(watson->getCurrentPosition())) {

                        if (sherlock_bag->passingSearch() && watson_bag->excemptionSearch()) {
                            while (watson_bag->getSize() < 15) {
                                if (watson_bag->insert(sherlock_bag->get(PASSING_CARD)) == 0) break;
                            }
                            while (sherlock_bag->getSize() < 13) {
                                if (sherlock_bag->insert(watson_bag->get(EXCEMPTION_CARD)) == 0) break;
                            }
                        }
                        
                    }
                    for (int ttt = 3; ttt < arr_mv_objs->size(); ++ttt) {
                        Robot* robot = dynamic_cast<Robot*>(arr_mv_objs->get(ttt));
                        if (sherlock->getCurrentPosition().isEqual(robot->getCurrentPosition())) {
                            BaseItem* found_item1 = NULL;
                            if (sherlock->getHp() % 2) found_item1 = sherlock_bag->get(EXCEMPTION_CARD);
                            if (found_item1 == NULL) {
                                switch (robot->getType())
                                {
                                case S:
                                    {
                                        if (sherlock->getExp() > 400) sherlock_bag->insert(robot->getItem());
                                        else {
                                            sherlock->setExp((int)(double(sherlock->getExp()) * 0.9 + 0.999));
                                            sherlock->setExp(Suitable(sherlock->getExp(), 0, 900));
                                        }
                                        break;
                                    }
                                case SW:
                                    {
                                        if (sherlock->getExp() > 300 && sherlock->getHp() > 335) sherlock_bag->insert(robot->getItem());
                                        else {
                                            sherlock->setExp((int)(double(sherlock->getExp()) * 0.85 + 0.999));
                                            sherlock->setHp((int)(double(sherlock->getHp()) * 0.85 + 0.999));
                                            sherlock->setExp(Suitable(sherlock->getExp(), 0, 900));
                                            sherlock->setHp(Suitable(sherlock->getHp(), 0, 500));
                                        }
                                        break;
                                    }
                                case W:
                                    {
                                        sherlock_bag->insert(robot->getItem());
                                        break;
                                    }
                                case C:
                                    {
                                        if (sherlock->getExp() > 500) sherlock->setCurrentPosition(criminal->getCurrentPosition());
                                        else sherlock_bag->insert(robot->getItem());
                                        break;
                                    }
                                }
                            }
                            else {
                                if (found_item1->canUse(sherlock, robot)) {
                                    found_item1->use(sherlock, robot);
                                    sherlock_bag->insert(robot->getItem());
                                }
                            }

                            BaseItem* found_item2 = NULL;
                            int item_value = sherlock_bag->search();
                            if (item_value == 0) found_item2 = sherlock_bag->get(MAGIC_BOOK);
                            else if (item_value == 1) found_item2 = sherlock_bag->get(ENERGY_DRINK);
                            else if (item_value == 2) found_item2 = sherlock_bag->get(FIRST_AID);
                             
                            if (found_item2 && found_item2->canUse(sherlock, nullptr)) 
                                found_item2->use(sherlock, nullptr);
                                
                            
                        }
                        if (watson->getCurrentPosition().isEqual(robot->getCurrentPosition())) {
                            BaseItem* found_item1 = NULL;
                            if (watson->getHp() % 2 == 0) found_item1 = watson_bag->get(PASSING_CARD);
                            if (found_item1 == NULL) {
                                switch (robot->getType())
                                {
                                case W:
                                    {
                                        if (watson->getHp() > 350) watson_bag->insert(robot->getItem());
                                        else watson->setHp((int)(double(watson->getHp()) * 0.95 + 0.999));
                                        watson->setExp(Suitable(watson->getExp(), 0, 900));
                                        watson->setHp(Suitable(watson->getHp(), 0, 500));
                                        break;
                                    }
                                case SW:
                                    {
                                        if (watson->getExp() > 600 && watson->getHp() > 165) watson_bag->insert(robot->getItem());
                                        else {
                                            watson->setExp((int)(double(watson->getExp()) * 0.85 + 0.999));
                                            watson->setHp((int)(double(watson->getHp()) * 0.85 + 0.999));
                                            watson->setExp(Suitable(watson->getExp(), 0, 900));
                                            watson->setHp(Suitable(watson->getHp(), 0, 500));
                                        }
                                        break;
                                    }
                                case C:
                                    {
                                        watson_bag->insert(robot->getItem());
                                        break;
                                    }
                                }
                            }
                            else {
                                if (found_item1->canUse(watson, robot)) {
                                    found_item1->use(watson, robot);
                                    watson_bag->insert(robot->getItem());
                                }
                            }
                            ////////////////////////////////Lấy đồ lần 2///////////////////////////////
                            BaseItem* found_item2 = NULL;
                            int item_value = watson_bag->search();
                            if (item_value == 0) found_item2 = watson_bag->get(MAGIC_BOOK);
                            else if (item_value == 1) found_item2 = watson_bag->get(ENERGY_DRINK);
                            else if (item_value == 2) found_item2 = watson_bag->get(FIRST_AID);
                            
                            if (found_item2 && found_item2->canUse(watson, nullptr)) 
                                found_item2->use(watson, nullptr);
                            
                        }

                        if (isStop()) {
                            if (verbose) printStep(istep);
                            this->flag_break = 1;
                            break;
                        }
                    }
                }
                else {
                    Robot* robot = dynamic_cast<Robot*>(arr_mv_objs->get(i));
                    if (sherlock->getCurrentPosition().isEqual(robot->getCurrentPosition())) {
                        BaseItem* found_item1 = NULL;
                        if (sherlock->getHp() % 2) found_item1 = sherlock_bag->get(EXCEMPTION_CARD);
                        if (found_item1 == NULL) {
                            switch (robot->getType())
                            {
                            case S:
                                {
                                    if (sherlock->getExp() > 400) sherlock_bag->insert(robot->getItem());
                                    else {
                                        sherlock->setExp((int)(double(sherlock->getExp()) * 0.9 + 0.999));
                                        sherlock->setExp(Suitable(sherlock->getExp(), 0, 900));
                                    }
                                    break;
                                }
                            case SW:
                                {
                                    if (sherlock->getExp() > 300 && sherlock->getHp() > 335) sherlock_bag->insert(robot->getItem());
                                    else {
                                        sherlock->setExp((int)(double(sherlock->getExp()) * 0.85 + 0.999));
                                        sherlock->setHp((int)(double(sherlock->getHp()) * 0.85 + 0.999));
                                        sherlock->setExp(Suitable(sherlock->getExp(), 0, 900));
                                        sherlock->setHp(Suitable(sherlock->getHp(), 0, 500));
                                    }
                                    break;
                                }
                            case W:
                                {
                                    sherlock_bag->insert(robot->getItem());
                                    break;
                                }
                            case C:
                                {
                                    
                                    if (sherlock->getExp() > 500) sherlock->setCurrentPosition(criminal->getCurrentPosition());
                                    else sherlock_bag->insert(robot->getItem());
                                    break;
                                }
                            }
                        }
                        else {
                            if (found_item1->canUse(sherlock, robot)) {
                                found_item1->use(sherlock, robot);
                                sherlock_bag->insert(robot->getItem());
                            }
                        }
                        ////////////////////////////////Lấy đồ lần 2///////////////////////////////
                        //sherlock_bag->get()->getType() != PASSING_CARD && sherlock_bag->get()->getType() != EXCEMPTION_CARD
                        BaseItem* found_item2 = NULL;
                        int item_value = sherlock_bag->search();
                        if (item_value == 0) found_item2 = sherlock_bag->get(MAGIC_BOOK);
                        else if (item_value == 1) found_item2 = sherlock_bag->get(ENERGY_DRINK);
                        else if (item_value == 2) found_item2 = sherlock_bag->get(FIRST_AID);
                        
                        if (found_item2 && found_item2->canUse(sherlock, nullptr))
                            found_item2->use(sherlock, nullptr);
                            
                    }
                    if (watson->getCurrentPosition().isEqual(robot->getCurrentPosition())) {
                        BaseItem* found_item1 = NULL;
                        if (watson->getHp() % 2 == 0) found_item1 = watson_bag->get(PASSING_CARD);
                        if (found_item1 == NULL) {
                            switch (robot->getType())
                            {
                            case W:
                                {
                                    if (watson->getHp() > 350) watson_bag->insert(robot->getItem());
                                    else watson->setHp((int)(double(watson->getHp()) * 0.95 + 0.999));
                                    
                                    watson->setExp(Suitable(watson->getExp(), 0, 900));
                                    watson->setHp(Suitable(watson->getHp(), 0, 500));
                                    break;
                                }
                            case SW:
                            {
                                if (watson->getExp() > 600 && watson->getHp() > 165) watson_bag->insert(robot->getItem());
                                else {
                                    watson->setExp((int)(double(watson->getExp()) * 0.85 + 0.999));
                                    watson->setHp((int)(double(watson->getHp()) * 0.85 + 0.999));
                                    watson->setExp(Suitable(watson->getExp(), 0, 900));
                                    watson->setHp(Suitable(watson->getHp(), 0, 500));
                                }
                                break;
                            }
                            case C:
                                {
                                    watson_bag->insert(robot->getItem());
                                    break;
                                }
                            }
                        }
                        else {
                            if (found_item1->canUse(watson, robot)) {
                                found_item1->use(watson, robot);
                                watson_bag->insert(robot->getItem());
                            }
                        }
                        ////////////////////////////////Lấy đồ lần 2///////////////////////////////
                        BaseItem* found_item2 = NULL;
                        int item_value= watson_bag->search();
                        if (item_value == 0) found_item2 = watson_bag->get(MAGIC_BOOK);
                        else if (item_value == 1) found_item2 = watson_bag->get(ENERGY_DRINK);
                        else if (item_value == 2) found_item2 = watson_bag->get(FIRST_AID);
                        
                        if (found_item2 && found_item2->canUse(watson, nullptr)) 
                            found_item2->use(watson, nullptr);
                        
                        
                    }
                }
                if (flag_break) break;
                if (isStop()) {
                    if (verbose) printStep(istep);
                    this->flag_break = 1;
                    break;
                }
                if (verbose) printStep(istep);
                if (Criminal::robot_create && Criminal::robot_create % 3 == 0 && arr_mv_objs->isFull()==0 && Criminal::create_permit) {
                    if (arr_mv_objs->size() == 3) {
                        arr_mv_objs->add(new RobotC(arr_mv_objs->size(), criminal->getCurrentPosition(), map, criminal));
                    }
                    else {
                        int sher_cri = Manhattan(criminal, sherlock);
                        int wat_cri = Manhattan(criminal, watson);
                        if (sher_cri < wat_cri) {
                            arr_mv_objs->add(new RobotS(arr_mv_objs->size(), criminal->getCurrentPosition(), map, criminal, sherlock));
                        } 
                        else if (sher_cri > wat_cri) {
                            arr_mv_objs->add(new RobotW(arr_mv_objs->size(), criminal->getCurrentPosition(), map, criminal, watson));
                        }
                        else {
                            arr_mv_objs->add(new RobotSW(arr_mv_objs->size(), criminal->getCurrentPosition(), map, criminal, sherlock, watson));
                        }
                    }
                    Criminal::create_permit = 0;
                }
            }
            if (flag_break == 1) break;
            if (isStop()) {
                if(verbose) {
                    printStep(istep);
                }
                break;
            }
        }
        printResult();
    }

    ~StudyPinkProgram() {
        Criminal::direction = 'N';
        Criminal::robot_create = 0;
        Criminal::create_permit = 0;
        delete sherlock_bag;
        sherlock_bag = nullptr;
        delete watson_bag;
        watson_bag = nullptr;
        delete arr_mv_objs;
        arr_mv_objs = nullptr;
        delete watson;
        watson = nullptr;
        delete sherlock;
        sherlock = nullptr;
        delete criminal;
        criminal = nullptr;
        delete map;
        map = nullptr;
        delete config;
        config = nullptr;
    }
};

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_2_H_ */
