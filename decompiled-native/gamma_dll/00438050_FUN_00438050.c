// 00438050 FUN_00438050 [Global]
// programa: gamma.dll

undefined4 * __cdecl FUN_00438050(undefined4 *param_1,void *param_2)

{
  uint *this;
  
  this = FUN_0044e010(0x254);
  if (this != (uint *)0x0) {
    FUN_004380f0(this,param_2);
  }
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475040;
  param_1[1] = this;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  return param_1;
}


