void ClockType::setTime(int hr, int min, int sec) {
	if (hr < 0 || hr >= 24) {
		this->hr = 0;
	} else {
		this->hr = hr;
	}
	if (min < 0 || min >= 60) {
		this->min = 0;
	} else {
		this->min = min;
	}
	if (sec < 0 || sec >= 60) {
		this->sec = 0;
	} else {
		this->sec = sec;
	}
}
