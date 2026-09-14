// 0042b3f0 FUN_0042b3f0 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0042b3f0(void *this,undefined4 *param_1,int *param_2,uint *param_3)

{
  uint *puVar1;
  int *local_20;
  int *local_1c;
  undefined4 local_18 [2];
  
  if (param_2 != (int *)((int)this + 4)) {
    if (param_2[3] <= (int)*param_3) {
      if ((int)*param_3 <= param_2[3]) {
        *param_1 = param_2;
        return param_1;
      }
      local_1c = param_2;
      FUN_0042b5b0((int *)&local_1c);
      if ((local_1c == (int *)((int)this + 4)) || ((int)*param_3 < local_1c[3])) {
        if (param_2[1] == 0) {
          puVar1 = FUN_0042b5f0(this,param_2,'\0','\0',param_3);
          *param_1 = puVar1;
          return param_1;
        }
        puVar1 = FUN_0042b5f0(this,local_1c,'\x01','\0',param_3);
        *param_1 = puVar1;
        return param_1;
      }
      goto LAB_0042b512;
    }
  }
  local_20 = param_2;
  if (param_2 != *(int **)((int)this + 0xc)) {
    FUN_0042b570((int *)&local_20);
    if ((int)*param_3 <= local_20[3]) {
LAB_0042b512:
      FUN_0042b6e0(this,local_18,param_3);
      *param_1 = local_18[0];
      return param_1;
    }
  }
  if (*param_2 == 0) {
    puVar1 = FUN_0042b5f0(this,param_2,'\x01',param_2 == *(int **)((int)this + 0xc),param_3);
    *param_1 = puVar1;
    return param_1;
  }
  puVar1 = FUN_0042b5f0(this,local_20,'\0','\0',param_3);
  *param_1 = puVar1;
  return param_1;
}


