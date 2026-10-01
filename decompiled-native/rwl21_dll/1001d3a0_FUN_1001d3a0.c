// 1001d3a0 FUN_1001d3a0 [Global]
// program: RWL21.DLL

int * FUN_1001d3a0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  piVar1 = FUN_10037030(DAT_1005ac3c);
  if (piVar1 == (int *)0x0) {
    FUN_1000cba0(3);
  }
  else {
    iVar2 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(param_1 * 4);
    *piVar1 = iVar2;
    if (iVar2 == 0) {
      FUN_1000cba0(3);
      return piVar1;
    }
    piVar1[1] = param_1;
    if (0 < param_1) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 4;
        param_1 = param_1 + -1;
        *(undefined4 *)(*piVar1 + -4 + iVar2) = 0;
      } while (param_1 != 0);
    }
    piVar1[2] = 0;
    puVar3 = FUN_10037030(DAT_1005ac38);
    if (puVar3 == (undefined4 *)0x0) {
      FUN_1000cba0(3);
    }
    else {
      *(undefined1 *)(puVar3 + 0x10) = 0;
      *(undefined1 *)((int)puVar3 + 0x41) = 1;
      puVar3[0xf] = 0x3f800000;
      puVar3[10] = 0x3f800000;
      puVar3[5] = 0x3f800000;
      *puVar3 = 0x3f800000;
      puVar3[0xe] = 0;
      puVar3[0xd] = 0;
      puVar3[0xc] = 0;
      puVar3[0xb] = 0;
      puVar3[9] = 0;
      puVar3[8] = 0;
      puVar3[7] = 0;
      puVar3[6] = 0;
      puVar3[4] = 0;
      puVar3[3] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      *(undefined1 *)((int)puVar3 + 0x41) = 1;
      *(undefined1 *)(puVar3 + 0x10) = 1;
    }
    *(undefined4 **)(*piVar1 + piVar1[2] * 4) = puVar3;
    if (*(int *)(*piVar1 + piVar1[2] * 4) == 0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(*piVar1);
      FUN_10037010(DAT_1005ac3c,piVar1);
      return (int *)0x0;
    }
  }
  return piVar1;
}


