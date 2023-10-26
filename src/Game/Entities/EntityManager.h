#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"

class EntityManager {

public:
	Client* firstClient;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	void checkInspectorLeft();
	std::vector<Entity*> entities;
    int clientLeft = 0; 
	bool inspectorLeft = false;
};

