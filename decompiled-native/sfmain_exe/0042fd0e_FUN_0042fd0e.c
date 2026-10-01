// 0042fd0e FUN_0042fd0e [Global]
// program: sfmain.exe

longlong __fastcall FUN_0042fd0e(undefined4 param_1,uint param_2)

{
  uint in_EAX;
  
  if (((in_EAX & 3) == 0) && (((int)in_EAX % 100 != 0 || ((int)in_EAX % 400 == 0)))) {
    return CONCAT44(param_2,1);
  }
  return (ulonglong)param_2 << 0x20;
}


