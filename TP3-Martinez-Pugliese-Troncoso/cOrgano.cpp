#include "cOrgano.h"



//contructor de cOrgano
cOrgano::cOrgano(string _organo, cFechayHora* _fechayhora_extraccion) {

	this->organo = _organo;
	fechayhora_extraccion = _fechayhora_extraccion;

}


//destructor de cOrgano
cOrgano::~cOrgano() {

	delete fechayhora_extraccion;

}
