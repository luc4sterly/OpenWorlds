// 10032b50 FUN_10032b50 [Global]
// programa: RWL21.DLL

void FUN_10032b50(undefined *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int extraout_ECX;
  int extraout_ECX_00;
  void *extraout_ECX_01;
  void *this;
  int extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined4 uVar4;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int *piVar5;
  int iVar6;
  int *piVar7;
  undefined8 uVar8;
  
  iVar2 = FUN_10041c30();
  if (iVar2 == 0) {
    if ((*(uint *)(param_2 + 0x188) & 4) == 0) {
      uVar3 = (*(uint *)(param_2 + 0x188) & 2) >> 1;
    }
    else {
      uVar3 = 2;
    }
  }
  else {
    uVar3 = 2;
  }
  if (uVar3 == 0) {
    piVar1 = *(int **)(param_2 + 0x98);
    piVar5 = (int *)piVar1[2];
    piVar7 = piVar1 + 2;
    iVar6 = *piVar1 + -1;
    iVar2 = extraout_ECX;
    uVar4 = extraout_EDX;
    if (-1 < iVar6) {
      do {
        piVar7 = piVar7 + 1;
        uVar8 = FUN_10051000(iVar2,uVar4,(int)piVar5);
        uVar3 = -(uint)((int)uVar8 == 0) & 0x10000;
        if (uVar3 == 0) {
LAB_10032bd3:
          (*(code *)param_1)(piVar5,uVar3);
          iVar2 = extraout_ECX_00;
          uVar4 = extraout_EDX_00;
        }
        else {
          iVar2 = *piVar5;
          uVar4 = CONCAT31((int3)((ulonglong)uVar8 >> 0x28),*(byte *)(iVar2 + 0x30));
          if ((*(byte *)(iVar2 + 0x30) & 0x80) != 0) goto LAB_10032bd3;
        }
        piVar5 = (int *)*piVar7;
        iVar6 = iVar6 + -1;
        if (iVar6 < 0) {
          return;
        }
      } while( true );
    }
  }
  else {
    if (uVar3 == 1) {
      if ((*(int *)(param_2 + 0xa4) != 0) ||
         (this = (void *)0x0, *(int *)(*(int *)(param_2 + 0xa8) + 4) != 0)) {
        (**(code **)(PTR_DAT_1005b69c + 0x40))(param_3);
        this = extraout_ECX_01;
      }
      FUN_10033e70(this,param_1,param_2);
      return;
    }
    if (uVar3 != 2) {
      return;
    }
    piVar1 = *(int **)(param_2 + 0x98);
    piVar5 = (int *)piVar1[2];
    piVar7 = piVar1 + 2;
    iVar2 = *piVar1;
    iVar6 = extraout_ECX;
    uVar4 = extraout_EDX;
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      piVar7 = piVar7 + 1;
      uVar8 = FUN_10051000(iVar6,uVar4,(int)piVar5);
      uVar3 = -(uint)((int)uVar8 == 0) & 0x10000;
      if (uVar3 == 0) {
LAB_10032c51:
        (*(code *)param_1)(piVar5,uVar3);
        iVar6 = extraout_ECX_02;
        uVar4 = extraout_EDX_01;
      }
      else {
        iVar6 = *piVar5;
        uVar4 = CONCAT31((int3)((ulonglong)uVar8 >> 0x28),*(byte *)(iVar6 + 0x30));
        if ((*(byte *)(iVar6 + 0x30) & 0x80) != 0) goto LAB_10032c51;
      }
      piVar5 = (int *)*piVar7;
    }
  }
  return;
}


