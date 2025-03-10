#include "study_in_pink2.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

/// Mot so loi duoc phat hien
// 1. ở một số chỗ, getCurrentPosition phải được đổi thành pos 
// EXPLAIN: Hàm getCurrentPosition trả ra một bản sao pos chứ không phải pos có trong MovingObject nên không dùng nó để cập nhật các giá trị row, col được
// Đã được sửa ở dòng 220 và 351 và 281
// 2. COnstructor co the bi loi neu khong truyen dung doi so
// Tai day constructor MovingObject(index, pos, map, "") se gay loi khong xac dinh pos nen can chuyen ve MovingObject(index, init_pos, map, "")
// 3. Thu test cho 4 bức tường xung quanh các character, các robot
// 4. Cho những trường hợp sai trả về kết quả false như việc truyền criminal vào hàm canUse(criminal, robot) sẽ trả về 0
// 5. Việc so sánh hai string bằng toán tử == có thể gây ra lỗi ở những compiler khác dùng strcmp()
// 6. Nhớ test cái capacity với cái count và size của arr_mv_obj xem có đúng như thực tế không
// 7. Không được phép điều chỉnh các prototype có sẵn trong đề
// 
// 6. DOWNCASTING dynamic_cast and static_cast
//
// 8. So sánh hai string bằng lệnh == có thể gây ra lỗi
//
// 9. Tên của Sherlock và Watson viét hoa
// 
// 10. Cẩn thận với hàm destructor có thể gây lỗi memory rất khó sửa
//
// 11. Hàm getItem không đối số khi trả về ra item nếu dùng getType() thì có thể trả về 0 mà 0 lại là NULL....??!!!???
//
// 12. Test thử lại getNextPosition của SW
//
// 13. Không được phép gọi hai lần hàm getNextPosition trong 1 lần chạy run, hàm getNextPosition có trong hàm move
//
// 14. Swallow copy với deep copy cho dòng 689 file pink.h ở item robot, tách biệt địa chỉ hai items
//
// 15. Trường hợp dừng xảy ra ngay đầu chương trình như hp sherlock  = 0 thì có dừng luôn không ---> hỏi lại
//
// 16. Hỏi lại cho rõ hàm get không đối số
//
// Nếu xét đến món đồ sử dụng được thì 
// ------TH1: Xét mỗi điều kiện sử dụng của món đồ thì hàm get có thể sử dụng được cho môi nhân vật là 4 món đồ (khác nhau ở Passingcard và excemptioncard)
// ------TH2: Xét luôn đk phải có robot mới sử dụng được passing card và excemption card thì hàm get không đối số chỉ lấy được 3 món đồ với giá trị robot truyền vào là NULL
// 17. Nếu exp = 0 thì nhân vật Sherlock và Watson không di chuyển cho đến khi exp>0 trở lại nhưng chương trình vẫn chạy đúng không ạ  

MapElement::MapElement(ElementType in_type) {
	this->type = in_type;
}
ElementType MapElement::getType()const { return this->type; }
MapElement::~MapElement(){}

Path::Path() : MapElement(PATH){}
ElementType Path::getType()const { return this->type; }

Wall::Wall() : MapElement(WALL) {}
ElementType Wall::getType()const { return this->type; }

FakeWall::FakeWall() : MapElement(FAKE_WALL) {}
FakeWall::FakeWall(int in_req_exp) : MapElement(FAKE_WALL) {
	this->req_exp = in_req_exp;
}
int FakeWall::getReqExp() const{
	return req_exp;
}
ElementType FakeWall::getType()const { return this->type; }


int Suitable(int x, int low, int high) {
	if (x < low) return 0;
	if (x > high) return high;
	return x;
}
////////////////////////MAP/////OVERRIDE//////MAP///////////////
Map::Map(int num_rows, int num_cols, int num_walls, Position* array_walls, int num_fake_walls, Position* array_fake_walls) : num_rows(num_rows), num_cols(num_cols) 
{
	map = new MapElement * *[num_rows];
	for (int i = 0; i < num_rows; ++i) {
		map[i] = new MapElement * [num_cols];
		for (int j = 0; j < num_cols; ++j) {
			map[i][j] = new Path;   
		}
	}
	for (int i = 0; i < num_walls; ++i) {
		int row = array_walls[i].getRow();
		int col = array_walls[i].getCol();
		delete map[row][col];
		map[row][col] = new Wall;
	}
	for (int i = 0; i < num_fake_walls; ++i) {
		int row = array_fake_walls[i].getRow();
		int col = array_fake_walls[i].getCol();
		delete map[row][col];
		map[row][col] = new FakeWall((row * 257 + col * 139 + 89) % 900 + 1);
	}
}

Map::~Map() {
	for (int i = 0; i < num_rows; ++i) {
		for (int j = 0; j < num_cols; ++j) {
			delete map[i][j];
			map[i][j] = nullptr;
		}
		delete[] map[i];
	}
	delete[] map;
	map = nullptr;
}

bool Map::isValid(const Position& pos, MovingObject* mv_obj ) const 
{
	int row = pos.getRow();
	int col = pos.getCol();
	if (row >= num_rows || col >= num_cols || row < 0 || col < 0 ) return 0;
	if (map[row][col]->getType() == PATH) return 1;
	else if (map[row][col]->getType() == WALL) return 0;
	else if (mv_obj->getName() != "Watson") return 1;
	else if ((dynamic_cast<FakeWall*>(map[row][col]))->getReqExp() >= (dynamic_cast<Watson*>(mv_obj))->getExp()) return 0;
	
	return 1;
}

bool Map::isValidPosition(int row, int col, MovingObject* mv_obj) const 
{
	if (row < 0 || col < 0 || row >= num_rows || col >= num_cols) return 0;
	Position pos_pos = Position(row, col);
	return Map::isValid(pos_pos, mv_obj);
}

////////////////////////MAP/////OVERRIDE//////MAP///////////////



////////////////////////POSITION/////OVERRIDE//////POSITION///////////////

const Position Position::npos = Position(-1, -1);

