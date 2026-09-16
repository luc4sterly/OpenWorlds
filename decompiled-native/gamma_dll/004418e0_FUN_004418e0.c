// 004418e0 FUN_004418e0 [Global]
// programa: gamma.dll

undefined4 FUN_004418e0(int param_1,uint param_2,undefined4 *param_3)

{
  DWORD DVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  DVar1 = FUN_0044bad0(*(HANDLE *)(param_1 + 0x48),param_2,(HWND)0x0,0,0);
  if (DVar1 == 0x102) {
    *param_3 = *(undefined4 *)(param_1 + 8);
    return 0x40237;
  }
  *param_3 = *(undefined4 *)(param_1 + 8);
  return 0;
}


