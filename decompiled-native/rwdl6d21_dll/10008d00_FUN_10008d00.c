// 10008d00 FUN_10008d00 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10008d00(void)

{
  uint uVar1;
  char *pcVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
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
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  uint uVar15;
  float10 fVar16;
  longlong lVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  byte bStack_78;
  byte bStack_77;
  byte bStack_76;
  float fStack_74;
  int iStack_70;
  int iStack_6c;
  undefined1 *puStack_68;
  int iStack_64;
  undefined1 auStack_60 [96];
  
  if (DAT_1007bb4c != 8) {
    if ((DAT_1007bb4c == 0x10) || (DAT_1007bb4c == 0xf)) {
      iStack_6c = 0;
      puStack_68 = (undefined1 *)0x0;
      iStack_64 = DAT_10079220;
      do {
        iStack_70 = 0;
        uVar15 = 0;
        do {
          if (DAT_10079234 == 0) {
            fVar16 = (float10)iStack_6c * (float10)_DAT_10078098;
          }
          else {
            fVar16 = (float10)fsin((float10)iStack_6c * (float10)_DAT_10078080 *
                                   (float10)_DAT_10078088 * (float10)_DAT_10078090);
          }
          fStack_74 = (float)fVar16;
          if (DAT_10079238 <= fStack_74) {
            lVar17 = __ftol();
            uVar18 = FUN_10069324(extraout_ECX_02,(int)((ulonglong)lVar17 >> 0x20),uVar15,0x200000);
            uVar19 = FUN_10069324(extraout_ECX_03,(int)((ulonglong)uVar18 >> 0x20),uVar15,0x200000);
            FUN_10069324(extraout_ECX_04,(int)((ulonglong)uVar19 >> 0x20),uVar15,0x200000);
            iVar7 = (0x10080U - (-(int)lVar17 + 0x10000) & 0xffffff00) +
                    ((int)uVar18 + 0x80 >> 8) * (-(int)lVar17 + 0x10080 >> 8);
            if (0xffff < iVar7) {
              iVar7 = 0xffff;
            }
            pbVar8 = (byte *)(iStack_64 + iStack_70 + (int)puStack_68);
            bVar5 = (byte)(iVar7 >> 0xb);
            *pbVar8 = bVar5;
            if (0x1e < bVar5) {
              *pbVar8 = 0x1e;
            }
            bVar5 = *pbVar8;
          }
          else {
            lVar17 = __ftol();
            uVar18 = FUN_10069324(extraout_ECX,(int)((ulonglong)lVar17 >> 0x20),uVar15,0x200000);
            uVar19 = FUN_10069324(extraout_ECX_00,(int)((ulonglong)uVar18 >> 0x20),uVar15,0x200000);
            FUN_10069324(extraout_ECX_01,(int)((ulonglong)uVar19 >> 0x20),uVar15,0x200000);
            iVar7 = (*DAT_1007bda8 + 0x80 >> 8) * (0x10080 - (int)lVar17 >> 8) +
                    ((int)uVar18 + 0x80 >> 8) * ((int)lVar17 + 0x80 >> 8);
            if (0xffff < iVar7) {
              iVar7 = 0xffff;
            }
            pbVar8 = (byte *)(iStack_64 + iStack_70 + (int)puStack_68);
            bVar5 = (byte)(iVar7 >> 0xb);
            *pbVar8 = bVar5;
            if (0x1e < bVar5) {
              *pbVar8 = 0x1e;
            }
            bVar5 = *pbVar8;
          }
          if (bVar5 == 0) {
            *pbVar8 = 1;
          }
          uVar15 = uVar15 + 0x10000;
          iStack_70 = iStack_70 + 1;
        } while ((int)uVar15 < 0x200000);
        puStack_68 = (undefined1 *)((int)puStack_68 + 0x20);
        iStack_6c = iStack_6c + 1;
      } while ((int)puStack_68 < 0x400);
      iStack_6c = 0;
      puStack_68 = (undefined1 *)0x0;
      do {
        iStack_70 = 0;
        uVar15 = 0;
        do {
          if (DAT_10079234 == 0) {
            fVar16 = (float10)iStack_6c * (float10)_DAT_10078098;
          }
          else {
            fVar16 = (float10)fsin((float10)iStack_6c * (float10)_DAT_10078080 *
                                   (float10)_DAT_10078088 * (float10)_DAT_10078090);
          }
          fStack_74 = (float)fVar16;
          if (DAT_10079238 <= fStack_74) {
            lVar17 = __ftol();
            uVar18 = FUN_10069324(extraout_ECX_08,(int)((ulonglong)lVar17 >> 0x20),uVar15,0x200000);
            uVar18 = FUN_10069324(extraout_ECX_09,(int)((ulonglong)uVar18 >> 0x20),uVar15,0x200000);
            FUN_10069324(extraout_ECX_10,(int)((ulonglong)uVar18 >> 0x20),uVar15,0x200000);
            iVar7 = ((int)uVar18 + 0x80 >> 8) * (-(int)lVar17 + 0x10080 >> 8) +
                    (0x10080U - (-(int)lVar17 + 0x10000) & 0xffffff00);
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
            lVar17 = __ftol();
            uVar18 = FUN_10069324(extraout_ECX_05,(int)((ulonglong)lVar17 >> 0x20),uVar15,0x200000);
            uVar18 = FUN_10069324(extraout_ECX_06,(int)((ulonglong)uVar18 >> 0x20),uVar15,0x200000);
            FUN_10069324(extraout_ECX_07,(int)((ulonglong)uVar18 >> 0x20),uVar15,0x200000);
            iVar7 = ((int)uVar18 + 0x80 >> 8) * ((int)lVar17 + 0x80 >> 8) +
                    (DAT_1007bda8[1] + 0x80 >> 8) * (0x10080 - (int)lVar17 >> 8);
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
          uVar15 = uVar15 + 0x10000;
          iStack_70 = iStack_70 + 1;
        } while ((int)uVar15 < 0x200000);
        puStack_68 = (undefined1 *)((int)puStack_68 + 0x20);
        iStack_6c = iStack_6c + 1;
      } while ((int)puStack_68 < 0x400);
      iStack_6c = 0;
      puStack_68 = (undefined1 *)0x0;
      do {
        iStack_70 = 0;
        uVar15 = 0;
        do {
          if (DAT_10079234 == 0) {
            fVar16 = (float10)iStack_6c * (float10)_DAT_10078098;
          }
          else {
            fVar16 = (float10)fsin((float10)iStack_6c * (float10)_DAT_10078080 *
                                   (float10)_DAT_10078088 * (float10)_DAT_10078090);
          }
          fStack_74 = (float)fVar16;
          if (DAT_10079238 <= fStack_74) {
            lVar17 = __ftol();
            uVar18 = FUN_10069324(extraout_ECX_14,(int)((ulonglong)lVar17 >> 0x20),uVar15,0x200000);
            uVar18 = FUN_10069324(extraout_ECX_15,(int)((ulonglong)uVar18 >> 0x20),uVar15,0x200000);
            uVar18 = FUN_10069324(extraout_ECX_16,(int)((ulonglong)uVar18 >> 0x20),uVar15,0x200000);
            iVar7 = ((int)uVar18 + 0x80 >> 8) * (-(int)lVar17 + 0x10080 >> 8) +
                    (0x10080U - (-(int)lVar17 + 0x10000) & 0xffffff00);
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
            lVar17 = __ftol();
            uVar18 = FUN_10069324(extraout_ECX_11,(int)((ulonglong)lVar17 >> 0x20),uVar15,0x200000);
            uVar18 = FUN_10069324(extraout_ECX_12,(int)((ulonglong)uVar18 >> 0x20),uVar15,0x200000);
            uVar18 = FUN_10069324(extraout_ECX_13,(int)((ulonglong)uVar18 >> 0x20),uVar15,0x200000);
            iVar7 = ((int)uVar18 + 0x80 >> 8) * ((int)lVar17 + 0x80 >> 8) +
                    (DAT_1007bda8[2] + 0x80 >> 8) * (0x10080 - (int)lVar17 >> 8);
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
          uVar15 = uVar15 + 0x10000;
          iStack_70 = iStack_70 + 1;
        } while ((int)uVar15 < 0x200000);
        puStack_68 = (undefined1 *)((int)puStack_68 + 0x20);
        iStack_6c = iStack_6c + 1;
      } while ((int)puStack_68 < 0x400);
    }
    return;
  }
  iStack_70 = DAT_1007921c;
  iStack_64 = DAT_10079220;
  FUN_10006e50(DAT_10079220);
  iStack_6c = 0;
  puVar14 = (undefined1 *)(iStack_70 + 0x20);
  do {
    puStack_68 = (undefined1 *)((float)iStack_6c * _DAT_10078074);
    uVar15 = 0;
    do {
      uVar1 = uVar15 + 1;
      fStack_74 = (float)uVar1;
      FUN_10009780(auStack_60);
      if ((uVar15 & 1) == 0) {
        puVar11 = puVar14 + -0x20;
        puVar13 = auStack_60;
        do {
          puVar10 = puVar13 + 3;
          uVar4 = (*(code *)DAT_1007bda8[0xa1])(puVar13);
          *puVar11 = uVar4;
          puVar11 = puVar11 + 1;
          puVar13 = puVar10;
        } while (puVar10 < &stack0x00000000);
      }
      else {
        puVar11 = auStack_60;
        puVar13 = puVar14;
        do {
          puVar13 = puVar13 + -1;
          puVar10 = puVar11 + 3;
          uVar4 = (*(code *)DAT_1007bda8[0xa1])(puVar11);
          *puVar13 = uVar4;
          puVar11 = puVar10;
        } while (puVar10 < &stack0x00000000);
      }
      puVar14 = puVar14 + 0x20;
      uVar15 = uVar1;
    } while ((int)uVar1 < 4);
    iStack_6c = iStack_6c + 1;
  } while (iStack_6c < 0x24);
  FUN_10009780(auStack_60);
  puVar14 = (undefined1 *)(iStack_70 + 0x1200);
  puVar11 = auStack_60;
  do {
    puVar13 = puVar11 + 3;
    uVar4 = (*(code *)DAT_1007bda8[0xa1])(puVar11);
    *puVar14 = uVar4;
    puVar14 = puVar14 + 1;
    puVar11 = puVar13;
  } while (puVar13 < &stack0x00000000);
  iStack_70 = 0;
  do {
    iStack_6c = 0;
    puStack_68 = (undefined1 *)(iStack_70 + iStack_64);
    do {
      if (DAT_10079234 == 0) {
        fVar16 = (float10)iStack_6c * (float10)_DAT_10078098;
      }
      else {
        fVar16 = (float10)fsin((float10)iStack_6c * (float10)_DAT_10078080 * (float10)_DAT_10078088
                               * (float10)_DAT_10078090);
      }
      fStack_74 = (float)fVar16;
      if (DAT_10079238 <= fStack_74) {
        lVar17 = __ftol();
        bStack_77 = *(byte *)((int)&DAT_1007bfc0 + iStack_70);
        bStack_78 = *(byte *)((int)&DAT_1007bec0 + iStack_70);
        uVar15 = 0x10080U - (-(int)lVar17 + 0x10000) & 0xffffff00;
        iVar6 = -(int)lVar17 + 0x10080 >> 8;
        bStack_76 = *(byte *)((int)&DAT_1007bdb0 + iStack_70);
        FUN_10006d60(&bStack_78,&bStack_78);
        iVar7 = ((int)((uint)bStack_78 * 0x100 + 0x80) >> 8) * iVar6 + uVar15;
        if (0xffff < iVar7) {
          iVar7 = 0xffff;
        }
        iVar12 = ((int)((uint)bStack_77 * 0x100 + 0x80) >> 8) * iVar6 + uVar15;
        if (0xffff < iVar12) {
          iVar12 = 0xffff;
        }
        iVar6 = ((int)((uint)bStack_76 * 0x100 + 0x80) >> 8) * iVar6 + uVar15;
        if (0xffff < iVar6) {
          iVar6 = 0xffff;
        }
        bStack_78 = (byte)((uint)iVar7 >> 8);
        bStack_77 = (byte)((uint)iVar12 >> 8);
        bStack_76 = (byte)((uint)iVar6 >> 8);
        uVar4 = (*(code *)DAT_1007bda8[0xa1])(&bStack_78);
      }
      else {
        lVar17 = __ftol();
        iVar12 = (int)lVar17 + 0x80 >> 8;
        bStack_78 = *(byte *)((int)&DAT_1007bec0 + iStack_70);
        bStack_77 = *(byte *)((int)&DAT_1007bfc0 + iStack_70);
        bStack_76 = *(byte *)((int)&DAT_1007bdb0 + iStack_70);
        FUN_10006d60(&bStack_78,&bStack_78);
        iVar6 = 0x10080 - (int)lVar17 >> 8;
        iVar7 = ((int)((uint)bStack_78 * 0x100 + 0x80) >> 8) * iVar12 +
                (*DAT_1007bda8 + 0x80 >> 8) * iVar6;
        if (0xffff < iVar7) {
          iVar7 = 0xffff;
        }
        iVar9 = ((int)((uint)bStack_77 * 0x100 + 0x80) >> 8) * iVar12 +
                (DAT_1007bda8[1] + 0x80 >> 8) * iVar6;
        if (0xffff < iVar9) {
          iVar9 = 0xffff;
        }
        iVar6 = ((int)((uint)bStack_76 * 0x100 + 0x80) >> 8) * iVar12 +
                (DAT_1007bda8[2] + 0x80 >> 8) * iVar6;
        if (0xffff < iVar6) {
          iVar6 = 0xffff;
        }
        bStack_78 = (byte)((uint)iVar7 >> 8);
        bStack_77 = (byte)((uint)iVar9 >> 8);
        bStack_76 = (byte)((uint)iVar6 >> 8);
        uVar4 = (*(code *)DAT_1007bda8[0xa1])(&bStack_78);
      }
      *puStack_68 = uVar4;
      puStack_68 = puStack_68 + 0x100;
      iStack_6c = iStack_6c + 1;
    } while (iStack_6c < 0x20);
    iStack_70 = iStack_70 + 1;
  } while (iStack_70 < 0x100);
  FUN_10006e50(iStack_6c);
  return;
}


