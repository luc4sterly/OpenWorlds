// 00401c27 FUN_00401c27 [Global]
// program: sfmain.exe

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00401c27(undefined4 param_1,ushort *param_2)

{
  ushort *puVar1;
  double dVar2;
  undefined4 uVar3;
  undefined1 *in_EAX;
  undefined4 extraout_EAX;
  int extraout_ECX;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  double *pdVar7;
  double *unaff_EBX;
  float10 extraout_ST0;
  float10 fVar8;
  undefined8 uVar9;
  uint auStack_180 [2];
  double adStack_178 [10];
  undefined8 uStack_128;
  undefined8 uStack_120;
  double dStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_78;
  undefined8 uStack_70;
  double dStack_68;
  undefined8 uStack_60;
  double dStack_58;
  double dStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined8 uStack_40;
  undefined8 uStack_38;
  double dStack_30;
  double dStack_28;
  double *pdStack_20;
  uint uStack_1c;
  uint uStack_18;
  
  auStack_180[0] = (uint)*param_2;
  uStack_1c = Ordinal_15();
  uStack_1c = uStack_1c & 0xffff;
  dVar2 = (double)uStack_1c * _DAT_00435098;
  uStack_40 = (double)(byte)param_2[1] * _DAT_00435098;
  auStack_180[0] = 0;
  auStack_180[1] = 0;
  iVar6 = 0;
  do {
    puVar1 = param_2 + 2;
    uStack_18 = (uint)(ushort)(short)(char)*puVar1;
    iVar4 = iVar6 + 8;
    param_2 = (ushort *)((int)param_2 + 1);
    *(double *)((int)adStack_178 + iVar6) = (double)(short)(char)*puVar1 * _DAT_004350a0;
    iVar6 = iVar4;
  } while (iVar4 != 0x50);
  uStack_70._4_4_ = (undefined4)((ulonglong)dVar2 >> 0x20);
  uVar3 = uStack_70._4_4_;
  uStack_70._0_4_ = SUB84(dVar2,0);
  if ((((ulonglong)dVar2 & 0x7fffffff00000000) == 0) && ((int)uStack_70 == 0)) {
    uVar5 = 0x40080000;
    dStack_50 = 3.0;
  }
  else {
    uVar5 = 0x50;
    dStack_50 = dVar2;
  }
  uStack_70 = dVar2;
  FUN_0042b7a8(uVar3,uVar5);
  dStack_30 = *unaff_EBX;
  uStack_38 = unaff_EBX[1];
  iVar6 = 1;
  uStack_40 = (double)((float10)uStack_40 / extraout_ST0);
  pdVar7 = unaff_EBX;
  do {
    iVar6 = iVar6 + 1;
    (&dStack_d8)[iVar6] = pdVar7[3];
    pdVar7 = pdVar7 + 1;
  } while (iVar6 < 0xb);
  if (((((ulonglong)*unaff_EBX & 0x7fffffff00000000) == 0) && (*(int *)unaff_EBX == 0)) ||
     ((((ulonglong)uStack_70 & 0x7fffffff00000000) == 0 && ((int)uStack_70 == 0)))) {
    dStack_28 = 0.0;
    dStack_58 = 0.0;
    iVar6 = 8;
    do {
      iVar4 = iVar6 + 8;
      *(undefined4 *)((int)&uStack_128 + iVar6) = 0;
      *(undefined4 *)((int)&uStack_128 + iVar6 + 4) = 0;
      iVar6 = iVar4;
    } while (iVar4 != 0x58);
  }
  else {
    dStack_28 = (uStack_70 - *unaff_EBX) / _DAT_004350b0;
    dStack_58 = (uStack_40 - unaff_EBX[1]) / _DAT_004350b0;
    iVar6 = 1;
    pdVar7 = unaff_EBX;
    do {
      iVar4 = iVar6 + 1;
      adStack_178[iVar6 + 10] = (*(double *)(auStack_180 + iVar6 * 2) - pdVar7[3]) / _DAT_004350b0;
      iVar6 = iVar4;
      pdVar7 = pdVar7 + 1;
    } while (iVar4 < 0xb);
  }
  if ((((ulonglong)dStack_30 & 0x7fffffff00000000) == 0) && (dStack_30._0_4_ == 0)) {
    *(undefined4 *)(unaff_EBX + 0x18) = 0;
  }
  pdStack_20 = unaff_EBX + 10;
  iVar6 = 0;
  do {
    if ((((ulonglong)dStack_30 & 0x7fffffff00000000) == 0) && (dStack_30._0_4_ == 0)) {
      uVar9 = FUN_0042b942(iVar6,0);
      uStack_1c = (uint)uVar9;
      uStack_60 = (double)(int)uStack_1c * _DAT_004350b8 * uStack_38;
    }
    else if (*(int *)(unaff_EBX + 0x18) == 0) {
      fVar8 = FUN_0042b8ce();
      *(int *)(unaff_EBX + 0x18) = (int)ROUND(fVar8);
      uStack_60 = (double)CONCAT44(uStack_38._4_4_,extraout_EAX);
    }
    else {
      uStack_60 = 0.0;
      *(int *)(unaff_EBX + 0x18) = *(int *)(unaff_EBX + 0x18) + -1;
    }
    iVar6 = 10;
    uStack_78 = uStack_60;
    pdVar7 = pdStack_20;
    do {
      dStack_68 = pdVar7[0xc];
      uStack_48 = *(undefined4 *)((int)&uStack_d0 + iVar6 * 8);
      uStack_44 = *(undefined4 *)((int)&uStack_d0 + iVar6 * 8 + 4U);
      *(double *)((int)&uStack_d0 + iVar6 * 8) =
           (double)CONCAT44(uStack_44,uStack_48) + (double)(&uStack_128)[iVar6];
      uStack_78 = uStack_78 - dStack_68 * (double)CONCAT44(uStack_44,uStack_48);
      dStack_68 = uStack_78 * (double)CONCAT44(uStack_44,uStack_48) + dStack_68;
      iVar6 = iVar6 + -1;
      pdVar7[0xd] = dStack_68;
      pdVar7 = pdVar7 + -1;
    } while (0 < iVar6);
    *(undefined4 *)(unaff_EBX + 0xd) = (undefined4)uStack_78;
    fVar8 = FUN_0042b8ce();
    uStack_1c = (uint)ROUND(fVar8);
    *(undefined4 *)((int)unaff_EBX + 0x6c) = uStack_78._4_4_;
    iVar6 = extraout_ECX + 1;
    dStack_30 = dStack_30 + dStack_28;
    *in_EAX = (&DAT_00427192)[(int)(uStack_1c & 0xffff) >> 3];
    uStack_38 = uStack_38 + dStack_58;
    in_EAX = in_EAX + 1;
  } while (iVar6 < 0xa0);
  *(int *)unaff_EBX = (int)uStack_70;
  *(undefined4 *)((int)unaff_EBX + 4) = uStack_70._4_4_;
  *(undefined4 *)(unaff_EBX + 1) = (undefined4)uStack_40;
  iVar6 = 1;
  *(undefined4 *)((int)unaff_EBX + 0xc) = uStack_40._4_4_;
  do {
    iVar4 = iVar6 * 2;
    iVar6 = iVar6 + 1;
    unaff_EBX[3] = *(double *)(auStack_180 + iVar4);
    unaff_EBX = unaff_EBX + 1;
  } while (iVar6 < 0xb);
  return;
}


