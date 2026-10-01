// 00409c1a FUN_00409c1a [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00409c1a(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int in_EAX;
  int extraout_EAX;
  int extraout_ECX;
  int iVar4;
  int unaff_EBX;
  short sVar5;
  float10 fVar6;
  
  if ((*(int *)(param_2 + 0x14) == 1) && (*(int *)(param_2 + 8) == 1)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if ((!bVar3) || (bVar3 = true, *(int *)(param_2 + 0x18) != 1)) {
    bVar3 = false;
  }
  if ((bVar3) && (*(int *)(param_2 + 0xc) == 1)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if ((!bVar3) || (sVar5 = 1, *(int *)(param_2 + 0x1c) != 1)) {
    sVar5 = 0;
  }
  if ((*(int *)(param_2 + 0xc) == 1) || (*(int *)(param_2 + 0x1c) == 1)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if ((sVar5 != 0) || ((bVar3 && (unaff_EBX == 0)))) {
    FUN_0042b8ce();
    fVar6 = FUN_0042b8ce();
    iVar4 = (int)ROUND(fVar6) * in_EAX + extraout_EAX;
    *(int *)(param_3 + 8) = iVar4;
    iVar4 = iVar4 + 0x9b;
    *(int *)(param_3 + 0x14) = iVar4;
    if ((1 < unaff_EBX) && (*(int *)(extraout_ECX + 0x14) < iVar4)) {
      *(int *)(param_3 + 8) = *(int *)(param_3 + 8) - in_EAX;
      *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) - in_EAX;
    }
    if (((unaff_EBX == 1) || (unaff_EBX == 3)) &&
       (*(int *)(param_3 + 8) < *(int *)(extraout_ECX + 8))) {
      *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + in_EAX;
      *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) + in_EAX;
    }
    while (0x21c < *(int *)(param_3 + 0x14)) {
      *(int *)(param_3 + 8) = *(int *)(param_3 + 8) - in_EAX;
      *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) - in_EAX;
    }
    while (*(int *)(param_3 + 8) < 0xb5) {
      *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + in_EAX;
      *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) + in_EAX;
    }
    bVar2 = true;
    param_1 = extraout_ECX;
  }
  else {
    *(undefined4 *)(param_3 + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(param_1 + 0x14);
    bVar2 = false;
  }
  iVar4 = (((*(int *)(param_3 + 0x14) - *(int *)(param_3 + 8)) + 1) / in_EAX) * in_EAX;
  if ((iVar4 == 0) || (!bVar3)) {
    *(undefined4 *)(param_4 + 8) = *(undefined4 *)(param_1 + 8);
    iVar4 = *(int *)(param_1 + 0x14);
  }
  else if ((bVar2) || (unaff_EBX != 2)) {
    iVar1 = *(int *)(param_3 + 8);
    *(int *)(param_4 + 8) = iVar1;
    iVar4 = iVar4 + iVar1 + -1;
  }
  else {
    *(int *)(param_4 + 8) = (*(int *)(param_3 + 0x14) - iVar4) + 1;
    iVar4 = *(int *)(param_3 + 0x14);
  }
  *(int *)(param_4 + 0x14) = iVar4;
  _DAT_00440158 = sVar5;
  return;
}


