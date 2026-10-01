// 1007d650 FUN_1007d650 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_1007d650(int param_1)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int unaff_ESI;
  int unaff_EDI;
  uint uVar11;
  undefined *puVar12;
  float10 in_ST0;
  float10 fVar13;
  float10 fVar14;
  float10 in_ST1;
  float10 fVar15;
  float10 in_ST2;
  float10 fVar16;
  float10 in_ST3;
  float10 fVar17;
  float10 fVar18;
  float10 fVar19;
  float10 in_ST4;
  float10 fVar20;
  float10 fVar21;
  float10 in_ST5;
  float10 fVar22;
  
  uVar11 = unaff_EDI + in_EAX * 2 & 6;
  puVar6 = (undefined4 *)((uint)(&DAT_1008f278 + param_1 * 2 + uVar11) & 0xfffffff8);
  puVar3 = (undefined4 *)(uVar11 + 0x1008f276 & 0xfffffff8);
  *puVar6 = 0;
  puVar6[1] = 0;
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar12 = &DAT_1008f278 + param_1 * 2 + uVar11;
  DAT_1008d490 = -param_1;
  if (param_1 == -0x14 || (int)DAT_1008d490 < 0x14) {
    puVar12 = puVar12 + param_1 * -2;
    _DAT_1008d440 = (float)in_ST0;
    _DAT_1008d458 = (float)in_ST3;
    _DAT_1008d448 = (float)in_ST1;
    fVar13 = in_ST1 * ((float10)_DAT_1008f3b8 / in_ST0);
    _DAT_1008d450 = (float)in_ST2;
    fVar17 = in_ST2 * ((float10)_DAT_1008f3b8 / in_ST0);
    _DAT_1008d460 = (float)in_ST4;
    _DAT_1008d468 = (float)in_ST5;
    fVar15 = (in_ST5 * ((float10)_DAT_1008f3b8 / in_ST3) - fVar17) *
             (float10)*(float *)(&DAT_1008f3c4 + param_1 * -4);
    fVar18 = (in_ST4 * ((float10)_DAT_1008f3b8 / in_ST3) - fVar13) *
             (float10)*(float *)(&DAT_1008f3c4 + param_1 * -4);
    DAT_1008d498 = (float)(fVar17 + (float10)_DAT_1008f3c0);
    DAT_1008d494 = (float)(fVar13 + (float10)_DAT_1008f3c0);
  }
  else {
    _DAT_1008d440 = (float)in_ST0;
    fVar18 = (float10)_DAT_1008f3bc / (float10)(int)DAT_1008d490;
    _DAT_1008d460 = (float)in_ST4;
    _DAT_1008d458 = (float)in_ST3;
    fVar13 = (in_ST4 - in_ST1) * fVar18;
    _DAT_1008d468 = (float)in_ST5;
    fVar15 = (in_ST3 - in_ST0) * fVar18;
    fVar18 = fVar18 * (in_ST5 - in_ST2);
    _DAT_1008d448 = (float)in_ST1;
    _DAT_1008d450 = (float)in_ST2;
    DAT_1008d4a4 = (float)(in_ST1 * ((float10)_DAT_1008f3b8 / in_ST0) + (float10)_DAT_1008f3c0);
    fVar1 = DAT_1008d4a4;
    DAT_1008d4a8 = (float)(((float10)_DAT_1008f3b8 / in_ST0) * in_ST2 + (float10)_DAT_1008f3c0);
    fVar2 = DAT_1008d4a8;
    if (((uint)puVar12 & 3) == 0) {
      fVar16 = in_ST0 + fVar15;
      fVar17 = (float10)_DAT_1008f3b8 / fVar16;
    }
    else {
      iVar5 = 4 - ((uint)puVar12 & 3);
      DAT_1008d490 = DAT_1008d490 - iVar5;
      fVar17 = (float10)*(float *)(&DAT_1008f424 + iVar5 * 4);
      in_ST2 = fVar18 * fVar17 + in_ST2;
      fVar16 = fVar15 * fVar17 + in_ST0;
      in_ST1 = fVar17 * fVar13 + in_ST1;
      fVar17 = (float10)_DAT_1008f3b8 / fVar16;
      DAT_1008d494 = (float)(in_ST1 * fVar17 + (float10)_DAT_1008f3c0);
      DAT_1008d498 = (float)(fVar17 * in_ST2 + (float10)_DAT_1008f3c0);
      fVar16 = fVar16 + fVar15;
      fVar17 = (float10)_DAT_1008f3b8 / fVar16;
      DAT_1008d4a4 = DAT_1008d494;
      uVar11 = (int)DAT_1008d494 - (int)fVar1;
      DAT_1008d4a8 = DAT_1008d498;
      uVar7 = (int)DAT_1008d498 - (int)fVar2;
      if (1 < iVar5) {
        if (iVar5 == 2) {
          uVar11 = uVar11 * 0x8000;
          uVar7 = (int)uVar7 >> 3;
        }
        else {
          uVar11 = uVar11 * 0x5000;
          uVar7 = (int)(uVar7 * 5) >> 6;
        }
      }
      uVar8 = (uint)fVar2 >> 2 & 0x3fff | (int)fVar1 << 0x10;
      puVar12 = puVar12 + iVar5 * 2;
      iVar5 = -iVar5;
      do {
        uVar4 = uVar8 >> 0x19;
        uVar9 = uVar8 & 0x3f80;
        uVar8 = uVar8 + (uVar11 & 0xffff0000 | uVar7 & 0x3fff);
        *(undefined2 *)(puVar12 + iVar5 * 2) = *(undefined2 *)(unaff_ESI + (uVar4 | uVar9) * 2);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0);
    }
    uVar11 = DAT_1008d490 >> 4;
    do {
      fVar2 = DAT_1008d4a8;
      fVar1 = DAT_1008d4a4;
      fVar19 = fVar13 + in_ST1;
      fVar20 = fVar18 + in_ST2;
      DAT_1008d494 = (float)(fVar19 * fVar17 + (float10)_DAT_1008f3c0);
      DAT_1008d498 = (float)(fVar17 * fVar20 + (float10)_DAT_1008f3c0);
      fVar14 = fVar19;
      in_ST1 = fVar20;
      in_ST2 = fVar18;
      fVar21 = fVar15;
      fVar22 = fVar13;
      if ((char)uVar11 != '\x01') {
        fVar14 = fVar16 + fVar15;
        fVar16 = (float10)_DAT_1008f3b8 / fVar14;
        in_ST1 = fVar19;
        in_ST2 = fVar20;
        fVar21 = fVar18;
        fVar22 = fVar15;
      }
      DAT_1008d4a4 = DAT_1008d494;
      uVar7 = (int)DAT_1008d494 - (int)fVar1;
      DAT_1008d4a8 = DAT_1008d498;
      uVar4 = (int)DAT_1008d498 - (int)fVar2;
      uVar8 = (int)fVar1 << 0x10 | (uint)fVar2 >> 2 & 0x3fff;
      iVar5 = -0x10;
      puVar12 = puVar12 + 0x20;
      do {
        uVar9 = uVar8 >> 0x19;
        uVar10 = uVar8 & 0x3f80;
        uVar8 = uVar8 + ((uVar7 & 0xffff0) << 0xc | uVar4 >> 6 & 0x3fff);
        *(undefined2 *)(puVar12 + iVar5 * 2) = *(undefined2 *)(unaff_ESI + (uVar9 | uVar10) * 2);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0);
      uVar11 = uVar11 - 1;
      fVar17 = fVar16;
      fVar16 = fVar14;
      fVar18 = fVar21;
      fVar15 = fVar22;
    } while (uVar11 != 0);
    uVar11 = DAT_1008d490 & 0xf;
    if (uVar11 == 0) {
      return;
    }
    DAT_1008d494 = (float)((uint)DAT_1008d494 & 0x7fffff);
    DAT_1008d498 = (float)((uint)DAT_1008d498 & 0x7fffff);
    fVar18 = ((float10)_DAT_1008d460 * ((float10)_DAT_1008f3b8 / (float10)_DAT_1008d458) -
             (float10)(int)DAT_1008d494) * (float10)*(float *)(&DAT_1008f3c4 + uVar11 * 4);
    fVar15 = (float10)*(float *)(&DAT_1008f3c4 + uVar11 * 4) *
             (((float10)_DAT_1008f3b8 / (float10)_DAT_1008d458) * (float10)_DAT_1008d468 -
             (float10)(int)DAT_1008d498);
    puVar12 = puVar12 + uVar11 * 2;
    param_1 = -uVar11;
  }
  DAT_1008d4a0 = (uint)ROUND(fVar15);
  DAT_1008d49c = (int)ROUND(fVar18);
  uVar7 = ((uint)DAT_1008d498 & 0xffff) >> 2 | (int)DAT_1008d494 << 0x10;
  uVar8 = DAT_1008d49c << 0x10;
  uVar11 = DAT_1008d4a0 & 0xffff;
  do {
    uVar4 = uVar7 >> 0x19;
    uVar9 = uVar7 & 0x3f80;
    uVar7 = uVar7 + (uVar11 >> 2 | uVar8);
    *(undefined2 *)(puVar12 + param_1 * 2) = *(undefined2 *)(unaff_ESI + (uVar4 | uVar9) * 2);
    param_1 = param_1 + 1;
  } while (param_1 < 0);
  return;
}


