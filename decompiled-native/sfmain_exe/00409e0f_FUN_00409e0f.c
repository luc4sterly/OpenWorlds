// 00409e0f FUN_00409e0f [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_00409e0f(undefined4 *param_1,int *param_2,int param_3,int param_4,int param_5,
            undefined4 *param_6,int *param_7,float *param_8)

{
  undefined4 uVar1;
  float fVar2;
  short sVar3;
  int in_EAX;
  int iVar4;
  undefined4 *puVar5;
  int extraout_EAX;
  int iVar6;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  undefined4 extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int iVar7;
  int extraout_EDX;
  undefined4 *puVar8;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  uint uVar9;
  undefined4 extraout_EDX_02;
  float *unaff_EBX;
  float10 fVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  longlong lVar11;
  int local_44;
  int local_3c;
  undefined4 local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  
  if ((int)*unaff_EBX < 0x3f800000) {
    *unaff_EBX = 1.0;
  }
  sVar3 = DAT_00438584;
  if ((int)DAT_00438580 < 0x3f800000) {
    DAT_00438580 = 1.0;
  }
  *param_8 = *unaff_EBX / (DAT_00438580 + (float)_DAT_00435824);
  iVar6 = DAT_00438578;
  if (sVar3 == 0) {
    local_28 = DAT_0044015c + 0xb4;
    local_44 = 0;
    *param_7 = 0;
    local_20 = 0;
    local_1c = 1;
    if ((*(int *)(in_EAX + 4) == iVar6) && (*(int *)(in_EAX + 8) == *(int *)(in_EAX + 4))) {
      if (*(int *)(in_EAX + 8) == 0) {
        *param_2 = 0x2d;
        DAT_0043857c = *param_2;
        if (0x41000000 < (int)*param_8) {
          DAT_00438580 = *unaff_EBX;
        }
      }
      local_2c = *(undefined4 *)(in_EAX + 8);
    }
    else if (DAT_00438578 == 1) {
      fVar10 = FUN_0042b8ce();
      local_28 = (int)ROUND(fVar10);
      iVar6 = 1;
      puVar5 = param_1;
      do {
        puVar5 = puVar5 + 1;
        (&DAT_0044015c)[iVar6] = *puVar5;
        iVar4 = iVar6 * 4;
        iVar6 = iVar6 + 1;
        *puVar5 = *(undefined4 *)(iVar4 + 0x440184);
      } while (iVar6 < 0xb);
      local_2c = 1;
      local_44 = 0x3f800000;
      param_7 = extraout_ECX_00;
    }
    else {
      fVar10 = FUN_0042b8ce();
      local_20 = (int)ROUND(fVar10);
      fVar10 = FUN_0042b8ce();
      *(int *)(extraout_EAX + 4) = (int)ROUND(fVar10);
      *(int *)(param_4 + 8) = extraout_EDX - *(int *)(extraout_EAX + 4);
      *(undefined4 *)(param_3 + 4) = 0;
      *(undefined4 *)(param_3 + 8) = 0;
      fVar2 = DAT_00438580;
      *(float *)(param_5 + 4) = DAT_00438580;
      *(float *)(param_5 + 8) = fVar2;
      puVar8 = param_6;
      iVar6 = 1;
      puVar5 = param_1;
      do {
        puVar5 = puVar5 + 1;
        iVar4 = iVar6 + 1;
        *puVar8 = *(undefined4 *)(iVar6 * 4 + 0x440184);
        puVar8[1] = *(undefined4 *)(iVar6 * 4 + 0x440184);
        puVar8 = puVar8 + 0xb;
        *(undefined4 *)(iVar4 * 4 + 0x440180) = *puVar5;
        iVar6 = iVar4;
      } while (iVar4 < 0xb);
      *extraout_ECX = 2;
      DAT_0043857c = *param_2;
      local_2c = 1;
      local_1c = local_20 + 1;
      param_7 = extraout_ECX;
    }
    while( true ) {
      for (; local_1c <= local_28; local_1c = local_1c + 1) {
        fVar10 = FUN_0042b8ce();
        param_7 = extraout_ECX_01;
        uVar9 = extraout_EDX_00;
        if ((extraout_EDX_00 & 0x7fffffff) != 0) {
          fVar10 = FUN_0042b8ce();
          param_7 = extraout_ECX_02;
          uVar9 = extraout_EDX_01;
        }
        local_18 = (int)ROUND(fVar10);
        if (local_18 <= local_1c - local_20) {
          iVar6 = *param_7;
          *param_7 = iVar6 + 1;
          if (0xb < iVar6 + 1) {
            FUN_0042bd7e(param_7,uVar9);
            param_7 = extraout_ECX_03;
          }
          fVar2 = (float)_DAT_0043584c;
          *(int *)(*param_7 * 4 + param_4) = local_18;
          *param_2 = local_18;
          *(undefined4 *)(*param_7 * 4 + param_3) = local_2c;
          local_20 = local_20 + local_18;
          iVar6 = 1;
          fVar10 = (float10)_DAT_00435854;
          puVar5 = param_6;
          do {
            FUN_0042bd0e();
            FUN_0042bd0e();
            FUN_0042b860(extraout_ECX_04,extraout_EDX_02);
            iVar6 = iVar6 + 1;
            puVar5[*extraout_ECX_05 + -1] =
                 (float)((extraout_ST0 + fVar10) / ((float10)1 + extraout_ST0));
            puVar5 = puVar5 + 0xb;
          } while (iVar6 < 0xb);
          FUN_0042bd0e();
          FUN_0042bd0e();
          *(float *)(*extraout_ECX_06 * 4 + param_5) =
               (float)((extraout_ST1 - extraout_ST0_00) *
                       (float10)(((float)local_20 - (float)local_18 * fVar2) / (float)local_28) +
                      extraout_ST0_00);
          lVar11 = FUN_0042b860(extraout_ECX_06,*extraout_ECX_06 * 4 + param_5);
          *(float *)((ulonglong)lVar11 >> 0x20) = (float)extraout_ST0_01;
          param_7 = extraout_ECX_07;
        }
      }
      if (local_44 != 0x3f800000) break;
      local_44 = 0;
      local_28 = DAT_0044015c + 0xb4;
      local_1c = local_20 + 1;
      local_2c = 0;
      DAT_00438580 = *unaff_EBX;
      iVar6 = 1;
      puVar5 = param_1;
      do {
        puVar5 = puVar5 + 1;
        iVar4 = iVar6 + 1;
        *puVar5 = (&DAT_0044015c)[iVar6];
        *(int *)(iVar4 * 4 + 0x440180) = (&DAT_0044015c)[iVar6];
        iVar6 = iVar4;
      } while (iVar4 < 0xb);
    }
    DAT_0044015c = local_28 - local_20;
  }
  else {
    iVar6 = *(int *)(in_EAX + 8);
    if (iVar6 == 0) {
      *param_2 = 0x2d;
    }
    iVar4 = (int)(0xb4 / (longlong)*param_2);
    *param_7 = iVar4;
    DAT_0044015c = 0xb4 - iVar4 * *param_2;
    iVar4 = 4;
    for (local_3c = 1; local_3c <= *param_7; local_3c = local_3c + 1) {
      puVar5 = param_1 + 1;
      iVar7 = (int)param_6 + iVar4;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *(undefined4 *)(iVar7 + -4) = uVar1;
        iVar7 = iVar7 + 0x2c;
      } while (puVar5 != param_1 + 0xb);
      *(int *)(param_3 + iVar4) = iVar6;
      *(int *)(param_4 + iVar4) = *param_2;
      *(float *)(param_5 + iVar4) = *unaff_EBX;
      iVar4 = iVar4 + 4;
    }
    DAT_00438584 = 0;
  }
  if (*param_7 != 0) {
    DAT_00438580 = *unaff_EBX;
    DAT_00438578 = *(int *)(in_EAX + 8);
    DAT_0043857c = *param_2;
    iVar6 = 1;
    do {
      param_1 = param_1 + 1;
      iVar6 = iVar6 + 1;
      *(undefined4 *)(iVar6 * 4 + 0x440180) = *param_1;
    } while (iVar6 < 0xb);
  }
  return;
}


