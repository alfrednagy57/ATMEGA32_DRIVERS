#ifndef StdType_H_
#define StdType_H_
	
	typedef unsigned char u8;//Range of unsigned char: 0 to 255
	typedef signed char   s8;//Range of char: -128 to 127
	
	typedef unsigned short int u16;//Range of short: -32,768 to 32,767
	typedef signed short int s16;//Range of unsigned short: 0 to 65,535
	
	typedef unsigned long int u32;//Range of unsigned int: 0 to 4,294,967,295
	typedef signed long int s32;//Range of int: -2,147,483,648 to 2,147,483,647
	typedef float f32;//Range of float: 1.175494E-38 to 3.402823E+38
	
	typedef unsigned long long int u64;//Range of long: 0 to 18,446,744,073,709,551,615 
	typedef signed long long int s64;//Range of long: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
	typedef double f64;//Range of double: 2.225074E-308 to 1.797693E+308

	typedef long double f96;//Range of long double: 3.362103E-4932 to 1.189731E+4932

#endif /* StdType_H_ */
