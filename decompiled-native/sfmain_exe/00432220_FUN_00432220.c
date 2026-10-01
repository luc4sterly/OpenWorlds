// 00432220 FUN_00432220 [Global]
// program: sfmain.exe

void __fastcall FUN_00432220(undefined4 param_1,undefined4 *param_2)

{
  int in_EAX;
  
  if ((in_EAX == 0) || (in_EAX == 0x40)) {
    *param_2 = 3;
    return;
  }
  if (in_EAX == 0x20) {
    *param_2 = 1;
    return;
  }
  if (in_EAX == 0x30) {
    *param_2 = 2;
    return;
  }
  *param_2 = 0;
  return;
}


