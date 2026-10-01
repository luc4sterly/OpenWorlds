// 00454eb0 FUN_00454eb0 [Global]
// program: gamma.dll

undefined4 __cdecl FUN_00454eb0(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  if ((*(ushort *)(param_1 + 1) >> 7 & 7) == 0) {
    return 0;
  }
  iVar2 = FUN_00454f40(param_1);
  iVar3 = (*(code *)param_1[0x12])(*param_1);
  *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0xfc7f;
  *param_1 = 0;
  if ((*(byte *)(param_1 + 2) >> 3 & 1) != 0) {
    FUN_00454a60((undefined4 *)param_1[8]);
  }
  bVar1 = true;
  if ((iVar2 == 0) && (iVar3 == 0)) {
    bVar1 = false;
  }
  if (bVar1) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


