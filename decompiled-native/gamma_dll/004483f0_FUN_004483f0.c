// 004483f0 FUN_004483f0 [Global]
// programa: gamma.dll

void FUN_004483f0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  LPVOID pvVar3;
  
  *param_1 = *param_2;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 1);
  *(undefined2 *)((int)param_1 + 6) = *(undefined2 *)((int)param_2 + 6);
  uVar1 = param_2[3];
  param_1[2] = param_2[2];
  param_1[3] = uVar1;
  param_1[4] = param_2[4];
  *(undefined2 *)(param_1 + 5) = *(undefined2 *)(param_2 + 5);
  *(undefined2 *)((int)param_1 + 0x16) = *(undefined2 *)((int)param_2 + 0x16);
  uVar1 = param_2[7];
  param_1[6] = param_2[6];
  param_1[7] = uVar1;
  param_1[8] = param_2[8];
  param_1[9] = param_2[9];
  param_1[10] = param_2[10];
  param_1[0xb] = param_2[0xb];
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)((int)param_1 + 0x32) = *(undefined2 *)((int)param_2 + 0x32);
  uVar1 = param_2[0xe];
  param_1[0xd] = param_2[0xd];
  param_1[0xe] = uVar1;
  param_1[0xf] = param_2[0xf];
  param_1[0x10] = param_2[0x10];
  param_1[0x11] = param_2[0x11];
  if (param_2[0x10] != 0) {
    pvVar3 = CoTaskMemAlloc(param_2[0x10]);
    param_1[0x11] = pvVar3;
    if ((undefined4 *)param_1[0x11] == (undefined4 *)0x0) {
      param_1[0x10] = 0;
    }
    else {
      FUN_0044df50((undefined4 *)param_1[0x11],(undefined4 *)param_2[0x11],param_1[0x10]);
    }
  }
  piVar2 = (int *)param_1[0xf];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  return;
}


