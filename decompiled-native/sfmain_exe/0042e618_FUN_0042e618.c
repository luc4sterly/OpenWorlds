// 0042e618 FUN_0042e618 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0042e618(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  int extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 *puVar4;
  undefined4 extraout_EDX;
  uint uVar5;
  undefined8 uVar6;
  
  (*(code *)PTR_FUN_0043e800)();
  if (_DAT_004e57a8 == (undefined4 *)0x0) {
    for (puVar3 = &DAT_0043e530; puVar3 < &DAT_0043e738; puVar3 = puVar3 + 0x1a) {
      if ((puVar3[0xc] & 3) == 0) {
        uVar6 = FUN_0042ba46(puVar3,extraout_EDX);
        uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
        puVar1 = (undefined4 *)uVar6;
        puVar4 = extraout_ECX;
        if (puVar1 == (undefined4 *)0x0) goto LAB_0042e6b8;
        uVar5 = 3;
        goto LAB_0042e68d;
      }
    }
    uVar5 = 0x4003;
    uVar6 = FUN_0042ba46(puVar3,extraout_EDX);
    uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
    puVar1 = (undefined4 *)uVar6;
    puVar4 = extraout_ECX_00;
    if (puVar1 == (undefined4 *)0x0) {
LAB_0042e6b8:
      FUN_0042d8ad(puVar4,uVar2);
      (*(code *)PTR_FUN_0043e804)();
      uVar2 = 0;
      goto LAB_0042e6ca;
    }
    puVar4 = puVar1 + 2;
  }
  else {
    puVar4 = (undefined4 *)_DAT_004e57a8[1];
    uVar5 = (uint)((ushort)puVar4[3] & 0x4003 | 3);
    puVar1 = _DAT_004e57a8;
    _DAT_004e57a8 = (undefined4 *)*_DAT_004e57a8;
  }
LAB_0042e68d:
  FUN_00408098(puVar4,0);
  *(uint *)(extraout_ECX_01 + 0xc) = uVar5;
  puVar1[1] = extraout_ECX_01;
  *puVar1 = _DAT_004e57b8;
  _DAT_004e57b8 = puVar1;
  (*(code *)PTR_FUN_0043e804)();
  uVar2 = extraout_ECX_02;
LAB_0042e6ca:
  return CONCAT44(param_2,uVar2);
}


