class Room {
private:
	double length;
	double breadth;
	double height;
public:
	Room(double length,
	     double breadth,
	     double height): length(length), breadth(breadth), height(height) {}
	double calculateArea() {
		return length*breadth;
	}
	double calculateVolume() {
		return calculateArea()*height;
	}
};
