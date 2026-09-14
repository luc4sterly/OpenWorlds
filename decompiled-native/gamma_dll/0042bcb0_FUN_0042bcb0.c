// 0042bcb0 FUN_0042bcb0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0042bcb0(void *this,undefined4 *param_1,void *param_2)

{
  int local_10;
  
  FUN_0042bf40(this,&local_10,param_2);
  if (local_10 != (int)this + 4) {
    *param_1 = &PTR_LAB_00471ff8;
    FUN_0044d6d0((char *)(param_1 + 1),(char *)(local_10 + 0x114),0xff);
    *(undefined1 *)((int)param_1 + 0x103) = 0;
    return param_1;
  }
  *param_1 = &PTR_LAB_00471ff8;
  *(undefined1 *)(param_1 + 1) = 0;
  return param_1;
}


