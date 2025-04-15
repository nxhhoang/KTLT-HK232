SCP* cloneSCP(SCP* original) {
// Student answer
	SCP* newobj = new SCP;
	newobj->id = original->id;
	newobj->objClass = original->objClass;
	newobj->speConProcedures = original->speConProcedures;
	newobj->description = original->description;
	newobj->addendums = new string[original->numAddendums];
	*newobj->addendums = *original->addendums;
	newobj->numAddendums = original->numAddendums;
	return newobj;
}
