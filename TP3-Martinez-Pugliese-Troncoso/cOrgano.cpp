#include "cOrgano.h"



//contructor de cOrgano
cOrgano::cOrgano(string _organo, cFechayHora* _fechayhora_extraccion) {

	this->organo = _organo;
	fechayhora_extraccion = _fechayhora_extraccion;

}


//destructor de cOrgano
cOrgano::~cOrgano() {

	if(fechayhora_extraccion !=NULL)
		delete fechayhora_extraccion;

}