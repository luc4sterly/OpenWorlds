// 0042f659 FUN_0042f659 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0042f659(undefined4 param_1,undefined4 param_2)

{
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  
  (*(code *)PTR_FUN_0043e800)(param_2,param_1);
  iVar3 = 0;
  uVar1 = extraout_ECX;
  for (puVar2 = _DAT_004e57b8; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if (((*(uint *)(puVar2[1] + 0xc) & uVar1) != 0) &&
       (iVar3 = iVar3 + 1, (*(byte *)(puVar2[1] + 0xd) & 0x10) != 0)) {
      uVar4 = FUN_0042d957(uVar1,puVar2);
      puVar2 = (undefined4 *)((ulonglong)uVar4 >> 0x20);
      uVar1 = extraout_ECX_00;
    }
  }
  (*(code *)PTR_FUN_0043e804)();
  return CONCAT44(param_2,iVar3);
}


