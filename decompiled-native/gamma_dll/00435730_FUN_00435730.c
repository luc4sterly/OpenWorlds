// 00435730 FUN_00435730 [Global]
// programa: gamma.dll

undefined4 * __fastcall FUN_00435730(undefined4 *param_1)

{
  undefined1 local_10c [260];
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_LAB_00475b54;
  param_1[4] = 0;
  param_1[5] = &PTR_LAB_00471ff8;
  *(undefined1 *)(param_1 + 6) = 0;
  param_1[0x46] = 0;
  FUN_00427410(local_10c,&DAT_00475b0c,0xff);
  FUN_004359a0(param_1,(int)local_10c);
  param_1[4] = DAT_00475b08;
  return param_1;
}


