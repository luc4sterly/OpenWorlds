// 00442590 FUN_00442590 [Global]
// programa: gamma.dll

undefined * __cdecl FUN_00442590(undefined4 param_1,int param_2,undefined4 *param_3)

{
  *param_3 = 0;
  switch(param_1) {
  case 0:
    *param_3 = 0x51;
    return &DAT_0047927c;
  case 1:
    break;
  default:
    return (undefined *)0x0;
  case 3:
    *param_3 = 0x16;
    return &DAT_004792d0;
  }
  if (param_2 != 0) {
    return (undefined *)0x0;
  }
  *param_3 = 0x31;
  return &DAT_00479028;
}


