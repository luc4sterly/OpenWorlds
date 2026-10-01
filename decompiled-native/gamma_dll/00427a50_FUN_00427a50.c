// 00427a50 FUN_00427a50 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00427a50(void *this,float param_1)

{
  undefined8 local_10;
  
  local_10._0_4_ = (undefined4)(longlong)ROUND(ROUND(param_1));
  *(undefined4 *)this = (undefined4)local_10;
  local_10 = (ulonglong)*(uint *)this;
  local_10._0_4_ =
       (undefined4)(longlong)ROUND(ROUND((param_1 - (float)local_10) * (float)_DAT_00472028));
  *(undefined4 *)((int)this + 4) = (undefined4)local_10;
  return;
}


