// 00439920 FUN_00439920 [Global]
// program: gamma.dll

undefined4 * __cdecl
FUN_00439920(undefined4 *param_1,int *param_2,char *param_3,int param_4,undefined4 param_5)

{
  uint *this;
  
  this = FUN_0044e010(0x10);
  if (this != (uint *)0x0) {
    FUN_00439a10(this,param_2,param_3,param_4,param_5);
  }
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_0047545c;
  param_1[1] = this;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  return param_1;
}


