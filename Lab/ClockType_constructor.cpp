
ClockType::ClockType(int hr, int min, int sec) {
	this->hr = (hr < 0 || hr>=24) ? 0 : hr;
	this->min = (min < 0 || min>=60) ? 0 : min;
	this->sec = (sec < 0 || sec>=60) ? 0 : sec;
}
ClockType::ClockType() {
	this->hr = 0;
	this->min = 0;
	this->sec = 0;
}
