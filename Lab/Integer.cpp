class Integer {
private:
	int val;
public:
	Integer(int val):val(val) {}
	void setValue(int k) {
		this->val = k;
	}
	int getValue() {
		return this->val;
	}
};
