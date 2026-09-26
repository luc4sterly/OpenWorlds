// 004066d2 FUN_004066d2 [Global]
// programa: gdkup.exe

longlong __fastcall FUN_004066d2(undefined4 param_1,uint param_2)

{
  short *in_EAX;
  
  if (((*in_EAX == 1) && (*(int *)(in_EAX + 2) != 0)) &&
     (((ushort)in_EAX[5] < 0x10 || (0x12 < (ushort)in_EAX[5])))) {
    return CONCAT44(param_2,1);
  }
  return (ulonglong)param_2 << 0x20;
}


