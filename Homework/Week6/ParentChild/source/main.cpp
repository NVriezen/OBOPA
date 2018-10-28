
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>

#include <iostream>
#include <memory>
#include "Parent.h"

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main() {
//---------------------------------------------------------------------------------

	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	// since the default dispatcher handles the bios flags no vblank handler
	// is required
	irqInit();
	irqEnable(IRQ_VBLANK);

	consoleDemoInit();

//---------------------------------------------------------------------------------
	{
		//Assignment code below
		std::shared_ptr<Parent> p1 = std::make_shared<Parent>("Parent1");
		std::cout << "P1:" << *p1 << std::endl;

		std::shared_ptr<Parent> p2 = std::make_shared<Parent>(*p1); // roept de copy constructor aan
		std::cout << "P2:" << *p2 << std::endl;

		std::shared_ptr<Parent> p3 = std::make_shared<Parent>("Parent3");
		std::cout << "P3:" << *p3 << std::endl;

		//*p3 = *p1; // roept de assignment operator aan
		p3 = p1;
		std::cout << "P3:" << *p3 << std::endl;

		std::shared_ptr<Parent> p4 = p1;

		std::cout << "usecount: " << p1.use_count() << std::endl;
	}
//---------------------------------------------------------------------------------

	while (1) {
		VBlankIntrWait();
	}
	return 0;
}


