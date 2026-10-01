// 0042f800 FUN_0042f800 [Global]
// program: gamma.dll

undefined4 * __cdecl FUN_0042f800(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_00471ff8;
  FUN_0044d6d0((char *)(param_1 + 1),&DAT_004a021c,0xff);
  *(undefined1 *)((int)param_1 + 0x103) = 0;
  return param_1;
}


