// 00404b33 FUN_00404b33 [Global]
// program: sfmain.exe

void __fastcall FUN_00404b33(short *param_1,int param_2)

{
  short sVar1;
  ushort uVar2;
  short *in_EAX;
  short *psVar3;
  short *extraout_ECX;
  int *piVar4;
  int iVar5;
  int extraout_ECX_00;
  short sVar6;
  int iVar7;
  int extraout_EDX;
  int *piVar8;
  int iVar9;
  short *unaff_EBX;
  int *piVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  undefined8 uVar14;
  short local_7a [41];
  int local_28;
  int local_24;
  short *local_20;
  short local_10;
  
  iVar12 = 0;
  psVar3 = in_EAX;
  do {
    sVar6 = *psVar3;
    if (sVar6 < 0) {
      if (sVar6 == -0x8000) {
        iVar7 = 0x7fff;
      }
      else {
        iVar7 = -(int)sVar6;
      }
    }
    else {
      iVar7 = (int)sVar6;
    }
    if ((short)iVar12 < (short)iVar7) {
      iVar12 = iVar7;
    }
    psVar3 = psVar3 + 1;
  } while (psVar3 != in_EAX + 0x28);
  uVar2 = (ushort)psVar3 ^ (ushort)(in_EAX + 0x28);
  local_20 = param_1;
  if ((short)iVar12 != 0) {
    if ((short)iVar12 < 1) {
      local_7a[0] = 0x40;
      FUN_0042b978();
      param_1 = extraout_ECX;
      iVar7 = extraout_EDX;
    }
    local_7a[0] = 0x40;
    uVar14 = FUN_00407eb1(param_1,iVar7);
    uVar2 = (ushort)uVar14;
  }
  if ((short)uVar2 < 7) {
    sVar6 = 6 - uVar2;
  }
  else {
    sVar6 = 0;
  }
  if (sVar6 < 0) {
    local_7a[0] = 0x40;
    FUN_0042b978();
  }
  iVar12 = 0;
  do {
    sVar1 = *in_EAX;
    iVar12 = iVar12 + 1;
    in_EAX = in_EAX + 1;
    local_7a[iVar12] = (short)((int)sVar1 >> ((byte)sVar6 & 0x1f));
  } while (iVar12 < 0x28);
  iVar12 = 0;
  local_10 = 0x28;
  local_28 = 0x28;
  piVar10 = (int *)(param_2 + -0x4e);
  piVar13 = (int *)(param_2 + -0xe);
  piVar4 = (int *)(param_2 + -0x3a);
  piVar8 = (int *)(param_2 + -0x24);
  do {
    local_24 = *(int *)((int)piVar13 + 10) >> 0x10;
    iVar7 = (int)local_7a[1] * (int)*(short *)(local_28 * -2 + param_2) +
            (int)local_7a[2] * (int)(short)*piVar10 + (int)local_7a[3] * (*piVar10 >> 0x10) +
            (int)local_7a[4] * (*(int *)((int)piVar10 + 2) >> 0x10) +
            (int)local_7a[5] * (piVar10[1] >> 0x10) +
            (int)local_7a[6] * (*(int *)((int)piVar10 + 6) >> 0x10) +
            (int)local_7a[7] * (piVar10[2] >> 0x10) +
            (int)local_7a[8] * (*(int *)((int)piVar10 + 10) >> 0x10) +
            (int)local_7a[9] * (piVar10[3] >> 0x10) +
            (int)local_7a[10] * (*(int *)((int)piVar10 + 0xe) >> 0x10) +
            (int)local_7a[0xb] * (piVar10[4] >> 0x10) + (int)local_7a[0xc] * (int)(short)*piVar4 +
            (int)local_7a[0xd] * (*piVar4 >> 0x10) +
            (int)local_7a[0xe] * (*(int *)((int)piVar4 + 2) >> 0x10) +
            (int)local_7a[0xf] * (piVar4[1] >> 0x10) +
            (int)local_7a[0x10] * (*(int *)((int)piVar4 + 6) >> 0x10) +
            (int)local_7a[0x11] * (piVar4[2] >> 0x10) +
            (int)local_7a[0x12] * (*(int *)((int)piVar4 + 10) >> 0x10) +
            (int)local_7a[0x13] * (piVar4[3] >> 0x10) +
            (int)local_7a[0x14] * (*(int *)((int)piVar4 + 0xe) >> 0x10) +
            (int)local_7a[0x15] * (piVar4[4] >> 0x10) +
            (int)local_7a[0x16] * (*(int *)((int)piVar4 + 0x12) >> 0x10) +
            (int)local_7a[0x17] * (int)(short)*piVar8 + (int)local_7a[0x18] * (*piVar8 >> 0x10) +
            (int)local_7a[0x19] * (*(int *)((int)piVar8 + 2) >> 0x10) +
            (int)local_7a[0x1a] * (piVar8[1] >> 0x10) +
            (int)local_7a[0x1b] * (*(int *)((int)piVar8 + 6) >> 0x10) +
            (int)local_7a[0x1c] * (piVar8[2] >> 0x10) +
            (int)local_7a[0x1d] * (*(int *)((int)piVar8 + 10) >> 0x10) +
            (int)local_7a[0x1e] * (piVar8[3] >> 0x10) +
            (int)local_7a[0x1f] * (*(int *)((int)piVar8 + 0xe) >> 0x10) +
            (int)local_7a[0x20] * (piVar8[4] >> 0x10) +
            (int)local_7a[0x21] * (*(int *)((int)piVar8 + 0x12) >> 0x10) +
            (int)local_7a[0x22] * (int)(short)*piVar13 + (int)local_7a[0x23] * (*piVar13 >> 0x10) +
            (int)local_7a[0x24] * (*(int *)((int)piVar13 + 2) >> 0x10) +
            (int)local_7a[0x25] * (piVar13[1] >> 0x10) +
            (int)local_7a[0x26] * (*(int *)((int)piVar13 + 6) >> 0x10) +
            (int)local_7a[0x27] * (piVar13[2] >> 0x10) + local_7a[0x28] * local_24;
    if (iVar12 < iVar7) {
      local_10 = (short)local_28;
      iVar12 = iVar7;
    }
    piVar10 = (int *)((int)piVar10 + -2);
    piVar4 = (int *)((int)piVar4 + -2);
    piVar8 = (int *)((int)piVar8 + -2);
    local_28 = local_28 + 1;
    piVar13 = (int *)((int)piVar13 + -2);
  } while (local_28 < 0x79);
  *local_20 = local_10;
  if ((100 < sVar6) || (sVar6 < -100)) {
    local_7a[0] = 0x40;
    FUN_0042b978();
  }
  iVar12 = iVar12 * 2 >> (6 - (byte)sVar6 & 0x1f);
  if ((0x78 < local_10) || (local_10 < 0x28)) {
    local_7a[0] = 0x40;
    FUN_0042b978();
  }
  iVar11 = 0;
  iVar7 = 0;
  do {
    iVar5 = iVar7 - local_10;
    iVar9 = (int)*(short *)(iVar5 * 2 + param_2) >> 3;
    iVar9 = iVar9 * iVar9;
    iVar7 = iVar7 + 1;
    iVar11 = iVar11 + iVar9;
  } while (iVar7 < 0x28);
  if (iVar12 < 1) {
    *unaff_EBX = 0;
  }
  else if (iVar12 < iVar11 * 2) {
    local_7a[0] = 0x40;
    uVar14 = FUN_00407eb1(iVar5,iVar9);
    iVar7 = (iVar11 * 2 << ((byte)uVar14 & 0x1f)) >> 0x10;
    for (sVar6 = 0; sVar6 < 3; sVar6 = sVar6 + 1) {
      local_7a[0] = 0x40;
      iVar7 = FUN_00407d75(iVar7,(short)((uint)*(undefined4 *)((int)&DAT_00438152 + sVar6 * 2) >>
                                        0x10));
      if ((short)((uint)(iVar12 << ((byte)uVar14 & 0x1f)) >> 0x10) <= (short)iVar7) break;
      iVar7 = extraout_ECX_00;
    }
    *unaff_EBX = sVar6;
  }
  else {
    *unaff_EBX = 3;
  }
  return;
}


