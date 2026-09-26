// 0042c6a0 FUN_0042c6a0 [Global]
// programa: sfmain.exe

/* WARNING: Removing unreachable block (ram,0x0042c72c) */

undefined4 __fastcall FUN_0042c6a0(undefined4 param_1,int param_2)

{
  DWORD DVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  undefined4 *puVar3;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 uVar4;
  uint unaff_EBX;
  undefined8 uVar5;
  
  (*(code *)PTR_FUN_0043e7f0)();
  if ((*(byte *)(extraout_ECX + 3) & 6) == 0) {
    if (unaff_EBX == 0) {
      FUN_0042f45e(extraout_ECX,extraout_EDX);
      iVar2 = FUN_0042c65e(extraout_ECX_01,(int *)extraout_ECX_01);
    }
    else {
      if (1 < unaff_EBX) {
        puVar3 = extraout_ECX;
        uVar4 = extraout_EDX;
        if (unaff_EBX != 2) goto LAB_0042c6d1;
        *(byte *)(extraout_ECX + 3) = *(byte *)(extraout_ECX + 3) & 0xef;
        *extraout_ECX = extraout_ECX[2];
        extraout_ECX[1] = 0;
        goto LAB_0042c6fa;
      }
      iVar2 = FUN_0042c65e(extraout_ECX,extraout_ECX);
    }
    if (iVar2 == 0) goto LAB_0042c785;
  }
  else {
    if ((*(byte *)((int)extraout_ECX + 0xd) & 0x10) == 0) {
      extraout_ECX[1] = 0;
      *extraout_ECX = extraout_ECX[2];
      puVar3 = extraout_ECX;
    }
    else {
      uVar5 = FUN_0042d957(extraout_ECX,extraout_EDX);
      uVar4 = (undefined4)((ulonglong)uVar5 >> 0x20);
      puVar3 = extraout_ECX_00;
      if ((int)uVar5 != 0) {
        if ((unaff_EBX != 0) || (-1 < param_2)) goto LAB_0042c708;
LAB_0042c6d1:
        FUN_0042d8ad(puVar3,uVar4);
        goto LAB_0042c708;
      }
    }
    *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) & 0xeb;
  }
LAB_0042c6fa:
  DVar1 = FUN_0042f424();
  if (DVar1 == 0xffffffff) {
LAB_0042c708:
    (*(code *)PTR_FUN_0043e7f4)();
    return 0xffffffff;
  }
LAB_0042c785:
  (*(code *)PTR_FUN_0043e7f4)();
  return 0;
}


