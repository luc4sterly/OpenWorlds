// 0042fe62 FUN_0042fe62 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_0042fe62(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  int extraout_ECX_04;
  uint extraout_EDX;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  longlong lVar12;
  
  uVar11 = 0;
  if (*PTR_DAT_0043e95a == '\0') goto LAB_00430116;
  uVar2 = FUN_0042fe2e(in_EAX,0x43e8e8);
  if (uVar2 == 0) {
    piVar10 = (int *)&DAT_0043e8c4;
    piVar9 = &DAT_0043e8e8;
  }
  else {
    piVar10 = &DAT_0043e8e8;
    piVar9 = (int *)&DAT_0043e8c4;
  }
  iVar6 = *(int *)(extraout_ECX + 0x10);
  lVar12 = FUN_0042fd0e(extraout_ECX,extraout_EDX);
  iVar7 = iVar6 * 2;
  if ((int)lVar12 == 0) {
    iVar5 = *(int *)(&DAT_00437ce4 + iVar7);
    iVar7 = *(int *)(&DAT_00437ce2 + iVar7);
  }
  else {
    iVar5 = *(int *)(&DAT_00437cfe + iVar7);
    iVar7 = *(int *)(&DAT_00437cfc + iVar7);
  }
  iVar7 = (iVar5 >> 0x10) - (iVar7 >> 0x10);
  bVar1 = false;
  in_EAX = extraout_ECX_00;
  if (piVar10[8] == 0) {
    if (piVar10[4] < iVar6) {
      uVar11 = 1;
    }
    else if (iVar6 == piVar10[4]) {
      iVar5 = *(int *)(extraout_ECX_00 + 0xc) -
              ((*(int *)(extraout_ECX_00 + 0x18) + 7) - piVar10[6]) % 7;
      iVar3 = (*(int *)(extraout_ECX_00 + 0xc) + -1) -
              ((*(int *)(extraout_ECX_00 + 0x18) + 6) - piVar10[6]) % 7;
      if (piVar10[3] == 5) {
        iVar4 = iVar7 + -7;
        if ((iVar4 < iVar5) && (uVar11 = 1, iVar3 <= iVar4)) {
LAB_0042ffe7:
          uVar11 = 1;
          bVar1 = true;
        }
      }
      else {
        iVar4 = (piVar10[3] + -1) * 7 + 1;
        if ((iVar4 <= iVar5) && (uVar11 = 1, iVar3 < iVar4)) goto LAB_0042ffe7;
      }
    }
  }
  else {
    uVar8 = piVar10[7];
    if (piVar10[8] == 1) {
      lVar12 = FUN_0042fd0e(extraout_ECX_00,uVar8);
      iVar5 = (int)((ulonglong)lVar12 >> 0x20);
      if (((int)lVar12 != 0) && (DAT_00437ce6 >> 0x10 < iVar5)) {
        iVar5 = iVar5 + 1;
      }
      uVar8 = iVar5 - 1;
      in_EAX = extraout_ECX_01;
    }
    if (((int)uVar8 <= (int)*(uint *)(in_EAX + 0x1c)) &&
       (uVar11 = 1, uVar8 == *(uint *)(in_EAX + 0x1c))) goto LAB_0042ffe7;
  }
  if (bVar1) {
    iVar5 = FUN_00430125(in_EAX,piVar10);
    uVar11 = (uint)(iVar5 == 0);
    in_EAX = extraout_ECX_02;
  }
  if (uVar11 == 0) {
    if (uVar2 != 0) {
      uVar11 = uVar2;
    }
    goto LAB_00430116;
  }
  bVar1 = false;
  if (piVar9[8] == 0) {
    if (piVar9[4] < iVar6) {
      uVar11 = 0;
    }
    else if (iVar6 == piVar9[4]) {
      iVar6 = *(int *)(in_EAX + 0xc) - ((*(int *)(in_EAX + 0x18) + 7) - piVar9[6]) % 7;
      uVar11 = 0;
      iVar5 = (*(int *)(in_EAX + 0xc) + -1) - ((*(int *)(in_EAX + 0x18) + 6) - piVar9[6]) % 7;
      if (piVar9[3] == 5) {
        iVar7 = iVar7 + -7;
        if (iVar7 < iVar6) {
          if (iVar5 <= iVar7) {
LAB_004300f6:
            uVar11 = 0;
            bVar1 = true;
          }
        }
        else {
LAB_00430093:
          uVar11 = 1;
        }
      }
      else {
        iVar7 = (piVar9[3] + -1) * 7 + 1;
        if (iVar6 < iVar7) goto LAB_00430093;
        if (iVar5 < iVar7) goto LAB_004300f6;
      }
    }
  }
  else {
    uVar8 = piVar9[7];
    if (piVar9[8] == 1) {
      lVar12 = FUN_0042fd0e(in_EAX,uVar8);
      iVar6 = (int)((ulonglong)lVar12 >> 0x20);
      if (((int)lVar12 != 0) && (DAT_00437ce6 >> 0x10 < iVar6)) {
        iVar6 = iVar6 + 1;
      }
      uVar8 = iVar6 - 1;
      in_EAX = extraout_ECX_03;
    }
    if (((int)uVar8 <= (int)*(uint *)(in_EAX + 0x1c)) &&
       (uVar11 = 0, uVar8 == *(uint *)(in_EAX + 0x1c))) goto LAB_004300f6;
  }
  if (bVar1) {
    uVar11 = FUN_00430125(in_EAX,piVar9);
    in_EAX = extraout_ECX_04;
  }
  if (uVar2 != 0) {
    uVar11 = uVar2 - uVar11;
  }
LAB_00430116:
  *(uint *)(in_EAX + 0x20) = uVar11;
  return CONCAT44(param_2,uVar11);
}


