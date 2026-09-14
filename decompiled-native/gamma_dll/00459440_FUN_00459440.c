// 00459440 FUN_00459440 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00459440(undefined4 *param_1,uint *param_2,int param_3,uint param_4)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 1);
  if (param_3 == 0) {
    FUN_00454f40(param_1);
  }
  if (((*(byte *)(param_1 + 2) & 7) != 0) || ((uVar1 >> 7 & 7) == 0)) {
    return 0xffffffff;
  }
  if ((param_3 != 0) && ((param_3 != 1 && (param_3 != 2)))) {
    return 0xffffffff;
  }
  if (((undefined4 *)param_1[8] != (undefined4 *)0x0) && ((*(byte *)(param_1 + 2) >> 3 & 1) != 0)) {
    FUN_00454a60((undefined4 *)param_1[8]);
  }
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0x9f | ((byte)param_3 & 3) << 5;
  *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xf7;
  param_1[8] = (int)param_1 + 0x11;
  param_1[10] = (int)param_1 + 0x11;
  param_1[9] = 1;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  if ((param_3 != 0) && (param_4 != 0)) {
    if (param_2 == (uint *)0x0) {
      param_2 = FUN_00454a10(param_4);
      if (param_2 == (uint *)0x0) {
        return 0xffffffff;
      }
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xf7 | 8;
    }
    param_1[8] = param_2;
    param_1[10] = param_1[8];
    param_1[9] = param_4;
    param_1[0xc] = 0;
    return 0;
  }
  *(undefined1 *)param_1[10] = 0;
  return 0;
}


