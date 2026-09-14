// 00433890 FUN_00433890 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00433890(void *this,undefined4 *param_1)

{
  if (*(void **)((int)this + 0x14) != (void *)0x0) {
    FUN_00439c60(*(void **)((int)this + 0x14),param_1);
    return param_1;
  }
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475468;
  param_1[1] = 0;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  return param_1;
}


