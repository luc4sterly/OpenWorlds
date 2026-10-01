// 0042be63 FUN_0042be63 [Global]
// program: sfmain.exe

uint __fastcall FUN_0042be63(int *param_1,uint param_2)

{
  char cVar1;
  char *in_EAX;
  DWORD DVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  uint uVar3;
  int iVar4;
  int extraout_ECX_02;
  int extraout_EDX;
  uint uVar5;
  int unaff_EBX;
  char *pcVar6;
  char *pcVar7;
  undefined8 uVar8;
  char *pcStack_18;
  uint uStack_14;
  uint uStack_10;
  
  (*(code *)PTR_FUN_0043e7f0)();
  if ((*(byte *)(extraout_ECX + 0xc) & 1) == 0) {
    FUN_0042d8ad(extraout_ECX,extraout_EDX);
    *(byte *)(extraout_ECX_00 + 0xc) = *(byte *)(extraout_ECX_00 + 0xc) | 0x20;
    (*(code *)PTR_FUN_0043e7f4)();
    return 0;
  }
  uStack_10 = unaff_EBX * extraout_EDX;
  if (uStack_10 == 0) {
    (*(code *)PTR_FUN_0043e7f4)();
    return 0;
  }
  iVar4 = extraout_ECX;
  if (*(int *)(extraout_ECX + 8) == 0) {
    FUN_0042d8e0(extraout_ECX);
    iVar4 = extraout_ECX_01;
  }
  uStack_14 = 0;
  pcStack_18 = in_EAX;
  if ((*(byte *)(param_1 + 3) & 0x40) == 0) {
    pcVar6 = in_EAX + uStack_10;
    do {
      if (param_1[1] == 0) {
        uVar8 = FUN_0042e2dd(iVar4,in_EAX);
        in_EAX = (char *)((ulonglong)uVar8 >> 0x20);
        if ((int)uVar8 == 0) break;
      }
      pcVar7 = (char *)*param_1;
      iVar4 = param_1[1] + -1;
      param_1[1] = iVar4;
      *param_1 = (int)(pcVar7 + 1);
      cVar1 = *pcVar7;
      if (cVar1 == '\r') {
        if (param_1[1] == 0) {
          uVar8 = FUN_0042e2dd(iVar4,in_EAX);
          in_EAX = (char *)((ulonglong)uVar8 >> 0x20);
          iVar4 = extraout_ECX_02;
          if ((int)uVar8 == 0) break;
        }
        pcVar7 = (char *)*param_1;
        param_1[1] = param_1[1] + -1;
        *param_1 = (int)(pcVar7 + 1);
        cVar1 = *pcVar7;
      }
      if (cVar1 == '\x1a') goto LAB_0042bf93;
      *in_EAX = cVar1;
      uStack_14 = uStack_14 + 1;
      in_EAX = in_EAX + 1;
    } while (in_EAX != pcVar6);
  }
  else {
    do {
      while( true ) {
        uVar5 = param_1[1];
        if (uVar5 != 0) {
          if (uStack_10 < uVar5) {
            uVar5 = uStack_10;
          }
          pcVar6 = (char *)*param_1;
          pcVar7 = pcStack_18;
          for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
            pcVar6 = pcVar6 + 4;
            pcVar7 = pcVar7 + 4;
          }
          for (uVar3 = uVar5 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *pcVar7 = *pcVar6;
            pcVar6 = pcVar6 + 1;
            pcVar7 = pcVar7 + 1;
          }
          pcStack_18 = pcStack_18 + uVar5;
          uStack_14 = uStack_14 + uVar5;
          uStack_10 = uStack_10 - uVar5;
          *param_1 = *param_1 + uVar5;
          param_1[1] = param_1[1] - uVar5;
        }
        if (uStack_10 == 0) goto LAB_0042c047;
        if ((uStack_10 < (uint)param_1[5]) && ((*(byte *)((int)param_1 + 0xd) & 4) == 0)) break;
        param_1[1] = 0;
        *param_1 = param_1[2];
        DVar2 = FUN_0042e19c();
        if (DVar2 == 0xffffffff) {
          *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x20;
          goto LAB_0042c047;
        }
        if (DVar2 == 0) goto LAB_0042bf93;
        pcStack_18 = pcStack_18 + DVar2;
        uStack_10 = uStack_10 - DVar2;
        uStack_14 = uStack_14 + DVar2;
      }
      uVar8 = FUN_0042e2dd(uStack_10,uVar5);
    } while ((int)uVar8 != 0);
  }
LAB_0042c047:
  (*(code *)PTR_FUN_0043e7f4)();
  return uStack_14 / param_2;
LAB_0042bf93:
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x10;
  goto LAB_0042c047;
}


