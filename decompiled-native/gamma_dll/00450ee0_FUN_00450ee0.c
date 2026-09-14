// 00450ee0 FUN_00450ee0 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00450ee0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined4 *)param_1[3];
  uVar1 = puVar2[1];
  param_1[3] = *puVar2;
  uVar3 = (uint)*(char *)*param_2;
  if ((uVar3 & 8) != 0) {
    puVar2 = puVar2 + -1;
    *param_1 = *puVar2;
  }
  if ((uVar3 & 0x40) != 0) {
    puVar2 = puVar2 + -1;
    param_1[1] = *puVar2;
  }
  if ((uVar3 & 0x80) != 0) {
    param_1[2] = puVar2[-1];
  }
  return uVar1;
}