Position::Position(int r, int c ) : r(r), c(c) {}
Position::Position(const std::string& str_pos) {
	if (!str_pos.empty()) {
		std::istringstream iss(str_pos);
		char open_paren, comma, close_paren;
		int in_r, in_c;
		iss >> open_paren >> in_r >> comma >> in_c >> close_paren;
		r = in_r;
		c = in_c;
	}
}

int Position::getRow() const { return r; }
int Position::getCol() const { return c; }
void Position::setRow(int r) { this->r = r; }
void Position::setCol(int c) { this->c = c; }


string Position::str() const {
	std::ostringstream oss;
	oss << "(" << r << "," << c << ")";
	return oss.str();
}


bool Position::isEqual(int in_r, int in_c) const {  // viet them bool isEqual(Position pos) nua
	return (in_r == r && in_c == c);
}


bool Position::isEqual(const std::string& str_pos) const {
	std::istringstream iss(str_pos);
	char open_paren, comma, close_paren;
	int in_r, in_c;

	iss >> open_paren >> in_r >> comma >> in_c >> close_paren;
	return (in_r == r && in_c == c);
}

bool Position::isEqual(Position pos) const {
	return (pos.getRow() == r && pos.getCol() == c);
}


////////////////////////POSITION/////OVERRIDE//////POSITION///////////////
//
//
//
////////////////////////MOVING_OBJECT/////OVERRIDE//////MOVING_OBJECT///////////////
MovingObject::MovingObject(int index, const Position pos, Map* map, const string& name ) 
				: index(index), pos(pos), name(name), map(map) {}

Position MovingObject::getCurrentPosition() const {
	return pos;
}

MovingObject::~MovingObject() {}

string MovingObject::getName() const { return name; }

int MovingObject::getIndex() const { return index; }


////////////////////////MOVING_OBJECT/////OVERRIDE//////MOVING_OBJECT///////////////

///Character///
Character::Character(int index, const string& moving_rule, const Position& init_pos, Map* map, const string& name ) 
				: MovingObject(index, init_pos, map, "") {
	this->name = name;
	this->moving_rule = moving_rule;
}

Character::~Character(){}

int Character::getExp() const { return exp; }
void Character::setExp(int exp) { this->exp = exp; }
int Character::getHp() const { return hp; }
void Character::setHp(int hp) { this->hp = hp; }
///Character///


////////////////////////SHERLOCK/////OVERRIDE//////SHERLOCK///////////////

Sherlock::Sherlock(int index, const string& moving_rule, const Position& init_pos, Map* map, int init_hp, int init_exp) 
				: Character(index, moving_rule, init_pos, map, "Sherlock") 
{
	if (init_hp >= 500) hp = 500;
	else hp = init_hp;
	exp = (init_exp >= 900) ? 900 : init_exp;
}

Position Sherlock::getNextPosition() {
	dem = (dem) % (moving_rule.size());
	char direc = moving_rule[dem];
	dem++;
	
	if (exp == 0) return Position::npos;
	
	int row = getCurrentPosition().getRow();
	int col = getCurrentPosition().getCol();
	if (direc == 'L') col--;
	else if (direc == 'R') col++;
	else if (direc == 'U') row--;
	else if (direc == 'D') row++;
	
	if (map->isValidPosition(row, col, this)) {
		return Position(row, col);
	}
	return Position::npos;
}

string Sherlock::str() const {
	return "Sherlock[index=" + to_string(index) + ";pos=" + this->getCurrentPosition().str() + ";moving_rule=" + (moving_rule)+"]";
}

void Sherlock::move() {
	Position next_pos = getNextPosition();
	if (next_pos.getRow() == -1 && next_pos.getCol() == -1) return;
	
	if (map->isValid(next_pos, this)) pos = next_pos;
}

int Sherlock::getExp() const { return Character::getExp(); }
int Sherlock::getHp() const { return  Character::getHp(); }

void Sherlock::setCurrentPosition(Position diff_pos)
{
	this->pos = diff_pos;
}

void Sherlock::setExp(int exp)
{
	if (exp > 900) this->exp = 900;
	else this->exp = exp;
}

void Sherlock::setHp(int hp)
{
	if (hp > 500) this->hp = 500;
	else this->hp = hp;
}



Sherlock::~Sherlock(){}

////////////////////////SHERLOCK/////OVERRIDE//////SHERLOCK///////////////


/////////////////////////////
// Watson can co exp cao hon moi qua duoc fakewall
// Watson khong qua duoc Wall
////////////////////////WATSON/////OVERRIDE//////WATSON///////////////
Watson::Watson(int index, const string& moving_rule, const Position& init_pos, Map* map, int init_hp, int init_exp) : Character(index, moving_rule, init_pos, map, "Watson")
{
	if (init_hp >= 500) this->hp = 500;
	else this->hp = init_hp;
	this->exp = (init_exp >= 900) ? 900 : init_exp;
}

Position Watson::getNextPosition() {
	demm = (demm) % (moving_rule.size());
	char direc = moving_rule[demm++];
	
	if (exp == 0) return Position::npos;
	
	int row = getCurrentPosition().getRow();
	int col = getCurrentPosition().getCol();
	if (direc == 'L') col --;
	else if (direc == 'R') col ++;
	else if (direc == 'U') row --;
	else if (direc == 'D') row++;
	
	if (map->isValidPosition(row, col, this)) {
		return Position(row, col);
	}
	return Position::npos;
}

string Watson::str() const {
	return "Watson[index=" + to_string(index) + ";pos=" + this->getCurrentPosition().str() + ";moving_rule=" + (moving_rule)+"]";
}

void Watson::move() {
	Position next_pos = this->getNextPosition();

	if (next_pos.getRow() == -1 && next_pos.getCol() == -1) return;
	if (map->isValid(next_pos, this)) pos = next_pos;
}

int Watson::getExp() const { return Character::getExp(); }
int Watson::getHp() const { return Character::getHp();}

void Watson::setCurrentPosition(Position diff_pos)
{
	this->pos = diff_pos;
}

