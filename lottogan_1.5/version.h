#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char loto_DATE[] = "03";
	static const char loto_MONTH[] = "11";
	static const char loto_YEAR[] = "2021";
	static const char loto_UBUNTU_VERSION_STYLE[] =  "21.11";
	
	//Software Status
	static const char loto_STATUS[] =  "Alpha";
	static const char loto_STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long loto_MAJOR  = 1;
	static const long loto_MINOR  = 0;
	static const long loto_BUILD  = 4;
	static const long loto_REVISION  = 23;
	
	//Miscellaneous Version Types
	static const long loto_BUILDS_COUNT  = 11;
	#define loto_RC_FILEVERSION 1,0,4,23
	#define loto_RC_FILEVERSION_STRING "1, 0, 4, 23\0"
	static const char loto_FULLVERSION_STRING [] = "1.0.4.23";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long loto_BUILD_HISTORY  = 4;
	

}
#endif //VERSION_H
