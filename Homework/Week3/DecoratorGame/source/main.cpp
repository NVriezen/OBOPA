/*Nintendo DS Specific*/
#include <nds.h>

/*Non-Platform Specific*/
#include <iostream>

#include "Orc.h"
#include "Elf.h"
#include "Shaman.h"
#include "Soldier.h"
#include "Farmer.h"

int main() {
	consoleDemoInit(); //To be able to use the console of the DS

	//Create some NPCs
	NPC *npc1 = new Orc("Herman");
	NPC *npc2 = new Shaman(new Elf("Anne"));
	NPC *npc3 = new Farmer(new Shaman(new Elf("Sophie")));
	NPC *npc4 = new Soldier(new Orc("Kees"));

	std::cout << "Decorator Game V1.01\n" << std::endl;

	//call the render functions to get their information
	npc1->render();
	npc2->render();
	npc3->render();
	npc4->render();

	//Is there a game being made out of this?
	std::cout << "\n\nTo be continued..." << std::endl;

	//This while loop is needed to keep displaying the text.
	//Otherwise the DS will exit the application.
	while (1) {
		swiWaitForVBlank();
	}
	return 0;
}