void Watson::setExp(int exp)
{
	if (exp > 900) this->exp = 900;
	else this->exp = exp;
}

void Watson::setHp(int hp)
{
	if (hp > 500) this->hp = 500;
	else this->hp = hp;
}

Watson::~Watson(){}

////////////////////////WATSON/////OVERRIDE//////WATSON///////////////


////////////////////////Criminal/////OVERRIDE//////Criminal///////////////
Criminal::Criminal(int index, const Position& init_pos, Map* map, Sherlock* sherlock, Watson* watson) 
				: Character(index, "", init_pos, map, "Criminal") 
{
	this->sherlock = sherlock;
	this->watson = watson;
	this->direction = 'N';
	this->robot_create = 0;
	this->create_permit = 0;
}

int Criminal::getSherlockDistance() const
{
	int row = sherlock->getCurrentPosition().getRow();
	int col = sherlock->getCurrentPosition().getCol();
	return abs(row - getCurrentPosition().getRow()) + abs(col - getCurrentPosition().getCol());
}
int Criminal::getWatsonDistance() const
{
	int row = watson->getCurrentPosition().getRow();
	int col = watson->getCurrentPosition().getCol();
	return abs(row - getCurrentPosition().getRow()) + abs(col - getCurrentPosition().getCol());
}

Position Criminal::getNextPosition()
{
	int cri_row = getCurrentPosition().getRow(); //Criminal
	int cri_col = getCurrentPosition().getCol();
	int sher_row = sherlock->getCurrentPosition().getRow();  //Sherlock
	int sher_col = sherlock->getCurrentPosition().getCol();
	int wat_row = watson->getCurrentPosition().getRow(); //Watson
	int wat_col = watson->getCurrentPosition().getCol();
	int max_U = -1, max_D = -1, max_L = -1, max_R = -1;

	if (map->isValidPosition(cri_row - 1, cri_col, this)) {   //UP
		max_U = abs(cri_row - 1 - sher_row) + abs(cri_col - sher_col) + abs(cri_row - 1 - wat_row) + abs(cri_col - wat_col);
	}
	if (map->isValidPosition(cri_row + 1, cri_col, this)) {   //DOWN
		max_D = abs(cri_row + 1 - sher_row) + abs(cri_col - sher_col) + abs(cri_row + 1 - wat_row) + abs(cri_col - wat_col);
	}
	if (map->isValidPosition(cri_row, cri_col + 1, this)) {   //RIGHT
		max_R = abs(cri_row - sher_row) + abs(cri_col + 1 - sher_col) + abs(cri_row - wat_row) + abs(cri_col + 1 - wat_col);
	}
	if (map->isValidPosition(cri_row, cri_col - 1, this)) {   //LEFT
		max_L = abs(cri_row - sher_row) + abs(cri_col - 1 - sher_col) + abs(cri_row - wat_row) + abs(cri_col - 1 - wat_col);
	}
	if (max_U == -1 && max_D == -1 && max_L == -1 && max_R == -1) return Position::npos;
	int max_dist = 0;
	max_dist = max(max_U, max(max_L, max(max_D, max_R)));
	
	if (max_dist == max_U) direction = 'U', cri_row--; 
	else if (max_dist == max_L) direction = 'L', cri_col--; 
	else if (max_dist == max_D) direction = 'D', cri_row++; 
	else if (max_dist == max_R) direction = 'R', cri_col++; 
	
	return Position(cri_row, cri_col);
}

void Criminal::move() {
	Position next_pos = this->getNextPosition();
	if (next_pos.getRow() == -1 && next_pos.getCol() == -1) return;
	
	if (map->isValid(next_pos, this)) {
		Criminal::robot_create++;
		pos = next_pos;
	}
}

string Criminal::str() const {
	return "Criminal[index=" + to_string(index) + ";pos=" + getCurrentPosition().str() + "]";
}

int Criminal::getExp() const { return -1; }
void Criminal::setExp(int exp) { this->exp = -1; }
int Criminal::getHp() const { return -1; }
void Criminal::setHp(int hp) { this->hp = -1; }

Criminal::~Criminal()
{
	Criminal::direction = 'N';
	Criminal::robot_create = 0;
	Criminal::create_permit = 0;
}

char Criminal::direction = 'N';
int Criminal::robot_create = 0;
bool Criminal::create_permit = 0;
////////////////////////Criminal/////OVERRIDE//////Criminal///////////////




////////////////////////ArrayMovingObject/////OVERRIDE//////ArrayMovingObject///////////////
ArrayMovingObject::ArrayMovingObject(int capacity) : capacity(capacity)
{
	arr_mv_objs = new MovingObject * [capacity];
}

bool ArrayMovingObject::isFull() const {
	return (capacity == count);   
}

bool ArrayMovingObject::add(MovingObject* mv_obj) 
{
	if (this->isFull() || mv_obj == nullptr) return 0;
	
	arr_mv_objs[count] = mv_obj;
	count++;
	return 1;
}

MovingObject* ArrayMovingObject::get(int index) const {
	return arr_mv_objs[index];
}

int ArrayMovingObject::size() const {
	return count;
}

ArrayMovingObject::~ArrayMovingObject() {
	if (count > 3) {
		for (int i = 3; i < count; i++) {
			delete arr_mv_objs[i];
			arr_mv_objs[i] = nullptr;
		}
		delete[] arr_mv_objs;
	}
	arr_mv_objs = nullptr;
}

string ArrayMovingObject::str() const {
	string result = "ArrayMovingObject[count=";
	result += to_string(count) + ";capacity=" + to_string(capacity);
	for (int i = 0; i < count; i++) {
		result += ";";
		result += arr_mv_objs[i]->str();
	}
	if (count == 0) result += ";";
	result += "]";
	return result;
}

