// 00451990 FUN_00451990 [Global]
// program: gamma.dll

ushort * FUN_00451990(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    uVar1 = *param_1;
    if (uVar1 < 0x100) {
      uVar1 = *(ushort *)(&DAT_004834e0 + (uint)uVar1 * 2);
    }
    *param_1 = uVar1;
  }
  return param_2;
}


