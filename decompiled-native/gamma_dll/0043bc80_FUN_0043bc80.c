// 0043bc80 FUN_0043bc80 [Global]
// programa: gamma.dll

undefined4 * __cdecl FUN_0043bc80(undefined4 *param_1,int param_2)

{
  uint *this;
  
  this = FUN_0044e010(0x14);
  if (this != (uint *)0x0) {
    FUN_0043bd70(this,param_2);
  }
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475438;
  param_1[1] = this;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  return param_1;
}