///////////////////////////////Configuration/////////////////////////////////////
Configuration::Configuration(const string& filepath) {
	ifstream file(filepath);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			istringstream iss(line);
			string attribute_name="", attribute_value="";
			int i = 0;
			while (line[i] != '=') { 
				attribute_name += line[i];
				i++; 
			} 
			i++;
			for (int j = i; j < line.size(); j++) attribute_value += line[j];
			
			if (attribute_name == "MAP_NUM_ROWS") map_num_rows = stoi(attribute_value);
			else if (attribute_name == "MAP_NUM_COLS") map_num_cols = stoi(attribute_value);
			else if (attribute_name == "MAX_NUM_MOVING_OBJECTS") max_num_moving_objects = stoi(attribute_value);
			else if (attribute_name == "SHERLOCK_MOVING_RULE") sherlock_moving_rule = attribute_value;
			else if (attribute_name == "SHERLOCK_INIT_HP") sherlock_init_hp = stoi(attribute_value);
			else if (attribute_name == "SHERLOCK_INIT_EXP") sherlock_init_exp = stoi(attribute_value);
			else if (attribute_name == "WATSON_MOVING_RULE") watson_moving_rule = attribute_value;
			else if (attribute_name == "WATSON_INIT_HP") watson_init_hp = stoi(attribute_value);
			else if (attribute_name == "WATSON_INIT_EXP") watson_init_exp = stoi(attribute_value);
			else if (attribute_name == "NUM_STEPS") num_steps = stoi(attribute_value);
			else if (attribute_name == "SHERLOCK_INIT_POS") {
				istringstream ss(attribute_value);
				char open_paren, comma, close_paren;
				int in_r, in_c;

				ss >> open_paren >> in_r >> comma >> in_c >> close_paren;

				sherlock_init_pos.setRow(in_r);
				sherlock_init_pos.setCol(in_c);
			}
			else if (attribute_name == "WATSON_INIT_POS") {
				istringstream ss(attribute_value);
				char open_paren, comma, close_paren;
				int in_r, in_c;

				ss >> open_paren >> in_r >> comma >> in_c >> close_paren;

				watson_init_pos.setRow(in_r);
				watson_init_pos.setCol(in_c);
			}
			else if (attribute_name == "CRIMINAL_INIT_POS") {
				istringstream ss(attribute_value);
				char open_paren, comma, close_paren;
				int in_r, in_c;

				ss >> open_paren >> in_r >> comma >> in_c >> close_paren;

				criminal_init_pos.setRow(in_r);
				criminal_init_pos.setCol(in_c);
			}
			else if (attribute_name == "ARRAY_WALLS") {
				if (attribute_value == "[]") this->num_walls = 0, arr_walls = nullptr;
				else {
					int num_walls = 1;
					int k = 0;
					while (1) {
						if (attribute_value[k] == ';') num_walls++;
						if (attribute_value[k] == ']') break;
						k++;
					}
					arr_walls = new Position[num_walls];
					istringstream ss(attribute_value);
					for (int i = 0; i < num_walls; i++) {
						char open_bracket, open_paren, comma, close_paren, close_bracket;
						int in_r, in_c;

						ss >> open_bracket >> open_paren >> in_r >> comma >> in_c >> close_paren;

						arr_walls[i].setRow(in_r);
						arr_walls[i].setCol(in_c);
						if (i == num_walls - 1) ss >> close_bracket;
						this->num_walls = num_walls;
					}
				}
			}
			else if (attribute_name == "ARRAY_FAKE_WALLS") {
				if (attribute_value == "[]") this->num_fake_walls = 0, arr_fake_walls = nullptr;
				else {
					int num_fake_walls = 1;
					int k = 0;
					while (1) {
						if (attribute_value[k] == ';') num_fake_walls++;
						if (attribute_value[k] == ']') break;
						k++;
					}
					arr_fake_walls = new Position[num_fake_walls];
					istringstream ss(attribute_value);
					for (int i = 0; i < num_fake_walls; i++) {
						char open_bracket, open_paren, comma, close_paren, close_bracket;
						int in_r, in_c;

						ss >> open_bracket >> open_paren >> in_r >> comma >> in_c >> close_paren;

						arr_fake_walls[i].setRow(in_r);
						arr_fake_walls[i].setCol(in_c);
						if (i == num_fake_walls - 1) ss >> close_bracket;
						this->num_fake_walls = num_fake_walls;
					}
				}
			}
		}
		file.close();
	}
}

Configuration::~Configuration() {
	if (arr_walls != nullptr) {
		delete[] arr_walls;
		arr_walls = nullptr;
	}
	if (arr_fake_walls != nullptr) {
		delete[] arr_fake_walls;
		arr_fake_walls = nullptr;
	}
}

string Configuration::str() const {
	string result = "Configuration[\n";
	result += "MAP_NUM_ROWS=" + to_string(map_num_rows) + "\n";
	result += "MAP_NUM_COLS=" + to_string(map_num_cols) + "\n";
	result += "MAX_NUM_MOVING_OBJECTS=" + to_string(max_num_moving_objects) + "\n";
	result += "NUM_WALLS=" + to_string(num_walls) + "\n";
	result += "ARRAY_WALLS=[";
	for (int i = 0; i < num_walls; ++i) {
		result += "(" + to_string(arr_walls[i].getRow()) + "," + to_string(arr_walls[i].getCol()) + ")";
		if (i != num_walls - 1) {
			result += ";";
		}
	}
	result += "]\n";
	result += "NUM_FAKE_WALLS=" + to_string(num_fake_walls) + "\n";
	result += "ARRAY_FAKE_WALLS=[";
	for (int i = 0; i < this->num_fake_walls; ++i) {
		result += "(" + to_string(arr_fake_walls[i].getRow()) + "," + to_string(arr_fake_walls[i].getCol()) + ")";
		if (i != num_fake_walls - 1) {
			result += ";";
		}
	}
	result += "]\n";
	result += "SHERLOCK_MOVING_RULE=" + sherlock_moving_rule + "\n";
	result += "SHERLOCK_INIT_POS=(" + to_string(sherlock_init_pos.getRow()) + "," + to_string(sherlock_init_pos.getCol()) + ")\n";
	result += "SHERLOCK_INIT_HP=" + to_string(sherlock_init_hp) + "\n";
	result += "SHERLOCK_INIT_EXP=" + to_string(sherlock_init_exp) + "\n";
	result += "WATSON_MOVING_RULE=" + watson_moving_rule + "\n";
	result += "WATSON_INIT_POS=(" + to_string(watson_init_pos.getRow()) + "," + to_string(watson_init_pos.getCol()) + ")\n";
	result += "WATSON_INIT_HP=" + to_string(watson_init_hp) + "\n";
	result += "WATSON_INIT_EXP=" + to_string(watson_init_exp) + "\n";
	result += "CRIMINAL_INIT_POS=(" + to_string(criminal_init_pos.getRow()) + "," + to_string(criminal_init_pos.getCol()) + ")\n";
	result += "NUM_STEPS=" + to_string(num_steps) + "\n";
	result += "]";
	return result;
}


