// 1005b3d0 __controlfp [Global]
// program: RWDL8D21.DLL

/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 1998 Release */

uint __cdecl __controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __control87(_NewValue,_Mask & 0xfff7ffff);
  return uVar1;
}


