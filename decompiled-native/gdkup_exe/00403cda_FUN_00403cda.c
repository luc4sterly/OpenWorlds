// 00403cda FUN_00403cda [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00403cda(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar1;
  undefined4 *extraout_EDX;
  int extraout_EDX_00;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  (*(code *)PTR_FUN_00408b3c)();
  if ((*(byte *)(extraout_EDX + 3) & 1) == 0) {
    FUN_00403848(extraout_ECX,extraout_EDX);
    *(byte *)(extraout_EDX_00 + 0xc) = *(byte *)(extraout_EDX_00 + 0xc) | 0x20;
    uVar5 = CONCAT44(extraout_EDX_00,0xffffffff);
    uVar1 = extraout_ECX_00;
  }
  else {
    iVar4 = extraout_EDX[1];
    extraout_EDX[1] = iVar4 + -1;
    if (iVar4 + -1 < 0) {
      uVar5 = FUN_00403d78(extraout_ECX,extraout_EDX);
      uVar1 = extraout_ECX_01;
    }
    else {
      uVar5 = CONCAT44(extraout_EDX,(uint)*(byte *)*extraout_EDX);
      *extraout_EDX = (byte *)*extraout_EDX + 1;
      uVar1 = extraout_ECX;
    }
  }
  puVar2 = (undefined4 *)((ulonglong)uVar5 >> 0x20);
  iVar4 = (int)uVar5;
  if ((*(byte *)(puVar2 + 3) & 0x40) == 0) {
    if (iVar4 == 0xd) {
      iVar4 = puVar2[1];
      puVar2[1] = iVar4 + -1;
      if (iVar4 + -1 < 0) {
        uVar5 = FUN_00403d78(uVar1,puVar2);
      }
      else {
        uVar5 = CONCAT44(puVar2,(uint)*(byte *)*puVar2);
        *puVar2 = (byte *)*puVar2 + 1;
      }
    }
    iVar3 = (int)((ulonglong)uVar5 >> 0x20);
    iVar4 = (int)uVar5;
    if (iVar4 == 0x1a) {
      iVar4 = -1;
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) | 0x10;
    }
  }
  (*(code *)PTR_FUN_00408b40)();
  return CONCAT44(param_2,iVar4);
}


