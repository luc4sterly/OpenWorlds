// 00430155 FUN_00430155 [Global]
// program: sfmain.exe

/* WARNING: Removing unreachable block (ram,0x0043040b) */
/* WARNING: Removing unreachable block (ram,0x00430424) */
/* WARNING: Removing unreachable block (ram,0x004302d5) */
/* WARNING: Removing unreachable block (ram,0x00430270) */
/* WARNING: Removing unreachable block (ram,0x0043028f) */
/* WARNING: Removing unreachable block (ram,0x004302ae) */
/* WARNING: Removing unreachable block (ram,0x00430296) */
/* WARNING: Removing unreachable block (ram,0x0043029f) */
/* WARNING: Removing unreachable block (ram,0x00430278) */
/* WARNING: Removing unreachable block (ram,0x004301f0) */
/* WARNING: Removing unreachable block (ram,0x0043020e) */
/* WARNING: Removing unreachable block (ram,0x00430253) */
/* WARNING: Removing unreachable block (ram,0x00430215) */
/* WARNING: Removing unreachable block (ram,0x004301f8) */
/* WARNING: Removing unreachable block (ram,0x004302bf) */
/* WARNING: Removing unreachable block (ram,0x00430202) */
/* WARNING: Removing unreachable block (ram,0x004304a6) */
/* WARNING: Removing unreachable block (ram,0x004304b4) */
/* WARNING: Removing unreachable block (ram,0x004304cd) */

undefined4 __fastcall FUN_00430155(undefined *param_1,byte *param_2)

{
  int iVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  undefined4 *extraout_ECX;
  char *pcVar5;
  char *extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  undefined4 *extraout_ECX_02;
  int *unaff_EBX;
  bool bVar6;
  int iStack_30;
  undefined4 *puStack_2c;
  int iStack_28;
  char cStack_1e;
  char acStack_1d [5];
  code *local_18;
  undefined1 local_14 [4];
  
  local_14[0] = 0;
  local_18 = (code *)param_1;
  while( true ) {
    while( true ) {
      bVar2 = *param_2;
      if (bVar2 == 0) {
        return 0;
      }
      param_2 = param_2 + 1;
      if (bVar2 == 0x25) break;
      (*local_18)();
      param_1 = (undefined *)extraout_ECX;
    }
    pbVar4 = FUN_004304f4(CONCAT31((int3)((uint)param_1 >> 8),bVar2),unaff_EBX);
    bVar2 = *pbVar4;
    param_2 = pbVar4 + 1;
    if (bVar2 == 0) break;
    if (bVar2 == 0x6e) {
      puVar3 = (undefined4 *)*unaff_EBX;
      param_1 = (undefined *)(puVar3 + 1);
      *unaff_EBX = (int)param_1;
      *(undefined4 *)*puVar3 = 0;
    }
    else {
      FUN_00430832((ushort *)local_14,unaff_EBX);
      if (cStack_1e == ' ') {
        while (iStack_30 = iStack_30 + -1, -1 < iStack_30) {
          (*local_18)();
        }
      }
      pcVar5 = acStack_1d;
      while (*pcVar5 != '\0') {
        (*local_18)();
        pcVar5 = extraout_ECX_00;
      }
      while (iVar1 = iStack_28 + -1, iStack_28 != 0) {
        (*local_18)();
        iStack_28 = iVar1;
      }
      param_1 = (undefined *)0xffffffff;
      if (cStack_1e != ' ') {
        while (iStack_30 = iStack_30 + -1, -1 < iStack_30) {
          (*local_18)();
          param_1 = (undefined *)extraout_ECX_01;
        }
      }
      if ((bVar2 == 0x73) || (bVar2 == 0x53)) {
        while (puVar3 = (undefined4 *)((int)puStack_2c + -1),
              bVar6 = puStack_2c != (undefined4 *)0x0, puStack_2c = puVar3, iStack_28 = iVar1, bVar6
              ) {
          (*local_18)();
          param_1 = (undefined *)extraout_ECX_02;
        }
      }
      else {
        while (param_1 = (undefined *)((int)puStack_2c + -1),
              bVar6 = puStack_2c != (undefined4 *)0x0, puStack_2c = (undefined4 *)param_1,
              iStack_28 = iVar1, bVar6) {
          (*local_18)();
        }
      }
    }
  }
  return 0;
}


