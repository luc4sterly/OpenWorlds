// 00448650 FUN_00448650 [Global]
// programa: gamma.dll

int * __fastcall FUN_00448650(int *param_1)

{
  int *piVar1;
  
  *param_1 = (int)&PTR_LAB_0047b8bc;
  param_1[3] = (int)&PTR_LAB_0047b8d4;
  param_1[4] = (int)&PTR_LAB_0047b918;
  (**(code **)(*param_1 + 0x124))();
  (**(code **)(*param_1 + 0x114))();
  piVar1 = (int *)param_1[0x12];
  if (piVar1 != (int *)0x0) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xf4))(1);
    }
    param_1[0x12] = 0;
  }
  piVar1 = (int *)param_1[0x1c];
  if (piVar1 != (int *)0x0) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))(1);
    }
    param_1[0x1c] = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x23));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1d));
  FUN_0044b270(param_1 + 0x15);
  FUN_0044b270(param_1 + 0x14);
  FUN_0044b270(param_1 + 0x13);
  FUN_00443880(param_1);
  return param_1;
}


