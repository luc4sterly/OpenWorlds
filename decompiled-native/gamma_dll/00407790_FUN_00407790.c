// 00407790 FUN_00407790 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00407790(void *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  float10 fVar2;
  bool bVar3;
  char cVar4;
  LPVOID pvVar5;
  int *piVar6;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  double local_70;
  int local_60 [2];
  int local_58 [2];
  double local_50;
  undefined1 local_45;
  undefined1 local_29;
  
  iVar1 = *(int *)((int)param_1 + 0x28);
  iVar10 = iVar1;
  if (iVar1 == 0) {
    iVar10 = 1;
  }
  *(int *)((int)param_1 + 0x28) = iVar10;
  if ((byte)((byte)((ushort)((ushort)(NAN(_DAT_0046d920) || NAN((double)CONCAT44(param_3,param_2)))
                            << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_0046d920 == (double)CONCAT44(param_3,param_2)) << 0xe) >>
                  8)) == 0x40) {
    *(int *)((int)param_1 + 0x28) = *(int *)((int)param_1 + 0x28) + -1;
  }
  else {
    if ((float10)(double)CONCAT44(param_3,param_2) < (float10)_DAT_0046d920) {
      pvVar5 = FUN_00453ed0();
      *(undefined4 *)((int)pvVar5 + 4) = 0x21;
      local_70 = (double)_DAT_004823b0;
    }
    else {
      fVar2 = (float10)log2((float10)(double)CONCAT44(param_3,param_2));
      local_70 = (double)((float10)0.3010299956639812 * (float10)1 * fVar2);
    }
    local_50 = ROUND(local_70);
    iVar10 = (int)ROUND(local_50);
    if (((byte)((double)CONCAT44(param_3,param_2) < _DAT_0046d938 |
               (byte)((ushort)((ushort)(NAN((double)CONCAT44(param_3,param_2)) || NAN(_DAT_0046d938)
                                       ) << 10) >> 8)) == 1) &&
       ((byte)((byte)((ushort)((ushort)(NAN(_DAT_0046d920) || NAN(local_70 - local_50)) << 10) >> 8)
              | (byte)((ushort)((ushort)(_DAT_0046d920 == local_70 - local_50) << 0xe) >> 8)) !=
        0x40)) {
      iVar10 = iVar10 + -1;
    }
    if ((iVar10 < -4) || (*(int *)((int)param_1 + 0x28) <= iVar10)) {
      *(int *)((int)param_1 + 0x28) = *(int *)((int)param_1 + 0x28) + -1;
      FUN_00407a70(param_1,param_2,param_3,param_4);
      bVar3 = false;
      goto LAB_004078e1;
    }
    *(int *)((int)param_1 + 0x28) = (*(int *)((int)param_1 + 0x28) - iVar10) + -1;
  }
  FUN_00407fe0(param_1,param_2,param_3,param_4);
  bVar3 = true;
LAB_004078e1:
  if ((*(ushort *)((int)param_1 + 0x30) & 0x400) == 0) {
    FUN_004049b0(param_1,local_60);
    local_45 = DAT_004890b4;
    piVar6 = (int *)FUN_00404a00(local_60);
    FUN_00404dc0(local_60);
    FUN_004049b0(param_1,local_58);
    local_29 = DAT_004890b6;
    piVar7 = (int *)FUN_00406190(local_58);
    FUN_00404dc0(local_58);
    if (bVar3) {
      uVar11 = 0;
      cVar4 = FUN_004088d0(piVar7);
      uVar11 = FUN_00408ef0(param_4,cVar4,uVar11);
      pcVar8 = (char *)FUN_004089f0(param_4);
    }
    else {
      if ((*(ushort *)((int)param_1 + 0x30) & 0x4000) == 0) {
        cVar4 = (**(code **)(*piVar6 + 0x14))(0x65);
      }
      else {
        cVar4 = (**(code **)(*piVar6 + 0x14))(0x45);
      }
      iVar10 = FUN_00408b30(param_4,cVar4,0xffffffff);
      iVar9 = FUN_004088e0(param_4);
      pcVar8 = (char *)(iVar9 + iVar10);
      uVar11 = 0;
      cVar4 = FUN_004088d0(piVar7);
      uVar11 = FUN_00408ef0(param_4,cVar4,uVar11);
    }
    if (uVar11 < *(uint *)*param_4) {
      while( true ) {
        pcVar8 = pcVar8 + -1;
        cVar4 = (**(code **)(*piVar6 + 0x14))(0x30);
        if (*pcVar8 != cVar4) break;
        iVar10 = FUN_004088e0(param_4);
        FUN_00408f50(param_4,(int)pcVar8 - iVar10,1,0,0);
        FUN_004088e0(param_4);
      }
      cVar4 = FUN_004088d0(piVar7);
      if (*pcVar8 == cVar4) {
        iVar10 = FUN_004088e0(param_4);
        FUN_00408f50(param_4,(int)pcVar8 - iVar10,1,0,0);
        FUN_004088e0(param_4);
      }
    }
  }
  *(int *)((int)param_1 + 0x28) = iVar1;
  return;
}


