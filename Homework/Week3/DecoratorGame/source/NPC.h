#pragma once

//Base NPC Class
class NPC {
public:
	NPC();
	virtual ~NPC();
	virtual void render() = 0;
};
