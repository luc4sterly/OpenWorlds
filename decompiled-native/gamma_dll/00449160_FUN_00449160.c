// 00449160 FUN_00449160 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_00449160(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0x29];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[0x29] = 0;
  }
  if (*(int *)(param_1[0x1c] + 0x18) == 0) {
    return 1;
  }
  if ((param_1[5] != 0) && (*(char *)(param_1[0x1c] + 0x25) == '\0')) {
    return 0x80040224;
  }
  FUN_00449b50(param_1,0);
  (**(code **)(*param_1 + 0x108))();
  (**(code **)(*param_1 + 0x114))();
  param_1[0x16] = 0;
  return 0;
}


