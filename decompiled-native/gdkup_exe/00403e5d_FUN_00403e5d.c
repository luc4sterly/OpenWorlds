// 00403e5d FUN_00403e5d [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00403e5d(undefined4 param_1,undefined4 param_2)

{
  DWORD DVar1;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  undefined4 *puVar2;
  undefined4 *extraout_ECX_02;
  DWORD extraout_EDX;
  int iVar3;
  int iVar4;
  LPCVOID pvVar5;
  
  (*(code *)PTR_FUN_00408b3c)();
  iVar3 = 0;
  puVar2 = extraout_ECX;
  if ((*(byte *)((int)extraout_ECX + 0xd) & 0x10) == 0) {
    if ((extraout_ECX[2] != 0) &&
       (*(byte *)(extraout_ECX + 3) = *(byte *)(extraout_ECX + 3) & 0xef,
       (*(byte *)((int)extraout_ECX + 0xd) & 0x20) == 0)) {
      DVar1 = 0;
      if (extraout_ECX[1] != 0) {
        DVar1 = FUN_00403f98();
        puVar2 = extraout_ECX_02;
      }
      if (DVar1 == 0xffffffff) {
        *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) | 0x20;
        iVar3 = -1;
      }
    }
  }
  else {
    *(byte *)((int)extraout_ECX + 0xd) = *(byte *)((int)extraout_ECX + 0xd) & 0xef;
    if (((*(byte *)(extraout_ECX + 3) & 2) != 0) &&
       (pvVar5 = (LPCVOID)extraout_ECX[2], pvVar5 != (LPCVOID)0x0)) {
      iVar4 = extraout_ECX[1];
      while ((iVar4 != 0 && (iVar3 == 0))) {
        DVar1 = FUN_0040592d(puVar2,pvVar5);
        puVar2 = extraout_ECX_00;
        if (DVar1 == 0xffffffff) {
          *(byte *)(extraout_ECX_00 + 3) = *(byte *)(extraout_ECX_00 + 3) | 0x20;
          iVar3 = -1;
        }
        else if (DVar1 == 0) {
          FUN_00403848(extraout_ECX_00,0);
          iVar3 = -1;
          *(byte *)(extraout_ECX_01 + 3) = *(byte *)(extraout_ECX_01 + 3) | 0x20;
          puVar2 = extraout_ECX_01;
          DVar1 = extraout_EDX;
        }
        pvVar5 = (LPCVOID)((int)pvVar5 + DVar1);
        iVar4 = iVar4 - DVar1;
      }
    }
  }
  *puVar2 = puVar2[2];
  puVar2[1] = 0;
  (*(code *)PTR_FUN_00408b40)();
  return CONCAT44(param_2,iVar3);
}


