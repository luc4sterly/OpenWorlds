// 10037030 FUN_10037030 [Global]
// program: RWL21.DLL

undefined4 * FUN_10037030(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    if (DAT_1005b334 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(0xff8);
      if (puVar1 == (undefined4 *)0x0) {
        FUN_1000cba0(3);
      }
      else {
        DAT_1005b338 = DAT_1005b338 + 1;
      }
    }
    else {
      DAT_1005b33c = DAT_1005b33c + -1;
      puVar1 = DAT_1005b334;
      DAT_1005b334 = (undefined4 *)*DAT_1005b334;
    }
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1[0x3fd] = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 **)(param_1 + 0x18) = puVar1;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    iVar2 = 1;
    *(undefined4 **)(param_1 + 0x10) = puVar1;
    puVar3 = puVar1;
    if (1 < *(int *)(param_1 + 0xc)) {
      do {
        iVar2 = iVar2 + 1;
        puVar1 = (undefined4 *)(*(int *)(param_1 + 8) + (int)puVar3);
        *puVar3 = puVar1;
        puVar3 = puVar1;
      } while (iVar2 < *(int *)(param_1 + 0xc));
    }
    *puVar1 = 0;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = *puVar1;
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  return puVar1;
}


