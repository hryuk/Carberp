


///////////////////////////////////////////////////////

void UnprotectFile(char *fname)
{
	BOOL resO, resD;

	if (/*@S==*/ isSystemNT() == 0 /*@E*/) 
		return;                                          

	resO = _SetFileSecurity(fname, OWNER_SECURITY_INFORMATION, sdsc2); 
	resD = _SetFileSecurity(fname, DACL_SECURITY_INFORMATION, sdsc2);  

 #ifdef dbgdbg
	adddeb("SetFileSecurity results %s set_owner:%u set_dacl:%u (0==fail)", fname, resO, resD);
 #endif
}
