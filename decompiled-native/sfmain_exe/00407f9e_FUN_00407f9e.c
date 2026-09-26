// 00407f9e FUN_00407f9e [Global]
// programa: sfmain.exe

int __fastcall FUN_00407f9e(undefined4 param_1,int param_2)

{
  int in_EAX;
  
  if (0xf < param_2) {
    return -CONCAT22((short)((uint)in_EAX >> 0x10),(ushort)((short)in_EAX < 0));
  }
  if (param_2 < -0xf) {
    return 0;
  }
  if (param_2 < 0) {
    return in_EAX << (-(byte)param_2 & 0x1f);
  }
  return (int)(short)in_EAX >> ((byte)param_2 & 0x1f);
}


