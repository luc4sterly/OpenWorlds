// 1004a190 __ioinit [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __ioinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __ioinit(void)

{
  undefined4 *puVar1;
  DWORD DVar2;
  HANDLE hFile;
  UINT *pUVar3;
  UINT UVar4;
  UINT UVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  _STARTUPINFOA local_44;
  
  puVar1 = _malloc(0x480);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_1005f7d0 = 0x20;
  DAT_1005f6d0 = puVar1;
  if (puVar1 < puVar1 + 0x120) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 9;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1[2] = 0;
      puVar1 = puVar6;
    } while (puVar6 < DAT_1005f6d0 + 0x120);
  }
  GetStartupInfoA(&local_44);
  if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
    UVar4 = *(UINT *)local_44.lpReserved2;
    pUVar3 = (UINT *)((int)local_44.lpReserved2 + 4);
    pbVar7 = (byte *)(UVar4 + (int)pUVar3);
    if (0x7ff < (int)UVar4) {
      UVar4 = 0x800;
    }
    UVar5 = UVar4;
    if ((int)DAT_1005f7d0 < (int)UVar4) {
      piVar9 = &DAT_1005f6d4;
      do {
        puVar1 = _malloc(0x480);
        UVar5 = DAT_1005f7d0;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar9 = (int)puVar1;
        DAT_1005f7d0 = DAT_1005f7d0 + 0x20;
        if (puVar1 < puVar1 + 0x120) {
          do {
            *(undefined1 *)(puVar1 + 1) = 0;
            puVar6 = puVar1 + 9;
            *puVar1 = 0xffffffff;
            *(undefined1 *)((int)puVar1 + 5) = 10;
            puVar1[2] = 0;
            puVar1 = puVar6;
          } while (puVar6 < (undefined4 *)(*piVar9 + 0x480));
        }
        piVar9 = piVar9 + 1;
        UVar5 = UVar4;
      } while ((int)DAT_1005f7d0 < (int)UVar4);
    }
    uVar10 = 0;
    if (0 < (int)UVar5) {
      do {
        if (((*(HANDLE *)pbVar7 != (HANDLE)0xffffffff) && ((*pUVar3 & 1) != 0)) &&
           (((*pUVar3 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar7), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   ((uVar10 & 0x1f) * 0x24 +
                   *(int *)((int)&DAT_1005f6d0 + ((int)(uVar10 & 0xffffffe7) >> 3)));
          *puVar1 = *(undefined4 *)pbVar7;
          *(byte *)(puVar1 + 1) = (byte)*pUVar3;
        }
        uVar10 = uVar10 + 1;
        pUVar3 = (UINT *)((int)pUVar3 + 1);
        pbVar7 = pbVar7 + 4;
      } while ((int)uVar10 < (int)UVar5);
    }
  }
  iVar8 = 0;
  iVar11 = 0;
  do {
    piVar9 = (int *)((int)DAT_1005f6d0 + iVar8);
    if (*piVar9 == -1) {
      DVar2 = 0xfffffff6;
      *(undefined1 *)(piVar9 + 1) = 0x81;
      if (iVar8 != 0) {
        DVar2 = (iVar11 == 1) - 0xc;
      }
      hFile = GetStdHandle(DVar2);
      if ((hFile == (HANDLE)0xffffffff) || (DVar2 = GetFileType(hFile), DVar2 == 0)) {
        *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 0x40;
      }
      else {
        *piVar9 = (int)hFile;
        if ((DVar2 & 0xff) == 2) {
          *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 0x40;
        }
        else if ((DVar2 & 0xff) == 3) {
          *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 8;
        }
      }
    }
    else {
      *(byte *)(piVar9 + 1) = *(byte *)(piVar9 + 1) | 0x80;
    }
    iVar8 = iVar8 + 0x24;
    iVar11 = iVar11 + 1;
  } while (iVar8 < 0x6c);
  UVar4 = SetHandleCount(DAT_1005f7d0);
  return UVar4;
}


