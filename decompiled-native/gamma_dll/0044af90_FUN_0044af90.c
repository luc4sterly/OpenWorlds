// 0044af90 FUN_0044af90 [Global]
// program: gamma.dll

int * __thiscall FUN_0044af90(int *param_1,uint param_2)

{
  if (param_1 != (int *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = (int)&PTR_FUN_0047b574;
      param_1[3] = (int)&PTR_FUN_0047b58c;
      param_1[4] = (int)&PTR_FUN_0047b5d0;
      param_1[0x2f] = (int)&PTR_FUN_0047b6d4;
      param_1[0x30] = (int)&PTR_FUN_0047b700;
      FUN_00448650(param_1);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,FUN_0044a000);
    }
  }
  return param_1;
}


