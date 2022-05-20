#include "cOrgano.h"




//contructor de cOrgano
cOrgano::cOrgano(eOrgano _organo, cFechayHora* _fechayhora_extraccion) {
	
	this->organo = _organo;
	fechayhora_extraccion = _fechayhora_extraccion;
	vehiculo = NULL;

}

eOrgano cOrgano::get_Organo() {
	return this->organo;
}


//destructor de cOrgano
cOrgano::~cOrgano() {

	if(fechayhora_extraccion !=NULL)
		delete fechayhora_extraccion;
	if (vehiculo != NULL) 
		delete vehiculo;

}