///////////////////////////////Configuration/////////////////////////////////////

int Manhattan(MovingObject* mv_obj1, MovingObject* mv_obj2) {
	return abs(mv_obj1->getCurrentPosition().getRow() - mv_obj2->getCurrentPosition().getRow()) + abs(mv_obj1->getCurrentPosition().getCol() - mv_obj2->getCurrentPosition().getCol());
}

int Manhattan(const MovingObject* mv_obj1, MovingObject* mv_obj2) {
	return abs(mv_obj1->getCurrentPosition().getRow() - mv_obj2->getCurrentPosition().getRow()) + abs(mv_obj1->getCurrentPosition().getCol() - mv_obj2->getCurrentPosition().getCol());
}

///////////////////////////////////Robot/////////////////////////////////////////

Robot::Robot(int index, const Position& init_pos, Map* map, Criminal* criminal) : MovingObject(index, init_pos, map, ""), criminal(criminal)
{
	using ll = long long;
	ll p = (ll)this->getCurrentPosition().getRow() * this->getCurrentPosition().getCol(); /// Có bị tràn số không
	while (p >= 10) {
		int sum = 0;
		while (p > 0) {
			sum += p % 10;
			p /= 10;
		}
		p = sum;
	}
	this->s = p;
	if (s >= 0 && s <= 1) this->item = new MagicBook;
	else if (s >= 2 && s <= 3) this->item = new EnergyDrink;
	else if (s >= 4 && s <= 5) this->item = new FirstAid;
	else if (s >= 6 && s <= 7) this->item = new ExcemptionCard;
	else {
		int t = ((ll)getCurrentPosition().getRow() * 11 + (ll)getCurrentPosition().getCol()) % 4;
		switch (t) {
		case 0:
			this->item = new PassingCard("RobotS");
			break;
		case 1:
			this->item = new PassingCard("RobotC");
			break;
		case 2:
			this->item = new PassingCard("RobotSW");
			break;
		default:
			this->item = new PassingCard("all");
			break;
		}
	}
}

string Robot::str() const {
	return "Robot[pos=" + this->getCurrentPosition().str() + ";type=";
}

BaseItem* Robot::getItem() const { return item;}
RobotType Robot::getType() const { return this->robot_type; }

Robot::~Robot() { delete item; item = nullptr; }

///////////////////////////////////Robot/////////////////////////////////////////

///////////////////////////////////RobotC/////////////////////////////////////////

RobotC::RobotC(int index, const Position& init_pos, Map* map, Criminal* criminal) : Robot(index, init_pos, map, criminal) { this->robot_type = C; }


//Lam the nao de lay duoc cai previous position cua criminal--->them ham getPreviosPosition--->hoac ham lay cai direction cu cua criminal
Position RobotC::getNextPosition() 
{
	int row = criminal->getCurrentPosition().getRow();
	int col = criminal->getCurrentPosition().getCol();

	if (Criminal::direction == 'U') { //then robot go down
		row++;
		col;
	}
	else if (Criminal::direction == 'D') { //then robot go up
		row--;
		col;
	}
	else if (Criminal::direction == 'R') { //then robot go left
		row;
		col--;
	}
	else if (Criminal::direction == 'L') { //then robot go right
		row;
		col++;
	}
	else return Position::npos;

	Criminal::direction = 'N';
	return Position(row, col);
}

void RobotC::move() {
	Position next_pos = getNextPosition();
	if (next_pos.getRow() == -1 && next_pos.getCol() == -1) return;
	if ((*map).isValid(next_pos, this)) pos = next_pos;
}

int RobotC::getDistance(Sherlock* sherlock) const {return Manhattan(this, sherlock);}
int RobotC::getDistance(Watson* watson) const { return Manhattan(this, watson); }
int RobotC::getDistance() const { return INT_MAX; }

string RobotC::str() const {
	return Robot::str() + "C;dist=]";
}

RobotC::~RobotC(){}
///////////////////////////////////RobotC/////////////////////////////////////////


///////////////////////////////////RobotS/////////////////////////////////////////
RobotS::RobotS(int index, const Position& init_pos, Map* map, Criminal* criminal, Sherlock* sherlock) : Robot(index, init_pos, map, criminal)
{
	this->sherlock = sherlock;
	this->robot_type = S;
}

void RobotS::move() {
	Position next_pos = this->getNextPosition();
	if (next_pos.getRow() == -1 && next_pos.getCol() == -1) return;
	if ((*map).isValid(next_pos, this)) this->pos = next_pos;	
}

