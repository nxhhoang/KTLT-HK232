void Course::getinfo() {
	cout << "ID: ";
	cin >> ID;
	cout << "Number of Students: ";
	cin >> numOfStudent;
	cout << "Number of Teachers: ";
	cin >> numOfTeacher;
	cout << "Number of TAs: ";
	cin >> numOfTA;
}
void Course::disinfo()
{
	cout<<endl;
	cout<< "CourseID = "<< ID << endl;
	cout<< "Number of student = " << numOfStudent << endl;
	cout<< "Number of teacher = " << numOfTeacher << endl;
	cout<< "Number of TA = " << numOfTA<< endl;
}
