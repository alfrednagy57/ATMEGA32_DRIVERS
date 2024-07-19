#ifndef BitMath_H_
#define BitMath_H_


#define SetBit(Reg,BitNum)       Reg |= (1<<BitNum)
#define ClrBit(Reg,BitNum)       Reg &= ~(1<<BitNum)
#define ReadBit(Reg,BitNum)      (Reg>>BitNum)&1
#define TogBit(Reg,BitNum)       Reg ^= (1<<BitNum)
#define TogGroup(Reg,Data)		 Reg^=(Data)

#define Sol(Reg,NoShift)         Reg<<=NoShift
#define Sor(Reg,NoShift)         Reg>>=NoShift

#define Rol(Reg,NoShit)          (Reg= Reg<<NoShift | (Reg>>(8-NoShift)) )
#define Ror(Reg,NoShit)          (Reg= Reg>>NoShift | (Reg<<(8-NoShift)) )

#endif /* BitMath_H_ */