Position RobotS::getNextPosition()
{
	
	int s_row = getCurrentPosition().getRow(); //RobotS
	int s_col = getCurrentPosition().getCol();
	int sher_row = sherlock->getCurrentPosition().getRow();  //Sherlock
	int sher_col = sherlock->getCurrentPosition().getCol();
	int min_U = INT_MAX, min_D = INT_MAX, min_L = INT_MAX, min_R = INT_MAX; 

	if (map->isValidPosition(s_row - 1, s_col, this))     //UP
		min_U = abs(s_row - 1 - sher_row) + abs(s_col - sher_col);
	if (map->isValidPosition(s_row + 1, s_col, this))     //DOWN
		min_D = abs(s_row + 1 - sher_row) + abs(s_col - sher_col);
	if (map->isValidPosition(s_row, s_col + 1, this))     //RIGHT
		min_R = abs(s_row - sher_row) + abs(s_col + 1 - sher_col);
	if (map->isValidPosition(s_row, s_col - 1, this))     //LEFT
		min_L = abs(s_row - sher_row) + abs(s_col - 1 - sher_col);

	if (min_U == INT_MAX && min_D == INT_MAX && min_L == INT_MAX && min_R == INT_MAX) return Position::npos;
	int min_dist = min(min_U, min(min_L, min(min_D, min_R)));

	if (min_dist == min_U) s_row--;
	else if (min_dist == min_R) s_col++;
	else if (min_dist == min_D) s_row++;
	else if (min_dist == min_L) s_col--;

	return Position(s_row, s_col);
}

//////// Manhattan(const MovingObject*  , MovingObject );
int RobotS::getDistance() const { return Manhattan(this, sherlock); }


string RobotS::str() const {
	return Robot::str() + "S;dist=" + to_string(this->getDistance()) + "]";
}

RobotS::~RobotS() {}

///////////////////////////////////RobotS/////////////////////////////////////////


///////////////////////////////////RobotW/////////////////////////////////////////
RobotW::RobotW(int index, const Position& init_pos, Map* map, Criminal* criminal, Watson* watson) : Robot(index, init_pos, map, criminal)
{
	this->watson = watson;
	this->robot_type = W;
}

void RobotW::move() {
	Position next_pos = getNextPosition();
	if (next_pos.getRow() == -1 && next_pos.getCol() == -1) return;
	if ((*map).isValid(next_pos, this)) pos = next_pos;
}

Position RobotW::getNextPosition()
{
	int w_row = getCurrentPosition().getRow(); //RobotW
	int w_col = getCurrentPosition().getCol();
	int wat_row = watson->getCurrentPosition().getRow(); //Watson
	int wat_col = watson->getCurrentPosition().getCol();
	int min_U = INT_MAX, min_D = INT_MAX, min_L = INT_MAX, min_R = INT_MAX;
	if (map->isValidPosition(w_row - 1, w_col, this))     //UP
		min_U = abs(w_row - 1 - wat_row) + abs(w_col - wat_col);
	if (map->isValidPosition(w_row + 1, w_col, this))     //DOWN
		min_D = abs(w_row + 1 - wat_row) + abs(w_col - wat_col);
	if (map->isValidPosition(w_row, w_col + 1, this))     //RIGHT
		min_R = abs(w_row - wat_row) + abs(w_col + 1 - wat_col);
	if (map->isValidPosition(w_row, w_col - 1, this))     //LEFT
		min_L = abs(w_row - wat_row) + abs(w_col - 1 - wat_col);

	if (min_U == INT_MAX && min_D == INT_MAX && min_L == INT_MAX && min_R == INT_MAX) return Position::npos;

	int min_dist = min(min_U, min(min_L, min(min_D, min_R)));
	if (min_dist == min_U) w_row--;
	else if (min_dist == min_R) w_col++;
	else if (min_dist == min_D) w_row++;
	else if (min_dist == min_L) w_col--;

	return Position(w_row, w_col);
}

int RobotW::getDistance() const { return Manhattan(this, watson); }

string RobotW::str() const {
	return Robot::str() + "W;dist=" + to_string(this->getDistance()) + "]";
}

RobotW::~RobotW() {}
///////////////////////////////////RobotW/////////////////////////////////////////



///////////////////////////////////RobotSW/////////////////////////////////////////
RobotSW::RobotSW(int index, const Position& init_pos, Map* map, Criminal* criminal, Sherlock* sherlock, Watson* watson) : Robot(index, init_pos, map, criminal) 
{
	this->sherlock = sherlock;
	this->watson = watson;
	this->robot_type = SW;
}

void RobotSW::move() {
	Position next_pos = getNextPosition();
	if (next_pos.getRow() == -1 && next_pos.getCol() == -1) return;
	if ((*map).isValid(next_pos, this)) pos = next_pos;
}

int RobotSW::getDistance() const { return Manhattan(this, watson) + Manhattan(this, sherlock); }

string RobotSW::str() const {
	return Robot::str() + "SW;dist=" + to_string(this->getDistance()) + "]";
}

RobotSW::~RobotSW() {}

/// /////////////CHECK KI LAI//// SW thay đổi 2 đơn vị mỗi bước đi

