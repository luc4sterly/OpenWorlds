// 00427410 FUN_00427410 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_00427410(void *this,char *param_1,uint param_2)

{
  *(undefined ***)this = &PTR_LAB_00471ff8;
  if (0xff < param_2) {
    param_2 = 0xff;
  }
  FUN_0044d6d0((char *)((int)this + 4),param_1,param_2);
  *(undefined1 *)((int)this + param_2 + 4) = 0;
  return this;
}


