// 10029210 FUN_10029210 [Global]
// program: RWL21.DLL

int FUN_10029210(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 uVar9;
  int local_c;
  
  bVar1 = *(byte *)((int)param_1 + 0x3a);
  iVar5 = param_1[0xf];
  uVar3 = *(undefined4 *)(iVar5 + 0xc);
  uVar4 = *(undefined4 *)(iVar5 + 0x14);
  bVar2 = *(byte *)(iVar5 + 0x48);
  if ((bVar2 & 0x3f) != 0) {
    uVar7 = CONCAT44(uVar4,(uint)bVar2) & 0xffffffff00000003;
    if ((bVar2 & 3) == 1) {
      *(undefined4 *)(iVar5 + 0x18) = 0;
    }
    else {
      uVar7 = __ftol();
      *(int *)(iVar5 + 0x18) = (int)uVar7;
      uVar3 = extraout_ECX;
    }
    if ((bVar2 & 0xf) == 4) {
      *(undefined4 *)(iVar5 + 0x1c) = 0;
    }
    else {
      uVar7 = __ftol();
      *(int *)(iVar5 + 0x1c) = (int)uVar7;
      uVar3 = extraout_ECX_00;
    }
    uVar4 = (undefined4)(uVar7 >> 0x20);
    if ((bVar2 & 0x3f) == 0x10) {
      *(undefined4 *)(iVar5 + 0x20) = 0x7fffff00;
    }
    else if ((bVar2 & 0x3f) == 0x20) {
      *(undefined4 *)(iVar5 + 0x20) = 0x1000000;
    }
    else {
      lVar8 = __ftol();
      uVar4 = (undefined4)((ulonglong)lVar8 >> 0x20);
      *(int *)(iVar5 + 0x20) = (int)lVar8 + 0x1000000;
      uVar3 = extraout_ECX_01;
    }
  }
  if (1 < bVar1) {
    piVar6 = param_1 + 0x10;
    local_c = bVar1 - 1;
    do {
      iVar5 = *piVar6;
      uVar3 = *(undefined4 *)(iVar5 + 0x10);
      bVar1 = *(byte *)(iVar5 + 0x48);
      uVar7 = (ulonglong)*(uint *)(iVar5 + 0x14) << 0x20;
      if ((bVar1 & 0x3f) != 0) {
        uVar7 = CONCAT44(*(uint *)(iVar5 + 0x14),(uint)bVar1) & 0xffffffff00000003;
        if ((bVar1 & 3) == 1) {
          *(undefined4 *)(iVar5 + 0x18) = 0;
        }
        else {
          uVar7 = __ftol();
          *(int *)(iVar5 + 0x18) = (int)uVar7;
          uVar3 = extraout_ECX_02;
        }
        if ((bVar1 & 0xf) == 4) {
          *(undefined4 *)(iVar5 + 0x1c) = 0;
        }
        else {
          uVar7 = __ftol();
          *(int *)(iVar5 + 0x1c) = (int)uVar7;
          uVar3 = extraout_ECX_03;
        }
      }
      uVar4 = (undefined4)(uVar7 >> 0x20);
      if ((bVar1 & 0x3f) != 0) {
        if ((bVar1 & 0x3f) == 0x10) {
          *(undefined4 *)(iVar5 + 0x20) = 0x7fffff00;
        }
        else if ((bVar1 & 0x3f) == 0x20) {
          *(undefined4 *)(iVar5 + 0x20) = 0x1000000;
        }
        else {
          lVar8 = __ftol();
          uVar4 = (undefined4)((ulonglong)lVar8 >> 0x20);
          *(int *)(iVar5 + 0x20) = (int)lVar8 + 0x1000000;
          uVar3 = extraout_ECX_04;
        }
      }
      piVar6 = piVar6 + 1;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  if (2 < *(byte *)((int)param_1 + 0x3a)) {
    iVar5 = 0x10000;
    uVar9 = FUN_10051000(uVar3,uVar4,(int)param_1);
    if ((int)uVar9 == 0) goto LAB_1002944b;
  }
  iVar5 = 0;
LAB_1002944b:
  if ((iVar5 == 0) || ((*(byte *)(*param_1 + 0x30) & 0x80) != 0)) {
    (*DAT_1005ad20)(param_1,iVar5);
  }
  return iVar5;
}


