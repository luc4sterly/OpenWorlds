// 00450830 FUN_00450830 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00450830(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = DAT_0049fa64;
  param_3[1] = param_2;
  param_3[2] = param_1;
  DAT_0049fa64 = param_3;
  return param_1;
}


