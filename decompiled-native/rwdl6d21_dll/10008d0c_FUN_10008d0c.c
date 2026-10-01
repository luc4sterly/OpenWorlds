// 10008d0c FUN_10008d0c [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10008d0c(void)

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
  int iVar7;
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
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  undefined1 *puVar12;
  bool in_ZF;
  float10 fVar13;
  longlong lVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  float fStack00000004;
  int iStack00000008;
  int iStack0000000c;
  undefined1 *puStack00000010;
  int iStack00000014;
  
  if (!in_ZF) {
    if ((DAT_1007bb4c == 0x10) || (DAT_1007bb4c == 0xf)) {
      iStack0000000c = 0;
      puStack00000010 = (undefined1 *)0x0;
      iStack00000014 = DAT_10079220;
      do {
        iStack00000008 = 0;
        uVar11 = 0;
        do {
          if (DAT_10079234 == 0) {
            fVar13 = (float10)iStack0000000c * (float10)_DAT_10078098;
          }
          else {
            fVar13 = (float10)fsin((float10)iStack0000000c * (float10)_DAT_10078080 *
                                   (float10)_DAT_10078088 * (float10)_DAT_10078090);
          }
          fStack00000004 = (float)fVar13;
          if (DAT_10079238 <= fStack00000004) {
            lVar14 = __ftol();
            uVar15 = FUN_10069324(extraout_ECX_02,(int)((ulonglong)lVar14 >> 0x20),uVar11,0x200000);
            uVar16 = FUN_10069324(extraout_ECX_03,(int)((ulonglong)uVar15 >> 0x20),uVar11,0x200000);
            FUN_10069324(extraout_ECX_04,(int)((ulonglong)uVar16 >> 0x20),uVar11,0x200000);
            iVar7 = (0x10080U - (-(int)lVar14 + 0x10000) & 0xffffff00) +
                    ((int)uVar15 + 0x80 >> 8) * (-(int)lVar14 + 0x10080 >> 8);
            if (0xffff < iVar7) {
              iVar7 = 0xffff;
            }
            pbVar6 = (byte *)(iStack00000014 + iStack00000008 + (int)puStack00000010);
            bVar5 = (byte)(iVar7 >> 0xb);
            *pbVar6 = bVar5;
            if (0x1e < bVar5) {
              *pbVar6 = 0x1e;
            }
            bVar5 = *pbVar6;
          }
          else {
            lVar14 = __ftol();
            uVar15 = FUN_10069324(extraout_ECX,(int)((ulonglong)lVar14 >> 0x20),uVar11,0x200000);
            uVar16 = FUN_10069324(extraout_ECX_00,(int)((ulonglong)uVar15 >> 0x20),uVar11,0x200000);
            FUN_10069324(extraout_ECX_01,(int)((ulonglong)uVar16 >> 0x20),uVar11,0x200000);
            iVar7 = (*DAT_1007bda8 + 0x80 >> 8) * (0x10080 - (int)lVar14 >> 8) +
                    ((int)uVar15 + 0x80 >> 8) * ((int)lVar14 + 0x80 >> 8);
            if (0xffff < iVar7) {
              iVar7 = 0xffff;
            }
            pbVar6 = (byte *)(iStack00000014 + iStack00000008 + (int)puStack00000010);
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
          uVar11 = uVar11 + 0x10000;
          iStack00000008 = iStack00000008 + 1;
        } while ((int)uVar11 < 0x200000);
        puStack00000010 = (undefined1 *)((int)puStack00000010 + 0x20);
        iStack0000000c = iStack0000000c + 1;
      } while ((int)puStack00000010 < 0x400);
      iStack0000000c = 0;
      puStack00000010 = (undefined1 *)0x0;
      do {
        iStack00000008 = 0;
        uVar11 = 0;
        do {
          if (DAT_10079234 == 0) {
            fVar13 = (float10)iStack0000000c * (float10)_DAT_10078098;
          }
          else {
            fVar13 = (float10)fsin((float10)iStack0000000c * (float10)_DAT_10078080 *
                                   (float10)_DAT_10078088 * (float10)_DAT_10078090);
          }
          fStack00000004 = (float)fVar13;
          if (DAT_10079238 <= fStack00000004) {
            lVar14 = __ftol();
            uVar15 = FUN_10069324(extraout_ECX_08,(int)((ulonglong)lVar14 >> 0x20),uVar11,0x200000);
            uVar15 = FUN_10069324(extraout_ECX_09,(int)((ulonglong)uVar15 >> 0x20),uVar11,0x200000);
            FUN_10069324(extraout_ECX_10,(int)((ulonglong)uVar15 >> 0x20),uVar11,0x200000);
            iVar7 = ((int)uVar15 + 0x80 >> 8) * (-(int)lVar14 + 0x10080 >> 8) +
                    (0x10080U - (-(int)lVar14 + 0x10000) & 0xffffff00);
            if (0xffff < iVar7) {
              iVar7 = 0xffff;
            }
            bVar5 = (byte)(iVar7 >> 0xb);
            *(byte *)(iStack00000014 + iStack00000008 + 0x400 + (int)puStack00000010) = bVar5;
            pcVar2 = (char *)(iStack00000014 + iStack00000008 + 0x400 + (int)puStack00000010);
            if (0x1e < bVar5) {
              *pcVar2 = '\x1e';
            }
            cVar3 = *pcVar2;
          }
          else {
            lVar14 = __ftol();
            uVar15 = FUN_10069324(extraout_ECX_05,(int)((ulonglong)lVar14 >> 0x20),uVar11,0x200000);
            uVar15 = FUN_10069324(extraout_ECX_06,(int)((ulonglong)uVar15 >> 0x20),uVar11,0x200000);
            FUN_10069324(extraout_ECX_07,(int)((ulonglong)uVar15 >> 0x20),uVar11,0x200000);
            iVar7 = ((int)uVar15 + 0x80 >> 8) * ((int)lVar14 + 0x80 >> 8) +
                    (DAT_1007bda8[1] + 0x80 >> 8) * (0x10080 - (int)lVar14 >> 8);
            if (0xffff < iVar7) {
              iVar7 = 0xffff;
            }
            bVar5 = (byte)(iVar7 >> 0xb);
            *(byte *)(iStack00000014 + iStack00000008 + 0x400 + (int)puStack00000010) = bVar5;
            pcVar2 = (char *)(iStack00000014 + iStack00000008 + 0x400 + (int)puStack00000010);
            if (0x1e < bVar5) {
              *pcVar2 = '\x1e';
            }
            cVar3 = *pcVar2;
          }
          if (cVar3 == '\0') {
            *pcVar2 = '\x01';
          }
          uVar11 = uVar11 + 0x10000;
          iStack00000008 = iStack00000008 + 1;
        } while ((int)uVar11 < 0x200000);
        puStack00000010 = (undefined1 *)((int)puStack00000010 + 0x20);
        iStack0000000c = iStack0000000c + 1;
      } while ((int)puStack00000010 < 0x400);
      iStack0000000c = 0;
      puStack00000010 = (undefined1 *)0x0;
      do {
        iStack00000008 = 0;
        uVar11 = 0;
        do {
          if (DAT_10079234 == 0) {
            fVar13 = (float10)iStack0000000c * (float10)_DAT_10078098;
          }
          else {
            fVar13 = (float10)fsin((float10)iStack0000000c * (float10)_DAT_10078080 *
                                   (float10)_DAT_10078088 * (float10)_DAT_10078090);
          }
          fStack00000004 = (float)fVar13;
          if (DAT_10079238 <= fStack00000004) {
            lVar14 = __ftol();
            uVar15 = FUN_10069324(extraout_ECX_14,(int)((ulonglong)lVar14 >> 0x20),uVar11,0x200000);
            uVar15 = FUN_10069324(extraout_ECX_15,(int)((ulonglong)uVar15 >> 0x20),uVar11,0x200000);
            uVar15 = FUN_10069324(extraout_ECX_16,(int)((ulonglong)uVar15 >> 0x20),uVar11,0x200000);
            iVar7 = ((int)uVar15 + 0x80 >> 8) * (-(int)lVar14 + 0x10080 >> 8) +
                    (0x10080U - (-(int)lVar14 + 0x10000) & 0xffffff00);
            if (0xffff < iVar7) {
              iVar7 = 0xffff;
            }
            bVar5 = (byte)(iVar7 >> 0xb);
            *(byte *)(iStack00000014 + iStack00000008 + 0x800 + (int)puStack00000010) = bVar5;
            pcVar2 = (char *)(iStack00000014 + iStack00000008 + 0x800 + (int)puStack00000010);
            if (0x1e < bVar5) {
              *pcVar2 = '\x1e';
            }
            cVar3 = *pcVar2;
          }
          else {
            lVar14 = __ftol();
            uVar15 = FUN_10069324(extraout_ECX_11,(int)((ulonglong)lVar14 >> 0x20),uVar11,0x200000);
            uVar15 = FUN_10069324(extraout_ECX_12,(int)((ulonglong)uVar15 >> 0x20),uVar11,0x200000);
            uVar15 = FUN_10069324(extraout_ECX_13,(int)((ulonglong)uVar15 >> 0x20),uVar11,0x200000);
            iVar7 = ((int)uVar15 + 0x80 >> 8) * ((int)lVar14 + 0x80 >> 8) +
                    (DAT_1007bda8[2] + 0x80 >> 8) * (0x10080 - (int)lVar14 >> 8);
            if (0xffff < iVar7) {
              iVar7 = 0xffff;
            }
            bVar5 = (byte)(iVar7 >> 0xb);
            *(byte *)(iStack00000014 + iStack00000008 + 0x800 + (int)puStack00000010) = bVar5;
            pcVar2 = (char *)(iStack00000014 + iStack00000008 + 0x800 + (int)puStack00000010);
            if (0x1e < bVar5) {
              *pcVar2 = '\x1e';
            }
            cVar3 = *pcVar2;
          }
          if (cVar3 == '\0') {
            *pcVar2 = '\x01';
          }
          uVar11 = uVar11 + 0x10000;
          iStack00000008 = iStack00000008 + 1;
        } while ((int)uVar11 < 0x200000);
        puStack00000010 = (undefined1 *)((int)puStack00000010 + 0x20);
        iStack0000000c = iStack0000000c + 1;
      } while ((int)puStack00000010 < 0x400);
    }
    return;
  }
  iStack00000008 = DAT_1007921c;
  iStack00000014 = DAT_10079220;
  FUN_10006e50(DAT_10079220);
  iStack0000000c = 0;
  puVar12 = (undefined1 *)(iStack00000008 + 0x20);
  do {
    puStack00000010 = (undefined1 *)((float)iStack0000000c * _DAT_10078074);
    uVar11 = 0;
    do {
      uVar1 = uVar11 + 1;
      fStack00000004 = (float)uVar1;
      FUN_10009780(&stack0x00000018);
      if ((uVar11 & 1) == 0) {
        puVar9 = puVar12 + -0x20;
        puVar10 = &stack0x00000018;
        do {
          puVar8 = puVar10 + 3;
          uVar4 = (*(code *)DAT_1007bda8[0xa1])(puVar10);
          *puVar9 = uVar4;
          puVar9 = puVar9 + 1;
          puVar10 = puVar8;
        } while (puVar8 < &stack0x00000078);
      }
      else {
        puVar9 = &stack0x00000018;
        puVar10 = puVar12;
        do {
          puVar10 = puVar10 + -1;
          puVar8 = puVar9 + 3;
          uVar4 = (*(code *)DAT_1007bda8[0xa1])(puVar9);
          *puVar10 = uVar4;
          puVar9 = puVar8;
        } while (puVar8 < &stack0x00000078);
      }
      puVar12 = puVar12 + 0x20;
      uVar11 = uVar1;
    } while ((int)uVar1 < 4);
    iStack0000000c = iStack0000000c + 1;
  } while (iStack0000000c < 0x24);
  FUN_10009780(&stack0x00000018);
  puVar12 = (undefined1 *)(iStack00000008 + 0x1200);
  puVar9 = &stack0x00000018;
  do {
    puVar10 = puVar9 + 3;
    uVar4 = (*(code *)DAT_1007bda8[0xa1])(puVar9);
    *puVar12 = uVar4;
    puVar12 = puVar12 + 1;
    puVar9 = puVar10;
  } while (puVar10 < &stack0x00000078);
  iStack00000008 = 0;
  do {
    iStack0000000c = 0;
    puStack00000010 = (undefined1 *)(iStack00000008 + iStack00000014);
    do {
      if (DAT_10079234 == 0) {
        fVar13 = (float10)iStack0000000c * (float10)_DAT_10078098;
      }
      else {
        fVar13 = (float10)fsin((float10)iStack0000000c * (float10)_DAT_10078080 *
                               (float10)_DAT_10078088 * (float10)_DAT_10078090);
      }
      fStack00000004 = (float)fVar13;
      if (DAT_10079238 <= fStack00000004) {
        __ftol();
        FUN_10006d60(&stack0x00000000,&stack0x00000000);
        uVar4 = (*(code *)DAT_1007bda8[0xa1])(&stack0x00000000);
      }
      else {
        __ftol();
        FUN_10006d60(&stack0x00000000,&stack0x00000000);
        uVar4 = (*(code *)DAT_1007bda8[0xa1])(&stack0x00000000);
      }
      *puStack00000010 = uVar4;
      puStack00000010 = puStack00000010 + 0x100;
      iStack0000000c = iStack0000000c + 1;
    } while (iStack0000000c < 0x20);
    iStack00000008 = iStack00000008 + 1;
  } while (iStack00000008 < 0x100);
  FUN_10006e50(iStack0000000c);
  return;
}


