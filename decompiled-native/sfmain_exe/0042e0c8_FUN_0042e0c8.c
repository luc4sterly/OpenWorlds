// 0042e0c8 FUN_0042e0c8 [Global]
// programa: sfmain.exe

undefined4 FUN_0042e0c8(uint param_1)

{
  undefined4 in_EAX;
  ushort in_FPUStatusWord;
  
  if ((param_1 & 0x7f800000) == 0x7f800000) {
    return in_EAX;
  }
  if ((in_FPUStatusWord & 0x3800) != 0) {
    FUN_0042e00a();
    return in_EAX;
  }
  FUN_0042e00a();
  return in_EAX;
}


