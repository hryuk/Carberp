#include <windows.h>
#include "ms10_073.h"

int Entry()
{
	if( ExploitMS10_073() )
		MessageBox(0, "TRUE", "!!!", 0);
	else
		MessageBox(0, "FALSE", "!!!", 0);
	return 0;
}
