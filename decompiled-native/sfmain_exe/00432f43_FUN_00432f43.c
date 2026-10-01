// 00432f43 FUN_00432f43 [Global]
// program: sfmain.exe

longlong __fastcall FUN_00432f43(undefined4 param_1,uint param_2)

{
  uint in_EAX;
  
  if (3 < in_EAX) {
    return (ulonglong)param_2 << 0x20;
  }
  return CONCAT44(param_2,&DAT_0043e530 + in_EAX * 0x1a);
}


