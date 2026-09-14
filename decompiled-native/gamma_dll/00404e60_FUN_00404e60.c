// 00404e60 FUN_00404e60 [Global]
// programa: gamma.dll

int __fastcall FUN_00404e60(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint local_18;
  
  uVar1 = *(uint *)(param_1 + 4);
  local_18 = 0;
  if (uVar1 != 0) {
    iVar3 = 0;
    do {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 8) + iVar3);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[1] = puVar2[1] + -1;
        if (puVar2[1] != 0) {
          puVar2 = (undefined4 *)0x0;
        }
        if (puVar2 != (undefined4 *)0x0) {
          (**(code **)*puVar2)(1);
        }
      }
      local_18 = local_18 + 1;
      iVar3 = iVar3 + 4;
    } while (local_18 < uVar1);
  }
  FUN_00404ed0((int *)(param_1 + 0xc));
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    FUN_0044e100(*(undefined4 **)(param_1 + 8));
  }
  return param_1;
}


