// 0043ea90 FUN_0043ea90 [Global]
// programa: gamma.dll

undefined4 FUN_0043ea90(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  puVar1 = param_1 + -2;
  param_1[4] = param_1[4] + -1;
  if (param_1[4] != 0) {
    return param_1[4];
  }
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_00477898;
    param_1[-1] = &PTR_FUN_004778c4;
    *param_1 = &PTR_FUN_00477908;
    param_1[1] = &PTR_FUN_0047794c;
    param_1[2] = &PTR_FUN_0047797c;
    param_1[3] = &PTR_FUN_004779cc;
    piVar2 = (int *)param_1[7];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      param_1[7] = 0;
    }
    OleUninitialize();
    FUN_0044e100(puVar1);
  }
  return 0;
}


