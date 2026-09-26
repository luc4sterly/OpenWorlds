// 10004130 FUN_10004130 [Global]
// programa: RWDLDD21.DLL

void FUN_10004130(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    if (0 < *(int *)(param_1 + 4)) {
      iVar3 = 0;
      do {
        puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar3);
        if (puVar2[1] != 0) {
          *(undefined4 *)*puVar2 = 0xffffffff;
          *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar3) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0xc) + 4 + iVar3) = 0;
        }
        piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 0x14 + iVar3);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14 + iVar3) = 0;
        }
        piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 0x10 + iVar3);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10 + iVar3) = 0;
        }
        iVar3 = iVar3 + 0x18;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 4));
    }
    (**(code **)(DAT_100394fc + 0x358))(*(undefined4 *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}


