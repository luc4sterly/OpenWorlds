// 0040359d FUN_0040359d [Global]
// programa: sfmain.exe

void __fastcall FUN_0040359d(undefined4 param_1,short *param_2)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort *unaff_EBX;
  int iVar8;
  int iVar9;
  ushort uVar10;
  short *psVar11;
  
  iVar1 = *(int *)((int)in_EAX + 10) >> 0x12;
  iVar2 = *(int *)((int)in_EAX + 0x16) >> 0x12;
  iVar3 = *(int *)((int)in_EAX + 0x22) >> 0x12;
  iVar4 = *(int *)((int)in_EAX + 0x2e) >> 0x12;
  iVar5 = *(int *)((int)in_EAX + 0x3a) >> 0x12;
  iVar6 = *(int *)((int)in_EAX + 0x46) >> 0x12;
  iVar8 = (in_EAX[1] >> 0x12) * (in_EAX[1] >> 0x12) + iVar1 * iVar1 +
          (in_EAX[4] >> 0x12) * (in_EAX[4] >> 0x12) + iVar2 * iVar2 +
          (in_EAX[7] >> 0x12) * (in_EAX[7] >> 0x12) + iVar3 * iVar3 +
          (in_EAX[10] >> 0x12) * (in_EAX[10] >> 0x12) + iVar4 * iVar4 +
          (in_EAX[0xd] >> 0x12) * (in_EAX[0xd] >> 0x12) + iVar5 * iVar5 +
          (in_EAX[0x10] >> 0x12) * (in_EAX[0x10] >> 0x12) + iVar6 * iVar6;
  iVar1 = (int)(short)*in_EAX >> 2;
  iVar2 = *(int *)((int)in_EAX + 6) >> 0x12;
  iVar3 = *(int *)((int)in_EAX + 0x12) >> 0x12;
  iVar1 = (iVar8 + iVar1 * iVar1) * 2;
  iVar4 = *(int *)((int)in_EAX + 0x1e) >> 0x12;
  iVar5 = *(int *)((int)in_EAX + 0x2a) >> 0x12;
  iVar6 = *(int *)((int)in_EAX + 0x36) >> 0x12;
  iVar7 = *(int *)((int)in_EAX + 0x42) >> 0x12;
  iVar2 = ((*in_EAX >> 0x12) * (*in_EAX >> 0x12) + iVar2 * iVar2 +
           (in_EAX[3] >> 0x12) * (in_EAX[3] >> 0x12) + iVar3 * iVar3 +
           (in_EAX[6] >> 0x12) * (in_EAX[6] >> 0x12) + iVar4 * iVar4 +
           (in_EAX[9] >> 0x12) * (in_EAX[9] >> 0x12) + iVar5 * iVar5 +
           (in_EAX[0xc] >> 0x12) * (in_EAX[0xc] >> 0x12) + iVar6 * iVar6 +
           (in_EAX[0xf] >> 0x12) * (in_EAX[0xf] >> 0x12) + iVar7 * iVar7 +
          (in_EAX[0x12] >> 0x12) * (in_EAX[0x12] >> 0x12)) * 2;
  iVar3 = iVar1;
  if (iVar1 < iVar2) {
    iVar3 = iVar2;
  }
  uVar10 = (ushort)(iVar1 < iVar2);
  iVar9 = *(int *)((int)in_EAX + 2) >> 0x12;
  iVar1 = *(int *)((int)in_EAX + 0xe) >> 0x12;
  iVar2 = *(int *)((int)in_EAX + 0x1a) >> 0x12;
  iVar4 = *(int *)((int)in_EAX + 0x26) >> 0x12;
  iVar5 = *(int *)((int)in_EAX + 0x32) >> 0x12;
  iVar6 = *(int *)((int)in_EAX + 0x3e) >> 0x12;
  iVar7 = *(int *)((int)in_EAX + 0x4a) >> 0x12;
  iVar1 = (iVar9 * iVar9 + (in_EAX[2] >> 0x12) * (in_EAX[2] >> 0x12) + iVar1 * iVar1 +
           (in_EAX[5] >> 0x12) * (in_EAX[5] >> 0x12) + iVar2 * iVar2 +
           (in_EAX[8] >> 0x12) * (in_EAX[8] >> 0x12) + iVar4 * iVar4 +
           (in_EAX[0xb] >> 0x12) * (in_EAX[0xb] >> 0x12) + iVar5 * iVar5 +
           (in_EAX[0xe] >> 0x12) * (in_EAX[0xe] >> 0x12) + iVar6 * iVar6 +
           (in_EAX[0x11] >> 0x12) * (in_EAX[0x11] >> 0x12) + iVar7 * iVar7) * 2;
  if (iVar3 < iVar1) {
    uVar10 = 2;
    iVar3 = iVar1;
  }
  if (iVar3 < ((in_EAX[0x13] >> 0x12) * (in_EAX[0x13] >> 0x12) + iVar8) * 2) {
    uVar10 = 3;
  }
  iVar1 = 0;
  psVar11 = param_2 + 0xd;
  do {
    *param_2 = *(short *)((int)in_EAX + ((short)uVar10 + iVar1) * 2);
    param_2 = param_2 + 1;
    iVar1 = iVar1 + 3;
  } while (param_2 != psVar11);
  *unaff_EBX = uVar10;
  return;
}


