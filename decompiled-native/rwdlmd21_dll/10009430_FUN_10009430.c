// 10009430 FUN_10009430 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10009430(void)

{
  uint uVar1;
  char *pcVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  byte *pbVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_ECX_10;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  undefined4 extraout_ECX_14;
  undefined4 extraout_ECX_15;
  undefined4 extraout_ECX_16;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined1 *puVar13;
  uint uVar14;
  float10 fVar15;
  longlong lVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  byte bStack_78;
  byte bStack_77;
  byte bStack_76;
  float fStack_74;
  int iStack_70;
  int iStack_6c;
  undefined1 *puStack_68;
  int iStack_64;
  undefined1 auStack_60 [96];
  
  if (DAT_10089b7c == 8) {
    iStack_70 = DAT_10087244;
    iStack_64 = DAT_10087248;
    FUN_10007610(DAT_10087248);
    iStack_6c = 0;
    puVar13 = (undefined1 *)(iStack_70 + 0x20);
    do {
      puStack_68 = (undefined1 *)((float)iStack_6c * _DAT_10086074);
      uVar14 = 0;
      do {
        uVar1 = uVar14 + 1;
        fStack_74 = (float)uVar1;
        FUN_10009e90(auStack_60);
        if ((uVar14 & 1) == 0) {
          puVar9 = auStack_60;
          puVar11 = puVar13 + -0x20;
          do {
            puVar8 = puVar9 + 3;
            uVar4 = (*(code *)DAT_10089de0[0xa1])(puVar9);
            *puVar11 = uVar4;
            puVar9 = puVar8;
            puVar11 = puVar11 + 1;
          } while (puVar8 < &stack0x00000000);
        }
        else {
          puVar9 = auStack_60;
          puVar11 = puVar13;
          do {
            puVar11 = puVar11 + -1;
            puVar8 = puVar9 + 3;
            uVar4 = (*(code *)DAT_10089de0[0xa1])(puVar9);
            *puVar11 = uVar4;
            puVar9 = puVar8;
          } while (puVar8 < &stack0x00000000);
        }
        puVar13 = puVar13 + 0x20;
        uVar14 = uVar1;
      } while ((int)uVar1 < 4);
      iStack_6c = iStack_6c + 1;
    } while (iStack_6c < 0x24);
    FUN_10009e90(auStack_60);
    puVar13 = (undefined1 *)(iStack_70 + 0x1200);
    puVar9 = auStack_60;
    do {
      puVar11 = puVar9 + 3;
      uVar4 = (*(code *)DAT_10089de0[0xa1])(puVar9);
      *puVar13 = uVar4;
      puVar13 = puVar13 + 1;
      puVar9 = puVar11;
    } while (puVar11 < &stack0x00000000);
    iStack_70 = 0;
    do {
      iStack_6c = 0;
      puStack_68 = (undefined1 *)(iStack_70 + iStack_64);
      do {
        if (DAT_1008725c == 0) {
          fVar15 = (float10)iStack_6c * (float10)_DAT_10086098;
        }
        else {
          fVar15 = (float10)fsin((float10)iStack_6c * (float10)_DAT_10086080 *
                                 (float10)_DAT_10086088 * (float10)_DAT_10086090);
        }
        fStack_74 = (float)fVar15;
        if (DAT_10087260 <= fStack_74) {
          lVar16 = __ftol();
          bStack_77 = *(byte *)((int)&DAT_1008a000 + iStack_70);
          bStack_78 = *(byte *)((int)&DAT_10089f00 + iStack_70);
          uVar14 = 0x10080U - (-(int)lVar16 + 0x10000) & 0xffffff00;
          iVar10 = -(int)lVar16 + 0x10080 >> 8;
          bStack_76 = *(byte *)((int)&DAT_10089df0 + iStack_70);
          FUN_10007520(&bStack_78,&bStack_78);
          iVar7 = ((int)((uint)bStack_78 * 0x100 + 0x80) >> 8) * iVar10 + uVar14;
          if (0xffff < iVar7) {
            iVar7 = 0xffff;
          }
          bStack_78 = (byte)((uint)iVar7 >> 8);
          iVar7 = ((int)((uint)bStack_77 * 0x100 + 0x80) >> 8) * iVar10 + uVar14;
          if (0xffff < iVar7) {
            iVar7 = 0xffff;
          }
          bStack_77 = (byte)((uint)iVar7 >> 8);
          iVar7 = ((int)((uint)bStack_76 * 0x100 + 0x80) >> 8) * iVar10 + uVar14;
        }
        else {
          lVar16 = __ftol();
          iVar12 = 0x10080 - (int)lVar16 >> 8;
          iVar10 = (int)lVar16 + 0x80 >> 8;
          bStack_78 = *(byte *)((int)&DAT_10089f00 + iStack_70);
          bStack_77 = *(byte *)((int)&DAT_1008a000 + iStack_70);
          bStack_76 = *(byte *)((int)&DAT_10089df0 + iStack_70);
          FUN_10007520(&bStack_78,&bStack_78);
          iVar7 = ((int)((uint)bStack_78 * 0x100 + 0x80) >> 8) * iVar10 +
                  (*DAT_10089de0 + 0x80 >> 8) * iVar12;
          if (0xffff < iVar7) {
            iVar7 = 0xffff;
          }
          bStack_78 = (byte)((uint)iVar7 >> 8);
          iVar7 = ((int)((uint)bStack_77 * 0x100 + 0x80) >> 8) * iVar10 +
                  (DAT_10089de0[1] + 0x80 >> 8) * iVar12;
          if (0xffff < iVar7) {
            iVar7 = 0xffff;
          }
          bStack_77 = (byte)((uint)iVar7 >> 8);
          iVar7 = ((int)((uint)bStack_76 * 0x100 + 0x80) >> 8) * iVar10 +
                  (DAT_10089de0[2] + 0x80 >> 8) * iVar12;
        }
        bStack_76 = (byte)((uint)iVar7 >> 8);
        if (0xffff < iVar7) {
          bStack_76 = 0xff;
        }
        uVar4 = (*(code *)DAT_10089de0[0xa1])(&bStack_78);
        *puStack_68 = uVar4;
        puStack_68 = puStack_68 + 0x100;
        iStack_6c = iStack_6c + 1;
      } while (iStack_6c < 0x20);
      iStack_70 = iStack_70 + 1;
    } while (iStack_70 < 0x100);
    FUN_10007610(iStack_6c);
    return;
  }
  if ((DAT_10089b7c == 0x10) || (DAT_10089b7c == 0xf)) {
    iStack_6c = 0;
    puStack_68 = (undefined1 *)0x0;
    iStack_64 = DAT_10087248;
    do {
      iStack_70 = 0;
      uVar14 = 0;
      do {
        if (DAT_1008725c == 0) {
          fVar15 = (float10)iStack_6c * (float10)_DAT_10086098;
        }
        else {
          fVar15 = (float10)fsin((float10)iStack_6c * (float10)_DAT_10086080 *
                                 (float10)_DAT_10086088 * (float10)_DAT_10086090);
        }
        fStack_74 = (float)fVar15;
        if (DAT_10087260 <= fStack_74) {
          lVar16 = __ftol();
          uVar17 = FUN_1006a324(extraout_ECX_02,(int)((ulonglong)lVar16 >> 0x20),uVar14,0x200000);
          uVar18 = FUN_1006a324(extraout_ECX_03,(int)((ulonglong)uVar17 >> 0x20),uVar14,0x200000);
          FUN_1006a324(extraout_ECX_04,(int)((ulonglong)uVar18 >> 0x20),uVar14,0x200000);
          iVar7 = (0x10080U - (-(int)lVar16 + 0x10000) & 0xffffff00) +
                  ((int)uVar17 + 0x80 >> 8) * (-(int)lVar16 + 0x10080 >> 8);
          if (0xffff < iVar7) {
            iVar7 = 0xffff;
          }
          pbVar6 = (byte *)(iStack_64 + iStack_70 + (int)puStack_68);
          bVar5 = (byte)(iVar7 >> 0xb);
          *pbVar6 = bVar5;
          if (0x1e < bVar5) {
            *pbVar6 = 0x1e;
          }
          bVar5 = *pbVar6;
        }
        else {
          lVar16 = __ftol();
          uVar17 = FUN_1006a324(extraout_ECX,(int)((ulonglong)lVar16 >> 0x20),uVar14,0x200000);
          uVar18 = FUN_1006a324(extraout_ECX_00,(int)((ulonglong)uVar17 >> 0x20),uVar14,0x200000);
          FUN_1006a324(extraout_ECX_01,(int)((ulonglong)uVar18 >> 0x20),uVar14,0x200000);
          iVar7 = (*DAT_10089de0 + 0x80 >> 8) * (0x10080 - (int)lVar16 >> 8) +
                  ((int)uVar17 + 0x80 >> 8) * ((int)lVar16 + 0x80 >> 8);
          if (0xffff < iVar7) {
            iVar7 = 0xffff;
          }
          pbVar6 = (byte *)(iStack_64 + iStack_70 + (int)puStack_68);
          bVar5 = (byte)(iVar7 >> 0xb);
          *pbVar6 = bVar5;
          if (0x1e < bVar5) {
            *pbVar6 = 0x1e;
          }
          bVar5 = *pbVar6;
        }
        if (bVar5 == 0) {
          *pbVar6 = 1;
        }
        uVar14 = uVar14 + 0x10000;
        iStack_70 = iStack_70 + 1;
      } while ((int)uVar14 < 0x200000);
      puStack_68 = (undefined1 *)((int)puStack_68 + 0x20);
      iStack_6c = iStack_6c + 1;
    } while ((int)puStack_68 < 0x400);
    iStack_6c = 0;
    puStack_68 = (undefined1 *)0x0;
    do {
      iStack_70 = 0;
      uVar14 = 0;
      do {
        if (DAT_1008725c == 0) {
          fVar15 = (float10)iStack_6c * (float10)_DAT_10086098;
        }
        else {
          fVar15 = (float10)fsin((float10)iStack_6c * (float10)_DAT_10086080 *
                                 (float10)_DAT_10086088 * (float10)_DAT_10086090);
        }
        fStack_74 = (float)fVar15;
        if (DAT_10087260 <= fStack_74) {
          lVar16 = __ftol();
          uVar17 = FUN_1006a324(extraout_ECX_08,(int)((ulonglong)lVar16 >> 0x20),uVar14,0x200000);
          uVar17 = FUN_1006a324(extraout_ECX_09,(int)((ulonglong)uVar17 >> 0x20),uVar14,0x200000);
          FUN_1006a324(extraout_ECX_10,(int)((ulonglong)uVar17 >> 0x20),uVar14,0x200000);
          iVar7 = ((int)uVar17 + 0x80 >> 8) * (-(int)lVar16 + 0x10080 >> 8) +
                  (0x10080U - (-(int)lVar16 + 0x10000) & 0xffffff00);
          if (0xffff < iVar7) {
            iVar7 = 0xffff;
          }
          bVar5 = (byte)(iVar7 >> 0xb);
          *(byte *)(iStack_64 + iStack_70 + 0x400 + (int)puStack_68) = bVar5;
          pcVar2 = (char *)(iStack_64 + iStack_70 + 0x400 + (int)puStack_68);
          if (0x1e < bVar5) {
            *pcVar2 = '\x1e';
          }
          cVar3 = *pcVar2;
        }
        else {
          lVar16 = __ftol();
          uVar17 = FUN_1006a324(extraout_ECX_05,(int)((ulonglong)lVar16 >> 0x20),uVar14,0x200000);
          uVar17 = FUN_1006a324(extraout_ECX_06,(int)((ulonglong)uVar17 >> 0x20),uVar14,0x200000);
          FUN_1006a324(extraout_ECX_07,(int)((ulonglong)uVar17 >> 0x20),uVar14,0x200000);
          iVar7 = ((int)uVar17 + 0x80 >> 8) * ((int)lVar16 + 0x80 >> 8) +
                  (DAT_10089de0[1] + 0x80 >> 8) * (0x10080 - (int)lVar16 >> 8);
          if (0xffff < iVar7) {
            iVar7 = 0xffff;
          }
          bVar5 = (byte)(iVar7 >> 0xb);
          *(byte *)(iStack_64 + iStack_70 + 0x400 + (int)puStack_68) = bVar5;
          pcVar2 = (char *)(iStack_64 + iStack_70 + 0x400 + (int)puStack_68);
          if (0x1e < bVar5) {
            *pcVar2 = '\x1e';
          }
          cVar3 = *pcVar2;
        }
        if (cVar3 == '\0') {
          *pcVar2 = '\x01';
        }
        uVar14 = uVar14 + 0x10000;
        iStack_70 = iStack_70 + 1;
      } while ((int)uVar14 < 0x200000);
      puStack_68 = (undefined1 *)((int)puStack_68 + 0x20);
      iStack_6c = iStack_6c + 1;
    } while ((int)puStack_68 < 0x400);
    iStack_6c = 0;
    puStack_68 = (undefined1 *)0x0;
    do {
      iStack_70 = 0;
      uVar14 = 0;
      do {
        if (DAT_1008725c == 0) {
          fVar15 = (float10)iStack_6c * (float10)_DAT_10086098;
        }
        else {
          fVar15 = (float10)fsin((float10)iStack_6c * (float10)_DAT_10086080 *
                                 (float10)_DAT_10086088 * (float10)_DAT_10086090);
        }
        fStack_74 = (float)fVar15;
        if (DAT_10087260 <= fStack_74) {
          lVar16 = __ftol();
          uVar17 = FUN_1006a324(extraout_ECX_14,(int)((ulonglong)lVar16 >> 0x20),uVar14,0x200000);
          uVar17 = FUN_1006a324(extraout_ECX_15,(int)((ulonglong)uVar17 >> 0x20),uVar14,0x200000);
          uVar17 = FUN_1006a324(extraout_ECX_16,(int)((ulonglong)uVar17 >> 0x20),uVar14,0x200000);
          iVar7 = ((int)uVar17 + 0x80 >> 8) * (-(int)lVar16 + 0x10080 >> 8) +
                  (0x10080U - (-(int)lVar16 + 0x10000) & 0xffffff00);
          if (0xffff < iVar7) {
            iVar7 = 0xffff;
          }
          bVar5 = (byte)(iVar7 >> 0xb);
          *(byte *)(iStack_64 + iStack_70 + 0x800 + (int)puStack_68) = bVar5;
          pcVar2 = (char *)(iStack_64 + iStack_70 + 0x800 + (int)puStack_68);
          if (0x1e < bVar5) {
            *pcVar2 = '\x1e';
          }
          cVar3 = *pcVar2;
        }
        else {
          lVar16 = __ftol();
          uVar17 = FUN_1006a324(extraout_ECX_11,(int)((ulonglong)lVar16 >> 0x20),uVar14,0x200000);
          uVar17 = FUN_1006a324(extraout_ECX_12,(int)((ulonglong)uVar17 >> 0x20),uVar14,0x200000);
          uVar17 = FUN_1006a324(extraout_ECX_13,(int)((ulonglong)uVar17 >> 0x20),uVar14,0x200000);
          iVar7 = ((int)uVar17 + 0x80 >> 8) * ((int)lVar16 + 0x80 >> 8) +
                  (DAT_10089de0[2] + 0x80 >> 8) * (0x10080 - (int)lVar16 >> 8);
          if (0xffff < iVar7) {
            iVar7 = 0xffff;
          }
          bVar5 = (byte)(iVar7 >> 0xb);
          *(byte *)(iStack_64 + iStack_70 + 0x800 + (int)puStack_68) = bVar5;
          pcVar2 = (char *)(iStack_64 + iStack_70 + 0x800 + (int)puStack_68);
          if (0x1e < bVar5) {
            *pcVar2 = '\x1e';
          }
          cVar3 = *pcVar2;
        }
        if (cVar3 == '\0') {
          *pcVar2 = '\x01';
        }
        uVar14 = uVar14 + 0x10000;
        iStack_70 = iStack_70 + 1;
      } while ((int)uVar14 < 0x200000);
      puStack_68 = (undefined1 *)((int)puStack_68 + 0x20);
      iStack_6c = iStack_6c + 1;
    } while ((int)puStack_68 < 0x400);
  }
  return;
}


