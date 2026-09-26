// 10005340 FUN_10005340 [Global]
// programa: RWDLDD21.DLL

void FUN_10005340(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = 3;
    piVar2 = (int *)(param_1 + 0x28);
    do {
      piVar1 = (int *)*piVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar2 = 0;
      }
      piVar2[10] = 0;
      piVar2 = piVar2 + -1;
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
    piVar2 = *(int **)(param_1 + 0x18);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    piVar2 = *(int **)(param_1 + 0x14);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    piVar2 = *(int **)(param_1 + 0x10);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    piVar2 = *(int **)(param_1 + 0xc);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    (**(code **)(DAT_100394fc + 0x358))(param_1);
  }
  return;
}