Position RobotSW::getNextPosition()
{
	int sw_row = getCurrentPosition().getRow(); //RobotSW
	int sw_col = getCurrentPosition().getCol();
	int sher_row = sherlock->getCurrentPosition().getRow();  //Sherlock
	int sher_col = sherlock->getCurrentPosition().getCol();
	int wat_row = watson->getCurrentPosition().getRow(); //Watson
	int wat_col = watson->getCurrentPosition().getCol();

	int min_U = INT_MAX, min_D = INT_MAX, min_L = INT_MAX, min_R = INT_MAX;
	int min_LU = INT_MAX, min_RU = INT_MAX, min_LD = INT_MAX, min_RD = INT_MAX;

	if (map->isValidPosition(sw_row - 2, sw_col, this)) {   //UP
		min_U = abs(sw_row - 2 - sher_row) + abs(sw_col - sher_col) + abs(sw_row - 2 - wat_row) + abs(sw_col - wat_col);
	}
	if (map->isValidPosition(sw_row + 2, sw_col, this)) {   //DOWN
		min_D = abs(sw_row + 2 - sher_row) + abs(sw_col - sher_col) + abs(sw_row + 2 - wat_row) + abs(sw_col - wat_col);
	}
	if (map->isValidPosition(sw_row, sw_col + 2, this)) {   //RIGHT
		min_R = abs(sw_row - sher_row) + abs(sw_col + 2 - sher_col) + abs(sw_row - wat_row) + abs(sw_col + 2 - wat_col);
	}
	if (map->isValidPosition(sw_row, sw_col - 2, this)) {   //LEFT
		min_L = abs(sw_row - sher_row) + abs(sw_col - 2 - sher_col) + abs(sw_row - wat_row) + abs(sw_col - 2 - wat_col);
	}
	if (map->isValidPosition(sw_row - 1, sw_col - 1, this)) {   //UP AND LEFT
		min_LU = abs(sw_row - 1 - sher_row) + abs(sw_col - 1 - sher_col) + abs(sw_row - 1 - wat_row) + abs(sw_col - 1 - wat_col);
	}
	if (map->isValidPosition(sw_row - 1, sw_col + 1, this)) {   //UP AND RIGHT
		min_RU = abs(sw_row - 1 - sher_row) + abs(sw_col + 1 - sher_col) + abs(sw_row - 1 - wat_row) + abs(sw_col + 1 - wat_col);
	}
	if (map->isValidPosition(sw_row + 1, sw_col - 1, this)) {   //DOWN AND LEFT
		min_LD = abs(sw_row + 1 - sher_row) + abs(sw_col - 1 - sher_col) + abs(sw_row + 1 - wat_row) + abs(sw_col - 1 - wat_col);
	}
	if (map->isValidPosition(sw_row + 1, sw_col + 1, this)) {   //DOWN AND RIGHT
		min_RD = abs(sw_row + 1 - sher_row) + abs(sw_col + 1 - sher_col) + abs(sw_row + 1 - wat_row) + abs(sw_col + 1 - wat_col);
	}
	if (min_U == INT_MAX && min_D == INT_MAX && min_L == INT_MAX && min_R == INT_MAX && min_LU == INT_MAX && min_RU == INT_MAX && min_LD == INT_MAX && min_RD == INT_MAX) return Position::npos;
	int min_dist = 0;

	min_dist = min(min_U, min(min_L, min(min_D, min_R)));
	min_dist = min(min_LU, min_dist);
	min_dist = min(min_RU, min_dist);
	min_dist = min(min_LD, min_dist);
	min_dist = min(min_RD, min_dist);

	if (min_dist == min_U) sw_row-=2; 
	else if (min_dist == min_RU) sw_row--, sw_col++;
	else if (min_dist == min_R) sw_col+=2;
	else if (min_dist == min_RD) sw_row++, sw_col++;
	else if (min_dist == min_D) sw_row+=2;
	else if (min_dist == min_LD) sw_row++, sw_col--;
	else if (min_dist == min_L) sw_col-=2;
	else if (min_dist == min_LU) sw_row--, sw_col--;
	
	return Position(sw_row, sw_col);
}


///////////////////////////////////RobotSW/////////////////////////////////////////


///////////////////////////////////BaseItem/////////////////////////////////////////
BaseItem::BaseItem(ItemType item_type) {
	this->item_type = item_type;
}

ItemType BaseItem::getType() const { return this->item_type; }


BaseItem::~BaseItem() {}
///////////////////////////////////BaseItem/////////////////////////////////////////



///////////////////////////////////MagicBook/////////////////////////////////////////
MagicBook::MagicBook() : BaseItem(MAGIC_BOOK) {}

void MagicBook::use(Character* obj, Robot* robot)
{
	obj->setExp((int)(double(obj->getExp())*1.25+0.999));
	obj->setExp(Suitable(obj->getExp(), 0, 900));
}

bool MagicBook::canUse(Character* obj, Robot* robot) {
	if (obj->getName() == "Sherlock" || obj->getName() == "Watson") {
		if (obj->getExp() <= 350) return 1;
	}
	return false;
}


string MagicBook::str() const {	return "MagicBook";}
MagicBook::~MagicBook() {}
///////////////////////////////////MagicBook/////////////////////////////////////////


///////////////////////////////////EnergyDrink/////////////////////////////////////////
EnergyDrink::EnergyDrink() : BaseItem(ENERGY_DRINK) {}


bool EnergyDrink::canUse(Character* obj, Robot* robot) {
	if (obj->getName() == "Sherlock" || obj->getName() == "Watson") {
		if (obj->getHp() <= 100) return 1; 
	}
	return false;
}

void EnergyDrink::use(Character* obj, Robot* robot)
{
	obj->setHp((int)(double(obj->getHp()) * 1.2 + 0.999));
	obj->setHp(Suitable(obj->getHp(), 0, 500));
}

string EnergyDrink::str() const { return "EnergyDrink"; }

EnergyDrink::~EnergyDrink() {}
///////////////////////////////////EnergyDrink/////////////////////////////////////////


///////////////////////////////////FirstAid/////////////////////////////////////////
FirstAid::FirstAid() : BaseItem(FIRST_AID) {}


bool FirstAid::canUse(Character* obj, Robot* robot) {
	if (obj->getName() == "Sherlock" || obj->getName() == "Watson") {
		if (obj->getExp() <= 350 || obj->getHp() <= 100) return 1;
	}
	return 0;
}

void FirstAid::use(Character* obj, Robot* robot)
{
	obj->setHp((int)(double(obj->getHp()) * 1.5 + 0.999));
	obj->setHp(Suitable(obj->getHp(), 0, 500));
}

string FirstAid::str() const { return "FirstAid"; }

FirstAid::~FirstAid() {}
///////////////////////////////////FirstAid/////////////////////////////////////////


///////////////////////////////////ExcemptionCard/////////////////////////////////////////
ExcemptionCard::ExcemptionCard() : BaseItem(EXCEMPTION_CARD) {}

bool ExcemptionCard::canUse(Character* obj, Robot* robot) {
	if (robot == nullptr) return 0;
	if (obj->getName() == "Sherlock" || obj->getName() == "Watson") {
		if (obj->getName() == "Sherlock" && obj->getHp() % 2) return 1;
	}
	return 0;
}

void ExcemptionCard::use(Character* obj, Robot* robot)
{
	if (robot == nullptr || ExcemptionCard::canUse(obj, robot) == 0) return;
}

