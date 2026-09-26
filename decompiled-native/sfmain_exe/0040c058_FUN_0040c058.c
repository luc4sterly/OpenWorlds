// 0040c058 FUN_0040c058 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void __fastcall FUN_0040c058(int param_1,int *param_2,int *param_3,float *param_4,float *param_5)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  float fVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  int extraout_ECX_04;
  int extraout_ECX_05;
  int extraout_ECX_06;
  int extraout_ECX_07;
  uint *extraout_EDX;
  uint *extraout_EDX_00;
  int *unaff_EBX;
  float10 fVar11;
  undefined8 uVar12;
  uint local_58;
  int local_40;
  int local_3c;
  uint local_34;
  
  iVar6 = *(int *)(&DAT_00438da4 + in_EAX * 4);
  if (iVar6 < 5) {
    _DAT_004433ec = 0x3c;
    local_40 = iVar6;
  }
  else {
    local_40 = 2;
    _DAT_004433ec = iVar6;
  }
  _DAT_004433dc = *param_2;
  piVar10 = unaff_EBX + 1;
  iVar6 = 0;
  do {
    iVar9 = *piVar10;
    piVar10 = piVar10 + 1;
    *(int *)(&DAT_00441b30 + iVar6) = iVar9;
    iVar6 = iVar6 + 4;
  } while (piVar10 != unaff_EBX + 0xb);
  uVar2 = *(uint *)(&DAT_00438ca0 + (DAT_004390f0 * 4 + DAT_004390e8 * 0x10 + local_40 + 1) * 4);
  fVar11 = FUN_0042b8ce();
  if (DAT_004390ec < 0x800) {
    fVar11 = FUN_0042b8ce();
  }
  local_34 = (uint)ROUND(fVar11);
  local_3c = 4;
  if (DAT_004390ec < 0x800) {
    local_3c = 3;
  }
  if (DAT_004390ec < 0x400) {
    local_3c = 2;
  }
  if (DAT_004390ec < 0x80) {
    local_3c = 1;
  }
  fVar11 = FUN_0042b8ce();
  *(uint *)(param_1 + 4) = (int)ROUND(fVar11) & 1;
  *(uint *)(param_1 + 8) = local_34 & 1;
  if (DAT_004390f4 == 0) {
    if ((_DAT_004390e0 & local_34) != 0) {
      FUN_0042b8ce();
      uVar3 = *(uint *)(&DAT_004433dc + extraout_ECX);
      FUN_0040b3ac(extraout_ECX,extraout_EDX);
      *(int *)(&DAT_004433dc + extraout_ECX_00) = DAT_004433e4;
      if (-1 < (int)local_58) {
        *(uint *)(&DAT_004433dc + extraout_ECX_00) = local_58 * 2 + (uVar3 & 1);
      }
      iVar9 = 1;
      iVar6 = 0x34;
      do {
        uVar3 = *(uint *)(&DAT_00441b30 + iVar6);
        FUN_0042b8ce();
        FUN_0040b3ac(extraout_ECX_01,extraout_EDX_00);
        if ((int)local_58 < 0) {
          local_58 = (&DAT_00441b80)[4 - iVar9];
        }
        else {
          local_58 = (uVar3 & 1) + local_58 * 2;
          if ((local_58 & 0x10) != 0) {
            local_58 = local_58 - 0x20;
          }
        }
        iVar6 = extraout_ECX_02 + -4;
        iVar9 = iVar9 + 1;
        *(uint *)(&DAT_00441b30 + extraout_ECX_02) = local_58;
      } while (iVar9 < 5);
      fVar11 = FUN_0042b8ce();
      DAT_004390ec = (int)ROUND(fVar11);
    }
    *param_2 = DAT_004433e0;
    iVar6 = 0x2c;
    piVar10 = unaff_EBX;
    do {
      piVar10 = piVar10 + 1;
      piVar1 = (int *)((int)&DAT_00441b2c + iVar6);
      iVar6 = iVar6 + 4;
      *piVar10 = *piVar1;
      iVar9 = DAT_004390d8;
    } while (iVar6 != 0x54);
    if ((uVar2 & 3) == 1) {
      DAT_004433f0 = DAT_004433f4;
    }
    if ((uVar2 & 3) == 3) {
      DAT_004433f0 = _DAT_004433ec;
    }
    *param_3 = DAT_004433f0;
    if ((iVar9 != 0 & local_34) != 0) {
      iVar6 = FUN_0042c524();
      if (*(float *)(&DAT_00438d08 + extraout_ECX_03 * 0x20) <= (float)iVar6) {
        uVar12 = FUN_0042c524();
        if (*(float *)(&DAT_00438d08 + extraout_ECX_04) <= (float)(int)uVar12) {
          iVar6 = FUN_0040a743(DAT_004433e4,
                               *(int *)(&DAT_004433dc + (int)((ulonglong)uVar12 >> 0x20)));
          *param_2 = iVar6;
        }
      }
      iVar9 = 1;
      iVar6 = local_3c << 5;
      do {
        iVar8 = FUN_0042c524();
        if ((*(float *)(iVar6 + 0x438d0c) <= (float)iVar8) &&
           (iVar8 = FUN_0042c524(), *(float *)(iVar6 + 0x438d0c) <= (float)iVar8)) {
          iVar8 = FUN_0040a743(extraout_ECX_05,*(int *)((int)&DAT_00441b2c + extraout_ECX_05));
          unaff_EBX[iVar9] = iVar8;
        }
        iVar9 = iVar9 + 1;
        iVar6 = iVar6 + 4;
      } while (iVar9 < 7);
    }
    if (((DAT_004390dc != 0 & local_34) != 0) &&
       (iVar6 = FUN_0042c524(), *(float *)(&DAT_00438d04 + extraout_ECX_06 * 0x20) <= (float)iVar6))
    {
      uVar12 = FUN_0042c524();
      if (*(float *)(&DAT_00438d04 + extraout_ECX_07) <= (float)(int)uVar12) {
        iVar6 = FUN_0040a743(DAT_004433f4,*(int *)(&DAT_004433ec + (int)((ulonglong)uVar12 >> 0x20))
                            );
        *param_3 = iVar6;
      }
    }
  }
  else {
    DAT_004390f4 = 0;
  }
  if ((_DAT_004390e4 & local_34) != 0) {
    iVar6 = 5;
    piVar10 = unaff_EBX + 5;
    do {
      iVar9 = iVar6 * 4;
      iVar6 = iVar6 + 1;
      *piVar10 = *(int *)(iVar9 + 0x4390a8);
      piVar10 = piVar10 + 1;
    } while (iVar6 < 0xb);
  }
  DAT_004390f0 = local_40;
  DAT_004390e8 = *(int *)(param_1 + 8);
  DAT_004433f4 = DAT_004433f0;
  DAT_004433f0 = _DAT_004433ec;
  DAT_004433e4 = DAT_004433e0;
  DAT_004433e0 = _DAT_004433dc;
  iVar8 = 0x2c;
  iVar6 = 0x50;
  iVar9 = 0;
  do {
    *(undefined4 *)(&DAT_00441b30 + iVar6) = *(undefined4 *)((int)&DAT_00441b2c + iVar8);
    iVar7 = iVar8 + 4;
    *(undefined4 *)((int)&DAT_00441b2c + iVar8) = *(undefined4 *)(&DAT_00441b30 + iVar9);
    iVar8 = iVar7;
    iVar6 = iVar6 + 4;
    iVar9 = iVar9 + 4;
  } while (iVar7 != 0x54);
  *param_2 = *(int *)(&DAT_00438b88 + (0x1f - *param_2) * 8);
  iVar6 = 1;
  piVar10 = unaff_EBX;
  do {
    piVar10 = piVar10 + 1;
    iVar9 = *piVar10;
    bVar4 = false;
    iVar8 = iVar9;
    if (iVar9 < 0) {
      iVar8 = -iVar9;
      bVar4 = true;
      if (iVar9 != -0xf && 0xe < iVar8) {
        iVar8 = 0;
      }
    }
    iVar9 = (&DAT_00438fa4)[iVar8 * 2];
    if (bVar4) {
      iVar9 = -iVar9;
    }
    iVar8 = iVar6 * 4;
    iVar6 = iVar6 + 1;
    *piVar10 = iVar9 * (2 << (0xeU - (char)*(undefined4 *)(iVar8 + 0x439080) & 0x1f));
  } while (iVar6 < 3);
  iVar6 = 3;
  piVar10 = unaff_EBX + 3;
  do {
    if (0.0 <= (float)*(int *)(iVar6 * 4 + 0x439038) +
               (float)(*piVar10 * (2 << (0xeU - (char)*(undefined4 *)(iVar6 * 4 + 0x439080) & 0x1f))
                      + *(int *)(iVar6 * 4 + 0x439058)) * *(float *)(iVar6 * 4 + 0x439018)) {
      fVar11 = FUN_0042b8ce();
      iVar9 = (int)ROUND(fVar11);
    }
    else {
      fVar11 = FUN_0042b8ce();
      iVar9 = -(int)ROUND(fVar11);
    }
    *piVar10 = iVar9;
    iVar6 = iVar6 + 1;
    piVar10 = piVar10 + 1;
  } while (iVar6 < 0xb);
  *param_4 = (float)*param_2;
  piVar10 = unaff_EBX + 1;
  fVar5 = (float)_DAT_00435a38;
  do {
    param_5 = param_5 + 1;
    iVar6 = *piVar10;
    piVar10 = piVar10 + 1;
    *param_5 = (float)iVar6 * fVar5;
  } while (piVar10 != unaff_EBX + 0xb);
  return;
}


