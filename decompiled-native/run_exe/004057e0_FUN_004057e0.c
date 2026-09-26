// 004057e0 FUN_004057e0 [Global]
// programa: run.exe

undefined4 __cdecl FUN_004057e0(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((*(byte *)((int)&DAT_0040bd20 + param_1 + 1) & param_3) == 0) {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(ushort *)(&DAT_0040b5ba + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