string ExcemptionCard::str() const { return "ExcemptionCard"; }

ExcemptionCard::~ExcemptionCard() {}
///////////////////////////////////ExcemptionCard/////////////////////////////////////////


///////////////////////////////////PassingCard/////////////////////////////////////////
PassingCard::PassingCard(string challenge) : BaseItem(PASSING_CARD), challenge(challenge) {}

void PassingCard::use(Character* obj, Robot* robot)
{
	if (robot == nullptr) return;
	if (challenge == "all") {}
	else if (challenge == "RobotS" && robot->getType() == S) {}
	else if (challenge == "RobotC" && robot->getType() == C) {}
	else if (challenge == "RobotSW" && robot->getType() == SW) {}
	else obj->setExp(obj->getExp() - 50);
	obj->setExp(Suitable(obj->getExp(), 0, 900));
}

bool PassingCard::canUse(Character* obj, Robot* robot) {
	if (robot == nullptr) return 0;
	if (obj->getName() == "Sherlock" || obj->getName() == "Watson") {
		if (obj->getName().compare("Watson") == 0 && obj->getHp() % 2 == 0) return 1;
	}
	return 0;
}

string PassingCard::str() const { return "PassingCard"; }

PassingCard::~PassingCard() {}
///////////////////////////////////PassingCard/////////////////////////////////////////


///////////////////////////////////Node/////////////////////////////////////////
Node::Node(BaseItem* item, Node* next) : item(item), next(next) {}
Node::Node() {}
Node::~Node() { /*delete item;*/ }
///////////////////////////////////Node/////////////////////////////////////////


///////////////////////////////////BaseBag////////////////////////////////////////////////
bool BaseBag::insert(BaseItem* item) 
{
	if (item == nullptr) return 0;
	if (count == capacity) return 0;

	Node* newNode = new Node(item, nullptr);
	
	if (head == nullptr) head = newNode;
	else newNode->next = head, head = newNode;
	count++;
	return true;
}

BaseBag::BaseBag(Character* obj): obj(obj) { this->head = nullptr; }

BaseItem* BaseBag::get() // return the item as described above , if not found, return NULL 
{
	if (count == 0 || head == nullptr) return NULL;
	Node* temp = head;
	BaseItem* itemtouse = temp->item;
	head = head->next;
	delete temp;
	count--;
	return itemtouse;
} 

int BaseBag::search() const
{
	if (count == 0 || head == nullptr) return -1;
	Node* temp = head;
	Node* prev = nullptr;

	while (temp && !temp->item->canUse(obj, nullptr)) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == nullptr) return -1;

	if (temp->item->getType() == MAGIC_BOOK) return 0;
	else if (temp->item->getType() == ENERGY_DRINK) return 1;
	else if (temp->item->getType() == FIRST_AID) return 2;
	return -1;
}

BaseItem* BaseBag::get(ItemType itemType) // return the item as described above, if not found, return NULL
{
	if (count == 0 || head == nullptr) return NULL;
	Node* temp = head;
	Node* prev = nullptr;
	while (temp && temp->item->getType() != itemType) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == nullptr) return NULL;

	BaseItem* itemtouse = temp->item;
	if (prev) {
		if (prev != head) {
			Node* first = head;
			head = head->next;
			prev->next = first;
			first->next = temp->next;
		}
		else prev->next = temp->next;
		delete temp;
	} else {
		Node* toDel = head;
		head = head->next;
		delete toDel;
	}
	count--;
	return itemtouse;
}

BaseBag::~BaseBag() 
{
	Node* current = head;
	while (current) {
		Node* temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;
	count = 0;
}

string BaseBag::str() const 
{
	string result = "Bag[count=" + to_string(this->count) + ";";
	if (count == 0) return result += "]";
	Node* current = head;
	int item_count = 0;
	while (current != nullptr) {
		result += current->item->str();
		if (item_count == count - 1) result += "]";
		else result += ",";
		item_count++;
		current = current->next;
	}
	return result;
}

int BaseBag::getSize() const {
	return this->count;
}
///////////////////////////////////BaseBag////////////////////////////////////////////////



///////////////////////////////////SherlockBag////////////////////////////////////////////////
SherlockBag::SherlockBag(Sherlock* sherlock) : BaseBag(sherlock), sherlock(sherlock)
{ 
	this->capacity = 13; 
}

bool SherlockBag::insert(BaseItem* item) {
	return BaseBag::insert(item);
}

BaseItem* SherlockBag::get() {
	return BaseBag::get();
}

int SherlockBag::search() const {
	return BaseBag::search();
}

BaseItem* SherlockBag::get(ItemType itemType) {
	return BaseBag::get(itemType);
}

string SherlockBag::str() const
{
	return BaseBag::str();
}

bool SherlockBag::passingSearch() const
{
	if (head == nullptr) return 0;
	Node* current = head;
	while (current) {
		if (current->item->getType() == PASSING_CARD) return 1;
		current = current->next;
	}
	return 0;
}

SherlockBag::~SherlockBag() { }
///////////////////////////////////SherlockBag////////////////////////////////////////////////



///////////////////////////////////WatsonBag////////////////////////////////////////////////
WatsonBag::WatsonBag(Watson* watson) : BaseBag(watson), watson(watson) { this->capacity = 15; }

bool WatsonBag::insert(BaseItem* item) {
	return BaseBag::insert(item);
}

BaseItem* WatsonBag::get() {
	return BaseBag::get();
}

int WatsonBag::search() const {
	return BaseBag::search();
}

BaseItem* WatsonBag::get(ItemType itemType) {
	return BaseBag::get(itemType);
}

string WatsonBag::str() const
{
	return BaseBag::str();
}

bool WatsonBag::excemptionSearch() const
{
	if (head == nullptr) return 0;
	Node* current = head;
	while (current) {
		if (current->item->getType() == EXCEMPTION_CARD) return 1;
		current = current->next;
	}
	return 0;
}

WatsonBag::~WatsonBag() {}
///////////////////////////////////WatsonBag////////////////////////////////////////////////




////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
