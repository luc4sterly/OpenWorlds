// 10062850 __controlfp [Global]
// programa: rwdlmd21.dll

/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 1998 Release */

uint __cdecl __controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __control87(_NewValue,_Mask & 0xfff7ffff);
  return uVar1;
}


