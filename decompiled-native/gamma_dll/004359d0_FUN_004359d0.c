// 004359d0 FUN_004359d0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_004359d0(void *this,undefined4 *param_1)

{
  *param_1 = &PTR_LAB_00471ff8;
  FUN_0044d6d0((char *)(param_1 + 1),(char *)((int)this + 0x18),0xff);
  *(undefined1 *)((int)param_1 + 0x103) = 0;
  return param_1;
}


