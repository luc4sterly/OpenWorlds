// 00407ffe FUN_00407ffe [Global]
// program: sfmain.exe

int __fastcall FUN_00407ffe(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  
  if (0xf < param_2) {
    return 0;
  }
  if (param_2 < -0xf) {
    return -CONCAT22((short)((uint)in_EAX >> 0x10),(ushort)((short)in_EAX < 0));
  }
  if (param_2 < 0) {
    iVar1 = FUN_00407f9e(param_1,-param_2);
    return iVar1;
  }
  return in_EAX << ((byte)param_2 & 0x1f);
}


