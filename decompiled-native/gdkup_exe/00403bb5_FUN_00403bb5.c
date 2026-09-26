// 00403bb5 FUN_00403bb5 [Global]
// programa: gdkup.exe

/* WARNING: Removing unreachable block (ram,0x00403c41) */

undefined4 __fastcall FUN_00403bb5(undefined4 param_1,int param_2)

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
  
  (*(code *)PTR_FUN_00408b3c)();
  if ((*(byte *)(extraout_ECX + 3) & 6) == 0) {
    if (unaff_EBX == 0) {
      FUN_004056c3(extraout_ECX,extraout_EDX);
      iVar2 = FUN_00403b73(extraout_ECX_01,(int *)extraout_ECX_01);
    }
    else {
      if (1 < unaff_EBX) {
        puVar3 = extraout_ECX;
        uVar4 = extraout_EDX;
        if (unaff_EBX != 2) goto LAB_00403be6;
        *(byte *)(extraout_ECX + 3) = *(byte *)(extraout_ECX + 3) & 0xef;
        *extraout_ECX = extraout_ECX[2];
        extraout_ECX[1] = 0;
        goto LAB_00403c0f;
      }
      iVar2 = FUN_00403b73(extraout_ECX,extraout_ECX);
    }
    if (iVar2 == 0) goto LAB_00403c9a;
  }
  else {
    if ((*(byte *)((int)extraout_ECX + 0xd) & 0x10) == 0) {
      extraout_ECX[1] = 0;
      *extraout_ECX = extraout_ECX[2];
      puVar3 = extraout_ECX;
    }
    else {
      uVar5 = FUN_00403e5d(extraout_ECX,extraout_EDX);
      uVar4 = (undefined4)((ulonglong)uVar5 >> 0x20);
      puVar3 = extraout_ECX_00;
      if ((int)uVar5 != 0) {
        if ((unaff_EBX != 0) || (-1 < param_2)) goto LAB_00403c1d;
LAB_00403be6:
        FUN_00403848(puVar3,uVar4);
        goto LAB_00403c1d;
      }
    }
    *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) & 0xeb;
  }
LAB_00403c0f:
  DVar1 = FUN_00403f98();
  if (DVar1 == 0xffffffff) {
LAB_00403c1d:
    (*(code *)PTR_FUN_00408b40)();
    return 0xffffffff;
  }
LAB_00403c9a:
  (*(code *)PTR_FUN_00408b40)();
  return 0;
}


