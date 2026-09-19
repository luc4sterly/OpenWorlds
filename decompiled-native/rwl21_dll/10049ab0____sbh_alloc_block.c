// 10049ab0 ___sbh_alloc_block [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    ___sbh_alloc_block
   
   Library: Visual Studio 1998 Release */

undefined * __cdecl ___sbh_alloc_block(uint param_1)

{
  undefined *puVar1;
  char *pcVar2;
  byte bVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  char cVar8;
  int iVar9;
  int *piVar10;
  undefined **ppuVar11;
  int iVar12;
  undefined *puVar13;
  
  piVar10 = (int *)PTR_LOOP_1005c6f4;
  do {
    cVar8 = (char)param_1;
    if (piVar10[0x204] != 0) {
      iVar12 = piVar10[2];
      if (iVar12 < 0x400) {
        iVar9 = iVar12 << 0xc;
        do {
          bVar3 = *(byte *)(iVar12 + 0x10 + (int)piVar10);
          if (((param_1 <= bVar3) && (bVar3 != 0xff)) &&
             (param_1 < *(byte *)(iVar12 + 0x410 + (int)piVar10))) {
            puVar6 = (undefined *)
                     ___sbh_alloc_block_from_page
                               ((int *)(piVar10[0x204] + iVar9),(uint)bVar3,param_1);
            if (puVar6 != (undefined *)0x0) {
              pcVar2 = (char *)(iVar12 + 0x10 + (int)piVar10);
              PTR_LOOP_1005c6f4 = (undefined *)piVar10;
              *pcVar2 = *pcVar2 - cVar8;
              piVar10[2] = iVar12;
              return puVar6;
            }
            *(char *)(iVar12 + 0x410 + (int)piVar10) = cVar8;
          }
          iVar9 = iVar9 + 0x1000;
          iVar12 = iVar12 + 1;
        } while (iVar9 < 0x400000);
      }
      iVar12 = 0;
      iVar9 = 0;
      if (0 < piVar10[2]) {
        do {
          bVar3 = *(byte *)(iVar9 + 0x10 + (int)piVar10);
          if (((param_1 <= bVar3) && (bVar3 != 0xff)) &&
             (param_1 < *(byte *)(iVar9 + 0x410 + (int)piVar10))) {
            puVar6 = (undefined *)
                     ___sbh_alloc_block_from_page
                               ((int *)(piVar10[0x204] + iVar12),(uint)bVar3,param_1);
            if (puVar6 != (undefined *)0x0) {
              pcVar2 = (char *)(iVar9 + 0x10 + (int)piVar10);
              PTR_LOOP_1005c6f4 = (undefined *)piVar10;
              *pcVar2 = *pcVar2 - cVar8;
              piVar10[2] = iVar9;
              return puVar6;
            }
            *(char *)(iVar9 + 0x410 + (int)piVar10) = cVar8;
          }
          iVar12 = iVar12 + 0x1000;
          iVar9 = iVar9 + 1;
        } while (iVar9 < piVar10[2]);
      }
    }
    piVar10 = (int *)*piVar10;
  } while (piVar10 != (int *)PTR_LOOP_1005c6f4);
  ppuVar11 = &PTR_LOOP_1005bee0;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_1005bee0) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_1005c6f4 = (undefined *)ppuVar11;
      *puVar7 = (undefined *)((int)puVar7 + param_1 + 8);
      puVar7[1] = 0xf0 - param_1;
      *(char *)(ppuVar11 + 4) = *(char *)(ppuVar11 + 4) - cVar8;
      return ppuVar11[0x204] + 0x100;
    }
  }
  puVar4 = ppuVar11[3];
  puVar6 = puVar4 + 0x10;
  puVar5 = puVar4;
  if (0x3ff < (int)puVar6) {
    puVar6 = (undefined *)0x400;
  }
  do {
    puVar13 = puVar5 + 1;
    if ((int)puVar6 <= (int)puVar13) break;
    puVar1 = puVar5 + 0x11;
    puVar5 = puVar13;
  } while (puVar1[(int)ppuVar11] == -1);
  puVar6 = VirtualAlloc(ppuVar11[0x204] + (int)puVar4 * 0x1000,((int)puVar13 - (int)puVar4) * 0x1000
                        ,0x1000,4);
  if (puVar6 != ppuVar11[0x204] + (int)puVar4 * 0x1000) {
    return (undefined *)0x0;
  }
  puVar6 = ppuVar11[3];
  piVar10 = (int *)(ppuVar11[0x204] + (int)puVar6 * 0x1000);
  for (; (int)puVar6 < (int)puVar13; puVar6 = puVar6 + 1) {
    *piVar10 = (int)(piVar10 + 2);
    piVar10[1] = 0xf0;
    *(undefined1 *)(piVar10 + 0x3e) = 0xff;
    *(undefined1 *)((int)ppuVar11 + (int)(puVar6 + 0x10)) = 0xf0;
    *(undefined1 *)((int)ppuVar11 + (int)(puVar6 + 0x410)) = 0xf1;
    piVar10 = piVar10 + 0x400;
  }
  for (; ((int)puVar13 < 0x400 && ((puVar13 + 0x10)[(int)ppuVar11] != -1)); puVar13 = puVar13 + 1) {
  }
  puVar6 = ppuVar11[3];
  PTR_LOOP_1005c6f4 = (undefined *)ppuVar11;
  ppuVar11[3] = (undefined *)0xffffffff;
  if ((int)puVar13 < 0x400) {
    ppuVar11[3] = puVar13;
  }
  puVar7 = (undefined4 *)(ppuVar11[0x204] + (int)puVar6 * 0x1000);
  *(char *)(puVar7 + 2) = cVar8;
  ppuVar11[2] = puVar6;
  (puVar6 + 0x10)[(int)ppuVar11] = (puVar6 + 0x10)[(int)ppuVar11] - cVar8;
  *puVar7 = (undefined *)((int)puVar7 + param_1 + 8);
  puVar7[1] = puVar7[1] - param_1;
  return ppuVar11[0x204] + (int)puVar6 * 0x1000 + 0x100;
}


