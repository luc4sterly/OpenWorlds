// 00445420 FUN_00445420 [Global]
// program: gamma.dll

undefined4 FUN_00445420(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  iVar2 = *(int *)(param_1 + 0x28);
  if (iVar2 != 0) {
    iVar2 = iVar2 + 0xc;
  }
  *param_2 = iVar2;
  piVar1 = *(int **)(param_1 + 0x28);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x74))(piVar1);
  }
  if (*(short **)(param_1 + 0x14) == (short *)0x0) {
    *(undefined2 *)(param_2 + 2) = 0;
  }
  else {
    FUN_0044b2c0((short *)(param_2 + 2),*(short **)(param_1 + 0x14),0x80);
  }
  param_2[1] = *(int *)(param_1 + 0x1c);
  return 0;
}


